#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
/*
(i)inserir um aluno na estrutura;
(ii) consultar aluno por matrícula (dada a matrícula retorne o aluno caso ele exista)
(iii) excluir aluno por matrícula (dada a matrícula exclua o aluno caso ele exista)
(iv) exibir o conteudo da hash inteira.
*/

typedef struct HashFechada{
	LISTA **tabelaHash;
	int tamanhoAtual;
	double ocupacao;
}HASHFECHADA;

void exibirHash(HASHFECHADA *hash);
void inicializarHash(HASHFECHADA *hash, int tamanho);
void inserirHash(HASHFECHADA *hash, ALUNO *aluno);
ALUNO* consultarMatriculaHash(HASHFECHADA *hash, int matricula);
void excluirHash(HASHFECHADA *hash, int matricula);

