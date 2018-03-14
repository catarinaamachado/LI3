#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct users {
  long user_id;
  char * shortbio;
  char * username;
  int reputation;
  int n_posts;
  GArray * last_posts;
} Users;

long getUserId(Users * u) {
    return u->user_id;
}

void setUserId(Users * u, long i) {
    u->user_id = i;
}

char * getBio(Users * u) {
    char * bio = malloc(sizeof(char) * strlen(u->shortbio));
    strcpy(bio, u->shortbio);

    return bio;
}

void setBio(Users * u, char * bio) {
    char * shortbio = malloc(sizeof(char) * strlen(bio));
    strcpy(shortbio, bio);
    
    u->shortbio = shortbio;
}

char * getUsername(Users * u) {
    char * user = malloc(sizeof(char) * strlen(u->username));
    strcpy(user, u->username);

    return user;
}

void setUsername(Users * u, char * user) {
    char * username = malloc(sizeof(char) * strlen(user));
    strcpy(username, user);

    u->username = username;
}

int getReputation(Users * u) {
    return u->reputation;
}

void setReputation(Users * u, int reputation) {
    u->reputation = reputation;
}

int getNPosts(Users * u) {
    return u->n_posts;
}

void setNPosts(Users * u, int posts) {
    u->n_posts = posts;
}

GArray * getLastPosts(Users * u) { //FIXME:
    return u->last_posts;
}

void setLastPosts(Users * u, GArray * p) { //FIXME:
    u->last_posts = p;
}