/**
 * @file strgets_h.c
 * @brief Реализация функции безопасного считывания строки
 * @author harkut
 */

#include <stdio.h>
#include "libstrmy.h"

/**
 * @brief Считывает строку из стандартного ввода
 * @param str Указатель на буфер для записи строки
 * @param size_str Размер буфера в байтах
 * @return Указатель на считанную строку или NULL при ошибке
 * @details Удаляет символ новой строки из ввода, если он присутствует.
 *          Если введенная строка превышает размер буфера, очищает остаток ввода.
 *
 * @code
 * char buffer[100];
 * strGets(buffer, sizeof(buffer));
 * @endcode
 */
char* strGets(char* str, int size_str) {
  char* ret_str = NULL;
  char* find = NULL;

  ret_str = fgets(str, size_str, stdin);
  if (ret_str) {
    find = strChar(str, '\n');
    if (find) {
      *find = '\0';
    }
    else {
      while (getchar() != '\n') {}
    }
  }
  return ret_str;
}
