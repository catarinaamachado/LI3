#include <libxml/xmlreader.h>
#include <string.h>

#include "interface.h"
#include "struct.h"

    // if (xmlTextReaderNodeType(reader)==1)
    //             xmlTextReaderGetAttribute(reader, "Id");

static void processPosts(TAD_community com, xmlTextReaderPtr reader) {
    int a;
    char buf[100];        

    if (xmlTextReaderNodeType(reader) == 1) {

        sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("PostTypeId"))));

        if( !strcmp(buf, "1\n") && xmlTextReaderGetAttribute(reader, BAD_CAST("Id")) != 0) {

            Questions * pointer = malloc(sizeof(Questions));

            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Id"))));
            a = atoi(buf);
            pointer->post_id = a;

            sprintf(buf, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("OwnerUserId"))));
            a = atoi(buf);
            pointer->user_id = a;

            sprintf(pointer->title, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Title"))));
            sprintf(pointer->tags, "%s\n", (xmlTextReaderGetAttribute(reader, BAD_CAST("Tags"))));

            pointer->n_answers = 0;
            pointer->n_answer_votes = 0;

            pointer->answers = g_ptr_array_new();

            g_hash_table_insert(com->questions, GINT_TO_POINTER(pointer->post_id), pointer);
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