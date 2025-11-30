#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "./types.h"

void relatorio_aeronaves(NoAeronave_t *nova_aeronave);
void buscar_aeronave_prefixo(NoAeronave_t *nova_aeronave);
void listar_aeronave_fabricante(NoAeronave_t *nova_aeronave);
void listar_aeronave_tipo(NoAeronave_t *nova_aeronave);
void listar_aeronave_modelo(NoAeronave_t *nova_aeronave);
void listar_aeronave_ano_fabricacao(NoAeronave_t *nova_aeronave);
void listar_aeronave_situacao(NoAeronave_t *nova_aeronave);
void quantidade_manutencao(NoAeronave_t *nova_aeronave);

void consultar_rota_data(NoRota_t *nova_rota);
void listar_rota_origem(NoRota_t *nova_rota);
void listar_rota_destino(NoRota_t *nova_rota);
void porcentagem_voo_aeronave(NoRota_t *nova_rota);
void porcentagem_voos_intervalo(NoRota_t *nova_rota);
void consumo_combustivel_intervalo(NoRota_t *nova_rota);
void rota_mais_passageiros(NoRota_t *nova_rota);
void rota_menos_passageiros(NoRota_t *nova_rota);

#endif