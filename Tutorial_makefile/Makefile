#####
# Makefile for STM8
#
# Developer: Aniket Fondekar
#
# Date: 15 Jan 2020 
######

TARGET = main


SRC = src
INC = inc
BIN = bin
CC = g++

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[1;0m

CFLAGS = -Wall -std=gnu99 -I$(INC)

SOURCE = $(wildcard $(SRC)/*.c) $(wildcard $(SRC)/*.cpp)


OBJECT = $(patsubst %,$(BIN)/%,$(filter %.o,$(notdir $(SOURCE:.c=.o)))) $(patsubst %,$(BIN)/%,$(filter %.o,$(notdir $(SOURCE:.cpp=.o))))



$(BIN)/$(TARGET) : $(OBJECT) 
	@echo "$(RED)Linking...$(NC)"
	$(CC) -o $@ $^
	@echo "$(BLUE)Finished$(NC)"


$(BIN)/%.o: $(SRC)/%.c
	@echo "$(GREEN)Compiling...$(NC) "
	@echo "$< "
	@echo "$(OBJECT)"
	$(CC) $(CFLAGS) -c $< -o $@ 

$(BIN)/%.o: $(SRC)/%.cpp
	@echo "$(GREEN)Compiling...$(NC) "
	$(CC) $(CFLAGS) -c $< -o $@ 
.PHONY : run clean help

run : $(BIN)/$(TARGET) 
	@echo "$(YELLOW)Running...$(NC)"
	@./$(BIN)/$(TARGET)

clean:
	@rm -rf $(OBJECT) $(BIN)/$(TARGET)

help : 
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
