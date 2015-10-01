typedef struct no {
    float valor;
    struct pilha *prox;
}No;

typedef struct pilha{
    No* topo; 
}Pilha;

Pilha* cria (void);
No* ins_ini (No* l, float v);
No* ret_ini (No* l);
void push (Pilha* p, float v);
int vazia (Pilha* p);
float pop (Pilha* p);
void libera (Pilha* p);

Pilha* cria (void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

/* função auxiliar: insere no início */
No* ins_ini (No* l, float v) {
    No* p = (No*) malloc(sizeof(No));
    p->valor = v;
    p->prox = l;
    return p;
}

/* função auxiliar: retira do início */
No* ret_ini (No* l) {
    No* p = l->prox;
    free(l);
return p;
}
        
void push (Pilha* p, float v) {
    p->topo = ins_ini(p->topo,v);
}

int vazia (Pilha* p){
    return (p->topo == NULL);
}

float pop (Pilha* p) {
    float v;
    if (vazia(p)) {
         printf("Pilha vazia.\n");
         exit(1); /* aborta programa */
    }
    v = p->topo->valor;
    p->topo = ret_ini(p->topo);
    return v;
}

void libera (Pilha* p) { free(p); }