#include <stdio.h>
#include "../include/func_ex_1.h"

void printBook(const struct abonentbook *book) {
    struct abonent *current = book->head;
    int index = 0;

    printf("\nСписок абонентов:\n\n");
    while (current != NULL) {
        printf("Абонент %d:\n", index);
        printf("1. Имя: %s;\n", current->name);
        printf("2. Фамилия: %s;\n", current->second_name);
        printf("3. Телефон: %s.\n\n", current->tel);
        current = current->next;
        index++;
    }

    if (index == 0) {
        printf("Справочник пуст.\n");
    }
}
