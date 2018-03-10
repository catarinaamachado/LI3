#include <libxml/xmlreader.h>
#include <libxml/SAX.h>
#include <stdio.h>
#include <string.h>

#include "interface.h"
#include "struct.h"

    // if (xmlTextReaderNodeType(reader)==1)
    //             xmlTextReaderGetAttribute(reader, "Id");






static xmlSAXHandler make_sax_handler(char *dump_file_name);

static int read_xmlfile(FILE *file, char *dump_file_name);

static void OnStartElementUsers(void *ctx, const xmlChar *element_name, const xmlChar **attributes);

static void OnStartElementPosts(void *ctx, const xmlChar *element_name, const xmlChar **attributes);

static void OnStartElementVotes(void *ctx, const xmlChar *element_name, const xmlChar **attributes);


//abre e lê o ficheiro
void load_xmlfile(char* dump_file_path, char * dump_file_name) {

  FILE *file = fopen(dump_file_path, "r");
  if (!file) {
    puts("file open error.");
    exit(1);
  }

  if(read_xmlfile(file, dump_file_name)) {
    puts("xml read error.");
    exit(1);
  }

 fclose(file);

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
    int i;


    if (attributes != NULL) {
        for (i = 0;(attributes[i] != NULL);i++) {
          if(strncmp((const char *)attributes[i], "Id", 2) == 0 ||
             strncmp((const char *)attributes[i], "PostTypeId", 10) == 0 ||
             strncmp((const char *)attributes[i], "OwnerUserId", 11) == 0 ||
             strncmp((const char *)attributes[i], "Title", 5) == 0 ||
             strncmp((const char *)attributes[i], "Tags", 4) == 0 ||
             strncmp((const char *)attributes[i], "AnswerCount", 11) == 0) {
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


static void processPosts(TAD_community com, xmlTextReaderPtr reader) {
    char buf[100];
    int a;

    if (xmlTextReaderNodeType(reader) == 1 && xmlTextReaderGetAttribute(reader, BAD_CAST("Id")) != 0) {

        sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("PostTypeId"))));

        if( !strcmp(buf, "1\n")) {

            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Id"))));
            a = atoi(buf);

            Questions * pointer = g_hash_table_lookup (com->questions, GINT_TO_POINTER(a));

            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("AnswerCount"))));

            if(pointer == NULL) {
                pointer = malloc(sizeof(Questions));

                pointer->post_id = a;

                pointer->n_answers = atoi(buf);
                pointer->answers = g_ptr_array_sized_new(pointer->n_answers);

                pointer->n_answer_votes = 0;
            }

            else {
                pointer->n_answers = atoi(buf);
            }

            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("OwnerUserId"))));
            pointer->user_id = atoi(buf);

            sprintf(pointer->title, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Title"))));
            sprintf(pointer->tags, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Tags"))));

            g_hash_table_insert(com->questions, GINT_TO_POINTER(pointer->post_id), pointer);
        }

        else {
            Answers * pointer = malloc(sizeof(Answers));

            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Id"))));
            pointer->answer_id = atoi(buf);

            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Score"))));
            int votes = atoi(buf);
            pointer->score = votes;


            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("ParentId"))));
            int parent_id = atoi(buf);
            Questions * q = g_hash_table_lookup(com->questions, GINT_TO_POINTER(parent_id));

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

                sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("ParentId"))));
                q->post_id = atoi(buf);

                q->answers = g_ptr_array_new();
                q->n_answer_votes = votes;

                g_ptr_array_add(q->answers, pointer);

                g_hash_table_insert(com->questions, GINT_TO_POINTER(q->post_id), q);
            }
        }
    }

    xmlFree(xmlTextReaderName(reader));

    xmlFree(xmlTextReaderValue(reader));
}

static void processUsers(TAD_community com, xmlTextReaderPtr reader) {

    //TODO: process info

    xmlFree(xmlTextReaderName(reader));

    xmlFree(xmlTextReaderValue(reader));
}

static void processVotes(TAD_community com, xmlTextReaderPtr reader) {

    //TODO: process info

    xmlFree(xmlTextReaderName(reader));

    xmlFree(xmlTextReaderValue(reader));
}

void load_file(TAD_community com, char* dump_file_path, char * dump_file_name) {
    xmlTextReaderPtr reader;
    int ret;

    reader = xmlNewTextReaderFilename(dump_file_path);

    if (reader != NULL) {
        ret = xmlTextReaderRead(reader);

        if(!strcmp(dump_file_name, "Posts.xml"))
            //TODO substituir por load_xmlfile(dump_file_path, dump_file_name)
            while (ret == 1) {
                processPosts(com, reader);

                ret = xmlTextReaderRead(reader);
            }

        else if(!strcmp(dump_file_name, "Users.xml"))
            while (ret == 1) {
                processUsers(com, reader);

                ret = xmlTextReaderRead(reader);
            }

        else
            while (ret == 1) {
                processVotes(com, reader);

                ret = xmlTextReaderRead(reader);
            }

        xmlFreeTextReader(reader);
    }
}

TAD_community load(TAD_community com, char* dump_path) {
    int size = sizeof(char) * strlen(dump_path);

    char * posts = malloc(size + 10*sizeof(char));
    strcpy(posts, dump_path);
    strcat(posts, "/Posts.xml");
    load_file(com, posts, "Posts.xml");

    char * users = malloc(size + 10*sizeof(char));
    strcpy(users, dump_path);
    strcat(users, "/Users.xml");
    load_file(com, users, "Users.xml");

    char * votes = malloc(size + 10*sizeof(char));
    strcpy(votes, dump_path);
    strcat(votes, "/Votes.xml");
    load_file(com, votes, "Votes.xml");

    return com;
}
