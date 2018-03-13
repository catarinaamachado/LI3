#include <libxml/xmlreader.h>
#include <libxml/SAX.h>
#include <stdio.h>
#include <string.h>

#include "interface.h"
#include "struct.h"

TAD_community structure;

static xmlSAXHandler make_sax_handler(char *dump_file_name);

static int read_xmlfile(FILE *file, char *dump_file_name);

static void OnStartElementUsers(void *ctx, const xmlChar *element_name, const xmlChar **attributes);

static void OnStartElementPosts(void *ctx, const xmlChar *element_name, const xmlChar **attributes);

static void OnStartElementVotes(void *ctx, const xmlChar *element_name, const xmlChar **attributes);


TAD_community load(TAD_community com, char* dump_path) {
    structure = com;

    int size = sizeof(char) * strlen(dump_path);

    char * users = malloc(size + 10*sizeof(char));
    strcpy(users, dump_path);
    strcat(users, "Users.xml");
    FILE * u = fopen(users,"r");
    read_xmlfile(u, "Users.xml");

    char * posts = malloc(size + 10*sizeof(char));
    strcpy(posts, dump_path);
    strcat(posts, "Posts.xml");
    FILE * p = fopen(posts,"r");
    read_xmlfile(p, "Posts.xml");

    char * votes = malloc(size + 10*sizeof(char));
    strcpy(votes, dump_path);
    strcat(votes, "Votes.xml");
    FILE * v = fopen(votes,"r");
    read_xmlfile(v, "Votes.xml");

    fclose(p);
    fclose(u);
    fclose(v);

    return structure;
}


int read_xmlfile(FILE *file, char *dump_file_name) {
    char chars[1024];
    int result = fread(chars, 1, 4, file); //lê 4 bytes de f e coloca em chars
    if (result <= 0) {
        return 1;
    }

    //inicializa a estrutura xmlSAXHandler
    xmlSAXHandler SAXHander = make_sax_handler(dump_file_name);


    /*
    Inicializa o Sax;
    Informa quais são as callbacks a serem chamadas e verifica o encoding;
    */
    xmlParserCtxtPtr ctxt = xmlCreatePushParserCtxt(
        &SAXHander, NULL, chars, result, NULL);

    while ((result = fread(chars, 1, sizeof(chars), file)) > 0) {
        if(xmlParseChunk(ctxt, chars, result, 0)) {
            xmlParserError(ctxt, "xmlParseChunk");
            return 1;
        }
    }

    /* int xmlParseChunk (xmlParserCtxtPtr ctxt, const char *chunk, int size, int terminate); */
    xmlParseChunk(ctxt, chars, 0, 1);

    xmlFreeParserCtxt(ctxt);
    xmlCleanupParser();
    return 0;
}

xmlSAXHandler make_sax_handler (char *dump_file_name){
    xmlSAXHandler SAXHander;

    memset(&SAXHander, 0, sizeof(xmlSAXHandler)); //inicializa tudo a zero

    SAXHander.initialized = XML_SAX2_MAGIC;
    if (strncmp(dump_file_name, "Users.xml", 9) == 0)
      SAXHander.startElement = OnStartElementUsers;
    if (strncmp(dump_file_name, "Posts.xml", 9) == 0)
      SAXHander.startElement = OnStartElementPosts;
    if (strncmp(dump_file_name, "Votes.xml", 9) == 0)
      SAXHander.startElement = OnStartElementVotes;

    return SAXHander;
}


//Extrai os atributos necessários do user
static void OnStartElementUsers(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
    int i, id, reputation, name, about;
    id = reputation = name = about = 0;

    long user_id;

    if (attributes != NULL) {
        
        for (i = 0;(attributes[i] != NULL);i++) {
            if(strncmp((const char *)attributes[i], "Id", 2) == 0)
                id = ++i;

            else if(strncmp((const char *)attributes[i], "Reputation", 10) == 0)
                reputation = ++i;

            else if(strncmp((const char *)attributes[i], "DisplayName", 11) == 0)
                name = ++i;

            else if(strncmp((const char *)attributes[i], "AboutMe", 7) == 0)
                about = ++i;
        }

        user_id = atol((const char *)attributes[id]);

        Users * pointer = malloc(sizeof(Users));

        pointer->username = malloc(sizeof(char) * (strlen((const char *)attributes[name])+2));
        sprintf(pointer->username, "%s\n", (const char *)attributes[name]);

        if(about != 0) { 
            pointer->shortbio = malloc(sizeof(char) * (strlen((const char *)attributes[about])+2));
            sprintf(pointer->shortbio, "%s\n", (const char *)attributes[about]);
        }

        else {
            pointer->shortbio = malloc(sizeof(char));
            strcpy(pointer->shortbio, "\n");
        }

        pointer->reputation = atoi((const char *)attributes[reputation]);
        pointer->n_posts = 0;
        pointer->user_id = user_id;

        pointer->last_10posts = g_array_sized_new(FALSE, TRUE, sizeof(postDate), 10);
            
        g_hash_table_insert(structure->users, GINT_TO_POINTER(user_id), pointer);
    }
}

