#include <stdio.h>
#include <string.h>
#include "../include/types.h"
#include "../include/cadastros.h"
#include "../include/uteis.h"

void relatorio_aeronaves(NoAeronave_t *nova_aeronave)
{
    NoAeronave_t *atual = nova_aeronave;
    int contador = 0;

    if (atual == NULL) {
        printf("\nNenhuma aeronave cadastrada.\n");
        return;
    }

    printf("\n--- RELATÓRIO DE AERONAVES ---\n");

    while(atual != NULL) {
        printf("--- Aeronave #%d ---\n", ++contador);
        printf("ID....................: %i\n", atual->dados_aeronave.id);
        printf("Modelo................: %s\n", atual->dados_aeronave.modelo);
        printf("Fabricante............: %s\n", atual->dados_aeronave.fabricante);
        printf("Prefixo...............: %s\n", atual->dados_aeronave.prefixo);
        printf("Ano de fabricacao.....: %i\n", atual->dados_aeronave.ano_de_fabricacao);
        if(atual->dados_aeronave.tipo == 1) {
            printf("Tipo..................: Carga\n");
        } else if(atual->dados_aeronave.tipo == 2) {
            printf("Tipo..................: Passageiro\n");
            printf("Numero de passageiros.: %i\n", atual->dados_aeronave.numero_passageiros);
        } else {printf("TIPO INVALIDO!!!!");}

        if(atual->dados_aeronave.situacao == 1) {
            printf("Situacao..............: Operante\n");
        } else if(atual->dados_aeronave.situacao == 2) {
            printf("Situacao..............: Manutencao\n");
        } else {printf("SITUACAO INVALIDA!!!!");}

        printf("Quantidade de manutencao: %i\n", atual->dados_aeronave.quantidade_manutencao);
        printf("Quantidade de pilotos.: %i\n", atual->dados_tripulacao.qtd_pilotos);
        printf("Quantidade de membros.: %i\n", atual->dados_tripulacao.qtd_membros);
        
        for(int k = 0; k < atual->dados_tripulacao.qtd_pilotos && k < 10; k++) {
             printf(" Piloto %d: %s\n", k + 1, atual->dados_tripulacao.nome_pilotos[k]);
        }
        for(int k = 0; k < atual->dados_tripulacao.qtd_membros && k < 20; k++) {
             printf(" Membro %d: %s\n", k + 1, atual->dados_tripulacao.nome_membros[k]);
        }
        
        printf("\n");
        atual = atual->proximo;
    }
}

void buscar_aeronave_prefixo(NoAeronave_t *nova_aeronave)
{
    char prefixo_busca[MAX_AERONAVES];
    int encontrada = 0;
    NoAeronave_t *atual = nova_aeronave;

    printf("Digite o prefixo da aeronave: ");
    fgets(prefixo_busca, MAX_AERONAVES, stdin);
    retirar_enter(prefixo_busca);

    while (atual != NULL) {
        if (strcmp(prefixo_busca, atual->dados_aeronave.prefixo) == 0) {
            printf("\nAeronave encontrada.\n");
            printf("ID.........: %i\n", atual->dados_aeronave.id);
            printf("Modelo.....: %s\n", atual->dados_aeronave.modelo);
            printf("Fabricante.: %s\n", atual->dados_aeronave.fabricante);
            encontrada = 1;
            break;
        }
        atual = atual->proximo;
    }
    if (encontrada == 0)
    {
        printf("\nAeronave nao encontrada!!\n\n");
    }
}

void listar_aeronave_fabricante(NoAeronave_t *nova_aeronave)
{
    char fabricante_busca[MAX_AERONAVES];
    int encontrada = 0;
    NoAeronave_t *atual = nova_aeronave;

    printf("Digite o fabricante:\n ");
    fgets(fabricante_busca, MAX_AERONAVES, stdin);
    retirar_enter(fabricante_busca);

    printf("\n--- AERONAVES DO FABRICANTE %s\n ---\n", fabricante_busca);

    while (atual != NULL) {
        if (strcmp(fabricante_busca, atual->dados_aeronave.fabricante) == 0) {
            printf("ID...............: %i\n", atual->dados_aeronave.id);
            printf("Modelo...........: %s\n", atual->dados_aeronave.modelo);
            printf("Ano de fabricacao: %i\n\n", atual->dados_aeronave.ano_de_fabricacao);
            encontrada = 1;
        }
        atual = atual->proximo;
    }
    if (encontrada == 0)
    {
        printf("\nNenhuma aeronave encontrada para o fabricante %s\n\n", fabricante_busca);
    }
}

