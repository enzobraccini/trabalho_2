#include <stdio.h>
#include "./include/menu.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/types.h"
#include "./include/uteis.h"
#include "./include/arquivos.h"

int main()
{
    NoAeronave_t *nova_aeronave = NULL;
    NoRota_t *nova_rota = NULL;

    char prefixo[MAX_AERONAVES];
    int opcao, sub_opcao;

    carregar_dados_aeronave(&nova_aeronave);
    carregar_dados_rotas(&nova_rota);

    do {
        exibir_menu();
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {

            case 1:
                do {
                    exibir_sub_menu_listar_aeronave();
                    printf("0 - Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &sub_opcao);
                    getchar();

                    switch(sub_opcao)
                    {
                        case 1: relatorio_aeronaves(nova_aeronave); break;
                        case 2: buscar_aeronave_prefixo(nova_aeronave); break;
                        case 3: listar_aeronave_fabricante(nova_aeronave); break;
                        case 4: listar_aeronave_tipo(nova_aeronave); break;
                        case 5: listar_aeronave_modelo(nova_aeronave); break;
                        case 6: listar_aeronave_ano_fabricacao(nova_aeronave); break;
                        case 7: listar_aeronave_situacao(nova_aeronave); break;
                        case 8: quantidade_manutencao(nova_aeronave); break;
                        case 9: printf("Qual o prefixo da aeronave? ");
                                fgets(prefixo, MAX_AERONAVES, stdin);
                                retirar_enter(prefixo);
                                NoAeronave_t *aux = listar_aerorecursiva(prefixo, nova_aeronave);
                                if (aux) {
                                    printf("ID....................: %i\n", aux->dados_aeronave.id);
                                    printf("Modelo................: %s\n", aux->dados_aeronave.modelo);
                                    printf("Fabricante............: %s\n", aux->dados_aeronave.fabricante);
                                    printf("Prefixo...............: %s\n", aux->dados_aeronave.prefixo);
                                    printf("Ano de fabricacao.....: %i\n", aux->dados_aeronave.ano_de_fabricacao);
                                } else {
                                    printf("Aeronave com prefixo %s, não foi encontrada\n", prefixo);
                                }
                                break;

                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while(sub_opcao != 0);
                break;

            case 2:
                cadastrar_aeronave(&nova_aeronave);
                break;

            case 3:
                do {
                    exibir_sub_menu_listar_rota();
                    printf("0 - Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &sub_opcao);
                    getchar();

                    switch(sub_opcao)
                    {
                        case 1: consultar_rota_data(nova_rota); break;
                        case 2: listar_rota_origem(nova_rota); break;
                        case 3: listar_rota_destino(nova_rota); break;
                        case 4: porcentagem_voo_aeronave(nova_rota); break;
                        case 5: porcentagem_voos_intervalo(nova_rota); break;
                        case 6: consumo_combustivel_intervalo(nova_rota); break;
                        case 7: rota_mais_passageiros(nova_rota); break;
                        case 8: rota_menos_passageiros(nova_rota); break;
                        case 0: break;
                        default: printf("Opcao invalida!\n");
                    }
                } while(sub_opcao != 0);
                break;

            case 4:
                cadastrar_rota(&nova_rota, nova_aeronave);
                break;

            case 5:
                do {
                    exibir_sub_menu_exportar();
                    scanf("%d", &sub_opcao);
                    getchar();

                    switch(sub_opcao)
                    {
                        case 1:
                            exportar_dados_aviao_csv(nova_aeronave, "aeronaves.csv");
                            printf("Arquivo aeronaves.csv gerado!\n");
                            break;

                        case 2:
                            exportar_dados_aviao_html(nova_aeronave, "aeronaves.html");
                            printf("Arquivo aeronaves.html gerado!\n");
                            break;

                        case 3:
                            exportar_dados_rota_csv(nova_rota, "rotas.csv");
                            printf("Arquivo rotas.csv gerado!\n");
                            break;

                        case 4:
                            exportar_dados_rota_html(nova_rota, "rotas.html");
                            printf("Arquivo rotas.html gerado!\n");
                            break;

                        case 0:
                            break;

                        default:
                            printf("Opcao invalida!\n");
                    }

                } while(sub_opcao != 0);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                salvar_dados_aeronave(nova_aeronave);
                salvar_dados_rotas(nova_rota);
                liberar_lista_aeronaves(nova_aeronave);
                liberar_lista_rotas(nova_rota);
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}