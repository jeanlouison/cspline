OBJDIR = build
CC = gcc
CFLAGS = -Wall -Wextra
CLIBS = -lSDL2 -lm
FILES = test.c board.c point.c graphics.c
OBJECTS = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

ifeq ($(OS), Windows_NT)
	REM = del /Q $(OBJDIR)\*
	EXEC = main.exe
else
	REM = rm $(OBJDIR)/*
	EXEC = ./main
endif

all: $(OBJDIR) main

$(OBJDIR):
	mkdir $(OBJDIR)

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(CLIBS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(CLIBS)

clean:
	$(REM)