/*
  strgets_h.c
*/
/*--------------------------------------------------------------------------*/
// Заголовочные файлы.
#include <stdio.h>      /* Стандартный ввод вывод.*/

#include "string_h.h"  /* Библиотека для работы со строками (harkut). */ 
/*--------------------------------------------------------------------------*/
/*
  strGets(const char* str, int c)
  Описание:
  Получает аргументом строку str которая будет являться буфером для записи
  из stdin размером size_str. Символ новой строки в введенной строке удаляется
  и заменяется нуль-терминатором.
*/
char* strGets(char* str, int size_str) {
  char* ret_str;
  char* find;

  ret_str = fgets(str, size_str, stdin);
  if (ret_str) {
    find = strChar(str, 'n');
    if (find) {
      *find = '\0';
    }
    else {
      while (getchar() != '\n') {
        continue;
      }
    }
      
  }
  return ret_str;
}

