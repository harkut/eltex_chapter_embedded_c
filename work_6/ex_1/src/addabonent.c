#include <stdio.h>
#include <stdlib.h>
#include "../include/string_h.h"
#include "../include/func_ex_1.h"

void addAbonent(struct abonentbook *book) {
    if (book->size >= SIZE_BOOK) {
        printf("\nСправочник переполнен. Освободите место.\n");
        return;
    }

    struct abonent *new_abonent = (struct abonent *)malloc(sizeof(struct abonent));
    if (!new_abonent) {
        printf("Ошибка выделения памяти.\n");
        return;
    }

    printf("\nВведите имя абонента: ");
    strGets(new_abonent->name, LEN_NAME + 1);
    printf("Введите фамилию абонента: ");
    strGets(new_abonent->second_name, LEN_SNAME + 1);
    printf("Введите телефон абонента: ");
    strGets(new_abonent->tel, LEN_TEL + 1);

    new_abonent->next = NULL;
    new_abonent->prev = book->tail;

    if (book->tail) {
        book->tail->next = new_abonent;
    } else {
        book->head = new_abonent;
    }

    book->tail = new_abonent;
    book->size++;
}