void listar_aeronave_tipo(NoAeronave_t *nova_aeronave)
{
    NoAeronave_t *atual = nova_aeronave;
    printf("\n--- LISTAGEM POR TIPO ---\n");

    if (atual == NULL) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    printf("\n== Aeronaves de Carga ==\n");
    atual = nova_aeronave;
    int carga_contador = 0;
    while(atual != NULL)
    {
        if(atual->dados_aeronave.tipo == 1) {
            printf("ID: %d | Prefixo: %s\n", atual->dados_aeronave.id, atual->dados_aeronave.prefixo);
            carga_contador++;
        }
        atual = atual->proximo;
    }
    if (carga_contador == 0) {
        printf("Nenhuma aeronave de carga encontrada.\n");
    }

    printf("\n== Aeronaves de Passageiros ==\n");
    atual = nova_aeronave;
    int passageiro_contador = 0;
    while(atual != NULL)
    {
        if(atual->dados_aeronave.tipo == 2){
            printf("ID: %d | Prefixo: %s\n | Assentos: %d\n", atual->dados_aeronave.id, atual->dados_aeronave.prefixo, atual->dados_aeronave.numero_passageiros);
            passageiro_contador++;
        }
        atual = atual->proximo;
    }
    if (passageiro_contador == 0) {
        printf("Nenhuma aeronave de passageiros encontrada.\n");
        printf("\n");
    }
}

void listar_aeronave_modelo(NoAeronave_t *nova_aeronave)
{
    char modelo_busca[MAX_AERONAVES];
    NoAeronave_t *atual = nova_aeronave;
    int encontrada = 0;

    printf("Digite um modelo: ");
    fgets(modelo_busca, MAX_AERONAVES, stdin);
    retirar_enter(modelo_busca);

    printf("\n--- AERONAVES DO MODELO %s\n ---\n", modelo_busca);

    while (atual != NULL) {
        if (strcmp(modelo_busca, atual->dados_aeronave.modelo) == 0) {
            printf("ID.........: %i\n", atual->dados_aeronave.id);
            printf("Modelo.....: %s\n", atual->dados_aeronave.modelo);
            printf("Fabricante.: %s\n", atual->dados_aeronave.fabricante);
            encontrada = 1;
        }
        atual = atual->proximo;
    }

    if (encontrada == 0) {
        printf("Nenhuma aeronave encontrada para o modelo %s", modelo_busca);
    }
}

void listar_aeronave_ano_fabricacao(NoAeronave_t *nova_aeronave)
{
    int ano_busca;
    NoAeronave_t *atual = nova_aeronave;
    int encontrada = 0;

    printf("Digite um ano: ");
    scanf("%i", &ano_busca);
    getchar();

    printf("\n--- AERONAVES FABRICADAS EM %d ---\n", ano_busca);

    while(atual != NULL)
    {
        if(ano_busca == atual->dados_aeronave.ano_de_fabricacao){
            printf("ID.........: %i\n", atual->dados_aeronave.id);
            printf("Modelo.....: %s\n", atual->dados_aeronave.modelo);
            printf("Fabricante.: %s\n", atual->dados_aeronave.fabricante);
            encontrada = 1;
        }
        atual = atual->proximo;
    }

    if (encontrada == 0) {
        printf("Nenhuma aeronave encontrada para o ano %d.\n", ano_busca);
    }
}

void listar_aeronave_situacao(NoAeronave_t *nova_aeronave)
{
    NoAeronave_t *atual = nova_aeronave;
    printf("\n--- LISTAGEM POR SITUAÇÃO ---\n");

    if (atual == NULL) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    printf("\n== Aeronaves Operantes ==\n");
    atual = nova_aeronave;
    int operante_contador = 0;
    while(atual != NULL)
    {
        if(atual->dados_aeronave.situacao == 1) {
            printf("ID: %d | Prefixo: %s\n", atual->dados_aeronave.id, atual->dados_aeronave.prefixo);
            operante_contador++;
        }
        atual = atual->proximo;
    }
    if (operante_contador == 0) {
        printf("Nenhuma aeronave operante encontrada.\n");
    }

    printf("\n== Aeronaves em Manutencao ==\n");
    atual = nova_aeronave;
    int manutencao_contador = 0;
    while(atual != NULL)
    {
        if(atual->dados_aeronave.situacao == 2){
            printf("ID: %d | Prefixo: %s\n", atual->dados_aeronave.id, atual->dados_aeronave.prefixo);
            manutencao_contador++;
        }
        atual = atual->proximo;
    }
    if (manutencao_contador == 0) {
        printf("Nenhuma aeronave em manutencao encontrada.\n");
        printf("\n");
    }
}

