/**
 * @file div.c
 * @brief Реализация функции деления
 * @author harkut
 */

#include <stdio.h>
#include "libcalc.h"

/**
 * @brief Целочисленное деление двух чисел
 * @param a Делимое
 * @param b Делитель
 * @return Частное от деления a на b
 * @note При делении на 0 возвращает 0 и выводит сообщение об ошибке
 */
int divide(int a, int b) {
  if (b == 0) {
    fprintf(stderr, "Ошибка: деление на ноль!\n");
    return 0;
  }
  return a / b;
}
