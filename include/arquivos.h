#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

void salvar_dados_aeronave(NoAeronave_t *inicio);
void salvar_dados_rotas(NoRota_t *inicio);
void carregar_dados_aeronave(NoAeronave_t **inicio);
void carregar_dados_rotas(NoRota_t **inicio);
void exportar_dados_aviao_csv(NoAeronave_t *aviao, char *nome_arq);
void exportar_dados_aviao_html(NoAeronave_t *aviao, char *nome_arq);
void exportar_dados_rota_csv(NoRota_t *rota, char *nome_arq);
void exportar_dados_rota_html(NoRota_t *rota, char *nome_arq);

#endif