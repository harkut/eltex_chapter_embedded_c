/**
 * @brief
 *
 * @param
 * @param
 * @return
 * @note
 */
#ifndef FUNC_EX_1_H
#define FUNC_EX_1_H

typedef enum {
  LEN_NAME = 10,
  LEN_SNAME = 10,
  LEN_TEL = 10,
  SIZE_BOOK = 12
} info_book;

struct abonent {
  char name[LEN_NAME + 1];
  char second_name[LEN_SNAME + 1];
  char tel[LEN_TEL + 1];
};

void addAbonent(struct abonent* p,
                unsigned short int* cur_size_book, ...);

void deleteAbonent(struct abonent* p,
                   unsigned short int* cur_size_book);

void findAbonentName(const struct abonent* p);

void printBook(const struct abonent* p,
               unsigned short int cur_size_book);

#endif
