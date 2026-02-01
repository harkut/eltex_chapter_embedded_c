#include <stdio.h>
#include <stdlib.h>
#include "../include/string_h.h"
#include "../include/func_ex_1.h"

void deleteAbonent(struct abonentbook *book) {
    if (book->size == 0) {
        printf("\nСправочник пуст.\n");
        return;
    }

    char str[SIZE_BOOK] = {0};
    int index;
    int valid_input = 0;

    while (!valid_input) {
        printf("\nВведите порядковый номер абонента (от 0 до %d): ", book->size - 1);
        strGets(str, SIZE_BOOK);
        index = atoi_h(str);
        if (index >= 0 && index < book->size) {
            valid_input = 1;
        } else {
            printf("Неверный индекс. Попробуйте снова.\n");
        }
    }

    struct abonent *current = book->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        book->head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        book->tail = current->prev;
    }

    free(current);
    book->size--;
}
