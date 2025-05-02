#include <stdio.h>
#include <string.h>

struct Cidade {
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    float densidade_populacional;
    float pib_per_capita;
};

void calcularDensidade(struct Cidade* cidade) {
    cidade->densidade_populacional = cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib / cidade->populacao;
}

void exibirCidade(struct Cidade cidade) {
    printf("\nCódigo: %d\n", cidade.codigo);
    printf("Nome: %s", cidade.nome);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB Total: %.2f\n", cidade.pib);
    printf("Densidade Populacional: %.2f habitantes por km²\n", cidade.densidade_populacional);
    printf("PIB per Capita: %.2f\n", cidade.pib_per_capita);
}

int main() {
    int n;
    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &n);

    struct Cidade cidades[n];

    for (int i = 0; i < n; i++) {
        printf("\nDigite os dados da cidade %d:\n", i + 1);

        printf("Código: ");
        scanf("%d", &cidades[i].codigo);
        
        getchar();
        printf("Nome: ");
        fgets(cidades[i].nome, sizeof(cidades[i].nome), stdin);

        printf("População: ");
        scanf("%d", &cidades[i].populacao);

        printf("Área: ");
        scanf("%f", &cidades[i].area);

        printf("PIB: ");
        scanf("%f", &cidades[i].pib);

        calcularDensidade(&cidades[i]);
    }

    for (int i = 0; i < n; i++) {
        exibirCidade(cidades[i]);
    }

    return 0;
}














    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
