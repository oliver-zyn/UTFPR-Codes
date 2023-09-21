typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct livrocaixa {
    char situacao;
    Data dataLancamento;
    char tipoLancamento;
    char historicoLancamento[36];
    float valorLancamento;
} LivroCaixa;

