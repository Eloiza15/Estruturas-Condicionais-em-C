#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//Sistema de gestão de notas de alunos.

int main (){
	int opcao=0;
	printf ("Carregando o sistema... aguarde");
	Sleep (500);
	
	while ((opcao != 1) && (opcao != 2) && (opcao != 3)){
	system ("cls");
	printf ("Bem vindo ao meu sistema\n\n");
	printf ("MENU\n");
	printf ("----\n");
	printf ("1- Cadastro de Notas/Alunos\n");
	printf ("2- Alteracao de Notas/Alunos\n");
	printf ("3- Sair\n");
	printf ("Opcao: ");
	scanf ("%i", &opcao);
	}
	
	return 0;
}
