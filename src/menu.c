#include "../include/menu.h"
#include <stdio.h>

void exibir_menu(void)
{
    printf("\n--------------- MENU PRINCIPAL ---------------\n");
    printf("1 - Menu de Aeronaves\n");
    printf("2 - Cadastrar Aeronave\n");
    printf("3 - Menu de Rotas\n");
    printf("4 - Cadastrar Rota\n");
    printf("5 - Exportar dados\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void exibir_sub_menu_listar_aeronave()
{
    printf("1 - Relatório de aeronaves.....................:\n");
    printf("2 - Buscar aeronave por prefixo................:\n");
    printf("3 - Listar aeronave por fabricante.............:\n");
    printf("4 - Listar aeronave por tipo...................:\n");
    printf("5 - listar aeronave por modelo.................:\n");
    printf("6 - Listar aeronave por ano de fabricação......:\n");
    printf("7 - Listar aeronave por situação...............:\n");
    printf("8 - Vezes que uma aeronave esteve em manutenção:\n");
    printf("9 - Listar aeronave por prefixo (Recursiva)....:\n");
}

void exibir_sub_menu_listar_rota()
{
    printf("1 - Consultar rota por data...................:\n");
    printf("2 - Listar rota por origem....................:\n");
    printf("3 - Listar rota por destino...................:\n");
    printf("4 - Porcentagem de voo de uma aeronave........:\n");
    printf("5 - Porcentagem de voos em um intervalo.......:\n");
    printf("6 - Consumo de combustivel em um intervalo....:\n");
    printf("7 - Rota com mais passageiros.................:\n");
    printf("8 - Rota com menos passageiros................:\n");

}

void exibir_sub_menu_exportar()
{
    printf("\n------------- EXPORTAR DADOS -------------\n");
    printf("1 - Exportar aeronaves (CSV)\n");
    printf("2 - Exportar aeronaves (HTML)\n");
    printf("3 - Exportar rotas (CSV)\n");
    printf("4 - Exportar rotas (HTML)\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
}