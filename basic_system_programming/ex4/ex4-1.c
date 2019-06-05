#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAXLINE 16

struct list {
    struct list *next;
    char *word;
};

int main() {
    // Define the head list element
    struct list *head;
    char input[MAXLINE];
    
    head = NULL;

    // Register new words
    printf("Please type the word you want to register:\n");
    while (fgets(input, MAXLINE, stdin)) {
        // Add the new list element
        struct list *p;
        p = malloc(sizeof(struct list));
        p->word = malloc(sizeof(char)*MAXLINE + 1);

        // Copy input word to the added list
        strcpy(p->word, input);

        // Move Pointer to the added list
        p->next = head;
        head = p;
    }

    // Print the registered word list
    struct list *q;
    printf("\nThe registered words are:\n");
    for (q = head; head != NULL; q = q->next) {
        printf("%s", q->word);
        if (q->next == NULL) {
            break;
        }
    }
    exit(0);
}

