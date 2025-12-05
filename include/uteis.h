#ifndef UTEIS_H
#define UTEIS_H
#include <stdio.h>

#include "./types.h"

int contar_aeronaves(NoAeronave_t *nova);
int contar_rotas(NoRota_t *nova);
void liberar_lista_aeronaves(NoAeronave_t *nova);
void liberar_lista_rotas(NoRota_t *nova);
void retirar_enter(char *str);

#endif