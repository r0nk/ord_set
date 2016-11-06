CFLAGS=-fbuiltin -Wall -Wextra -g 
LIBS= -lgcc -lreadline -lm
CC=gcc

SRCFILES:= $(shell find -type f -name "*.c")

OBJFILES:= $(patsubst %.c,%.o,$(SRCFILES)) 

PROJ:=ord_set
	
.PHONY:all clean run

all: $(PROJ)

$(PROJ): $(OBJFILES)
	$(CC) -o $(PROJ) $(CFLAGS) $(OBJFILES) $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(LIBS) $< -o $@

clean:
	rm $(OBJFILES)
	rm $(PROJ)
