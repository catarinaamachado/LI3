#include <libxml/xmlreader.h>
#include <libxml/SAX.h>
#include <stdio.h>
#include <string.h>

#include "interface.h"
#include "struct.h"
#include "users.h"
#include "postDate.h"
#include "tags.h"

static TAD_community structure;
static GDate * begin_stackOverflow;

/**
@file 00load.c
Parse dos ficheiros e preenchimento da estrutura de dados.
*/

/**
\brief Função que extrai os elementos necessários do utilizador para preencher as
respetivas estruturas de dados.
@param ctx Apontador para estrutura do sax.
@param element_name Apontador para o nome do elemento do ficheiro XML.
@param attributes Um array com os apontadores para os atributos do elemento.
*/
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


/**
\brief Função que extrai os elementos necessários dos posts para preencher as
respetivas estruturas de dados.
@param ctx Apontador para estrutura do sax.
@param element_name Apontador para o nome do elemento do ficheiro XML.
@param attributes Um array com os apontadores para os atributos do elemento.
*/
static void OnStartElementPosts(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
    int i, id, post_type_id, owner_id, title, tags, score, comment_count, favorite_count, was_null;
    int parentid, date;

    post_type_id = parentid = owner_id = title = tags = date = was_null = 0;
    id = score = favorite_count = comment_count = -1;

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

            else if(strncmp((const char *)attributes[i], "Score", 5) == 0)
                score = ++i;

            else if(strncmp((const char *)attributes[i], "CommentCount", 12) == 0)
                comment_count= ++i;

            else if(strncmp((const char *)attributes[i], "ParentId", 8) == 0)
                parentid = ++i;

            else if(strncmp((const char *)attributes[i], "CreationDate", 12) == 0)
                date = ++i;
        }

        if(strncmp((const char *)attributes[post_type_id], "1", 1) && strncmp((const char *)attributes[post_type_id], "2", 1))
            return;

        postDate pd = malloc(getPDSize());

        setPostId(pd, atol((char *)attributes[id]));

        setDate(pd, (char *)attributes[date]);


        GDate * d = g_date_new_dmy(getPDDay(pd), getPDMonth(pd), getPDYear(pd));
        long indexDay = g_date_days_between(begin_stackOverflow, d);
        g_date_free(d);
        Day pointerDay = lookDay(structure, indexDay);


        if( !strncmp((const char *)attributes[post_type_id], "1", 1)) { //trata-se de uma pergunta
            long questionId = atol((const char *)attributes[id]);

            Questions pointer = lookQuestion(structure, questionId);

            if(pointer == NULL) { //se a pergunta ainda nao existe (caso em que resposta vem antes da pergunta, e se cria a pergunta vazia)
                was_null = 1;
                pointer = malloc(sizeQuestions());

                setQuestionId(pointer, questionId);
                setNAnswers(pointer, 0);
                setNAnswerVotes(pointer, 0);
                initAnswers(pointer);
            }

            setQUserId(pointer, atol((const char *)attributes[owner_id]));

            setTitle(pointer, (char *)attributes[title]);

            setTags(pointer, (char *)attributes[tags]);

            setQDate(pointer, (char *)attributes[date]);

            if(was_null)
                insertQuestion(structure, getQuestionId(pointer), pointer);

            addDAYQuestions(pointerDay, pointer);
        }

        else if(parentid != 0) {  // se for uma resposta e tiver uma pergunta associada (há respostas em que o parent id não existe)
            Answers pointer = malloc(sizeAnswers());

            setAnswerId(pointer, atol((const char *)attributes[id]));
            setAUserId(pointer, atol((const char *)attributes[owner_id]));

            setParentId(pointer, atol((const char *)attributes[parentid])); // atribuir o id da pergunta à resposta

            setAUserId(pointer, atol((const char *)attributes[owner_id]));

            int votes = atoi((const char *)attributes[score]);
            setScore(pointer, votes);

            setCommentCount(pointer, atoi((const char *)attributes[comment_count]));

            insertAnswers(structure, getAnswerId(pointer), pointer);

            long parent_id = atol((const char *)attributes[parentid]);
            Questions q = lookQuestion(structure, parent_id);

            if(q != NULL) {  // se a pergunta existe
                setNAnswerVotes(q, getNAnswerVotes(q) + votes);
                setNAnswers(q, getNAnswers(q) + 1);
                addAnswers(q, pointer);
            }

            else {
                q = malloc(sizeQuestions());

                setQUserId(q, 0);
                setTitle(q, 0);
                setTags(q, 0);
                setQDate(q, 0);

                setNAnswers(q, 1);
                setQuestionId(q, parent_id);

                initAnswers(q);
                setNAnswerVotes(q, votes);
                addAnswers(q, pointer);

                insertQuestion(structure, parent_id, q);
             }

            addDAYAnswers(pointerDay, pointer);
        }


        if(owner_id != 0) {  //se o owner id existe, acrescenta posts aos utilizadores
            long oid = atol((const char *)attributes[owner_id]);
            Users u = lookUsers(structure, oid);

            if(u != NULL) {
                incrementNPosts(u);

                appendPost(u, pd);
            } else
                cleanPD(pd);
        } else
            cleanPD(pd);
    }
}


