#include <libxml/xmlreader.h>
#include <string.h>

#include "interface.h"
#include "struct.h"

    // if (xmlTextReaderNodeType(reader)==1)
    //             xmlTextReaderGetAttribute(reader, "Id");

static void processPosts(TAD_community com, xmlTextReaderPtr reader) {
    char buf[100];     
    int a;   

    if (xmlTextReaderNodeType(reader) == 1 && xmlTextReaderGetAttribute(reader, BAD_CAST("Id")) != 0) {

        sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("PostTypeId"))));

        if( !strcmp(buf, "1\n")) {

            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Id"))));
            a = atoi(buf);

            Questions * pointer = g_hash_table_lookup (com->questions, GINT_TO_POINTER(a));

            if(pointer == NULL) {
                pointer = malloc(sizeof(Questions));

                pointer->post_id = a;

                sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("OwnerUserId"))));
                pointer->user_id = atoi(buf);

                sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("AnswerCount"))));
                pointer->n_answers = atoi(buf);
                pointer->answers = g_ptr_array_sized_new(pointer->n_answers);

                sprintf(pointer->title, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Title"))));
                sprintf(pointer->tags, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Tags"))));

                pointer->n_answer_votes = 0;

                g_hash_table_insert(com->questions, GINT_TO_POINTER(pointer->post_id), pointer);
            }

            else {
                sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("OwnerUserId"))));
                pointer->user_id = atoi(buf);

                 sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("AnswerCount"))));
                pointer->n_answers = atoi(buf);

                sprintf(pointer->title, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Title"))));
                sprintf(pointer->tags, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Tags"))));

                pointer->n_answer_votes = 0;

                g_hash_table_insert(com->questions, GINT_TO_POINTER(pointer->post_id), pointer);
            }
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
                q->n_answer_votes += votes;

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