#include <stdio.h>
#include <stdlib.h>
#include "../include/types.h"
#include "../include/cadastros.h"
#include "../include/uteis.h"

int cadastrar_aeronave(NoAeronave_t **nova_aeronave)
{
    NoAeronave_t *novo_no = (NoAeronave_t *)malloc(sizeof(NoAeronave_t));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria para a aeronave.\n");
        return 0;
    }

    int i = 0, j = 0;

    printf("Digite o ID: \n");
    scanf("%i", &novo_no->dados_aeronave.id);
    getchar();

    printf("Digite o modelo: \n");
    fgets(novo_no->dados_aeronave.modelo, MAX_AERONAVES, stdin);
    retirar_enter(novo_no->dados_aeronave.modelo);

    printf("Digite o fabricante: \n");
    fgets(novo_no->dados_aeronave.fabricante, MAX_AERONAVES, stdin);
    retirar_enter(novo_no->dados_aeronave.fabricante);

    printf("Digite o prefixo: \n");
    fgets(novo_no->dados_aeronave.prefixo, MAX_AERONAVES, stdin);
    retirar_enter(novo_no->dados_aeronave.prefixo);

    printf("Digite o ano de fabricacao: \n");
    scanf("%i", &novo_no->dados_aeronave.ano_de_fabricacao);

    printf("Digite se a aeronave eh, 1 = carga | 2 = passageiro \n");
    while(i == 0) {
        scanf("%i", &novo_no->dados_aeronave.tipo);
        if(novo_no->dados_aeronave.tipo == 1)
        {
            novo_no->dados_aeronave.numero_passageiros = 0;
            i = 1;
        } else if(novo_no->dados_aeronave.tipo == 2) {
            printf("Digite o numero de passageiros: \n");
            scanf("%i", &novo_no->dados_aeronave.numero_passageiros);
            i = 1;
        } else {
            printf("Opcao invalida!!! Tente novamente.\n");
        }
    }

    printf("Digite a condicao da aeronave, 1 = operante | 2 = manutencao \n");
    while( j == 0) {
        scanf("%i", &novo_no->dados_aeronave.situacao);
        if (novo_no->dados_aeronave.situacao == 1 || novo_no->dados_aeronave.situacao == 2){
            j = 1;
        } else {
            printf("Opcao invalida!!! Tente novamente.\n");
        }
    }

    printf("Digite quantas vezes a aeronave entrou em manutencao \n");
    scanf("%i", &novo_no->dados_aeronave.quantidade_manutencao);
    getchar();

    printf("Digite a quantidade de pilotos: \n");
    scanf("%i", &novo_no->dados_tripulacao.qtd_pilotos);
    
    printf("Digite a quantidade de membros da comissaria: \n");
    scanf("%i", &novo_no->dados_tripulacao.qtd_membros);
    getchar();

    if (novo_no->dados_tripulacao.qtd_pilotos > 0) {
        printf("Digite o nome dos %d pilotos (um por linha):\n", novo_no->dados_tripulacao.qtd_pilotos);
        for(int k = 0; k < novo_no->dados_tripulacao.qtd_pilotos && k < 10; k++)
        {
            printf("Piloto %d: ", k + 1);
            fgets(novo_no->dados_tripulacao.nome_pilotos[k], MAX_ROTAS, stdin);
            retirar_enter(novo_no->dados_tripulacao.nome_pilotos[k]);
        }
    }

    if (novo_no->dados_tripulacao.qtd_membros > 0) {
        printf("Digite o nome dos %d membros da comissaria (um por linha):\n", novo_no->dados_tripulacao.qtd_membros);
        for(int k = 0; k < novo_no->dados_tripulacao.qtd_membros && k < 20; k++)
        {
            printf("Membro %d: ", k + 1);
            fgets(novo_no->dados_tripulacao.nome_membros[k], MAX_ROTAS, stdin);
            retirar_enter(novo_no->dados_tripulacao.nome_membros[k]);
        }
    }

    novo_no->proximo = *nova_aeronave;
    *nova_aeronave = novo_no;

    printf("\nAeronave cadastrada com sucesso!\n");
    return 1;
}

int cadastrar_rota(NoRota_t **nova_rota, NoAeronave_t *nova_aeronave)
{
    NoRota_t *novo_no = (NoRota_t *)malloc(sizeof(NoRota_t));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria para a rota.\n");
        return 0;
    }

    int id_confirmacao = 0;
    int id = 0;
    NoAeronave_t *ponteiro_aeronave = NULL;

    printf("Digite o codigo da rota: \n ");
    scanf("%i", &novo_no->dados_rota.codigo);

    printf("Digite a data da Rota: 'Exemplo 00/00/0000'\n ");
    scanf("%d/%d/%d", &novo_no->dados_rota.data.dia, &novo_no->dados_rota.data.mes, &novo_no->dados_rota.data.ano);

    printf("Digite o horario da rota: 'Exemplo 00:00'\n ");
    scanf("%d:%d", &novo_no->dados_rota.horario.hora, &novo_no->dados_rota.horario.minuto);
    getchar();

    printf("Digite o local de partida da rota:\n ");
    fgets(novo_no->dados_rota.origem, MAX_ROTAS, stdin);
    retirar_enter(novo_no->dados_rota.origem);

    printf("Digite o local de destino da rota:\n ");
    fgets(novo_no->dados_rota.destino, MAX_ROTAS, stdin);
    retirar_enter(novo_no->dados_rota.destino);

    printf("Digite o tempo estimado da rota: 'Exemplo 00:00'\n ");
    scanf("%d:%d", &novo_no->dados_rota.tempo_estimado.hora, &novo_no->dados_rota.tempo_estimado.minuto);

    printf("Digite a quantidade de combustivel necessaria:\n ");
    scanf("%f", &novo_no->dados_rota.combustivel_necessario);

    printf("Digite a quantidade de passageiros transportados:\n ");
    scanf("%i", &novo_no->dados_rota.qtd_passageiros);

    printf("Digite a quantidade de carga transportada:\n ");
    scanf("%i", &novo_no->dados_rota.qtd_carga);

    while(id_confirmacao != 1) {
        printf("Digite o ID da aeronave que ira fazer a rota:\n ");
        scanf("%i", &id);
    
        NoAeronave_t *atual_aeronave = nova_aeronave;
        while(atual_aeronave != NULL)
        {
            if(id == atual_aeronave->dados_aeronave.id)
            {
                novo_no->dados_rota.id_aeronave_voo = id;
                id_confirmacao = 1;
                ponteiro_aeronave = atual_aeronave;
                break;
            }
            atual_aeronave = atual_aeronave->proximo;
        }

        if (id_confirmacao == 0) {
            printf("ID da aeronave nao encontrado. Tente novamente.\n");
        }
    }
    
    novo_no->proximo = *nova_rota;
    *nova_rota = novo_no;

    printf("\nRota cadastrada com sucesso!\n");
    return 1;
}