#ifndef ATIVIDADESEXT_H
#define ATIVIDADESEXT_H

typedef struct data Data;
typedef struct atividade Atividade;

void cadastrarAtividade(Atividade *atividade);
void imprimirData(Data *dt);
void liberarData(Data *dt);
Data *dataHoje(void);
int atividadeConcluida(Data *dt);
void imprimirAtividades(Atividade *atividades, int t);

#endif
