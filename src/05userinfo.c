#include "interface.h"
#include "user.h"
#include "struct.h"

gint sortDate (postDate a, postDate b) {
    if (a->year < b->year)
        return -1;
    else if (a->month < b->month)
        return -1;
    else if (a->day < b->day)
        return -1;
    else if (a->hour < b->hour)
        return -1;
    else if (a->min < b->min)
        return -1;
    else if (a->sec < b->sec)
        return -1;
    else if (a->mili < b->mili)
        return -1;

    return 1;
}

USER get_user_info(TAD_community com, long id){
    int i, n_posts;
    postDate pd[10];
    long posts[11];
    
    Users * user = g_hash_table_lookup(com->users, GINT_TO_POINTER(id));

    if(user == NULL)
        return NULL;

    g_array_sort(user->last_10posts, (GCompareFunc)sortDate);
    
    n_posts = user->n_posts;

    for (i = 0; i < n_posts && i < 10; i++)
        pd[i] = g_array_index(user->last_10posts, postDate , n_posts - i -1);

    for (int l = 0; l <= i; l++)
        posts[l] = pd[l]->post_id;   
    
    posts[i] = -1;

    USER u = create_user(user->shortbio, posts);

    return u;
}