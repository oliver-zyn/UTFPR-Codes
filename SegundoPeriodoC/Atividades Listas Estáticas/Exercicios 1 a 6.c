// Declaração:

#define MAXTAM 100
typedef struct item Item;
typedef struct lista Lista;

// Definição: 

struct item {
    int chave;
};

struct lista {
    Item item[MAXTAM];
    int ultimo;
};

// Funções Básicas das Listas Estáticas:

Lista * criarLista() {
    Lista *l = malloc(sizeof(Lista));
    l->ultimo = -1;
    return l;
}

int verificarListaCheia(Lista *l) {
    return l->ultimo == MAXTAM - 1;
}

int verificarListaVazia(Lista *l) {
    return l->ultimo == -1;
}

void adicionarItemNoFinal(Lista *l, int Chave) {
    if (verificarListaCheia(l)) {
        printf("Erro, lista cheia.");
        return;
    }
    Item item_novo;
    item_novo.chave = Chave;
    l->ultimo++;
    l->item[l->ultimo] = item_novo; 
}

void imprimirLista(Lista *l) {
    for(int i = 0; i <= l->ultimo; i++) {
        printf("Chave: %d\n", l->item[i].chave);
    }
}

int retornarPosicaoItem(Lista *l, int chave) {
    int i = 0;
    while(i <= l->ultimo && l->item[i].chave != chave) {
        i++;
    }
    if(i <= l->ultimo) {
        return i;
    } else {
        return -1;
    }
}

void removeItemEmLista(Lista *l, int chave) {
    int posicao = 0;
    posicao = retornarPosicaoItem(l, chave);
    if(posicao == -1) {
        printf("Erro, posicao inválida.");
        return;
    }
    for(int i = posicao; i < l->ultimo; i++) {
        l->item[i] = l->item[i + 1];
    }
    l->ultimo--;
}

// Exercicio 1:

void adicionaItemEmLista(Lista *l, int posicao, int chave) {
    if(posicao < 0 || posicao > l->ultimo) {
        printf("Erro, posicao inválida.");
        return;
    }
    for(int i = posicao; i < l->ultimo; i++) {
        l->item[i + 1] = l->item[i];
    }
    //
    l->item[posicao].chave = chave;
    //
    l->ultimo++;
}

void liberaLista(Lista *l) {
    free(l);
}

// Exercicio 2:

void inserirItemOrdenado(Lista *l, int chave) {
    if (verificarListaCheia(l)) {
        printf("Erro, lista cheia.");
        return;
    }

    int posicao = 0;
    while (posicao <= l->ultimo && l->item[posicao].chave < chave) {
        posicao++;
    }
    // Move os itens para abrir espaço para o novo item
    for (int i = l->ultimo; i >= posicao; i--) {
        l->item[i + 1] = l->item[i];
    }
    // Insere o novo item na posição correta
    l->item[posicao].chave = chave;
    l->ultimo++;
}

// Exercicio 3:

void adicionarItemNoFinal(Lista *l, int Chave) {
    if (verificarListaCheia(l)) {
        printf("Erro, lista cheia.");
        return;
    }
    for(int i = 0; i <= l->ultimo; i++) {
        if (Chave == l->item[i].chave) {
            printf("Erro, chave repetida.");
            return;
        }
    }
    Item item_novo;
    item_novo.chave = Chave;
    l->ultimo++;
    l->item[l->ultimo] = item_novo; 
}

// Exercicio 4:

void copiaLista(Lista *lVazia, Lista *lCheia) {
    if (!verificarListaVazia(lCheia)) {
        for(int i = 0; i <= lCheia->ultimo; i++) {
            lVazia->item[i] = lCheia->item[i];
        }
    }
}

// Exercicio 5:

void intersecaoListas(Lista *l1, Lista *l2, Lista *Intersect) {
    int i, y;
    
    if (!verificarListaVazia(l1) && !verificarListaVazia(l2)) {
        for (i = 0; i <= l1->ultimo; i++) {
            for (y = 0; y <= l2->ultimo; y++) {
                if (l1->item[i].chave == l2->item[y].chave) {
                    if (!verificarListaCheia(Intersect)) {
                        Intersect->item[++Intersect->ultimo] = l1->item[i];
                    } else {
                        printf("Erro, lista Intersect cheia.");
                        return;
                    }
                }
            }
        }
    }
}

// Exercicio 6:

void uniaoListas(Lista *l1, Lista *l2, Lista *Uniao) {
    int i, y;
    
    for (i = 0; i <= l1->ultimo; i++) {
        int chave = l1->item[i].chave;
        int jaExiste = 0; 
        
        for (y = 0; y <= Uniao->ultimo; y++) {
            if (Uniao->item[y].chave == chave) {
                jaExiste = 1;
                break;
            }
        }
        
        if (!jaExiste) {
            if (!verificarListaCheia(Uniao)) {
                Uniao->item[++Uniao->ultimo].chave = chave;
            } else {
                printf("Erro, lista União cheia.");
                return;
            }
        }
    }
    
    for (i = 0; i <= l2->ultimo; i++) {
        int chave = l2->item[i].chave;
        int jaExiste = 0;

        for (y = 0; y <= Uniao->ultimo; y++) {
            if (Uniao->item[y].chave == chave) {
                jaExiste = 1;
                break; 
            }
        }
    
        if (!jaExiste) {
            if (!verificarListaCheia(Uniao)) {
                Uniao->item[++Uniao->ultimo].chave = chave;
            } else {
                printf("Erro, lista União cheia.");
                return;
            }
        }
    }
}

