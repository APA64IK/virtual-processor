CC 			 := gcc
CFLAGS	 := -Wall -Wextra -std=c99 -Wno-unused-parameter

SOURCE_DIR 	 := ./src
INCLUDES_DIR := ./src/INCLUDES
BUILD_DIR 	 := ./build

SRC_FILES := $(wildcard $(SOURCE_DIR)/*.c) $(wildcard $(INCLUDES_DIR)/*.c)
OBJ_FILES := $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC_FILES)))

TARGET			:= main.c
TARGET_FILE := $(notdir $(TARGET))
OUTPUT_FILE := $(patsubst %.c,$(BUILD_DIR)/%.exe,$(TARGET_FILE))

all: clearScreen $(TARGET) run clean

run: $(OUTPUT_FILE)

rebuild: clean all

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(INCLUDES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) $^

$(OUTPUT_FILE): $(TARGET_FILE)
	@printf "Execution at:\n  "
	$@

clean:
	@rm -f $(BUILD_DIR)/*

clearScreen:
	@clear

.PHONY: all run clean clearScreen rebuild