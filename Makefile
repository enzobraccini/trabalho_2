CC = gcc
SRC = ./src
OBJS = ./objs
TARGET = teste
LIMPAR = rm

all: objetos
	$(CC) $(OBJS)/arquivos.o $(OBJS)/relatorios.o $(OBJS)/uteis.o $(OBJS)/menu.o $(OBJS)/cadastros.o $(OBJS)/main.o -o $(TARGET)
	

objetos:
	$(CC) -c $(SRC)/menu.c -o $(OBJS)/menu.o
	$(CC) -c $(SRC)/cadastros.c -o $(OBJS)/cadastros.o
	$(CC) -c $(SRC)/relatorios.c -o $(OBJS)/relatorios.o
	$(CC) -c $(SRC)/uteis.c -o $(OBJS)/uteis.o
	$(CC) -c $(SRC)/arquivos.c -o $(OBJS)/arquivos.o
	$(CC) -c main.c -o $(OBJS)/main.o


clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)