/**
 * @file strnull_h.c
 * @brief Реализация функции обнуления строки
 * @author harkut
 */

#include <stdio.h>
#include "libstrmy.h"

/**
 * @brief Обнуляет первый символ строки
 * @param str Строка для обнуления
 * @return Указатель на строку
 * @note Функция обнуляет только первый символ строки, а не всю строку
 *
 * @code
 * char text[] = "hello";
 * strNull(text); // text теперь пустая строка ""
 * @endcode
 */
char* strNull(char* str) {
  char* ret_str = NULL;

  ret_str = str;
  *ret_str = 0;

  return ret_str;
}
