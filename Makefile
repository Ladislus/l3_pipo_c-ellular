# Compilateur
CC := gcc
# Options de compilation
WFLAGS := -Wall -Wextra -pedantic  -Wno-unused-but-set-parameter -Wno-unused-variable -Wno-unused-parameter -Wno-abi
SFLAGS := -std=c99
IFLAGS := -I include
DFLAGS := -ggdb

#Compilateur final
COMPILEUR := $(CC) $(WFLAGS) $(SFLAGS) $(IFLAGS) $(DFLAGS)

#Noms des fichiers
FILES := obj/main.o obj/structure.o obj/printing.o obj/convert.o
#Nom de l'éxécutable
EXECUTABLE := exec

# règle de compilation
all : prepare main

main : $(FILES)
	$(COMPILEUR) -o $(EXECUTABLE) $^ -lm

obj/%.o : src/%.c
	$(COMPILEUR)  -o $@ -c $<

run :
	valgrind --leak-check=full ./$(EXECUTABLE)

prepare :
	test -d obj || mkdir obj

archive :
	tar -cf archive.tar.gz src/ include/ Makefile

clean :
	rm -rf obj exec