void quantidade_manutencao(NoAeronave_t *nova_aeronave)
{
    int id_busca;
    NoAeronave_t *atual = nova_aeronave;
    int encontrada = 0;

    printf("Digite o ID da aeronave: ");
    scanf("%d", &id_busca);
    getchar();

    while (atual != NULL) {
        if (id_busca == atual->dados_aeronave.id) {
            printf("\nA aeronave ID %d entrou em manutencao %i vezes.\n\n", id_busca, atual->dados_aeronave.quantidade_manutencao);
            encontrada = 1;
            break;
        }
        atual = atual->proximo;
    }
    
    if (encontrada == 0) {
        printf("\nAeronave com ID %d nao encontrada.\n\n", id_busca);
    }
}

NoAeronave_t *listar_aerorecursiva(char prefixo[MAX_AERONAVES], NoAeronave_t *nova_aeronave)
{
    if (nova_aeronave == NULL) return NULL;

    if (strcmp(nova_aeronave->dados_aeronave.prefixo, prefixo) == 0) return nova_aeronave;

    return listar_aerorecursiva(prefixo, nova_aeronave->proximo);
}






void consultar_rota_data(NoRota_t *nova_rota)
{
    int dia, mes, ano;
    NoRota_t *atual = nova_rota;
    int encontrada = 0;

    printf("Digite o dia: \n");
    scanf("%i", &dia);
    getchar();
    printf("Digite o mes: \n");
    scanf("%i", &mes);
    getchar();
    printf("Digite o ano: \n");
    scanf("%i", &ano);
    getchar();

    printf("\n ROTAS NA DATA %d/%d/%d ---\n", dia, mes, ano);

    while(atual != NULL)
    {
        if(atual->dados_rota.data.dia == dia && atual->dados_rota.data.mes == mes && atual->dados_rota.data.ano == ano)
        {
            printf("Codigo da rota........: %i\n", atual->dados_rota.codigo);
            printf("Horario da rota.......: %d:%d\n", atual->dados_rota.horario.hora, atual->dados_rota.horario.minuto);
            printf("Local de partida......: %s\n", atual->dados_rota.origem);
            printf("Local de destino......: %s\n", atual->dados_rota.destino);
            printf("Tempo estimado........: %d:%d\n", atual->dados_rota.tempo_estimado.hora, atual->dados_rota.tempo_estimado.minuto);
            printf("Combustivel necessario: %f Litros\n", atual->dados_rota.combustivel_necessario);
            printf("Aeronave ID...........: %i\n\n", atual->dados_rota.id_aeronave_voo);
            encontrada = 1;
        }
        atual = atual->proximo;
    }

    if (encontrada == 0) {
        printf("Nenhuma rota encontrada para a data especificada.\n");
    }
}

void listar_rota_origem(NoRota_t *nova_rota)
{
    char rota_origem[MAX_ROTAS];
    NoRota_t *atual = nova_rota;
    int encontrada = 0;

    printf("Digite a origem: \n");
    fgets(rota_origem, MAX_ROTAS, stdin);
    retirar_enter(rota_origem);

    printf("\nROTAS COM ORIGEM EM %s \n\n", rota_origem);

    while(atual != NULL)
    {
        if(strcmp(rota_origem, atual->dados_rota.origem) == 0){
            printf("Codigo da rota........: %i\n", atual->dados_rota.codigo);
            printf("Data da rota..........: %d/%d/%d\n", atual->dados_rota.data.dia, atual->dados_rota.data.mes, atual->dados_rota.data.ano);
            printf("Horario da rota.......: %d:%d\n", atual->dados_rota.horario.hora, atual->dados_rota.horario.minuto);
            printf("Local de destino......: %s\n", atual->dados_rota.destino);
            printf("Tempo estimado........: %d:%d\n\n", atual->dados_rota.tempo_estimado.hora, atual->dados_rota.tempo_estimado.minuto);
            encontrada = 1;
        }
        atual = atual->proximo;
    }

    if (encontrada == 0) {
        printf("Nenhuma rota encontrada com a origem especificada.\n");
    }
}

