#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include <unistd.h>
#include <windows.h>

//SISTEMA DE GESTÃO DE NOTAS

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("Carregando o sistema, por favor aguarde...\n");
    //sleep(3);
    Sleep(500);

    int opcao = 0;
    char nome[100];

    float nota1, nota2, nota3, nota4;
    float soma, media;

    do {
        system("cls");
        printf("\nMENU:\n");
        printf("------\n");
        printf("1- Cadastro de Notas\n ");
        printf("2- Alteração de Notas\n");
        printf("3- Sair\n\n");
        printf("Escolha uma opção:\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                printf("\nCadastro de Notas\n\n\n");

                printf("Digite as 4 notas do aluno (elas devem ser de 0 a 10)\n");

                soma = 0;
                for (int i = 0; i < 5; i++) {
                    printf("\n\nAluno %d: \n", i + 1);
                    printf("Qual é o nome do aluno(a):", i + 1);
                    scanf("%s", &nome);
                    do {
                        printf("Nota 1: ");
                        scanf("%f", &nota1);
                        if (nota1 < 0 || nota1 > 10) {
                            printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                        }
                    } while (nota1 < 0 || nota1 > 10);
                    
                    do {
                        printf("Nota 2: ");
                        scanf("%f", &nota2);
                        if (nota2 < 0 || nota2 > 10) {
                            printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                        }
                    } while (nota2 < 0 || nota2 > 10);
                    
                    do {
                        printf("Nota 3: ");
                        scanf("%f", &nota3);
                        if (nota3 < 0 || nota3 > 10) {
                            printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                        }
                    } while (nota3 < 0 || nota3 > 10);
                    
                    do {
                        printf("Nota 4: ");
                        scanf("%f", &nota4);
                        if (nota4 < 0 || nota4 > 10) {
                            printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                        }
                    } while (nota4 < 0 || nota4 > 10);

                    soma = nota1 + nota2 + nota3 + nota4;
                    media = soma / 4;

                    printf("Soma das notas: %.2f\n", soma);
                    printf("Média das notas: %.2f\n", media);

                    if (media >= 6) {
                        printf("Situação: APROVADO\n");
                    } else if (media < 4) {
                        printf("Situação: REPROVADO\n");
                    } else {
                        printf("Situação: RECUPERAÇÃO\n");
                    }
                }
				system("pause");
                break;

            case 2:
                system("cls");
                printf("\nAlteração de Notas\n\n\n");

                int aluno;
                printf("Digite o número do aluno que deseja alterar as notas (1 a 5):\n\n ");
                scanf("%d", &aluno);

                if (aluno < 1 || aluno > 5) {
                    printf("Número de aluno inválido.\n\n");
                    system("pause");
                    break;
                }

                printf("Digite as novas notas do aluno %d:\n\n", aluno);

                do {
                    printf("Nota 1: ");
                    scanf("%f", &nota1);
                    if (nota1 < 0 || nota1 > 10) {
                        printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                    }
                } while (nota1 < 0 || nota1 > 10);
                
                do {
                    printf("Nota 2: ");
                    scanf("%f", &nota2);
                    if (nota2 < 0 || nota2 > 10) {
                        printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                    }
                } while (nota2 < 0 || nota2 > 10);
                
                do {
                    printf("Nota 3: ");
                    scanf("%f", &nota3);
                    if (nota3 < 0 || nota3 > 10) {
                        printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                    }
                } while (nota3 < 0 || nota3 > 10);
                
                do {
                    printf("Nota 4: ");
                    scanf("%f", &nota4);
                    if (nota4 < 0 || nota4 > 10) {
                        printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                    }
                } while (nota4 < 0 || nota4 > 10);

                soma = nota1 + nota2 + nota3 + nota4;
                media = soma / 4;

                printf("\nNova soma das notas: %.2f\n", soma);
                printf("Nova média das notas: %.2f\n", media);

                if (media >= 6) {
                    printf("Nova Situação: APROVADO\n");
                } else if (media < 4) {
                    printf("Nova Situação: REPROVADO\n");
                } else {
                    printf("Nova Situação: RECUPERAÇÃO\n");
                }
	            system("pause");
                break;

            case 3:
                printf("Você Saiu do Programa!\n");
                break;

            default:
                printf("Opção Inválida!\n");
                system("pause");
        }

    } while (opcao != 3);

    return 0;
}
