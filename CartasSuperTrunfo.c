#include <stdio.h>

int main() {
    int codigo;
    char nome[50];
    int populacao;
    float area, pib;
    float densidade_populacional;
    float pib_per_capita;

    printf("Digite o código da cidade: ");
    scanf("%d", &codigo);

    printf("Digite o nome da cidade: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);

    printf("Digite a população da cidade: ");
    scanf("%d", &populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area);

    printf("Digite o PIB total da cidade: ");
    scanf("%f", &pib);

    densidade_populacional = populacao / area;
    pib_per_capita = pib / populacao;

    printf("\nDados da cidade:\n");
    printf("Código: %d\n", codigo);
    printf("Nome: %s", nome);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB Total: %.2f\n", pib);
    printf("Densidade Populacional: %.2f habitantes por km²\n", densidade_populacional);
    printf("PIB per Capita: %.2f\n", pib_per_capita);















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
