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

    char * posts = malloc(size + 10*sizeof(char));
    strcpy(posts, dump_path);
    strcat(posts, "Posts.xml");
    FILE * p = fopen(posts,"r");
    read_xmlfile(p, "Posts.xml");

    char * users = malloc(size + 10*sizeof(char));
    strcpy(users, dump_path);
    strcat(users, "Users.xml");
    FILE * u = fopen(users,"r");
    read_xmlfile(u, "Users.xml");

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
    int i;

    if (attributes != NULL) {
        for (i = 0;(attributes[i] != NULL);i++) {
          if(strncmp((const char *)attributes[i], "Id", 2) == 0 ||
             strncmp((const char *)attributes[i], "Reputation", 10) == 0 ||
             strncmp((const char *)attributes[i], "DisplayName", 11) == 0 ||
             strncmp((const char *)attributes[i], "AboutMe", 7) == 0) {
	          //fprintf(stdout, "%s = ", attributes[i]);
            i++;
	          if (attributes[i] != NULL) {
	             //fprintf(stdout, "%s ", attributes[i]);
             }
          }
	      }
    }
    //fprintf(stdout, "\n");
}

static void OnStartElementPosts(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
    int i, a, id, post_type_id, owner_id, title, tags, answer_count, score, parentid;
    id = post_type_id = owner_id = title = tags = answer_count = score = parentid = 0;

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

            pointer->user_id = atoi((const char *)attributes[owner_id]);

            sprintf(pointer->title, "%s\n", (const char *)attributes[title]);
            sprintf(pointer->tags, "%s\n", (const char *)attributes[tags]);

            g_hash_table_insert(structure->questions, GINT_TO_POINTER(pointer->post_id), pointer);
        }

        else {
            Answers * pointer = malloc(sizeof(Answers));

            pointer->answer_id = atoi((const char *)attributes[id]);

            int votes = atoi((const char *)attributes[score]);
            pointer->score = votes;

            int parent_id = atoi((const char *)attributes[parentid]);
            Questions * q = g_hash_table_lookup(structure->questions, GINT_TO_POINTER(parent_id));

            if(q != NULL) {
                q->n_answer_votes += votes;
                g_ptr_array_add(q->answers, pointer);
            }
            else {
                q = malloc(sizeof(Questions));

                q->user_id=0;
                strcpy(q->title, "");
                strcpy(q->tags, "");
                q->n_answers=1;

                q->post_id = atoi((const char *)attributes[parentid]);

                q->answers = g_ptr_array_new();
                q->n_answer_votes = votes;

                g_ptr_array_add(q->answers, pointer);

                g_hash_table_insert(structure->questions, GINT_TO_POINTER(q->post_id), q);
            }
        }

    }
}


static void OnStartElementVotes(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
    int i;


    if (attributes != NULL) {
        for (i = 0;(attributes[i] != NULL);i++) {
          if(strncmp((const char *)attributes[i], "Id", 2) == 0 ||
             strncmp((const char *)attributes[i], "PostId", 6) == 0 ||
             strncmp((const char *)attributes[i], "VoteTypeId", 10) == 0 ||
             strncmp((const char *)attributes[i], "UserId", 6) == 0) {
	          //fprintf(stdout, "%s = ", attributes[i]);
            i++;
	          if (attributes[i] != NULL) {
	            // fprintf(stdout, "%s ", attributes[i]);
            }
          }
	      }
    }
    //fprintf(stdout, "\n");
}