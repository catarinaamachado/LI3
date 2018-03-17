#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "users.h"

typedef struct users {
  long user_id;
  char * shortbio;
  char * username;
  int reputation;
  int n_posts;
  GArray * last_posts;
} users;

int getUsersSize() {
    return sizeof(struct users);
}

long getUserId(Users u) {
    return u->user_id;
}

void setUserId(Users u, long i) {
    u->user_id = i;
}

char * getBio(Users u) {
    char * bio = malloc(sizeof(char) * (strlen(u->shortbio)+2));
    strcpy(bio, u->shortbio);

    return bio;
}

void setBio(Users u, char * bio) {
    char * shortbio = malloc(sizeof(char) * (strlen(bio)+2));
    strcpy(shortbio, bio);
    
    u->shortbio = shortbio;
}

char * getUsername(Users u) {
    char * user = malloc(sizeof(char) * (strlen(u->username)+2));
    strcpy(user, u->username);

    return user;
}

void setUsername(Users u, char * user) {
    char * username = malloc(sizeof(char) * (strlen(user)+2));
    strcpy(username, user);

    u->username = username;
}

int getReputation(Users u) {
    return u->reputation;
}

void setReputation(Users u, int reputation) {
    u->reputation = reputation;
}

int getNPosts(Users u) {
    return u->n_posts;
}

void setNPosts(Users u, int posts) {
    u->n_posts = posts;
}

void incrementNPosts(Users u) {
    u->n_posts++;
}

void appendPost(Users u, postDate pd) {
    g_array_append_val(u->last_posts, pd);
}

void initLastPosts(Users u) {
    u->last_posts = g_array_sized_new(FALSE, TRUE, sizeof(postDate), 10);
}

postDate getPDindex(Users u, int l) {
    postDate pd = g_array_index(u->last_posts, postDate, l);

    return pd;
}


static gint sortDate (postDate a, postDate b) {
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

void sortPosts(Users u) {
    g_array_sort(u->last_posts, (GCompareFunc)sortDate);
}