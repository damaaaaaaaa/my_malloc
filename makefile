CC = gcc 
CFLAGS = -Wall -Wextra -std=c11 -I.
TARGET = my_malloc 

$(TARGET): src/my_malloc.c apps/main.c
	$(CC) $(CFLAGS) apps/main.c src/my_malloc.c -o $(TARGET) 

clean:
	rm -f $(TARGET)
