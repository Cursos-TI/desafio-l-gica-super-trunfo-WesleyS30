#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

typedef struct {
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float super_poder; 
    char nome[50];
} Cidade;

void cadastrarCidades(Cidade cidades[NUM_ESTADOS][NUM_CIDADES]) {
    char estado;
    int cidade;

    for (estado = 'A'; estado <= 'H'; estado++) {
        for (cidade = 1; cidade <= 4; cidade++) {
            printf("Cadastro da cidade %c%02d\n", estado, cidade);
            printf("Digite o nome da cidade:");
            scanf("%49s", cidades[estado - 'A'][cidade - 1].nome);

            while (getchar() != '\n');  
            printf("Digite a população: ");
            scanf("%d", &cidades[estado - 'A'][cidade - 1].populacao);

            while (getchar() != '\n');  
            printf("Digite a área (em km²): ");
            while (scanf("%f", &cidades[estado - 'A'][cidade - 1].area) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para a área: ");
                while (getchar() != '\n');
            }

            printf("Digite o PIB (em bilhões): ");
            while (scanf("%f", &cidades[estado - 'A'][cidade - 1].pib) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para o PIB: ");
                while (getchar() != '\n');
            }

            printf("Digite o número de pontos turísticos: ");
            while (scanf("%d", &cidades[estado - 'A'][cidade - 1].pontos_turisticos) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para pontos turísticos: ");
                while (getchar() != '\n');
            }

            cidades[estado - 'A'][cidade - 1].super_poder =
                cidades[estado - 'A'][cidade - 1].populacao +
                cidades[estado - 'A'][cidade - 1].area +
                cidades[estado - 'A'][cidade - 1].pib +
                cidades[estado - 'A'][cidade - 1].pontos_turisticos;

            printf("\n");
        }
    }
}

void compararCartas(Cidade carta1, Cidade carta2) {
    int escolha;
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Super Poder\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("- População: %s\n", carta1.populacao > carta2.populacao ? "Carta 1 vence" : "Carta 2 vence");
            break;
        case 2:
            printf("- Área: %s\n", carta1.area > carta2.area ? "Carta 1 vence" : "Carta 2 vence");
            break;
        case 3:
            printf("- PIB: %s\n", carta1.pib > carta2.pib ? "Carta 1 vence" : "Carta 2 vence");
            break;
        case 4:
            printf("- Pontos Turísticos: %s\n", carta1.pontos_turisticos > carta2.pontos_turisticos ? "Carta 1 vence" : "Carta 2 vence");
            break;
        case 5:
            printf("- Super Poder: %s\n", carta1.super_poder > carta2.super_poder ? "Carta 1 vence" : "Carta 2 vence");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES];
    int estado1, cidade1, estado2, cidade2;

    cadastrarCidades(cidades);

    printf("Selecione as cartas para comparação (Estado e Cidade):\n");
    printf("Carta 1 (Estado [1-8] e Cidade [1-4]): ");
    scanf("%d %d", &estado1, &cidade1);
    printf("Carta 2 (Estado [1-8] e Cidade [1-4]): ");
    scanf("%d %d", &estado2, &cidade2);

    estado1 -= 1;
    cidade1 -= 1;
    estado2 -= 1;
    cidade2 -= 1;

    compararCartas(cidades[estado1][cidade1], cidades[estado2][cidade2]);
    
    return 0;
}
