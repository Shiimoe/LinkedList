CC = gcc
CFLAGS  = -g -Wall
TARGET = ll
BUILD = ./build

bold=$(tput bold)

default: build

build: clean linked_list
	@tput bold
	@echo "Building target."
	@tput sgr0

	ln -s $(BUILD)/$(TARGET)
	
run: build
	@tput bold
	@echo -e "Running target (./$(TARGET)):\n"
	@tput sgr0

	@./$(TARGET)

linked_list: $(BUILD)/main.o $(BUILD)/linked_list.o
	@tput bold
	@echo "Compiling target."
	@tput sgr0

	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/$(TARGET) \
		$(BUILD)/main.o \
		$(BUILD)/linked_list.o

$(BUILD)/main.o:
	$(CC) $(CFLAGS) -c main.c -o $(BUILD)/main.o

$(BUILD)/linked_list.o:
	$(CC) $(CFLAGS) -c linked_list.c -o $(BUILD)/linked_list.o

clean:
	rm -rf $(BUILD)/*
	rm -rf $(TARGET)