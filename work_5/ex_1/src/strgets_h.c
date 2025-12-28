/*
  strgets_h.c
*/
/*--------------------------------------------------------------------------*/
// Заголовочные файлы.
#include <stdio.h>      /* Стандартный ввод вывод.*/

#include "../include/string_h.h"  /* Библиотека для работы со строками (harkut). */
/*--------------------------------------------------------------------------*/
/*
  strGets(const char* str, int size_str)
  Описание:
  Получает аргументом указатель на начало строки str который будет являться
  буфером для начала записи из stdin размером size_str. Символ новой строки в
  введенной строке удаляется и заменяется нуль-терминатором.
  Вовзращает указатель на начало этой строки.
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
