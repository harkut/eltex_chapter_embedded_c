#include <stdio.h>
#include "../include/string_h.h"
#include "../include/func_ex_1.h"

int main() {
    struct abonentbook book;
    unsigned short int cs = 0;

    initAbonentBook(&book);

    while (cs != 5) {
        printf("\nАбонентский справочник.\n");
        printf("1) Добавить абонента;\n");
        printf("2) Удалить абонента;\n");
        printf("3) Поиск абонентов по имени;\n");
        printf("4) Вывод списка абонентов;\n");
        printf("5) Выход.\n\n");

        printf("Введите пункт меню: ");
        while ((((cs = charGets() - '0') <= 5) && (cs > 0)) ? 0 : 1);
        switch (cs) {
            case 1:
                addAbonent(&book);
                break;
            case 2:
                deleteAbonent(&book);
                break;
            case 3:
                findAbonentName(&book);
                break;
            case 4:
                printBook(&book);
                break;
        }
    }

    clearAbonentBook(&book);
    return 0;
}
