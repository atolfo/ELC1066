typedef struct no {
    float valor;
    struct fila *prox;
}No;

typedef struct fila {
No* ini;
No* fim;
}Fila;

Fila* cria(void);
No* ins_fim (No* fim, float v);
No* ret_ini (No* ini);
void insere (Fila* f, float v);
float retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);


Fila* cria (void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

/* função auxiliar: insere no fim */
No* ins_fim (No* fim, float v) {
    No* p = (No*) malloc(sizeof(No));
    p->valor = v;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
        fim->prox = p;
    return p;
}

/* função auxiliar: retira do início */
No* ret_ini (No* ini) {
    No* p = ini->prox;
    free(ini);
    return p;
}

void insere (Fila* f, float v)  {
    f->fim = ins_fim(f->fim,v);
    if (f->ini==NULL) /* fila antes vazia? */
      f->ini = f->fim;
}

float retira (Fila* f) {
    float v;
    if (vazia(f)) {
        printf("Fila vazia.\n");
        exit(1); /* aborta programa */
    }
    v = f->ini->valor;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
        f->fim = NULL;
    return v;
}

int vazia (Fila* f) {
    return (f->ini==NULL);
}

void libera (Fila* f) {
    No* q = f->ini;
    while (q!=NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}