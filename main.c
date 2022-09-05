#include <stdio.h>
#include <stdlib.h>

#define MAX 50

type def int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
	int valor;
} REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int numElem;
} LISTA;


void inicializarLista(LISTA* l) {
	l->numElem = 0;
}

int numElementoLista(LISTA* l) {
	return l->numElem;
}

void exibirLista(LISTA* l) {
	int i;
	
	printf("Lista: \ " ");
	
	for(i = 0; i < l->numElem; i++) {
		printf("%d ", l->A[i].chave);
	}
	printf("\"\n");
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
	int i;
	
	while (i < l->numElem) {
		if (ch == l->A[i].chave){
			return i;
		}else{
			i++;
		}
		return -1;
	}
}

bool inserirElementoLista(LISTA* l, REGISTRO reg, int i) {
	int j;
	
	if(l->numElem == MAX ) || ( i < 0 ) || (i > l->numElem){
		return false;
	} 
	
	for (j = l->numElem; j > i; j--) l->A[j] = l->A[j-1];
	l->A[i] = reg;
	l->numElem++;
	return true;
}

void inserirElementoNoInicioLista(LISTA **l, REGISTRO reg) {
	
	LISTA *aux, *novo = malloc(sizeof(LISTA));
	
	if (novo) {
		novo->A = reg;
		novo->A = *l;
		*l = novo;
		// é o primeiro?
		
		if (*l == NULL) {
			*l = novo;
		} else {
			while (aux->A) 
				aux = aux->A;
			aux->A = novo;
		}
		
	} else {
		printf("Não foi possivel inserir");
	}
	
	
}

void inserirNoFim(LISTA **l, REGISTRO reg) {
	
	LISTA *novo = malloc(sizeof(LISTA));
	
	if (novo) {
		novo->A = reg;
		novo->A = NULL;
	}
}

bool excluirElementoLista(TIPOCHAVE ch, LISTA* l) {
	int pos, j;
	pos = buscaSequencial(l, ch);
	
	if (pos == -1) {
		retun false;
	}
	
	for (j = pos; j < l->numElem; j++) 
		l->A[j] = l->A[j+1]
	l->numElem--;
	return true;
}

void reiniciarLista(LISTA* l) {
	l->numElem = 0;
}

int main(int argc, char *argv[]) {
	return 0;
}

