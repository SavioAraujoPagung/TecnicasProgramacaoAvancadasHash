#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
 //(i)inserir um aluno na estrutura; 
 //(ii) consultar aluno por matrícula (dada a matrícula retorne o aluno caso ele exista); 
 //(iii) excluir aluno por matrícula (dada a matrícula exclua o aluno caso ele exista); 
 //(iv) exibir o conteúdo da hash inteira.
 
typedef struct NoHash{
	ALUNO *aluno;
	int continuar;
}NOHASH;
 
typedef struct HashAberta{
	NOHASH **tabelaHash;
	double expansao;
	double fatorCarga;
	double tamanho;
	double quantidade;
}HASHABERTA;
 
void inicializar(HASHABERTA *hash, double tamanhoInicial, double fatorCarga, double expansao);
void exibirHashAberta(HASHABERTA *hash);
void exibirInformacoesHashAberta(HASHABERTA *hash);
void inserirHashAberta(HASHABERTA *hash, ALUNO *aluno);
HASHABERTA* expansao(HASHABERTA *hash);
ALUNO* consultarMatriculaHashAberta(HASHABERTA *hash, int matricula);
void excluirHash(HASHABERTA *hash, int matricula);



