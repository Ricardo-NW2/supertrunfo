#include <stdio.h>

int main() {
    // --------- Declaração de variáveis ---------
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    int atributo1, atributo2;

    // --------- Cadastro da Carta 1 ---------
    printf("Cadastro da Carta 1:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // --------- Cadastro da Carta 2 ---------
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // --------- Menu Interativo: Escolha de Atributos ---------
    printf("\n--- ESCOLHA DO 1º ATRIBUTO ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    do {
        printf("\n--- ESCOLHA DO 2º ATRIBUTO (diferente do primeiro) ---\n");
        for (int i = 1; i <= 5; i++) {
            if (i != atributo1) {
                switch(i) {
                    case 1: printf("1. População\n"); break;
                    case 2: printf("2. Área\n"); break;
                    case 3: printf("3. PIB\n"); break;
                    case 4: printf("4. Pontos Turísticos\n"); break;
                    case 5: printf("5. Densidade Demográfica\n"); break;
                }
            }
        }
        printf("Escolha o segundo atributo: ");
        scanf("%d", &atributo2);
        if (atributo1 == atributo2) {
            printf("Você escolheu o mesmo atributo! Tente outro.\n");
        }
    } while (atributo1 == atributo2 || atributo2 < 1 || atributo2 > 5);

    // --------- Função de comparação ---------
    float valor1_carta1 = 0, valor2_carta1 = 0;
    float valor1_carta2 = 0, valor2_carta2 = 0;
    float soma1 = 0, soma2 = 0;

    float getValor(int op, float a, float b, float c, float d, int modoInverso) {
        float v1 = 0, v2 = 0;
        switch(op) {
            case 1: v1 = a; v2 = b; break; // população
            case 2: v1 = c; v2 = d; break; // área
            case 3: v1 = pib1; v2 = pib2; break;
            case 4: v1 = pontosTuristicos1; v2 = pontosTuristicos2; break;
            case 5: v1 = densidade1; v2 = densidade2; break;
        }
        return modoInverso ? ((v1 < v2) ? 1 : (v1 > v2 ? -1 : 0)) : ((v1 > v2) ? 1 : (v1 < v2 ? -1 : 0));
    }

    // Atribui os valores de comparação
    switch(atributo1) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = pontosTuristicos1; valor1_carta2 = pontosTuristicos2; break;
        case 5: valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
    }

    switch(atributo2) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = pontosTuristicos1; valor2_carta2 = pontosTuristicos2; break;
        case 5: valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
    }

    // Soma considerando regra invertida na densidade
    soma1 = valor1_carta1 + valor2_carta1 - (atributo1 == 5 ? 2 * valor1_carta1 : 0) - (atributo2 == 5 ? 2 * valor2_carta1 : 0);
    soma2 = valor1_carta2 + valor2_carta2 - (atributo1 == 5 ? 2 * valor1_carta2 : 0) - (atributo2 == 5 ? 2 * valor2_carta2 : 0);

    // --------- Resultado ---------
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Carta 1 - %s (%c): %.2f + %.2f = %.2f\n", nomeCidade1, estado1, valor1_carta1, valor2_carta1, soma1);
    printf("Carta 2 - %s (%c): %.2f + %.2f = %.2f\n", nomeCidade2, estado2, valor1_carta2, valor2_carta2, soma2);

    if (soma1 > soma2)
        printf("Vencedor: %s!\n", nomeCidade1);
    else if (soma2 > soma1)
        printf("Vencedor: %s!\n", nomeCidade2);
    else
        printf("Resultado: Empate!\n");

    return 0;
}