void listar_rota_destino(NoRota_t *nova_rota)
{
    char destino_busca[MAX_ROTAS];
    NoRota_t *atual = nova_rota;
    int encontrada = 0;

    printf("Digite o destino: \n");
    fgets(destino_busca, MAX_ROTAS, stdin);
    retirar_enter(destino_busca);

    printf("\n--- ROTAS COM DESTINO EM %s ---\n", destino_busca);

    while(atual != NULL)
    {
        if(strcmp(destino_busca, atual->dados_rota.destino) == 0){
            printf("Codigo da rota........: %i\n", atual->dados_rota.codigo);
            printf("Data da rota..........: %d/%d/%d\n", atual->dados_rota.data.dia, atual->dados_rota.data.mes, atual->dados_rota.data.ano);
            printf("Horario da rota.......: %d:%d\n", atual->dados_rota.horario.hora, atual->dados_rota.horario.minuto);
            printf("Local de partida......: %s\n", atual->dados_rota.origem);
            printf("Tempo estimado........: %d:%d\n\n", atual->dados_rota.tempo_estimado.hora, atual->dados_rota.tempo_estimado.minuto);
            encontrada = 1;
        }
        atual = atual->proximo;
    }

    if (encontrada == 0) {
        printf("Nenhuma rota encontrada com o destino especificado.\n");
    }
}

void porcentagem_voo_aeronave(NoRota_t *nova_rota)
{
    int id_busca;
    float contagem_voos = 0;
    int total_rotas = contar_rotas(nova_rota);
    float porcentagem;
    NoRota_t *atual = nova_rota;

    if (total_rotas == 0) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }

    printf("Digite o ID da aeronave para calcular a porcentagem de voos: ");
    scanf("%d", &id_busca);
    getchar();

    while (atual != NULL) {
        if (atual->dados_rota.id_aeronave_voo == id_busca) {
            contagem_voos++;
        }
        atual = atual->proximo;
    }

    porcentagem = (contagem_voos / total_rotas) * 100.0;
    printf("\n--- PORCENTAGEM DE VOOS DA AERONAVE ID %d ---\n", id_busca);
    printf("Total de Rotas Cadastradas: %d\n", total_rotas);
    printf("Rotas realizadas por ID %d: %f\n", id_busca, contagem_voos);
    printf("Porcentagem de voos: %f\n\n", porcentagem);
}

void porcentagem_voos_intervalo(NoRota_t *nova_rota)
{
    data_t inicio, fim;
    float contagem_voos = 0;
    int total_rotas = contar_rotas(nova_rota);
    float porcentagem;
    NoRota_t *atual = nova_rota;

    if (total_rotas == 0) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }

    printf("Digite a data de inicio do intervalo (dd/mm/aaaa): \n");
    scanf("%d/%d/%d", &inicio.dia, &inicio.mes, &inicio.ano);
    getchar();

    printf("Digite a data de fim do intervalo (dd/mm/aaaa): \n");
    scanf("%d/%d/%d", &fim.dia, &fim.mes, &fim.ano);
    getchar();

    printf("\n--- PORCENTAGEM DE VOOS NO INTERVALO %d/%d/%d a %d/%d/%d ---\n", inicio.dia, inicio.mes, inicio.ano, fim.dia, fim.mes, fim.ano);

    while (atual != NULL) {
        data_t d = atual->dados_rota.data;
        
        long data_inicio_long = (long)inicio.ano * 10000 + inicio.mes * 100 + inicio.dia;
        long data_fim_long = (long)fim.ano * 10000 + fim.mes * 100 + fim.dia;
        long data_rota_long = (long)d.ano * 10000 + d.mes * 100 + d.dia;

        if (data_rota_long >= data_inicio_long && data_rota_long <= data_fim_long) {
            contagem_voos++;
        }
        atual = atual->proximo;
    }


    porcentagem = (contagem_voos / total_rotas) * 100.0;

    printf("Total de rotas cadastradas: %d\n", total_rotas);
    printf("Rotas no intervalo: %f\n", contagem_voos);
    printf("Porcentagem de voos: %f\n\n", porcentagem);

}

