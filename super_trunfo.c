#include <stdio.h>

int main() {
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;

    printf("Codigo da carta (ex: A01): ");
    scanf("%s", codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade);

    printf("Populacao: ");
    scanf("%d", &populacao);

    printf("Area (km²): ");
    scanf("%f", &area);

    printf("PIB: ");
    scanf("%f", &pib);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos);

    printf("\n--- Carta Cadastrada ---\n");
    printf("Codigo: %s\n", codigo);
    printf("Cidade: %s\n", cidade);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("PIB: %.2f\n", pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);

    return 0;
}
