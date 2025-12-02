#include "../include/uteis.h"
#include "../include/types.h"
#include <stdlib.h>
#include <stdio.h>

int contar_aeronaves(NoAeronave_t *nova) {
    int contador = 0;
    NoAeronave_t *atual = nova;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

int contar_rotas(NoRota_t *nova) {
    int contador = 0;
    NoRota_t *atual = nova;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void liberar_lista_aeronaves(NoAeronave_t *nova) {
    NoAeronave_t *atual = nova;
    NoAeronave_t *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void liberar_lista_rotas(NoRota_t *nova) {
    NoRota_t *atual = nova;
    NoRota_t *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void mostrar_dados_aeronave(aeronave_t *aviao, FILE *fp)
{
    fprintf(fp, "ID....................: %i\n", aviao->id);
    fprintf(fp, "Modelo................: %s", aviao->modelo);
    fprintf(fp, "Fabricante............: %s", aviao->fabricante);
    fprintf(fp, "Prefixo...............: %s", aviao->prefixo);
    fprintf(fp, "Ano de fabricacao.....: %i\n", aviao->ano_de_fabricacao);
    fprintf(fp, "Tipo..................: %i\n", aviao->tipo);
    fprintf(fp, "Numero de passageiros.: %i\n", aviao->numero_passageiros);
    fprintf(fp, "Situacao..............: %i\n", aviao->situacao);
}

void mostrar_dados_rota(rota_t *rota, FILE *fp)
{
    fprintf(fp, "Codigo..................: %i\n", rota->codigo);
    fprintf(fp, "Data....................: %i/%i/%i\n", rota->data.dia, rota->data.mes, rota->data.ano);
    fprintf(fp, "Horario.................: %i:%i\n", rota->horario.hora, rota->horario.minuto);
    fprintf(fp, "Origem..................: %s", rota->origem);
    fprintf(fp, "Destino.................: %s", rota->destino);
    fprintf(fp, "Tempo estimado..........: %i:%i\n", rota->tempo_estimado.hora, rota->tempo_estimado.minuto);
    fprintf(fp, "Combustivel necessario..: %f\n", rota->combustivel_necessario);
    fprintf(fp, "Quantidade passageiros..: %i\n", rota->qtd_passageiros);
    fprintf(fp, "quantidade de carga.....: %i\n", rota->qtd_carga);
    fprintf(fp, "ID da aeronave..........: %i\n", rota->id_aeronave_voo);

}
