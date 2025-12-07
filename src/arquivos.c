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
    FILE *fp = NULL;
    NoAeronave_t *novo = NULL;

    fp = fopen("aeronaves.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo aeronaves.bin\n");
        return;
    }

    while (!feof(fp)) {

        novo = (NoAeronave_t*)malloc(sizeof(NoAeronave_t));
        if (!novo) {
            printf("Erro ao alocar memória!\n");
            break;
        }

        fread(novo, sizeof(NoAeronave_t), 1, fp);
        novo->proximo = NULL;

        if (!feof(fp)) {
            if (*inicio == NULL) {
                *inicio = novo;
            } else {
                NoAeronave_t *aux = *inicio;
                while (aux->proximo != NULL) {
                    aux = aux->proximo;
                }
                aux->proximo = novo;
            }

        } else {
            free(novo);
        }
    }
    fclose(fp);
}

void carregar_dados_rotas(NoRota_t **inicio)
{
    FILE *fp = NULL;
    NoRota_t *novo = NULL;

    fp = fopen("rotas.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo rotas.bin\n");
        return;
    }

    while (!feof(fp)) {

        novo = (NoRota_t*)malloc(sizeof(NoRota_t));
        if (!novo) {
            printf("Erro ao alocar memória!\n");
            break;
        }

        fread(novo, sizeof(NoRota_t), 1, fp);
        novo->proximo = NULL;

        if (!feof(fp)) {

            if (*inicio == NULL) {
                *inicio = novo;
            } else {
                NoRota_t *aux = *inicio;
                while (aux->proximo != NULL) {
                    aux = aux->proximo;
                }
                aux->proximo = novo;
            }

        } else {
            free(novo);
        }
    }

    fclose(fp);
}

void exportar_dados_aviao_csv(NoAeronave_t *aviao, char *nome_arq)
{
    FILE *fp = fopen(nome_arq, "w");
    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "ID;MODELO;FABRICANTE;PREFIXO\n");

    while (aviao) {
        fprintf(fp, "%d;%s;%s;%s\n",
            aviao->dados_aeronave.id,
            aviao->dados_aeronave.modelo,
            aviao->dados_aeronave.fabricante,
            aviao->dados_aeronave.prefixo
        );
        aviao = aviao->proximo;
    }

    fclose(fp);
}

void exportar_dados_aviao_html(NoAeronave_t *aviao, char *nome_arq)
{
    FILE *fp = fopen(nome_arq, "w");
    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<html><head><title>Relatorio de Aeronaves</title></head><body>\n");
    fprintf(fp, "<h2>Relatorio de Aeronaves</h2>\n");
    fprintf(fp, "<table border='1'>\n");
    fprintf(fp, "<tr><th>ID</th><th>Modelo</th><th>Fabricante</th><th>Prefixo</th></tr>\n");

    while (aviao) {
        fprintf(fp,
            "<tr><td>%d</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",
            aviao->dados_aeronave.id,
            aviao->dados_aeronave.modelo,
            aviao->dados_aeronave.fabricante,
            aviao->dados_aeronave.prefixo
        );
        aviao = aviao->proximo;
    }

    fprintf(fp, "</table></body></html>\n");

    fclose(fp);
}

void exportar_dados_rota_csv(NoRota_t *rota, char *nome_arq)
{
    FILE *fp = fopen(nome_arq, "w");
    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "ID;ORIGEM;DESTINO;COMBUSTIVEL;PASSAGEIROS;CARGA;AERONAVE\n");

    while (rota) {
        fprintf(fp, "%d;%s;%s;%f;%d;%d;%d\n",
            rota->dados_rota.codigo,
            rota->dados_rota.origem,
            rota->dados_rota.destino,
            rota->dados_rota.combustivel_necessario,
            rota->dados_rota.qtd_passageiros,
            rota->dados_rota.qtd_carga,
            rota->dados_rota.id_aeronave_voo
        );
        rota = rota->proximo;
    }

    fclose(fp);
}

void exportar_dados_rota_html(NoRota_t *rota, char *nome_arq)
{
    FILE *fp = fopen(nome_arq, "w");
    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<html><head><title>Relatorio de Rotas</title></head><body>\n");
    fprintf(fp, "<h2>Relatorio de Rotas</h2>\n");
    fprintf(fp, "<table border='1'>\n");

    fprintf(fp,
        "<tr>"
        "<th>ID</th><th>Origem</th><th>Destino</th><th>Combustivel</th>"
        "<th>Passageiros</th><th>Carga</th><th>Aeronave</th>"
        "</tr>\n"
    );

    while (rota) {
        fprintf(fp,
            "<tr>"
            "<td>%d</td><td>%s</td><td>%s</td><td>%f</td>"
            "<td>%d</td><td>%d</td><td>%d</td>"
            "</tr>\n",
            rota->dados_rota.codigo,
            rota->dados_rota.origem,
            rota->dados_rota.destino,
            rota->dados_rota.combustivel_necessario,
            rota->dados_rota.qtd_passageiros,
            rota->dados_rota.qtd_carga,
            rota->dados_rota.id_aeronave_voo
        );

        rota = rota->proximo;
    }

    fprintf(fp, "</table></body></html>\n");
    fclose(fp);
}