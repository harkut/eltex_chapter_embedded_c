/**
 * @file main.c
 * @brief Главный модуль программы "Калькулятор"
 * @author harkut
 * @version 1.0
 *
 * @details Программа представляет собой интерактивный калькулятор
 *          с поддержкой базовых арифметических операций над целыми числами.
 */

#include <stdio.h>
#include <stdlib.h>
#include "libcalc.h"
#include "libstrmy.h"

/**
 * @brief Печатает главное меню калькулятора на экран
 * @details Отображает доступные операции и запрашивает выбор пользователя
 */
void print_menu(void) {
  printf("\n==================================\n");
  printf("          КАЛЬКУЛЯТОР             \n");
  printf("==================================\n");
  printf("1) Сложение\n");
  printf("2) Вычитание\n");
  printf("3) Умножение\n");
  printf("4) Деление\n");
  printf("5) Выход\n");
  printf("==================================\n");
  printf("Выберите операцию (1-5): ");
}

/**
 * @brief Получает от пользователя два целых числа
 * @param a Указатель на переменную для первого числа
 * @param b Указатель на переменную для второго числа
 * @details Использует функции из библиотеки strmy для безопасного ввода
 */
void get_numbers(int *a, int *b) {
  char buffer[100];

  printf("Введите первое число: ");
  strGets(buffer, sizeof(buffer));
  *a = atoi_h(buffer);

  printf("Введите второе число: ");
  strGets(buffer, sizeof(buffer));
  *b = atoi_h(buffer);
}

/**
 * @brief Обрабатывает операцию сложения
 * @details Запрашивает два числа у пользователя, выполняет сложение
 *          и выводит результат на экран
 */
void handle_addition(void) {
  int a, b, result;

  printf("\n--- СЛОЖЕНИЕ ---\n");
  get_numbers(&a, &b);
  result = add(a, b);
  printf("%d + %d = %d\n", a, b, result);
}

/**
 * @brief Обрабатывает операцию вычитания
 * @details Запрашивает два числа у пользователя, выполняет вычитание
 *          и выводит результат на экран
 */
void handle_subtraction(void) {
  int a, b, result;

  printf("\n--- ВЫЧИТАНИЕ ---\n");
  get_numbers(&a, &b);
  result = sub(a, b);
  printf("%d - %d = %d\n", a, b, result);
}

/**
 * @brief Обрабатывает операцию умножения
 * @details Запрашивает два числа у пользователя, выполняет умножение
 *          и выводит результат на экран
 */
void handle_multiplication(void) {
  int a, b, result;

  printf("\n--- УМНОЖЕНИЕ ---\n");
  get_numbers(&a, &b);
  result = mul(a, b);
  printf("%d * %d = %d\n", a, b, result);
}

/**
 * @brief Обрабатывает операцию деления
 * @details Запрашивает два числа у пользователя, выполняет целочисленное деление
 *          и выводит результат на экран. Проверяет деление на ноль.
 */
void handle_division(void) {
  int a, b, result;

  printf("\n--- ДЕЛЕНИЕ ---\n");
  get_numbers(&a, &b);
  result = divide(a, b);

  if (b != 0) {
    printf("%d / %d = %d\n", a, b, result);

    // Покажем остаток от деления, если есть
    if (a % b != 0) {
      printf("Остаток: %d\n", a % b);
    }
  }
}

/**
 * @brief Очищает экран терминала
 */
void clear_screen(void) {
  system("clear");
}

/**
 * @brief Главная функция программы
 * @return 0 при успешном завершении программы
 * @details Основной цикл программы, который отображает меню,
 *          обрабатывает выбор пользователя и выполняет выбранную операцию.
 *
 * @code
 * // Пример работы программы:
 * // 1. Показывает меню
 * // 2. Получает выбор пользователя
 * // 3. Выполняет выбранную операцию
 * // 4. Возвращается в меню
 * // 5. Выходит при выборе пункта 5
 * @endcode
 */
int main(void) {
  char choice_str[10];
  int choice = 0;

  clear_screen();

  while (1) {
    print_menu();

    // Получаем выбор пользователя
    strGets(choice_str, sizeof(choice_str));
    choice = atoi_h(choice_str);

    // Обрабатываем выбор
    switch (choice) {
    case 1:
      handle_addition();
      break;

    case 2:
      handle_subtraction();
      break;

    case 3:
      handle_multiplication();
      break;

    case 4:
      handle_division();
      break;

    case 5:
      clear_screen();
      return 0;

    default:
      printf("\nОшибка: некорректный выбор. Пожалуйста, введите число от 1 до 5.\n");
      break;
    }

    // Пауза перед следующим циклом
    printf("\nНажмите Enter для продолжения...");
    getchar(); // Ждем нажатия Enter
    clear_screen();
  }

  return 0;
}
