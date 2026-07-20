CC=g++
CFLAGS=-Wall -Wextra
TARGET=sum-nbo
SOURCE=sum-nbo.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)
