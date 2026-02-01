# Настройки библиотеки strmy
CC       = gcc
AR       = ar
RANLIB   = ranlib

# Директории
SRC_DIR  = src
INC_DIR  = ../../include  # Заголовки в корне проекта
BUILD_ROOT ?= ../../build
OBJ_DIR  = $(BUILD_ROOT)/obj/libstrmy
LIB_DIR  = $(BUILD_ROOT)/lib

# Файлы библиотеки
SRCS     = $(wildcard $(SRC_DIR)/*.c)
OBJS     = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS     = $(OBJS:.o=.d)
TARGET   = $(LIB_DIR)/libstrmy.a

# Флаги
CFLAGS   = -Wall -Wextra -I$(INC_DIR) -MMD -MP
ARFLAGS  = rcs

# Цели
.PHONY: all clean

all: $(TARGET)

# Создание статической библиотеки
$(TARGET): $(OBJS) | $(LIB_DIR)
	@echo "Creating static library: $@"
	$(AR) $(ARFLAGS) $@ $^
	$(RANLIB) $@

# Компиляция исходников библиотеки
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling library source: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Создание директорий
$(OBJ_DIR) $(LIB_DIR):
	@mkdir -p $@

# Включение зависимостей
-include $(DEPS)

# Очистка
clean:
	@echo "Cleaning library strmy..."
	@rm -rf $(OBJ_DIR) $(TARGET)
