struct item{
    int chave;
};

struct fila{
    Item item[MAXTAM];
    int primeiro;
    int ultimo;
    int tamanho;
};
Fila *criaFilaVazia(){
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}
int filaCheia(Fila *f){
    return f->tamanho == MAXTAM;
}
void enfileira(Fila *f, int chave){
    if (filaCheia(f)){
        printf("Erro: Fila cheia!");
    }else{
        Item novoitem;
        novoitem.chave = chave;
        f->item[f->ultimo] = novoitem;
        f->ultimo = (f->ultimo+1) % MAXTAM;
        f->tamanho++;
    }
}
void imprimeFila(Fila *f){
    int t, i;
    i = f->primeiro;
    for(t = 0; t < f->tamanho; t++){
        printf("Chave: %d\n",f->item[i].chave);
        i = (i+1) % MAXTAM;
    }
}
void desinfileira(Fila *f){
    if (filaVazia(f)){
        printf("Erro: Fila vazia!");
    }else{
        f->primeiro = (f->primeiro + 1) % MAXTAM;
        f->tamanho--;
    }
}
int filaVazia(Fila *f){
    return f->tamanho == 0;
}
void liberaFila(Fila *f){
    free(f);
}