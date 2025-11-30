#include <stdio.h>
#include "./include/menu.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/types.h"
#include "./include/uteis.h"


int main()
{
    NoAeronave_t *nova_aeronave = NULL;
    NoRota_t *nova_rota = NULL;

    int opcao;

    do {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: cadastrar_aeronave(&nova_aeronave);
                    break;
            case 2: relatorio_aeronaves(nova_aeronave);
                    break;
            case 3: buscar_aeronave_prefixo(nova_aeronave);
                    break;
            case 4: listar_aeronave_fabricante(nova_aeronave);
                    break;
            case 5: listar_aeronave_tipo(nova_aeronave);
                    break;
            case 6: listar_aeronave_modelo(nova_aeronave);
                    break;
            case 7: listar_aeronave_ano_fabricacao(nova_aeronave);
                    break;
            case 8: listar_aeronave_situacao(nova_aeronave);
                    break;
            case 9: quantidade_manutencao(nova_aeronave);
                    break;
            case 10: cadastrar_rota(&nova_rota, nova_aeronave);
                     break;
            case 11: consultar_rota_data(nova_rota);
                     break;
            case 12: listar_rota_origem(nova_rota);
                     break;
            case 13: listar_rota_destino(nova_rota);
                     break;
            case 14: porcentagem_voo_aeronave(nova_rota);
                     break;
            case 15: porcentagem_voos_intervalo(nova_rota);
                     break;
            case 16: consumo_combustivel_intervalo(nova_rota);
                     break;
            case 17: rota_mais_passageiros(nova_rota);
                     break;
            case 18: rota_menos_passageiros(nova_rota);
                     break;
            case 0: printf("Encerrando o programa...\n");
                    liberar_lista_aeronaves(nova_aeronave);
                    liberar_lista_rotas(nova_rota);
                    break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}