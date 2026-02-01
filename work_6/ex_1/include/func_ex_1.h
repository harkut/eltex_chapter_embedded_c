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
  struct abonent *next;
  struct abonent *prev;
};

struct abonentbook {
  struct abonent *head;
  struct abonent *tail;
  unsigned short int size;
};

void initAbonentBook(struct abonentbook *book);
void addAbonent(struct abonentbook *book);
void deleteAbonent(struct abonentbook *book);
void findAbonentName(const struct abonentbook *book);
void printBook(const struct abonentbook *book);
void clearAbonentBook(struct abonentbook *book);

#endif
