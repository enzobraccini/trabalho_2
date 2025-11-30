#ifndef TYPES_H
#define TYPES_H

#define MAX_AERONAVES 50
#define MAX_ROTAS 50

typedef struct aeronave{
    int id;
    char modelo[MAX_AERONAVES];
    char fabricante[MAX_AERONAVES];
    char prefixo[MAX_AERONAVES];
    int ano_de_fabricacao;
    int tipo;
    int numero_passageiros;
    int situacao;
    int quantidade_manutencao;
} aeronave_t;

typedef struct tripulacao {
    int qtd_pilotos;
    int qtd_membros;
    char nome_pilotos[10][MAX_ROTAS];
    char nome_membros[20][MAX_ROTAS];
} tripulacao_t;

typedef struct data{
    int dia;
    int mes;
    int ano;
} data_t;

typedef struct horario{
    int hora;
    int minuto;
} horario_t;

typedef struct rota {
    int codigo;
    data_t data;
    horario_t horario;
    char origem[MAX_ROTAS];
    char destino[MAX_ROTAS];
    horario_t tempo_estimado;
    float combustivel_necessario;
    int qtd_passageiros;
    int qtd_carga;
    int id_aeronave_voo;
} rota_t;

typedef struct NoAeronave {
    aeronave_t dados_aeronave;
    tripulacao_t dados_tripulacao;
    struct NoAeronave *proximo;
} NoAeronave_t;

typedef struct NoRota {
    rota_t dados_rota;
    struct NoRota *proximo;
} NoRota_t;

#endif