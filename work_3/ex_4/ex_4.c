// ex_4.c
// Описание:
//    Заполнить матрицу от 1 до N^2 улиткой.

// Заголовочные файлы.
#include <stdio.h>   /* Стандартный ввод вывод. */

// Директивы препроцессора.
#define R 10 /* Размер матрицы arr[R][R]. */

int main() {

  int arr[R][R] = {0};
  short int num_arr = R;
  short int size_arr = R * R;
  
  short int num = 1;
  short int r = 0, c = 0;
  short int dir = 0;
  short int i = 0;

 short int r_min = 0, c_min = 0;
 short int r_max = num_arr - 1, c_max = num_arr - 1;
  
  // Заполнение матрицы улиткой.
  while (i <= num_arr * num_arr) {
    arr[r][c] = num++;

    // Движение вправо
    if (dir == 0) {
      if (c == c_max) {
        dir = 1; // Сменить направление на вниз
        r_min++; // Сдвинуть нижнюю границу
        r++;
      } else {
        c++;
      }
    }
    // Движение вниз
    else if (dir == 1) {
      if (r == r_max) {
        dir = 2; // Сменить направление на влево
        c_max--; // Сдвинуть правую границу
        c--;
      } else {
        r++;
      }
    }
    // Движение влево
    else if (dir == 2) {
      if (c == c_min) {
        dir = 3; // Сменить направление на вверх
        r_max--; // Сдвинуть верхнюю границу
        r--;
      } else {
        c--;
      }
    }
    // Движение вверх
    else if (dir == 3) {
      if (r == r_min) {
        dir = 0; // Сменить направление на вправо
        c_min++; // Сдвинуть левую границу
        c++;
      } else {
        r--;
      }
    }

    i++;
  }

  // Вывод массива arr в терминал.
  for (short int i = 0;
       i < size_arr;
       i++) {
    printf("%-4d", arr[i / num_arr][i % num_arr]);
    if (!((i + 1) % num_arr))
      printf("\n");
  }
 
  return 0;
}
