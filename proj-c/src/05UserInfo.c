#include <string.h>
#include <stdlib.h>

#include "struct.h"

/**
@file 05UserInfo.c
Resposta à interrogação 5.
*/

/**
\brief Dado um ID de utilizador, devolve a informação do
seu perfil (short bio) e os IDs dos seus 10 últimos posts
(perguntas ou respostas), ordenados por cronologia inversa.
@param com Apontador para a TCD_community.
@param id Identificador do utilizador.
@returns USER - Estrutura com a informação do perfil e IDS dos últimos
10 posts do utilizador passado como parâmetro.
*/
USER get_user_info(TAD_community com, long id) {
    int i, n_posts;
    postDate pd[10];
    long posts[12];

    Users user = lookUsers(com, id);

    if(user == NULL)
        return NULL;

    sortPosts(user);

    n_posts = getNPosts(user);

    for (i = 0; i < n_posts && i < 10; i++)
        pd[i] = getPDindex(user, n_posts - i -1);

    for (int l = 0; l < i && l < n_posts; l++)
        posts[l] = getPostId(pd[l]);

    posts[i] = -1;

    char * bio = getBio(user);

    USER u = create_user(bio, posts);

    free(bio);

    return u;
}
