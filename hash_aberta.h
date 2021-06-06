#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

typedef struct NoHash{
	ALUNO *aluno;
	int continuar;
	int tamanho;
}NOHASH;
 
typedef struct HashAberta{
	NOHASH **tabelaHash;
	double expansao;
	double fatorCarga;
	double tamanho;
	double quantidade;
	int indiceMaior;
}HASHABERTA;
 
void inicializar(HASHABERTA *hash, double tamanhoInicial, double fatorCarga, double expansao);
void exibirHashAberta(HASHABERTA *hash);
void exibirInformacoesHashAberta(HASHABERTA *hash);
HASHABERTA* inserirHashAberta(HASHABERTA *hash, ALUNO *aluno);
HASHABERTA* expansao(HASHABERTA *hash);
ALUNO* consultarMatriculaHashAberta(HASHABERTA *hash, int matricula);
void finalizarHashAberta(HASHABERTA *hash);
HASHABERTA* excluirAlunoHashAberta(HASHABERTA *hash, int matricula);



