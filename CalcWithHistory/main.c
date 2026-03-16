#include <stdio.h>
#include <float.h>
#include <stdlib.h>

#define HISTORY_FILE "history.txt"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

void clearConsole() {
    system("clear");
}

void showHistory() {
    FILE *file = fopen(HISTORY_FILE, "r");
    if (!file) {
        printf(YELLOW "\nNo history found.\n" RESET);
        return;
    }
    char line[256];
    printf(CYAN "\n\t--- Calculation History ---\n" RESET);
    while (fgets(line, sizeof(line), file)) {
        printf("\t%s", line);
    }
    printf(CYAN "\t---------------------------\n" RESET);
    fclose(file);
}

void saveToHistory(double a, char op, double b, double res) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if (!file) {
        printf(RED "Error saving history.\n" RESET);
        return;
    }
    fprintf(file, "%.2lf %c %.2lf = %.2lf\n", a, op, b, res);
    fclose(file);
}

void clearHistory() {
    FILE *file = fopen(HISTORY_FILE, "w");
    if (!file) {
        printf(RED "Error clearing history.\n" RESET);
        return;
    }
    fclose(file);
    printf(GREEN "\nHistory cleared successfully.\n" RESET);
}

void showMenu() {
    printf(BLUE "\n\t===== Simple Calculator =====\n" RESET);
    printf("\t1. C - Calculate\n");
    printf("\t2. H - View History\n");
    printf("\t3. X - Clear History\n");
    printf("\t4. L - Clear Console\n");
    printf("\t5. E - Exit\n");
    printf(BLUE "\t=============================\n" RESET);
    printf(GREEN "\tEnter your choice: " RESET);
}

int main() {
    char choice;
    do {
        showMenu();
        scanf(" %c", &choice);

        if (choice == 'C' || choice == 'c') {
            char op;
            double a, b, res;

            printf(CYAN "\tEnter an operator (+, -, *, /): " RESET);
            scanf(" %c", &op);

            printf(CYAN "\tEnter two operands: " RESET);
            scanf("%lf %lf", &a, &b);

            switch (op) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        printf(RED "Error! Division by zero.\n" RESET);
                        continue;
                    }
                    res = a / b;
                    break;
                default:
                    printf(RED "Error! Incorrect Operator Value\n" RESET);
                    continue;
            }

            printf(GREEN "\tResult: %.2lf\n" RESET, res);
            saveToHistory(a, op, b, res);

        } else if (choice == 'H' || choice == 'h') {
            showHistory();

        } else if (choice == 'X' || choice == 'x') {
            clearHistory();

        } else if (choice == 'L' || choice == 'l') {
            clearConsole();

        } else if (choice == 'E' || choice == 'e') {
            printf(BLUE "\nExiting...\n" RESET);

        } else {
            printf(RED "\nInvalid option! Try again.\n" RESET);
        }

    } while (choice != 'E' && choice != 'e');

    return 0;
}
