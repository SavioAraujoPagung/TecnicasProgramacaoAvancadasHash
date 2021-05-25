#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "Lista.h"
#include "hash.h"


 int main(int argc, char *argv[]) {	
	HASHABERTA *hash = (HASHABERTA*) malloc(sizeof(HASHABERTA));
	inicializarHash(hash, 10);
	
	char nome[30] = "savioPagung";
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO)); //criacao do novo Aluno para colocar no NO
	aluno->matricula = 0;
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
	strcpy(alunoDois->nome, nomeTres);	
	inserirHash(hash, alunoTres);
	
	char nomeQuatro[30] = "SavioA";
	ALUNO *alunoQuatro = (ALUNO*) malloc(sizeof(ALUNO)); //criacao do novo Aluno para colocar no NO
	alunoQuatro->matricula = 9;
	alunoQuatro->nota = 10.0;
	strcpy(alunoDois->nome, nomeQuatro);	
	inserirHash(hash, alunoQuatro);
	
	
	exibirHash(hash);
	
	return 0;
}

    














