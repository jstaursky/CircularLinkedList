PROJECT_DIR = ./..
INCLUDES = -I $(PROJECT_DIR)/include
LIB		 = $(PROJECT_DIR)/lib
SRC		 = $(PROJECT_DIR)/src
CC		 = gcc
CFLAGS	 = -Wall -g

%: CircularLinkedList.o %.o
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB)/$< $@.o -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

CircularLinkedList.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)/CircularLinkedList.c -o $(LIB)/$@

