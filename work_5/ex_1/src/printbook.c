/**
 * @brief
 *
 * @param
 * @param
 * @return
 * @note
 */
#include <stdio.h>

#include "../include/string_h.h"
#include "../include/func_ex_1.h"

void printBook(const struct abonent* p,
               unsigned short int cur_size_book) {
  short int i = 0;
  printf("\nСписок абонентов:\n\n");
  while (i < cur_size_book) {
    printf("Абонент %d:\n", i);
    printf("1. Имя: %s;\n", p[i].name);
    printf("2. Фамилия: %s;\n", p[i].second_name);
    printf("3. Телефон: %s.\n\n", p[i].tel);
    i++;
  }
}
