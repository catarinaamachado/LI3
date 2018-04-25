#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <answers.h>
#include <questions.h>

#include "users.h"

/**
@file users.c
Estrutura de dados relativa aos users, respetivos
getters e setters e funções auxiliares necessárias.
*/

/**
\brief Estrutura de dados destinada a armazenar as informações referentes aos utilizadores.
*/
typedef struct users {
  long user_id;
  char * shortbio;
  char * username;
  int reputation;
  int n_posts;
  GArray * last_posts;
} users;


/**
\brief Estrutura de dados que armazena o id do utilizador e a quantidade
de posts que este publicou. Esta estrutura será relevante para
responder à interrogação 2.
*/
typedef struct totalPosts {
  long user_id;
  int n_posts;
} totalPosts;


/**
\brief Função que devolve o tamanho da estrutura dos totalPosts.
@returns int - Tamanho da estrutura totalPosts.
*/
int getTotalPostsSize() {
    return sizeof(struct totalPosts);
}

/**
\brief Função que devolve o número total de posts de um utilizador,
sendo passado como parâmetro um apontador para totalPosts.
@param total_post Apontador para totalPosts.
@returns int - Número total de posts do utilizador.
*/
int getTotalNPosts(PtrTotalPosts total_post) {
  return total_post->n_posts;
}

/**
\brief Função que devolve o id de um utilizador, sendo passado como parâmetro
um apontador para totalPosts.
@param total_post Apontador para totalPosts.
@returns int - ID do utilizador.
*/
int getTotalPostsUserId(PtrTotalPosts total_post) {
  return total_post->user_id;
}

/*
\brief Função que estabelece o número de posts da estrutura totalPosts.
@param total_post Apontador para totalPosts.
@param n_posts Número de posts.
*/
void setTotalNPosts(PtrTotalPosts total_posts, int n_posts) {
  total_posts->n_posts = n_posts;
}

/**
\brief Função que estabelece o id do utilizador a figurar na estrutura totalPosts.
@param total_post Apontador para totalPosts.
@param user_id ID do utilizador.
*/
void setTotalPostsUserId(PtrTotalPosts total_posts, long user_id) {
  total_posts->user_id = user_id;
}

/**
\brief Função que insere num GArray os dois campos da estrutura totalPosts.
@param array Apontador para um GArray.
@param user_id ID do utilizador.
@param n_posts Número de posts.
*/
void insertTotalPostsArray(GArray * array, int user_id, int n_posts) {
  totalPosts total;

  total.user_id = user_id;
  total.n_posts = n_posts;

  g_array_append_val(array, total);
}

/**
\brief Função que devolve o id de um user, contido na estrutura totalPosts,
que se encontra numa determinada posição de um GArray.
@param array Apontador para um GArray.
@param index Índice do GArray.
@returns long - ID do utilizador.
*/
long getTotalPostsUserIdAtIndex(GArray * array, int index) {
   totalPosts total;

   total = g_array_index(array, totalPosts, index);

   return total.user_id;
}

int getTotalPostsAtIndex(GArray * array, int index) {
  totalPosts total;

  total = g_array_index(array, totalPosts, index);

  return total.n_posts;
}

/**
\brief Função que inicializa um GArray com a estrutura totalPosts.
@returns GArray - Apontador para GArray.
*/
GArray * initArrayTotalPosts() {
    return g_array_new(FALSE, FALSE, getTotalPostsSize());
}

/**
\brief Função que compara o número de posts de duas posições da estutura totalPost.
@param n_posts_a Número de posts de a.
@param n_posts_b Número de posts de b.
@returns gint - Número negativo se o número de posts de a for menor que o número
de posts de b, número positivo caso contrário e 0 se o número for igual.
*/
gint compare_func(gconstpointer n_posts_a, gconstpointer n_posts_b) {
  PtrTotalPosts a = (PtrTotalPosts) n_posts_a;
  PtrTotalPosts b = (PtrTotalPosts) n_posts_b;

//se a < b return n.º negativo se a = b return 0 e se a > b return n.º positivo
  return getTotalNPosts(b) - getTotalNPosts(a);
}

/**
\brief Função que ordena um GArray por ordem decrescente do número de posts.
@param array Apontador para um GArray.
*/
void sortArrayTotalPosts(GArray * array) {
  g_array_sort(array, (GCompareFunc)compare_func);
}

/**
\brief Função que liberta o espaço de memória ocupada pelo GArray.
@param array Apontador para um GArray.
*/
void freeArrayTotalPosts(GArray * array) {
  g_array_free (array, TRUE);
}

/**
\brief Devolve o tamanho da estrutura dos users.
@returns int - Tamanho da estrutura users.
*/
int getUsersSize() {
    return sizeof(struct users);
}

/**
\brief Devolve o id de um utilizador, sendo passado como parâmetro a estrutura users.
@param u Apontador para users.
@returns long - ID de um utilizador.
*/
long getUserId(Users u) {
    return u->user_id;
}

/**
\brief Estabelece o id de um utilizador, sendo passado como parâmetro a estrutura users.
@param u Apontador para users.
@param i ID de um utilizador.
*/
void setUserId(Users u, long i) {
    u->user_id = i;
}

/**
\brief Devolve a informação sobre o perfil de um utilizador.
@param u Apontador para users.
@returns char * - Short bio do utilizador.
*/
char * getBio(Users u) {
    char * bio = malloc(sizeof(char) * (strlen(u->shortbio)+2));
    strcpy(bio, u->shortbio);

    return bio;
}

