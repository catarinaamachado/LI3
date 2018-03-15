#include <libxml/xmlreader.h>
#include <libxml/SAX.h>
#include <stdio.h>
#include <string.h>

#include "interface.h"
#include "struct.h"
#include "users.h"
#include "postDate.h"

static TAD_community structure;

//para concatenar a data num unico inteiro
static int concatenate(int x, int y) {
    int pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
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

        user_id = atol((char *)attributes[id]);

        Users pointer = malloc(getUsersSize());

        setUsername(pointer, (char *)attributes[name]);

        if(about != 0)
            setBio(pointer, (char *)attributes[about]);

        else
            setBio(pointer, "");

        setReputation(pointer, atoi((char *)attributes[reputation]));
        setNPosts(pointer, 0);
        setUserId(pointer, user_id);

        initLastPosts(pointer);

        insertUser(structure, user_id, pointer);
    }
}

static void OnStartElementPosts(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
    int i, id, post_type_id, owner_id, title, tags, answer_count, score, parentid, date, dateInteger;
    id = post_type_id = owner_id = title = tags = answer_count = score = parentid = date = 0;
    long a;

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


        postDate pd = malloc(getPDSize());

        setPostId(pd, atol((char *)attributes[id]));

        setDate(pd, (char *)attributes[date]);

        // dateInteger = concatenate(getDay(pd), getMonth(pd));
        // dateInteger = concatenate(dateInteger, getYear(pd));

        // Day * pointerDay = g_hash_table_lookup (structure->day, GINT_TO_POINTER(dateInteger)); //TODO:

        // if(pointerDay == NULL) { //se o dia ainda nao existe na hash table
        //   pointerDay = malloc(sizeof(Day));

        //   pointerDay->n_questions = 0;
        //   pointerDay->questions = g_ptr_array_new();
        //   pointerDay->n_answers = 0;
        //   pointerDay->answers = g_ptr_array_new();
        // }

        // pointerDay->day = pd->day;
        // pointerDay->month = pd->month;
        // pointerDay->year = pd->year;

        if( !strncmp((const char *)attributes[post_type_id], "1", 1)) { //trata-se de uma pergunta
            a = atol((const char *)attributes[id]);

            Questions pointer = lookQuestion(structure, a);

            if(pointer == NULL) { //se a pergunta nao existe (caso em que resposta vem antes da pergunta, e se cria a pergunta vazia)
                pointer = malloc(sizeQuestions());

                setQuestionId(pointer, a);

                setNAnswers(pointer, atoi((char *)attributes[answer_count]));
                setNAnswerVotes(pointer, 0);

                initAnswers(pointer);
            }

            else {
                setNAnswers(pointer, atoi((char *)attributes[answer_count]));
            }

            setQUserId(pointer, atol((const char *)attributes[owner_id]));

            setTitle(pointer, (char *)attributes[title]);

            setTags(pointer, (char *)attributes[tags]);

            insertQuestion(structure, getQuestionId(pointer), pointer);

            //pointerDay->n_questions += 1; //TODO:
            //g_ptr_array_add(pointerDay->questions, pointer);
        }

        else {  // se for uma resposta
            Answers pointer = malloc(sizeAnswers());

            setAnswerId(pointer, atol((const char *)attributes[id]));

            int votes = atoi((const char *)attributes[score]);
            setScore(pointer, votes);
            //setTotalVoters(pointer, 0);
            //pointer->voters_id = g_array_new(FALSE, FALSE, sizeof(gint));  //inicializa o array dos voters

            insertAnswers(structure, getAnswerId(pointer), pointer);

            long parent_id = atol((const char *)attributes[parentid]);
            Questions q = lookQuestion(structure, parent_id);

            if(q != NULL) {  // se a pergunta existe
                setNAnswerVotes(q, getNAnswerVotes(q) + votes);

                addAnswers(q, pointer);
            }

            else {
                q = malloc(sizeQuestions());

                setQUserId(q, 0);

                setTitle(q, 0);

                setTags(q, 0);

                setNAnswers(q, 1);

                setQuestionId(q, atoi((const char *)attributes[parentid]));

                initAnswers(q);

                setNAnswerVotes(q, votes);

                addAnswers(q, pointer);

                insertQuestion(structure, getQuestionId(q), q);
            }

            //pointerDay->n_answers += 1;
            //g_ptr_array_add(pointerDay->answers, pointer);
        }


        //g_hash_table_insert (structure->day, GINT_TO_POINTER(dateInteger), pointerDay);


        if(owner_id) {  //acrescentar posts aos ids
            long oid = atol((const char *)attributes[owner_id]);
            Users u = lookUsers(structure, oid);

            if(u != NULL) {
                incrementNPosts(u);

                appendPost(u, pd);
            }
        }
    }
}


// static void OnStartElementVotes(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
//     int i, a, post_id, vote_type_id, user_id;
//     post_id = vote_type_id = user_id = 0;


//     if (attributes != NULL) {

//         for (i = 0; (attributes[i] != NULL); i++) {
//           if(strncmp((const char *)attributes[i], "PostId", 6) == 0)
//             post_id = ++i;

//           else if (strncmp((const char *)attributes[i], "VoteTypeId", 10) == 0)
//             vote_type_id = ++i;

//           else if (strncmp((const char *)attributes[i], "UserId", 6) == 0)
//             user_id = ++i;
//        }

//        if( !strncmp((const char *)attributes[vote_type_id], "5", 1)) {

//           a = atoi((const char *)attributes[post_id]);

//           Answers * pointer = g_hash_table_lookup (structure->answers, GINT_TO_POINTER(a));

//           if(pointer != NULL) { // se der null é porque a resposta não existe e, por isso, não lhe posso associar um voto

//               pointer->total_voters++;

//                 int num = atoi((const char *)attributes[user_id]);

//               g_array_append_val(pointer->voters_id, num);
//           }

//         }

//       }

// }


static xmlSAXHandler make_sax_handler (char *dump_file_name){
    xmlSAXHandler SAXHander;

    memset(&SAXHander, 0, sizeof(xmlSAXHandler)); //inicializa tudo a zero

    SAXHander.initialized = XML_SAX2_MAGIC;
    if (strncmp(dump_file_name, "Users.xml", 9) == 0)
      SAXHander.startElement = OnStartElementUsers;
    if (strncmp(dump_file_name, "Posts.xml", 9) == 0)
      SAXHander.startElement = OnStartElementPosts;
    // if (strncmp(dump_file_name, "Votes.xml", 9) == 0)
    //   SAXHander.startElement = OnStartElementVotes;

    return SAXHander;
}

static int read_xmlfile(FILE *file, char *dump_file_name) {
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

    // char * votes = malloc(size + 10*sizeof(char));
    // strcpy(votes, dump_path);
    // strcat(votes, "Votes.xml");
    // FILE * v = fopen(votes,"r");
    // read_xmlfile(v, "Votes.xml");

    fclose(u);
    fclose(p);
    // fclose(v);

    return structure;
}
