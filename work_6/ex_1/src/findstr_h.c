/*
  findstr_h.c
*/
/*--------------------------------------------------------------------------*/
// Заголовочные файлы.
#include <stdio.h>      /* Стандартный ввод вывод.*/

#include "../include/string_h.h"  /* Библиотека для работы со строками (harkut). */
/*--------------------------------------------------------------------------*/
char* findStr(const char* str, const char* substr) {
    // Проверка на NULL указатели
    if (str == NULL || substr == NULL) {
        return NULL;
    }

    // Используем локальные переменные для работы
    const char* current_str = str;
    const char* current_substr = substr;

    // Если обе строки пустые
    if (*current_str == '\0' && *current_substr == '\0') {
        return (char*)str;
    }

    // Сравниваем посимвольно
    while (*current_str != '\0' && *current_substr != '\0') {
        if (*current_str != *current_substr) {
            return NULL;
        }
        current_str++;
        current_substr++;
    }

    // Обе строки должны закончиться одновременно
    if (*current_str == '\0' && *current_substr == '\0') {
        return (char*)str;
    }

    return NULL;
}
