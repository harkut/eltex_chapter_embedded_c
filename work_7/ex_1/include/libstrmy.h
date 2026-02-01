/**
 * @file libstrmy.h
 * @brief Библиотека для работы со строками
 * @author harkut
 * @version 1.0
 */

#ifndef LIBSTRMY_H
#define LIBSTRMY_H

/**
 * @brief Считывает строку из стандартного ввода
 * @param str Указатель на буфер для записи строки
 * @param size_str Размер буфера в байтах
 * @return Указатель на считанную строку или NULL при ошибке
 * @details Удаляет символ новой строки из ввода, если он присутствует
 */
char* strGets(char* str, int size_str);

/**
 * @brief Ищет первое вхождение символа в строке
 * @param str Строка для поиска
 * @param s Искомый символ
 * @return Указатель на найденный символ или NULL, если символ не найден
 */
char* strChar(const char* str, int s);

/**
 * @brief Считывает один символ из стандартного ввода
 * @return Считанный символ
 * @details Игнорирует все символы до символа новой строки
 */
char charGets(void);

/**
 * @brief Обнуляет первый символ строки
 * @param str Строка для обнуления
 * @return Указатель на строку
 */
char* strNull(char* str);

/**
 * @brief Преобразует строку в целое число
 * @param str Строка для преобразования
 * @return Полученное целое число
 * @note Обрабатывает только положительные числа
 * @warning Не проверяет переполнение
 */
int atoi_h(const char* str);

/**
 * @brief Сравнивает две строки
 * @param str Первая строка для сравнения
 * @param substr Вторая строка для сравнения
 * @return Указатель на начало строки при совпадении, иначе NULL
 */
char* findStr(const char* str, const char* substr);

#endif // LIBSTRMY_H
