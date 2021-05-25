#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
/*
(i)inserir um aluno na estrutura;
(ii) consultar aluno por matrícula (dada a matrícula retorne o aluno caso ele exista)
(iii) excluir aluno por matrícula (dada a matrícula exclua o aluno caso ele exista)
(iv) exibir o conteudo da hash inteira.
*/

typedef struct HashAberta{
	LISTA **tabelaHash;
	int tamanhoAtual;
	double ocupacao;
}HASHABERTA;

void exibirHash(HASHABERTA *hash);
void inicializarHash(HASHABERTA *hash, int tamanho);
void inserirHash(HASHABERTA *hash, ALUNO *aluno);
ALUNO* consultarMatricula(HASHABERTA **hash, int matricula);
void excluirHash(HASHABERTA **hash, int matricula);

