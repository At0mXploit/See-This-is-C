#include <stdio.h>
#include "menu.h"

int showLoginMenu() {
    int c;
    printf("\n=== LOGIN MENU ===\n");
    printf("1. Admin\n");
    printf("2. Member Login\n");
    printf("3. Create Account\n");
    printf("0. Exit\n");
    printf("Choice: ");
    scanf("%d", &c);
    return c;
}


int showAdminMenu() {
    int c;
    printf("\n=== ADMIN MENU ===\n");
    printf("1. View Books\n");
    printf("2. Add Book\n");
    printf("3. Delete Book\n");
    printf("4. View Members\n");
    printf("0. Logout\n");
    printf("Choice: ");
    scanf("%d", &c);
    return c;
}


int showMemberMenu() {
    int c;
    printf("\n1. View Books\n2. Issue Book\n3. Return Book\n0. Logout\nChoice: ");
    scanf("%d", &c);
    return c;
}

