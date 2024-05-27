#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

//Sistema de gestão de notas de alunos.

// Estrutura do aluno
struct Aluno {
    char nome[50];
    float notas[4];
    float nota_total;
    float media;
    char resultado[50];
};

int quantidade_alunos = 5;

// Função para calcular a nota total e a média de cada aluno
void calcular_as_notas(struct Aluno alunos[], int quantidade){
	int i=0, j=0;
    for (i = 0; i < quantidade; i++){
        alunos[i].nota_total = 0;
        for (j = 0; j < 4; j++){
            alunos[i].nota_total += alunos[i].notas[j];
        }
        alunos[i].media = alunos[i].nota_total / 4;
    }
}

// Função para calcular a situação do aluno
void situacao_do_aluno(struct Aluno alunos[], int quantidade){
	int i = 0;
    for (i = 0; i < quantidade; i++) {
        if (alunos[i].media < 4) {
            strcpy(alunos[i].resultado, "Reprovado");
        } else if (alunos[i].media >= 4 && alunos[i].media < 6) {
            strcpy(alunos[i].resultado, "Recuperação");
        } else {
            strcpy(alunos[i].resultado, "Aprovado");
        }
    }
}

// Função para exibir as informações do aluno
void exibir_as_informacoes(struct Aluno alunos[], int quantidade){
	int i=0, j=0;
    for (i = 0; i < quantidade; i++) {
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Notas: ");
        for (j=0; j < 4; j++){
            printf("%.2f, ", alunos[i].notas[j]);
        }
        printf("Nota total: %.2f\n", alunos[i].nota_total);
        printf("Média: %.2f\n", alunos[i].media);
        printf("Situação do aluno: %s\n\n", alunos[i].resultado);
    }
}

void cadastro_das_notas(struct Aluno alunos[], int quantidade) {
    system("cls");
    printf("Cadastro de Notas/Alunos\n");
    int i=0, j=0;
    for (i = 0; i < quantidade; i++){
        printf("Digite o nome do aluno - %d\n", (i+1));
        scanf("%s", alunos[i].nome);
        printf("\n");
        for (j = 0; j < 4; j++){
            float nota;
            do {
                printf("Digite a nota %d do aluno %s: ", j + 1, alunos[i].nome);
                scanf("%f", &nota);
                if (nota < 0 || nota > 10){
                    printf("Nota inválida! Por favor, digite uma nota com o valor entre 0 e 10.\n");
                }
            } while (nota < 0 || nota > 10);
            alunos[i].notas[j] = nota;
        }
        printf("\n");
    }
    printf("\n");
    calcular_as_notas(alunos, quantidade);
    situacao_do_aluno(alunos, quantidade);
    exibir_as_informacoes(alunos, quantidade);
    system("pause");
    return;
}

void alteracao_notas(struct Aluno alunos[], int quantidade) {
    system("cls");
    printf("Alteração de Notas/Alunos\n");
    char nome_aluno[50];
    printf("Digite o nome do aluno que deseja alterar o resultado: ");
    scanf("%s", nome_aluno);

    int encontrado = 0;
    int i = 0;
    for (i = 0; i < quantidade; i++) {
        if (strcmp(alunos[i].nome, nome_aluno) == 0) {
            encontrado = 1;
            printf("Situação atual do aluno %s: %s\n", alunos[i].nome, alunos[i].resultado);
            printf("Digite o novo resultado para o aluno %s (Aprovado, Reprovado, Recuperação): ", alunos[i].nome);
            scanf("%s", alunos[i].resultado);
            printf("Resultado do aluno %s alterado para: %s\n", alunos[i].nome, alunos[i].resultado);
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }

    system("pause");
    return;
}

int main() {
    struct Aluno alunos[5];
    setlocale(LC_ALL, "");

    int opcao = 0;
    printf("Carregando o sistema... aguarde\n");
    Sleep(500);

    while (opcao != 3) {
        system("cls");
        printf("Bem vindo ao menu do programa\n\n");
        printf("Menu\n");
        printf("----\n");
        printf("1 - Cadastro de Notas/Alunos\n");
        printf("2 - Alteração de Notas/Alunos\n");
        printf("3 - Sair\n\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastro_das_notas(alunos, quantidade_alunos);
        } else if (opcao == 2) {
            alteracao_notas(alunos, quantidade_alunos);
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
            Sleep(1000);
        }
    }

return 0;
}
