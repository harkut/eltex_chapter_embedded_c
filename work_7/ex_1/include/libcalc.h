/**
 * @file libcalc.h
 * @brief Библиотека математических операций для калькулятора
 * @author harkut
 * @version 1.0
 */

#ifndef LIBCALC_H
#define LIBCALC_H

/**
 * @brief Сложение двух целых чисел
 * @param a Первое слагаемое
 * @param b Второе слагаемое
 * @return Сумма a и b
 */
int add(int a, int b);

/**
 * @brief Вычитание двух целых чисел
 * @param a Уменьшаемое
 * @param b Вычитаемое
 * @return Разность a и b
 */
int sub(int a, int b);

/**
 * @brief Умножение двух целых чисел
 * @param a Первый множитель
 * @param b Второй множитель
 * @return Произведение a и b
 */
int mul(int a, int b);

/**
 * @brief Целочисленное деление двух чисел
 * @param a Делимое
 * @param b Делитель
 * @return Частное от деления a на b
 * @note При делении на 0 возвращает 0 и выводит сообщение об ошибке
 * @warning Деление на ноль обрабатывается, но результат равен 0
 */
int divide(int a, int b);

#endif // LIBCALC_H
