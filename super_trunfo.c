#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura da carta (mantida e expandida com IDH conforme requisito avançado)
struct Carta {
    char nome[50];
    long int populacao;     // Alterado para long int para valores reais
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float idh;             // Novo atributo adicionado
};

// Função para exibir o valor de um atributo específico
float obterValorAtributo(struct Carta c, int atributo) {
    switch(atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.idh;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* obterNomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        case 6: return "IDH";
        default: return "Desconhecido";
    }
}

// Função para verificar se é atributo de menor vence (Densidade)
int isMenorVence(int atributo) {
    return (atributo == 5) ? 1 : 0; // Operador ternário
}

// Função para exibir menu dinâmico (exclui o atributo já escolhido)
void exibirMenu(int excluido) {
    printf("\n===== MENU DE ATRIBUTOS =====\n");
    if (excluido != 1) printf("1 - Populacao\n");
    if (excluido != 2) printf("2 - Area\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turisticos\n");
    if (excluido != 5) printf("5 - Densidade Demografica (Menor vence!)\n");
    if (excluido != 6) printf("6 - IDH\n");
    printf("=============================\n");
}

// Função para limpar buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Cartas pré-cadastradas (mantidas e atualizadas)
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 1.8, 50, 25.1, 0.765};
    struct Carta carta2 = {"Japao", 125000000, 377975.0, 5.0, 80, 330.0, 0.919};

    int opcao1, opcao2;
    float soma1 = 0, soma2 = 0;
    
    printf("===== SUPER TRUNFO - NIVEL MESTRE =====\n");
    printf("Dois atributos serao comparados!\n\n");

    // Escolha do primeiro atributo
    printf("Escolha o PRIMEIRO atributo:");
    exibirMenu(0); // 0 = nada excluído ainda
    printf("Opcao: ");
    
    if (scanf("%d", &opcao1) != 1 || opcao1 < 1 || opcao1 > 6) {
        printf("Opcao invalida!\n");
        return 1;
    }
    limparBuffer();

    // Escolha do segundo atributo (MENU DINÂMICO - exclui o primeiro)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):");
    exibirMenu(opcao1); // Passa o primeiro atributo para ser excluído do menu
    printf("Opcao: ");
    
    if (scanf("%d", &opcao2) != 1) {
        printf("Entrada invalida!\n");
        return 1;
    }
    limparBuffer();

    // Validação: impede escolha do mesmo atributo ou opção inválida
    if (opcao2 < 1 || opcao2 > 6) {
        printf("Opcao invalida! Deve ser entre 1 e 6.\n");
        return 1;
    }
    if (opcao2 == opcao1) {
        printf("Erro: Voce nao pode escolher o mesmo atributo duas vezes!\n");
        return 1;
    }

    printf("\n\n>>>>>>>>>> RESULTADO DA COMPARACAO <<<<<<<<<<\n");
    printf("Paises: %s vs %s\n", carta1.nome, carta2.nome);
    printf("Atributos selecionados: %s e %s\n\n", obterNomeAtributo(opcao1), obterNomeAtributo(opcao2));

    // Comparar primeiro atributo
    printf("--- PRIMEIRO ATRIBUTO: %s ---\n", obterNomeAtributo(opcao1));
    float val1_attr1 = obterValorAtributo(carta1, opcao1);
    float val2_attr1 = obterValorAtributo(carta2, opcao1);
    
    printf("%s: %.2f\n", carta1.nome, val1_attr1);
    printf("%s: %.2f\n", carta2.nome, val2_attr1);
    
    int vencedor_attr1;
    if (isMenorVence(opcao1)) {
        // Densidade: menor vence
        vencedor_attr1 = (val1_attr1 < val2_attr1) ? 1 : (val2_attr1 < val1_attr1) ? 2 : 0;
    } else {
        // Outros: maior vence
        vencedor_attr1 = (val1_attr1 > val2_attr1) ? 1 : (val2_attr1 > val1_attr1) ? 2 : 0;
    }
    
    // Operador ternário aninhado para determinar texto do vencedor
    const char* texto_vencedor1 = (vencedor_attr1 == 1) ? carta1.nome : 
                                  (vencedor_attr1 == 2) ? carta2.nome : "Empate";
    printf("Vencedor deste atributo: %s\n\n", texto_vencedor1);

    // Comparar segundo atributo
    printf("--- SEGUNDO ATRIBUTO: %s ---\n", obterNomeAtributo(opcao2));
    float val1_attr2 = obterValorAtributo(carta1, opcao2);
    float val2_attr2 = obterValorAtributo(carta2, opcao2);
    
    printf("%s: %.2f\n", carta1.nome, val1_attr2);
    printf("%s: %.2f\n", carta2.nome, val2_attr2);
    
    int vencedor_attr2;
    if (isMenorVence(opcao2)) {
        vencedor_attr2 = (val1_attr2 < val2_attr2) ? 1 : (val2_attr2 < val1_attr2) ? 2 : 0;
    } else {
        vencedor_attr2 = (val1_attr2 > val2_attr2) ? 1 : (val2_attr2 > val1_attr2) ? 2 : 0;
    }
    
    const char* texto_vencedor2 = (vencedor_attr2 == 1) ? carta1.nome : 
                                  (vencedor_attr2 == 2) ? carta2.nome : "Empate";
    printf("Vencedor deste atributo: %s\n\n", texto_vencedor2);

    // Calcular soma dos atributos
    soma1 = val1_attr1 + val1_attr2;
    soma2 = val2_attr1 + val2_attr2;

    printf("--- SOMA DOS ATRIBUTOS ---\n");
    printf("%s: %.2f + %.2f = %.2f\n", carta1.nome, val1_attr1, val1_attr2, soma1);
    printf("%s: %.2f + %.2f = %.2f\n", carta2.nome, val2_attr1, val2_attr2, soma2);

    // Determinar vencedor final usando comparação de somas
    printf("\n========== RESULTADO FINAL ==========\n");
    
    if (soma1 == soma2) {
        printf("EMPATE! Ambas as cartas tem a mesma soma (%.2f).\n", soma1);
    } else {
        // Operador ternário para determinar vencedor final
        const char* vencedor_final = (soma1 > soma2) ? carta1.nome : carta2.nome;
        float soma_vencedor = (soma1 > soma2) ? soma1 : soma2;
        float soma_perdedor = (soma1 > soma2) ? soma2 : soma1;
        
        printf("VENCEDOR: %s!\n", vencedor_final);
        printf("Soma vencedora: %.2f\n", soma_vencedor);
        printf("Diferenca: %.2f pontos\n", soma_vencedor - soma_perdedor);
    }
    
    printf("=====================================\n");

    return 0;
}
