#ifndef atv_entrega_h
#define atv_entrega_h

typedef struct atvs Atvs;
typedef struct data Data;

void criaAtvs(Atvs *atividades);
void imprimirData(Data *dt);
Data *dataHoje(void);
void freeData(Data *data);
int atividadeConcluida(Data *dt);
void imprimirAtvs(Atvs *atividade, int t);

#endif 