/**
\brief Função que extrai os elementos necessários das tags para preencher a
respetiva estruturas de dados.
@param ctx Apontador para estrutura do sax.
@param element_name Apontador para o nome do elemento do ficheiro XML.
@param attributes Um array com os apontadores para os atributos do elemento.
*/
static void OnStartElementTags(void *ctx, const xmlChar *element_name, const xmlChar **attributes) {
  int id, tagname, i;

  if (attributes != NULL) {

      for (i = 0;(attributes[i] != NULL);i++) {
          if(strncmp((const char *)attributes[i], "Id", 2) == 0)
              id = ++i;

          else if(strncmp((const char *)attributes[i], "TagName", 7) == 0)
              tagname = ++i;
      }

      Tags pointer = malloc(getTagsSize());

      int tag_id = atoi((const char *)attributes[id]);
      setTagId(pointer, tag_id);

      setTagName(pointer, (const char *)attributes[tagname]);
      setTagValue(pointer, 0);

      char * tag = getTagName(pointer);
      insertTag(structure, tag, pointer);
      free(tag);
  }
}

/**
\brief Função que define as callbacks a serem chamadas e carrega a estrutura do SAX.
@param dump_file_name O ficheiro que vamos fazer parse,
@returns xmlSAXHandler - Estrutura de dados do SAX.
*/
static xmlSAXHandler make_sax_handler (char *dump_file_name){
    xmlSAXHandler SAXHander;

    memset(&SAXHander, 0, sizeof(xmlSAXHandler)); //inicializa tudo a zero

    SAXHander.initialized = XML_SAX2_MAGIC;
    if (strncmp(dump_file_name, "Users.xml", 9) == 0)
      SAXHander.startElement = OnStartElementUsers;
    if (strncmp(dump_file_name, "Posts.xml", 9) == 0)
      SAXHander.startElement = OnStartElementPosts;
    if (strncmp(dump_file_name, "Tags.xml", 8) == 0)
      SAXHander.startElement = OnStartElementTags;

    return SAXHander;
}

/**
\brief Função que verifica o encoding. De seguida, executa a função make_sax_handler,
que define quais as callbacks a serem utilizadas pelo programa. Posteriormente,
inicializa o SAX e vai lendo o conteúdo do ficheiro XML respectivo, passando a
informação relevante para o buffer (chars) e, posteriormente, faz parser desse
mesmo buffer.
Note-se que quando esta função estiver a executar o parser dos dados, através da
função xmlParseChunk chama as diversas callbacks sempre que se justifique.
@param file Apontador para um ficheiro.
@param dump_file_name Apontador para nome do ficheiro dos dados XML.
@returns int - (1) se não conseguiu ler e 0 se leu dados do ficheiro XML.
*/
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
    xmlParserCtxtPtr ctxt = xmlCreatePushParserCtxt(&SAXHander, NULL, chars, result, NULL);

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

/**
\brief Função que carrega as estruturas de dados.
@param com Apontador para a TCD_community.
@param dump_path Apontador para o caminho do dump.
@returns TAD_community - Apontador para a TCD_community.
*/
TAD_community load(TAD_community com, char* dump_path) {
    structure = com;
    begin_stackOverflow = g_date_new_dmy (15, 9, 2008); //aloca um GDate e define uma data

    int size = sizeof(char) * strlen(dump_path);

    char * users = malloc(size + 11 * sizeof(char));
    strcpy(users, dump_path);
    strcat(users, "/Users.xml");
    FILE * u = fopen(users,"r");
    read_xmlfile(u, "Users.xml");
    fclose(u);
    free(users);

    char * posts = malloc(size + 11 * sizeof(char));
    strcpy(posts, dump_path);
    strcat(posts, "/Posts.xml");
    FILE * p = fopen(posts,"r");
    read_xmlfile(p, "Posts.xml");
    fclose(p);
    free(posts);

    char * tags = malloc(size + 10 * sizeof(char));
    strcpy(tags, dump_path);
    strcat(tags, "/Tags.xml");
    FILE * t = fopen(tags,"r");
    read_xmlfile(t, "Tags.xml");
    fclose(t);
    free(tags);

    return structure;
}
