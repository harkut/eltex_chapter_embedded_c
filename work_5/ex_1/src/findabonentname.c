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

void findAbonentName(const struct abonent* p) {
  char str[SIZE_BOOK] = {0};
  short int i = 0;
  printf("\nВведите имя абонента: ");
  strGets(str, SIZE_BOOK);
  printf("\nАбоненты с таким именем: \n\n");
  while (i <= SIZE_BOOK - 1) {
    char* ptr = findStr(p[i].name, str);
    if ((ptr != NULL)) {
      printf("Абонент %d:\n", i);
      printf("1. Имя: %s;\n", p[i].name);
      printf("2. Фамилия: %s;\n", p[i].second_name);
      printf("3. Телефон: %s.\n\n", p[i].tel);
    }
    i++;
  }
}
