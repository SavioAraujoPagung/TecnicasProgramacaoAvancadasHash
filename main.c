#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hash.h"


 int main(int argc, char *argv[]) {	
	HASHABERTA *hash = (HASHABERTA*) malloc(sizeof(HASHABERTA));
	inicializarHash(hash, 10);
	
	//inserindo valores na hash
	char nome[30] = "savioPagung";
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO)); //criacao do novo Aluno para colocar no NO
	aluno->matricula = 11;
	aluno->nota = 10.0;
	strcpy(aluno->nome, nome);	
	inserirHash(hash, aluno);
	
	char nomeDois[30] = "SavioAraujo";
	ALUNO *alunoDois = (ALUNO*) malloc(sizeof(ALUNO)); //criacao do novo Aluno para colocar no NO
	alunoDois->matricula = 1;
	alunoDois->nota = 10.0;
	strcpy(alunoDois->nome, nomeDois);	
	inserirHash(hash, alunoDois);
	
	char nomeTres[30] = "SavioAP";
	ALUNO *alunoTres = (ALUNO*) malloc(sizeof(ALUNO)); //criacao do novo Aluno para colocar no NO
	alunoTres->matricula = 2;
	alunoTres->nota = 10.0;
	strcpy(alunoTres->nome, nomeTres);	
	inserirHash(hash, alunoTres);
	
	char nomeQuatro[30] = "SavioA";
	ALUNO *alunoQuatro = (ALUNO*) malloc(sizeof(ALUNO)); //criacao do novo Aluno para colocar no NO
	alunoQuatro->matricula = 9;
	alunoQuatro->nota = 10.0;
	strcpy(alunoQuatro->nome, nomeQuatro);	
	inserirHash(hash, alunoQuatro);
	
	//exibindo valores da tabela hash
	exibirHash(hash);
	
	//buscando um aluno por matricula
	int matriculaParaFiltrar = 9;
	ALUNO *alunoFiltrado = (ALUNO*) malloc(sizeof(ALUNO)); 
	alunoFiltrado = consultarMatriculaHash(hash, matriculaParaFiltrar);
	
	//removendo aluno
	int matriculaParaExcluido = 2;
	excluirHash(hash, matriculaParaExcluido);
	exibirHash(hash);//exibindo valores da tabela hash apos excluir
	
	
	return 0;
}

    














