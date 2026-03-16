#include <stdio.h>
#include <stdlib.h>
#include "member.h"

#define MEMBER_FILE "data/members.dat"

static Member *members = NULL;
static int memberCount = 0;

void initMembers() {
    FILE *fp = fopen(MEMBER_FILE, "rb");

    if (!fp) {
        memberCount = 2;
        members = malloc(sizeof(Member) * memberCount);

        members[0] = (Member){1, "Alice"};
        members[1] = (Member){2, "Bob"};

        fp = fopen(MEMBER_FILE, "wb");
        fwrite(&memberCount, sizeof(int), 1, fp);
        fwrite(members, sizeof(Member), memberCount, fp);
        fclose(fp);
        return;
    }

    fread(&memberCount, sizeof(int), 1, fp);
    members = malloc(sizeof(Member) * memberCount);
    fread(members, sizeof(Member), memberCount, fp);
    fclose(fp);
}

void printAllMembers() {
    printf("\nID   Name\n");
    printf("-----------\n");
    for (int i = 0; i < memberCount; i++)
        printf("%-4d %s\n", members[i].id, members[i].name);
}

Member* findMemberById(int id) {
    for (int i = 0; i < memberCount; i++)
        if (members[i].id == id)
            return &members[i];
    return NULL;
}

void freeMembers() {
    FILE *fp = fopen(MEMBER_FILE, "wb");
    fwrite(&memberCount, sizeof(int), 1, fp);
    fwrite(members, sizeof(Member), memberCount, fp);
    fclose(fp);

    free(members);
}

