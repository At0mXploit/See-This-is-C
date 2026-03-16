#include <stdio.h>
#include "library.h"
#include "menu.h"
#include "transaction.h"
#include "errors.h"
#include "input.h"
#include "user.h"

#define ROLE_ADMIN  1
#define ROLE_MEMBER 2

int main() {
    initLibrary();
    initUsers();

    while (1) {
        int role = showLoginMenu();

        if (role == 0)
            break;

        if (role == ROLE_ADMIN) {
            if (adminLogin() == AUTH_FAIL)
                continue;
        }

        if (role == ROLE_MEMBER) {
            if (!loginUser())
                continue;
        }

        if (role == 3) {
            signupUser();
            continue;
        }

        int loggedIn = 1;
        while (loggedIn) {
            if (role == ROLE_ADMIN) {
                switch (showAdminMenu()) {
                    case 1:
                        printAllBooks();
                        break;
                    case 2:
                        addBook();
                        break;
                    case 3:
                        deleteBook();
                        break;
                    case 4:
                        printAllUsers();
                        break;
                    case 0:
                        loggedIn = 0;
                        break;
                }
            } else if (role == ROLE_MEMBER) {
                int id;
                switch (showMemberMenu()) {
                    case 1:
                        printAllBooks();
                        break;
                    case 2:
                        printf("Book ID: ");
                        scanf("%d", &id);
                        issueBook(id);
                        break;
                    case 3:
                        printf("Book ID: ");
                        scanf("%d", &id);
                        returnBook(id);
                        break;
                    case 0:
                        loggedIn = 0;
                        break;
                }
            }
        }
    }

    freeLibrary();
    freeUsers();
    printf("System exited.\n");
    return 0;
}

