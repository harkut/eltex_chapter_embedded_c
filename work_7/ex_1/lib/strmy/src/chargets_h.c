/**
 * @file chargets_h.c
 * @brief Реализация функции считывания одного символа
 * @author harkut
 */

#include <stdio.h>
#include "libstrmy.h"

/**
 * @brief Считывает один символ из стандартного ввода
 * @return Считанный символ
 * @details Игнорирует все символы до символа новой строки
 *
 * @code
 * char ch = charGets(); // Считывает один символ
 * @endcode
 */
char charGets(void) {
  int ch = 0;

  ch = getchar();
  while (getchar() != '\n') {}

  return ch;
}
