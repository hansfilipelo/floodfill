UNAME=$(shell uname -s)
HOSTNAME = $(shell hostname)

CC = g++
EXEC = flood
CCFLAGS = --std=c++14
INC =
LDFLAGS = -lm

SRC_DIR=src
BUILD_DIR=build
OBJS_DIR=$(BUILD_DIR)/objs/

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
H_FILES = $(wildcard $(SRC_DIR)/*.hpp)

OBJS_TMP = $(notdir $(SRC_FILES:.cpp=.o))
OBJS = $(addprefix $(OBJS_DIR),$(OBJS_TMP))

# Compile

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(INC) -o $(EXEC) $(LDFLAGS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: src/%.cpp src/%.hpp | $(OBJS_DIR)
	$(CC) $(CCFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(EXEC) $(OBJS)
	rm -rf $(BUILD_DIR)

