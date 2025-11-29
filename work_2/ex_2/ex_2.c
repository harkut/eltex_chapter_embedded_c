// ex_2.c
// Описание:
//    Поменять местами элементы в заданном массиве и вывести на экран.

// Заголовочные файлы.
#include <stdio.h>   /* Стандартный ввод вывод. */

// Директивы препроцессора.
#define R 10 /* Размер матрицы arr[R][R]. */

int main() {

    int arr[R] = {0};
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    int tmp;

    for (int i = 0;
         i < size_arr;
         i++) {
      arr[i] = i;
    }

    // Вывод массива arr.
    for (int i = 0;
         i < size_arr;
         i++) {
      printf("%d ", arr[i]); 
    }
    printf("\n");

    // Смена местами левых и правых элементов массива arr через промежуточную
    // переменную tmp.
    for (int i = 0;
         i < size_arr / 2;
         i++) {
      tmp = arr[i];
      arr[i] = arr[size_arr - 1 - i];
      arr[size_arr - 1 - i] = tmp;
    }

    // Вывод обратного массива arr.
    for (int i = 0;
         i < size_arr;
         i++) {
      printf("%d ", arr[i]); 
    }
    printf("\n");
 
  return 0;
}
