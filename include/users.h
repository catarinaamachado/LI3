#ifndef __USERS__
#define __USERS__


#include <gmodule.h>

#include "postDate.h"

typedef struct users * Users;

typedef struct totalPosts * PtrTotalPosts;

int getUsersSize();
int getTotalPostsSize();

int getTotalNPosts(PtrTotalPosts n_post);
void setTotalNPosts(PtrTotalPosts total_posts, int n_posts);

int getTotalPostsUserId(PtrTotalPosts total_post);
void setTotalPostsUserId(PtrTotalPosts total_posts, long user_id);

GArray * initArrayTotalPosts();

void insertTotalPostsArray(GArray * array, int user_id, int n_posts);

void sortArrayTotalPosts(GArray * array);

long getTotalPostsUserIdAtIndex(GArray * array, int index);

//int getTotalPostsAtIndex(GArray * array, int index);

void freeArrayTotalPosts(GArray * array);

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
postDate getPDindex(Users u, int l);
void sortPosts(Users u);

void sortUsersReputation(GPtrArray * total_users);

void cleanUser(Users u);

#endif
