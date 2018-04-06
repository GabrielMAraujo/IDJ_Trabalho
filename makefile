CC=g++
EXECNAME = jogo.out
SRCDIR = src
INCDIR = include
BINDIR = bin
OBJDIR = object
LFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer
CFLAGS = -std=c++11

BIN = $(BINDIR)/$(EXECNAME)
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(OBJ)
	$(CC) $(OBJ) $(LFLAGS)  $(CFLAGS) -o $(EXECNAME) -g -ggdb

%.o: $(patsubst $(OBJDIR)/%.o, $(SRCDIR)/%.cpp, $@)
	$(CC) -c $(patsubst $(OBJDIR)/%.o, $(SRCDIR)/%.cpp, $@) -o $@ -g -ggdb

clean:
	rm -f $(OBJ) *~
