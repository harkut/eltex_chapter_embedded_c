// ex_3.c
// Описание:
//    Заполнить нижний правый треугольник матрицы 1, а верхний нулями.

// Заголовочные файлы.
#include <stdio.h>   /* Стандартный ввод вывод. */

// Директивы препроцессора.
#define R 10 /* Размер матрицы arr[R][R]. */

int main() {

  int arr[R][R] = {0};
  short int num_arr = R;
  short int size_arr = R * R;
  
  // Вывод массива arr в терминал.
  for (short int i = 0;
       i < size_arr;
       i++) {
    printf("%-3d", arr[i / num_arr][i % num_arr]);
    if (!((i + 1) % num_arr))
      printf("\n");
  }
  printf("\n");

  // Заполнение побочной диагонали.
  for (short int i = 0;
       i < num_arr;
       i++) {
    arr[i][num_arr - i -1] = 1; 
  }

  // Вывод массива arr в терминал.
  for (short int i = 0;
       i < size_arr;
       i++) {
    printf("%-3d", arr[i / num_arr][i % num_arr]);
    if (!((i + 1) % num_arr))
      printf("\n");
  }
  printf("\n");\

  // Заполнение ниже побочной диагонали.
  for (short int i = 0;
       i < num_arr;
       i++) {
    for (short int j = 0;
         j < num_arr;
         j++) {
      if (i + j > num_arr - 1) {
        arr[i][j] = 1;
      }
    }
  }

  // Вывод массива arr в терминал.
  for (short int i = 0;
       i < size_arr;
       i++) {
    printf("%-3d", arr[i / num_arr][i % num_arr]);
    if (!((i + 1) % num_arr))
      printf("\n");
  }
  printf("\n");
  
  return 0;
}
