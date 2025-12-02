#ifndef UTEIS_H
#define UTEIS_H
#include <stdio.h>

#include "./types.h"

int contar_aeronaves(NoAeronave_t *nova);
int contar_rotas(NoRota_t *nova);
void liberar_lista_aeronaves(NoAeronave_t *nova);
void liberar_lista_rotas(NoRota_t *nova);
void mostrar_dados_aeronave(aeronave_t *aviao, FILE *fp);
void mostrar_dados_rota(rota_t *rota, FILE *fp);
void retirar_enter(char *str);
void limpar_buffer();

#endif