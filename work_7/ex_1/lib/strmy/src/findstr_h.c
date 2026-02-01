/**
 * @file findstr_h.c
 * @brief Реализация функции сравнения строк
 * @author harkut
 */

#include <stdio.h>
#include "libstrmy.h"

/**
 * @brief Сравнивает две строки
 * @param str Первая строка для сравнения
 * @param substr Вторая строка для сравнения
 * @return Указатель на начало строки при полном совпадении, иначе NULL
 * @note Функция проверяет полное совпадение строк, а не поиск подстроки
 *
 * @code
 * char* result = findStr("hello", "hello"); // Возвращает указатель на "hello"
 * char* result2 = findStr("hello", "world"); // Возвращает NULL
 * @endcode
 */
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
