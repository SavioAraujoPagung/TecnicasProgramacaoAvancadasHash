#include <stdio.h>
#include <stdlib.h>
/*
(i)inserir um aluno na estrutura;
(ii) consultar aluno por matrícula (dada a matrícula retorne o aluno caso ele exista)
(iii) excluir aluno por matrícula (dada a matrícula exclua o aluno caso ele exista)
(iv) exibir o conteúdo da hash inteira.
*/
typedef struct Aluno{
	char nome[30];
	int matricula;
	double nota;
	int posicao;
}ALUNO;

typedef struct No{
	struct No *proximo;
	struct No *anterior;
	ALUNO *aluno;
}NO;

typedef struct lista{
	NO *inicio;
	NO *fim;
	int tamanho;
}LISTA;

void inicializarLista(LISTA *lista);
int listaVazia(LISTA *lista);
void exibir(LISTA *lista);
void inserirLista(LISTA *lista, ALUNO *aluno);
int excluir(LISTA *lista, int matricula);
ALUNO *consultarPorMatriculaLista(LISTA *lista, int matricula);













