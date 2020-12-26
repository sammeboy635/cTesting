CC       = gcc
CFLAGS   = -Wall -g
LDFLAGS  =
OBJFILES = chunk.o cube.o main.o
TARGET   = main
all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~