#include <stdio.h>
#include <string.h>
#include "input.h"
#include "errors.h"

#define ADMIN_PASSWORD "admin123"

int adminLogin() {
    char pass[50];

    printf("Enter admin password: ");
    scanf("%49s", pass);

    if (strcmp(pass, ADMIN_PASSWORD) == 0) {
        return AUTH_SUCCESS;
    }

    printf("Wrong password!\n");
    return AUTH_FAIL;
}

