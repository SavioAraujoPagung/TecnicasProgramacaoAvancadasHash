#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "hash_aberta.h"


 int main(int argc, char *argv[]) {	
 	setlocale(LC_ALL, "Portuguese");
 	
	HASHABERTA *hash = (HASHABERTA*) malloc(sizeof(HASHABERTA*));
	inicializar(hash, 7.0, 0.8, 3.0);
	
	ALUNO* aluno = (ALUNO*) malloc(sizeof(ALUNO*));
	aluno->matricula = 87;
	aluno->nota = 9.8;
	inserirHashAberta(hash, aluno);
	exibirHashAberta(hash);
	
	//exibirInformacoesHashAberta(hash);
	//hash = expansao(hash);
	//printf("apos expandir\n");
	//exibirInformacoesHashAberta(hash);
	
	return 0;
}

    














