struct item{
    int chave;
    // demais campos
};
struct pilha{
    Item item[MAXTAM];
    int topo;
};

Pilha *criaPilhaVazia(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int pilhaCheia(Pilha *p){
    return p->topo == MAXTAM-1;
}

void empilha(Pilha *p, int chave){
    if (pilhaCheia(p)){
        printf("Erro: Pilha cheia...!\n");
    }else{
        Item novoItem;
        novoItem.chave = chave;
        p->topo++;
        p->item[p->topo] = novoItem;
    }
}
void imprimePilha(Pilha *p){
    int tam = p->topo;
    int i;
    for(i = tam; i >= 0; i--){
        printf("Chave: %d\n",p->item[i].chave);
    }
}
void desempilha(Pilha *p){
    if(pilhaVazia(p)){
        printf("Erro: Pilha vaiza");
    }else{
        p->topo--;
    }
}
int pilhaVazia(Pilha *p){
    return p->topo == -1;
}

void liberaPilha(Pilha *p){
    free(p);
}