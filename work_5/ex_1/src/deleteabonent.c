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

void deleteAbonent(struct abonent* p,
                   unsigned short int* cur_size_book) {
  if (*cur_size_book > 0) {
    short int i = 0;
    char str[SIZE_BOOK] = {0};
    printf("\nВведите порядковый номер абонента (от 0 до %d): ",
           *cur_size_book - 1);
    while ((((i = (atoi_h(strGets(str, SIZE_BOOK)))) < *cur_size_book)
            && (i >= 0)) ? 0 : 1);
    strNull(p[i].name);
    strNull(p[i].second_name);
    strNull(p[i].tel);
    (*cur_size_book)--;
    while (i < *cur_size_book) {
      p[i] = p[i + 1];
      i++;
    }
  }
  else {
    printf("\nСправочник пуст.\n");
  }
}
