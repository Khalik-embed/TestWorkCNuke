
CC = gcc
CFLAGS= -Wall -Werror  -I./include

BUILD_DIR = build
SRC_DIR = src

SOURCES = $(SRC_DIR)/main.c \
		$(SRC_DIR)/mem_handlings.c \
		$(SRC_DIR)/input_cheking.c \
		$(SRC_DIR)/file_handlings.c \
		$(SRC_DIR)/error_handlings.c \
		$(SRC_DIR)/search_point.c

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

TARGET = $(BUILD_DIR)/nuke


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	del $(BUILD_DIR)/*.o $(TARGET)

.PHONY: clean