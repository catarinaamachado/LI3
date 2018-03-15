#include <gmodule.h>

#include "postDate.h"

typedef struct users * Users;

int getUsersSize();

long getUserId(Users u);
void setUserId(Users u, long i);

char * getBio(Users u);
void setBio(Users u, char * bio);

char * getUsername(Users u);
void setUsername(Users u, char * user);

int getReputation(Users u);
void setReputation(Users u, int reputation);

int getNPosts(Users u);
void setNPosts(Users u, int posts);
void incrementNPosts(Users u);

GArray * getLastPosts(Users u);
void initLastPosts(Users u);

void appendPost(Users u, postDate pd);
void initLastPosts(Users u);