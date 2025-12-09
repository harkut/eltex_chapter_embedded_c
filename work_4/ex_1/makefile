TARGET = ex_1
CFLAGS = -Wall -Wextra -g
CC = gcc

CSRC = ex_1.c chargets_h.c strchar_h.c strgets_h.c strnull_h.c atoi_h.c findstr_h.c
COBJ = $(CSRC:.c=.o)

all: $(TARGET)

$(TARGET): $(COBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(COBJ) $(TARGET)

.PHONY: all clean












