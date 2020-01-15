######
# Makefile for STM8
#
# Developer: Aniket Fondekar
#
# Date: 7 July 2019 
######

DEVICE = stm8s103f3
PROGRAMMER = stlinkv2

SRC = src
INC = inc
BIN = bin
CC = sdcc
TARGET = $(BIN)/$(DEVICE).ihx

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NC = \033[1;0m

DEFINES = 
ifeq ($(DEVICE),stm8s003f3)
DEFINES += -DSTM8S003
endif
ifeq ($(DEVICE),stm8s103f3)
DEFINES += -DSTM8S103
endif

CFLAGS = --Werror -mstm8 -lstm8 --opt-code-size
INCLUDE = -I$(INC)

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.rel)))

.PHONY = all clean run help

$(BIN)/$(TARGET) : $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $^
	@echo "$(BLUE)Finished...$(NC)"
$(BIN)/%.rel : $(SRC)/%.c
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDE) -c $? -o $@
	@echo "$(GREEN)Compiling...$(NC)"

clean : 
	rm -rf $(BIN)/*
flash : 
	stm8flash -c $(PROGRAMMER) -p $(DEVICE) -w $(TARGET)
help :
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
