/**
 * @brief Заполняет элементы структуры с данными абонента.
 *
 * @param (struct abonent *p)  Указатель на начало структуры с информацией об
 абонентах.
 * @param (struct abonent *p)  Указатель на начало структуры с информацией об
 абонентах.
 * @return
 * @note =
 */
#include <stdio.h>
#include <stdarg.h>

#include "../include/string_h.h"
#include "../include/func_ex_1.h"

void addAbonent(struct abonent *p, unsigned short int *cur_size_book, ...) {
  va_list args;
  va_start(args, cur_size_book);
  if (*cur_size_book < va_arg(args, int)) {
    printf("\nВведите имя абонента: ");
    strGets(p->name, va_arg(args, int) + 1);
    printf("Введите фамилию абонента: ");
    strGets(p->second_name, va_arg(args, int) + 1);
    printf("Введите телефон абонента: ");
    strGets(p->tel, va_arg(args, int) + 1);
    (*cur_size_book)++;
    va_end(args);
  } else {
    printf("\nСправочник переполенен. Освободите место.\n");
  }
}
