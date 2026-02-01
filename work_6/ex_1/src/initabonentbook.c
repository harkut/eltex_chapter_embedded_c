#include <stdio.h>
#include "../include/func_ex_1.h"

void initAbonentBook(struct abonentbook *book) {
    book->head = NULL;
    book->tail = NULL;
    book->size = 0;
}
