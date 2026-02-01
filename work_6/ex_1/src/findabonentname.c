#include <stdio.h>
#include "../include/string_h.h"
#include "../include/func_ex_1.h"

void findAbonentName(const struct abonentbook *book) {
    char name[LEN_NAME + 1];
    printf("\nВведите имя абонента: ");
    strGets(name, LEN_NAME + 1);

    struct abonent *current = book->head;
    int found = 0;
    int index = 0;

    printf("\nАбоненты с именем %s:\n", name);
    while (current != NULL) {
        if (findStr(current->name, name) != NULL) {
            printf("Абонент %d:\n", index);
            printf("1. Имя: %s;\n", current->name);
            printf("2. Фамилия: %s;\n", current->second_name);
            printf("3. Телефон: %s.\n\n", current->tel);
            found = 1;
        }
        current = current->next;
        index++;
    }

    if (!found) {
        printf("Абоненты с таким именем не найдены.\n");
    }
}
