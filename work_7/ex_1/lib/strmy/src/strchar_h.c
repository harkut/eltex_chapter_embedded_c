/**
 * @file strchar_h.c
 * @brief Реализация функции поиска символа в строке
 * @author harkut
 */

#include <stdio.h>
#include "libstrmy.h"

/**
 * @brief Ищет первое вхождение символа в строке
 * @param str Строка для поиска
 * @param s Искомый символ
 * @return Указатель на найденный символ или NULL, если символ не найден
 *
 * @code
 * char* pos = strChar("hello", 'l'); // Возвращает указатель на первую 'l'
 * @endcode
 */
char* strChar(const char* str, int s) {
  int i = 0;

  while (str[i] && str[i] != s) {
    ++i;
  }
  return s == str[i] ? (char*)str + i : NULL;
}
