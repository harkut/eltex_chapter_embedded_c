# ==========================================
# Настройки проекта
# ==========================================
TARGET     = ex_1
CC         = gcc
BUILD_MODE ?= debug

# Директории
SRC_DIR    = src
LIB_DIR    = lib
INC_DIR    = include
BUILD_DIR  = build
OBJ_DIR    = $(BUILD_DIR)/obj
BIN_DIR    = $(BUILD_DIR)/bin
DOC_DIR    = doc

# Библиотеки проекта
LIBS       = calc strmy
LIBRARIES  = $(addprefix $(BUILD_DIR)/lib/lib, $(addsuffix .a, $(LIBS)))

# Исходные файлы приложения
APP_SRCS   = $(wildcard $(SRC_DIR)/*.c)
APP_OBJS   = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/app/%.o, $(APP_SRCS))
APP_DEPS   = $(APP_OBJS:.o=.d)

# Флаги для поиска заголовков
INC_FLAGS  = -I$(INC_DIR)

# ==========================================
# Флаги компиляции и линковки
# ==========================================
COMMON_CFLAGS = -Wall -Wextra $(INC_FLAGS) -MMD -MP

ifeq ($(BUILD_MODE), release)
    CFLAGS  = $(COMMON_CFLAGS) -O3
    LDFLAGS = -s -L$(BUILD_DIR)/lib
else
    CFLAGS  = $(COMMON_CFLAGS) -g3 -O0 -DDEBUG=1
    LDFLAGS = -L$(BUILD_DIR)/lib
endif

# Библиотеки для линковки
LDLIBS     = $(addprefix -l, $(LIBS))

# Инструменты
CHECKER    = cppcheck
VALGRIND   = valgrind
DOXYGEN    = doxygen

# ==========================================
# Основные цели
# ==========================================
.PHONY: all clean run check memcheck debug doc rebuild tree

all: $(BIN_DIR)/$(TARGET)

# Сборка исполняемого файла
$(BIN_DIR)/$(TARGET): $(APP_OBJS) $(LIBRARIES) | $(BIN_DIR)
	@echo "--- Linking ($(BUILD_MODE)): $@ ---"
	$(CC) $(LDFLAGS) $< $(LDLIBS) -o $@

# Компиляция исходников приложения
$(OBJ_DIR)/app/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)/app
	@echo "--- Compiling app: $< ---"
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для сборки библиотек
$(BUILD_DIR)/lib/lib%.a:
	@echo "--- Building library $* ---"
	$(MAKE) -C $(LIB_DIR)/$* BUILD_ROOT=$(CURDIR)/$(BUILD_DIR)

# Создание директорий
$(BIN_DIR) $(OBJ_DIR)/app:
	@mkdir -p $@

# Включение зависимостей
-include $(APP_DEPS)

# ==========================================
# Служебные команды
# ==========================================
clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR) $(DOC_DIR)
	@for lib in $(LIBS); do \
		if [ -d "$(LIB_DIR)/$$lib" ]; then \
			$(MAKE) -C $(LIB_DIR)/$$lib clean; \
		fi \
	done

run: $(BIN_DIR)/$(TARGET)
	@echo "--- Running $(TARGET) ---"
	./$(BIN_DIR)/$(TARGET)

check:
	@echo "Running Cppcheck..."
	$(CHECKER) --enable=all --suppress=missingIncludeSystem \
		$(INC_FLAGS) $(SRC_DIR)

memcheck: $(BIN_DIR)/$(TARGET)
	@echo "Running Valgrind..."
	$(VALGRIND) --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(BIN_DIR)/$(TARGET)

debug: $(BIN_DIR)/$(TARGET)
	@gdb ./$(BIN_DIR)/$(TARGET)

rebuild: clean all

tree:
	@echo "Project structure:"
	@find . -type f \( -name "*.c" -o -name "*.h" -o -name "Makefile" \) | sort | sed 's|^\./||'

# ==========================================
# Документация
# ==========================================
doc:
	@echo "--- Generating Doxygen Documentation ---"
	@if [ -f Doxyfile ]; then \
		mkdir -p $(DOC_DIR); \
		$(DOXYGEN) Doxyfile; \
		if [ -d "$(DOC_DIR)/latex" ]; then \
			echo "--- Generating PDF (LaTeX) ---"; \
			$(MAKE) -C $(DOC_DIR)/latex; \
			cp $(DOC_DIR)/latex/refman.pdf \
				$(DOC_DIR)/$(TARGET)_docs.pdf; \
			echo "PDF created: $(DOC_DIR)/$(TARGET)_docs.pdf"; \
		fi; \
	else \
		echo "Error: Doxyfile not found."; \
	fi
