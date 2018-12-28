#include<stdio.h>
#include<stdlib.h>



typedef struct lista{
    float info;
    struct lista* prox;
}Lista;

typedef struct pilha{
    Lista* prim;
}Pilha;

Pilha* cria_pilha(){
Pilha* p=(Pilha*)malloc(sizeof(Pilha));
p->prim=NULL;
return p;
}

void push(Pilha* p,float v){
    Lista* n=(Lista*)malloc(sizeof(Lista));
    n->info=v;
    n->prox=p->prim;
    p->prim=n;
}

float pop(Pilha* p){
    Lista* t;
    float v;
    if(vazia(p)){
        printf("Vazia!");
        exit(1);
    }
    t=p->prim;
    v=t->info;
    p->prim=t->prox;
    free(t);
    return v;
}

int vazia(Pilha* p){
return (p->prim == NULL);
}

void liberarPilha(Pilha* p){
    Lista* q =p->prim;
    while(q != NULL){
        Lista* t=q->prox;
        free(q);
        q=t;
    }
    free(p);
}

float topo(Pilha* p){
    if(vazia(p)){
        printf("Vazia!");
        exit(1);
    }
    return p->prim->info;
}


int main(){
Pilha* p;
p=cria_pilha();
push(p,10.0);
push(p,20.0);
push(p,30.0);
push(p,50.0);
pop(p);
printf("Topo pilha: %.2f",topo(p));
return 0;
}
