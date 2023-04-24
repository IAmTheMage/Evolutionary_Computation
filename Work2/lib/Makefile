CC = gcc
CFLAGS = -Wall -O3 -Werror -fpic
LDFLAGS = -shared

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
TARGET_LIB = libcore.so

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

INC_PARAMS = $(addprefix -I,$(INC_DIR))

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET_LIB)

$(BUILD_DIR)/$(TARGET_LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC_PARAMS) -MMD -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)