#ifndef USER_H
#define USER_H

typedef struct {
    char username[50];
    char password[50];
} User;

void initUsers();
int signupUser();
void printAllUsers();
int loginUser();
void freeUsers();

#endif

