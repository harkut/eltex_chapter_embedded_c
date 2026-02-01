#include <stdlib.h>
#include "../include/func_ex_1.h"

void clearAbonentBook(struct abonentbook *book) {
    struct abonent *current = book->head;
    struct abonent *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    book->head = NULL;
    book->tail = NULL;
    book->size = 0;
}