void consumo_combustivel_intervalo(NoRota_t *nova_rota)
{
    data_t inicio, fim;
    float total_consumo = 0.0;
    NoRota_t *atual = nova_rota;

    if (atual == NULL) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }

    printf("Digite a data de inicio do intervalo (dd/mm/aaaa): \n");
    scanf("%d/%d/%d", &inicio.dia, &inicio.mes, &inicio.ano);
    getchar();

    printf("Digite a data de fim do intervalo (dd/mm/aaaa): \n");
    scanf("%d/%d/%d", &fim.dia, &fim.mes, &fim.ano);
    getchar();

    printf("\n--- CONSUMO DE COMBUSTÍVEL NO INTERVALO %d/%d/%d a %d/%d/%d ---\n", inicio.dia, inicio.mes, inicio.ano, fim.dia, fim.mes, fim.ano);

    while (atual != NULL) {
        data_t d = atual->dados_rota.data;

        long data_inicio_long = (long)inicio.ano * 10000 + inicio.mes * 100 + inicio.dia;
        long data_fim_long = (long)fim.ano * 10000 + fim.mes * 100 + fim.dia;
        long data_rota_long = (long)d.ano * 10000 + d.mes * 100 + d.dia;

        if (data_rota_long >= data_inicio_long && data_rota_long <= data_fim_long) {
            total_consumo += atual->dados_rota.combustivel_necessario;
        }
        atual = atual->proximo;
    }

    printf("Consumo total: %f Litros\n\n", total_consumo);
}

void rota_mais_passageiros(NoRota_t *nova_rota)
{
    NoRota_t *atual = nova_rota;
    NoRota_t *mais_passageiros_no = NULL;
    int max_passageiros = -1;
    
    if (atual == NULL) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }
    
    while (atual != NULL) {
        if (atual->dados_rota.qtd_passageiros > max_passageiros) {
            max_passageiros = atual->dados_rota.qtd_passageiros;
            mais_passageiros_no = atual;
        }
        atual = atual->proximo;
    }

    if (mais_passageiros_no != NULL) {
        printf("\n--- ROTA COM MAIS PASSAGEIROS ---\n");
        printf("Codigo da rota...........: %i\n", mais_passageiros_no->dados_rota.codigo);
        printf("Data.....................: %d/%d/%d\n", mais_passageiros_no->dados_rota.data.dia, mais_passageiros_no->dados_rota.data.mes, mais_passageiros_no->dados_rota.data.ano);
        printf("Origem...................: %s\n", mais_passageiros_no->dados_rota.origem);
        printf("Destino..................: %s\n", mais_passageiros_no->dados_rota.destino);
        printf("Quantidade de passageiros: %i\n", mais_passageiros_no->dados_rota.qtd_passageiros);
        printf("Aeronave ID..............: %i\n\n", mais_passageiros_no->dados_rota.id_aeronave_voo);
    }
}

void rota_menos_passageiros(NoRota_t *nova_rota)
{
    NoRota_t *atual = nova_rota;
    NoRota_t *menos_passageiros_no = NULL;
    int min_passageiros = -1;
    
    if (atual == NULL) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }
    
    min_passageiros = atual->dados_rota.qtd_passageiros;
    menos_passageiros_no = atual;
    atual = atual->proximo;

    while (atual != NULL) {
        if (atual->dados_rota.qtd_passageiros < min_passageiros) {
            min_passageiros = atual->dados_rota.qtd_passageiros;
            menos_passageiros_no = atual;
        }
        atual = atual->proximo;
    }

    if (menos_passageiros_no != NULL) {
        printf("\n--- ROTA COM MENOS PASSAGEIROS ---\n");
        printf("Codigo da Rota...........: %i\n", menos_passageiros_no->dados_rota.codigo);
        printf("Data.....................: %d/%d/%d\n", menos_passageiros_no->dados_rota.data.dia, menos_passageiros_no->dados_rota.data.mes, menos_passageiros_no->dados_rota.data.ano);
        printf("Origem...................: %s\n", menos_passageiros_no->dados_rota.origem);
        printf("Destino..................: %s\n", menos_passageiros_no->dados_rota.destino);
        printf("Quantidade de Passageiros: %i\n", menos_passageiros_no->dados_rota.qtd_passageiros);
        printf("Aeronave ID..............: %i\n\n", menos_passageiros_no->dados_rota.id_aeronave_voo);
    }
}
