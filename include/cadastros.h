#ifndef CADASTROS_H
#define CADASTROS_H

#include "./types.h"

int cadastrar_aeronave(NoAeronave_t **nova_aeronave);
int cadastrar_rota(NoRota_t **nova_rota, NoAeronave_t *nova_aeronave);

#endif