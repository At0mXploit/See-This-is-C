#ifndef MEMBER_H
#define MEMBER_H

typedef struct {
    int id;
    char name[100];
} Member;

void initMembers();
void printAllMembers();
void freeMembers();
Member* findMemberById(int id);

#endif

