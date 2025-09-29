// PRÁTICA - SISTEMA DE BIBLIOTECA
// Foco em Structs, E/S e organização
// Parte 1 - Cadastro de Livros - Concluído
// Parte 2 - Sistema de Empréstimo de Livros - concluído
// Parte 3- Modularização do código - Em andamento

#include <stdio.h>   // biblioteca para entrada e saída de dados
#include <stdlib.h>  // biblioteca para alocação dinâmica de memória
#include <string.h>  // biblioteca para manipular strings em linguagem C

// CONSTANTES GLOBAIS
#define MAX_LIVROS 50       // nº máximo de livros
#define TAM_STRING 100      // nº máximo do tamanho da string (texto)
#define MAX_EMPRESTIMOS 100 // nº máximo de empréstimos por usuário

// DEFINIÇÃO DA STRUCT
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    char edicao[TAM_STRING]; // alterado para string
    int disponivel;          // 1 - disponível, 0 - não disponível
};

// STRUCT INFORMAÇÕES DE EMPRÉSTIMO
struct Emprestimo {
    int indiceLivro;              // índice para saber qual livro foi emprestado
    char nomeUsuario[TAM_STRING]; // nome do usuário
};

// PROTÓTIPOS DAS FUNÇÕES
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivros(const struct Livro *biblioteca, int totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

// FUNÇÃO PARA LIMPAR O BUFFER DE ENTRADA
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// FUNÇÃO PRINCIPAL
int main() {
    struct Livro *biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));
    struct Emprestimo *emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                cadastrarLivro(biblioteca, &totalLivros);
                break;

            case 2:
                listarLivros(biblioteca, totalLivros);
                break;

            case 3:
                realizarEmprestimo(biblioteca, totalLivros, emprestimos, &totalEmprestimos);
                break;

            case 4:
                listarEmprestimos(biblioteca, emprestimos, totalEmprestimos);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }

    } while (opcao != 0);

    liberarMemoria(biblioteca, emprestimos); // liberar memória alocada

    return 0;
}

// FUNÇÃO PARA EXIBIR O MENU
void exibirMenu() {
    printf("=======================================\n");
    printf("\n=== Sistema de Biblioteca PARTE 3 ===\n");
    printf("=======================================\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Listar Livros\n");
    printf("3. Realizar Empréstimo\n");
    printf("4. Listar Empréstimos\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

// FUNÇÃO PARA CADASTRAR LIVRO
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros) {
    printf("\n--- Cadastro de Livro ---\n");

    if (*totalLivros < MAX_LIVROS) {
        int indice = *totalLivros;

        printf("Digite o nome do livro: ");
        fgets(biblioteca[indice].nome, TAM_STRING, stdin);

        printf("Digite o autor do livro: ");
        fgets(biblioteca[indice].autor, TAM_STRING, stdin);

        printf("Digite a editora do livro: ");
        fgets(biblioteca[indice].editora, TAM_STRING, stdin);

        biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
        biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
        biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';

        printf("Digite a edição do livro: ");
        fgets(biblioteca[indice].edicao, TAM_STRING, stdin);
        biblioteca[indice].edicao[strcspn(biblioteca[indice].edicao, "\n")] = '\0';

        biblioteca[indice].disponivel = 1; // Livro disponível
        (*totalLivros)++;
        printf("Livro cadastrado com sucesso!\n");

    } else {
        printf("Capacidade máxima de livros atingida!\n");
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

// FUNÇÃO PARA LISTAR LIVROS
void listarLivros(const struct Livro *biblioteca, int totalLivros) {
    printf("\n--- Lista de Livros ---\n");

    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
    } else {
        for (int i = 0; i < totalLivros; i++) {
            printf("LIVRO: %d\n", i + 1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Editora: %s\n", biblioteca[i].editora);
            printf("Edição: %s\n", biblioteca[i].edicao);
            printf("Status: %s\n", biblioteca[i].disponivel ? "Disponível" : "Emprestado");
            printf("--------------------------------\n");
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

// FUNÇÃO PARA REALIZAR EMPRÉSTIMO
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos) {
    printf("\n--- Realizar Empréstimo ---\n");

    if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Capacidade máxima de empréstimos atingida!\n");
    } else {
        printf("Livros disponíveis:\n");
        int disponiveis = 0;
        for (int i = 0; i < totalLivros; i++) {
            if (biblioteca[i].disponivel) {
                printf("%d - %s\n", i + 1, biblioteca[i].nome);
                disponiveis++;
            }
        }
        if (disponiveis == 0) {
            printf("Nenhum livro disponível para empréstimo.\n");
        } else {
            printf("Digite o número do livro que deseja emprestar: ");
            int NumLivro;
            scanf("%d", &NumLivro);
            limparBufferEntrada();

            int indiceLivro = NumLivro - 1;

            if (indiceLivro >= 0 && indiceLivro < totalLivros && biblioteca[indiceLivro].disponivel) {
                printf("Digite seu nome: ");
                fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")] = '\0';

                emprestimos[*totalEmprestimos].indiceLivro = indiceLivro;
                biblioteca[indiceLivro].disponivel = 0; // Marca como emprestado

                (*totalEmprestimos)++;
                printf("Empréstimo realizado com sucesso!\n");
            } else {
                printf("Número de livro inválido ou livro não disponível.\n");
            }
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

// FUNÇÃO PARA LISTAR EMPRÉSTIMOS
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos) {
    printf("\n--- Lista de Empréstimos ---\n");

    if (totalEmprestimos == 0) {
        printf("Nenhum empréstimo realizado.\n");
    } else {
        for (int i = 0; i < totalEmprestimos; i++) {
            int indiceLivro = emprestimos[i].indiceLivro;
            printf("----------------------------------------\n");
            printf("EMPRÉSTIMO %d:\n", i + 1);
            printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
            printf("Livro: %s\n", biblioteca[indiceLivro].nome);
        }
        printf("--------------------------------\n");
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

// FUNÇÃO PARA LIBERAR MEMÓRIA
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos) {
    free(biblioteca);
    free(emprestimos);
    printf("Memória liberada. Programa encerrado.\n");
}
//para rodar: gcc "prática desafio .c" -o biblioteca (com aspas na string) e depois ./biblioteca
