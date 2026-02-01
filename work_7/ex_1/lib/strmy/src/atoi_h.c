/**
 * @file atoi_h.c
 * @brief Реализация функции преобразования строки в целое число
 * @author harkut
 */

#include <stdio.h>
#include "libstrmy.h"

/**
 * @brief Преобразует строку в целое число
 * @param str Указатель на строку для преобразования
 * @return Полученное целое число
 * @note Обрабатывает только положительные числа
 * @warning Не проверяет переполнение и не обрабатывает отрицательные числа
 *
 * @code
 * int num = atoi_h("123"); // num = 123
 * @endcode
 */
int atoi_h(const char* str) {
  short int i, n;
  n = 0;
  for (i = 0;
       str[i] >= '0' && str[i] <= '9';
       ++i) {
    n = 10 * n + (str[i] - '0');
  }
  return n;
}
