#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include "../include/types.h"
#include <stdio.h>
#include <stdlib.h>

void salvar_dados_aeronave(NoAeronave_t *inicio)
{
    FILE *fp = NULL;

    fp = fopen("aeronaves.bin", "wb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo aeronaves.bin\n");
        return;
    }

    while (inicio) {
        fwrite(inicio, sizeof(NoAeronave_t), 1, fp);
        inicio = inicio->proximo;
    }
    fclose(fp);
}

void salvar_dados_rotas(NoRota_t *inicio)
{
    FILE *fp = NULL;

    fp = fopen("rotas.bin", "wb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo rotas.bin\n");
        return;
    }

    while (inicio) {
        fwrite(inicio, sizeof(NoRota_t), 1, fp);
        inicio = inicio->proximo;
    }
    fclose(fp);
}  

void carregar_dados_aeronave(NoAeronave_t **inicio)
{
    FILE *fp = fopen("aeronaves.bin", "rb");
    if (!fp) {
        printf("Erro ao abrir aeronaves.bin\n");
        return;
    }

    while (1) {
        NoAeronave_t *novo = malloc(sizeof(NoAeronave_t));
        if (!novo) {
            printf("Erro ao alocar memória!\n");
            break;
        }

        if (fread(novo, sizeof(NoAeronave_t), 1, fp) != 1) {
            free(novo);
            break;
        }

        novo->proximo = NULL;


        if (*inicio == NULL) {
            *inicio = novo;
        } else {
            NoAeronave_t *aux = *inicio;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }

    fclose(fp);
}

void carregar_dados_rotas(NoRota_t **inicio)
{
    FILE *fp = fopen("rotas.bin", "rb");
    if (!fp) {
        printf("Erro ao abrir rotas.bin\n");
        return;
    }

    while (1) {
        NoRota_t *novo = malloc(sizeof(NoRota_t));
        if (!novo) {
            printf("Erro ao alocar memória!\n");
            break;
        }

        if (fread(novo, sizeof(NoRota_t), 1, fp) != 1) {
            free(novo);
            break;
        }

        novo->proximo = NULL;

        if (*inicio == NULL) {
            *inicio = novo;
        } else {
            NoRota_t *aux = *inicio;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }

    fclose(fp);
}