static void OnStartElementPosts(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
    int i, a, id, post_type_id, owner_id, title, tags, answer_count, score, parentid, date;
    id = post_type_id = owner_id = title = tags = answer_count = score = parentid = date = 0;

    if (attributes != NULL) {

        for (i = 0;(attributes[i] != NULL);i++) {
            if(strncmp((const char *)attributes[i], "Id", 2) == 0)
                id = ++i;

            else if(strncmp((const char *)attributes[i], "PostTypeId", 10) == 0)
                post_type_id = ++i;

            else if(strncmp((const char *)attributes[i], "OwnerUserId", 11) == 0)
                owner_id = ++i;

            else if(strncmp((const char *)attributes[i], "Title", 5) == 0)
                title = ++i;

            else if(strncmp((const char *)attributes[i], "Tags", 4) == 0)
                tags = ++i;

            else if(strncmp((const char *)attributes[i], "AnswerCount", 11) == 0)
                answer_count = ++i;

            else if(strncmp((const char *)attributes[i], "Score", 5) == 0)
                score = ++i;

            else if(strncmp((const char *)attributes[i], "ParentId", 8) == 0)
                parentid = ++i;

            else if(strncmp((const char *)attributes[i], "CreationDate", 12) == 0)
                date = ++i;
        }

        if( !strncmp((const char *)attributes[post_type_id], "1", 1)) {

            a = atoi((const char *)attributes[id]);

            Questions * pointer = g_hash_table_lookup (structure->questions, GINT_TO_POINTER(a));

            if(pointer == NULL) {
                pointer = malloc(sizeof(Questions));

                pointer->post_id = a;

                pointer->n_answers = atoi((const char *)attributes[answer_count]);
                pointer->answers = g_ptr_array_sized_new(pointer->n_answers);

                pointer->n_answer_votes = 0;
            }

            else {
                pointer->n_answers = atoi((const char *)attributes[answer_count]);
            }

            pointer->user_id = atol((const char *)attributes[owner_id]);

            pointer->title = malloc(sizeof(char) * (strlen((const char *)attributes[title])+2));
            sprintf(pointer->title, "%s\n", (const char *)attributes[title]);

            pointer->tags = malloc(sizeof(char) * (strlen((const char *)attributes[tags])+2));
            sprintf(pointer->tags, "%s\n", (const char *)attributes[tags]);

            g_hash_table_insert(structure->questions, GINT_TO_POINTER(pointer->post_id), pointer);
        }

        else {
            Answers * pointer = malloc(sizeof(Answers));

            pointer->answer_id = atoi((const char *)attributes[id]);

            int votes = atoi((const char *)attributes[score]);
            pointer->score = votes;
            pointer->total_voters = 0; //inicializa votantes a zero
            pointer->voters_id = g_array_new(FALSE, FALSE, sizeof(gint));  //inicializa o array dos voters

            g_hash_table_insert(structure->answers, GINT_TO_POINTER(pointer->answer_id), pointer); //insere uma resposta na hash table das answers

            int parent_id = atoi((const char *)attributes[parentid]);
            Questions * q = g_hash_table_lookup(structure->questions, GINT_TO_POINTER(parent_id));

            if(q != NULL) {
                q->n_answer_votes += votes;
                g_ptr_array_add(q->answers, pointer);
            }
            else {
                q = malloc(sizeof(Questions));

                q->user_id=0;

                q->title = 0;

                q->tags = 0;

                q->n_answers=1;

                q->post_id = atoi((const char *)attributes[parentid]);

                q->answers = g_ptr_array_new();
                q->n_answer_votes = votes;

                g_ptr_array_add(q->answers, pointer);

                g_hash_table_insert(structure->questions, GINT_TO_POINTER(q->post_id), q);
            }
        }

        if(owner_id) {
            int oid = atoi((const char *)attributes[owner_id]);
            Users * u = g_hash_table_lookup(structure->users, GINT_TO_POINTER(oid));

            if(u != NULL) {
                u->n_posts++;

                postDate pd = malloc(sizeof(struct postAndDate));

                pd->post_id = atol((const char *)attributes[id]);
                sscanf((const char *)attributes[date], "%d-%d-%dT%d:%d:%d.%d\n", 
                    &pd->year, &pd->month, &pd->day, &pd->hour, &pd->min, &pd->sec, &pd->mili);

                g_array_append_val(u->last_10posts, pd);
            }
        }
    }
}


static void OnStartElementVotes(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
    int i, a, post_id, vote_type_id, user_id;
    post_id = vote_type_id = user_id = 0;


    if (attributes != NULL) {

        for (i = 0; (attributes[i] != NULL); i++) {
          if(strncmp((const char *)attributes[i], "PostId", 6) == 0)
            post_id = i++;

          else if (strncmp((const char *)attributes[i], "VoteTypeId", 10) == 0)
            vote_type_id = i++;

          else if (strncmp((const char *)attributes[i], "UserId", 6) == 0)
            user_id = i++;
       }

       if( !strncmp((const char *)attributes[vote_type_id], "5", 1)) {

          a = atoi((const char *)attributes[post_id]);

          Answers * pointer = g_hash_table_lookup (structure->answers, GINT_TO_POINTER(a));

          if(pointer != NULL) { // se der null é porque a resposta não existe e, por isso, não lhe posso associar um voto

              pointer->total_voters++;

              g_array_append_val(pointer->voters_id, attributes[user_id]);
          }

        }

      }

}