/**
\brief Estabelece a informação sobre o perfil de um utilizador.
@param u Apontador para users.
@param bio Short bio do utilizador.
*/
void setBio(Users u, char * bio) {
    char * shortbio = malloc(sizeof(char) * (strlen(bio)+2));
    strcpy(shortbio, bio);

    u->shortbio = shortbio;
}

/**
\brief Devolve o nome de um utilizador.
@param u Apontador para users.
@returns char * - Nome de um utilizador.
*/
char * getUsername(Users u) {
    char * user = NULL;

    if(u->username != NULL) {
      user = malloc(sizeof(char) * (strlen(u->username)+2));
      strcpy(user, u->username);
    }

    return user;
}

/**
\brief Estabelece o nome de um utilizador.
@param u Apontador para users.
@param user Nome de um utilizador.
*/
void setUsername(Users u, char * user) {
    char * username = malloc(sizeof(char) * (strlen(user)+2));
    strcpy(username, user);

    u->username = username;
}

/**
\brief Devolve a reputação de um utilizador.
@param u Apontador para users.
@returns int - Reputação de um utilizador.
*/
int getReputation(Users u) {
    return u->reputation;
}

/**
\brief Estabelece a reputação de um utilizador.
@param u Apontador para users.
@param reputation Reputação de um utilizador.
*/
void setReputation(Users u, int reputation) {
    u->reputation = reputation;
}

/**
\brief Devolve o número de posts de um utilizador.
@param u Apontador para users.
@returns int - Número de posts de um utilizador.
*/
int getNPosts(Users u) {
    return u->n_posts;
}

/**
\brief Estabelece o número de posts de um utilizador.
@param u Apontador para users.
@param posts Número de posts de um utilizador.
*/
void setNPosts(Users u, int posts) {
    u->n_posts = posts;
}

/**
\brief Incrementa em uma unidade o número de posts de um utilizador.
@param u Apontador para users.
*/
void incrementNPosts(Users u) {
    u->n_posts++;
}

/**
\brief Acrescenta ao array last_posts informação sobre a data do post.
@param u Apontador para users.
@param pd Apontador para a data do post.
*/
void appendPost(Users u, postDate pd) {
    g_array_append_val(u->last_posts, pd);
}

/**
\brief Inicializa o array de post do utilizador com dez elementos.
@param u Apontador para users.
*/
void initLastPosts(Users u) {
    u->last_posts = g_array_sized_new(FALSE, TRUE, sizeof(postDate), 10);
}

/**
\brief Devolve um apontador para o l elemento do array last_post,
dando-nos informação sobre a data do post.
@param u Apontador para users.
@param l Índice do array.
@returns postDate - Apontador para a data do post.
*/
postDate getPDindex(Users u, int l) {
    postDate pd = g_array_index(u->last_posts, postDate, l);

    return pd;
}

/**
\brief Função que compara as datas de dois posts recebidos como parâmetro.
@param a Apontador para a data do post a.
@param b Apontador para a data do post b.
@returns gint - -1 se o primeiro post passado como parâmetro for mais antigo
que o segundo ou 1 caso contrário.
*/
static gint sortDate(postDate a, postDate b) {
    if(a != NULL && b != NULL)
        return 0;

    if (getPDYear(a) < getPDYear(b))
        return -1;
    else if (getPDYear(a) > getPDYear(b))
        return 1;

    else if (getPDMonth(a) < getPDMonth(b))
        return -1;
    else if (getPDMonth(a) > getPDMonth(b))
        return 1;

    else if (getPDDay(a) < getPDDay(b))
        return -1;
    else if (getPDDay(a) > getPDDay(b))
        return 1;

    else if (getPDHour(a) < getPDHour(b))
        return -1;
    else if (getPDHour(a) > getPDHour(b))
        return 1;

    else if (getPDMin(a) < getPDMin(b))
        return -1;
    else if (getPDMin(a) > getPDMin(b))
        return 1;

    else if (getPDSec(a) < getPDSec(b))
        return -1;
    else if (getPDSec(a) > getPDSec(b))
        return 1;

    else if (getPDMili(a) < getPDMili(b))
        return -1;

    else if (getPDMili(a) > getPDMili(b))
        return 1;

    return 1;
}

/**
\brief Função que ordena os posts do utilizador de acordo com a sua data,
(do mais recente para o mais antigo).
@param u Apontador para users.
*/
void sortPosts(Users u) {
    g_array_sort(u->last_posts, (GCompareFunc)sortDate);
}

/**
\brief Função que compara as reputações de dois users recebidos como parâmetro.
@param u1 Apontador para o apontador do users.
@param u2 Apontador para o apontador do users.
@returns gint - -1 se a reputação do primeiro utilizador passado como parâmetro
for maior que o segundo ou 1 caso contrário.
*/
static gint sortReputation(Users * u1, Users * u2) {
  int rep1, rep2;
  if ((*u1) != NULL)
    rep1 = getReputation(*u1);
  else
    rep1 = 0;
  if ((*u2) != NULL)
    rep2 = getReputation(*u2);
  else
    rep2 = 0;

  if(rep1 < rep2)
    return 1;
  else
    return -1;
}

/**
\brief Função que ordena os users de acordo com a sua reputação,
(do user com maior reputação para o user com menos).
@param total_users Apontador para um GPtrArray que contém os users.
*/
void sortUsersReputation(GPtrArray * total_users) {
  g_ptr_array_sort(total_users, (GCompareFunc)sortReputation);
}

/**
\brief Função que liberta o apontador para a estrutura users.
@param u Apontador para users.
*/
void cleanUser(Users u) {
    free(u->shortbio);
    free(u->username);

    g_array_set_clear_func(u->last_posts, (GDestroyNotify)cleanPDp);
    g_array_free(u->last_posts, TRUE);

    free(u);
}
