#include <stdio.h>
#include <string.h>

int main() {
    int PopulacaoC1, PopulacaoC2, NumTurismoC1, NumTurismoC2;
    float AreaC1, AreaC2, PIBC1, PIBC2, DensidPC1 = 0, DensidPC2 = 0;
    char EstadoC1[2], EstadoC2[2], CodC1[4], CodC2[4], NomeCidadeC1[50], NomeCidadeC2[50];
    int opcao;

    // Entrada Carta 1
    printf("---*Carta 1---*\n");
    printf("Digite a sigla que representa o Estado da Carta: \n");
    scanf("%s", EstadoC1);
    printf("Digite o código da carta: \n");
    scanf("%s", CodC1);
    printf("Digite o nome da cidade: \n");
    getchar(); 
    fgets(NomeCidadeC1, sizeof(NomeCidadeC1), stdin);
    NomeCidadeC1[strcspn(NomeCidadeC1, "\n")] = '\0';
    printf("Digite a população da cidade: \n");
    scanf("%d", &PopulacaoC1);
    printf("Digite a área da cidade (em km²): \n");
    scanf("%f", &AreaC1);
    printf("Digite o PIB da cidade (em bilhões): \n");
    scanf("%f", &PIBC1);
    printf("Digite o número de pontos turísticos da cidade: \n");
    scanf("%d", &NumTurismoC1);

    // Entrada Carta 2
    printf("---*Carta 2---*\n");
    printf("Digite a sigla que representa o Estado da Carta: \n");
    getchar();
    scanf("%s", EstadoC2);
    printf("Digite o código da carta: \n");
    scanf("%s", CodC2);
    printf("Digite o nome da cidade: \n");
    getchar();
    fgets(NomeCidadeC2, sizeof(NomeCidadeC2), stdin);
    NomeCidadeC2[strcspn(NomeCidadeC2, "\n")] = '\0';
    printf("Digite a população da cidade: \n");
    scanf("%d", &PopulacaoC2);
    printf("Digite a área da cidade (em km²): \n");
    scanf("%f", &AreaC2);
    printf("Digite o PIB da cidade (em bilhões): \n");
    scanf("%f", &PIBC2);
    printf("Digite o número de pontos turísticos da cidade: \n");
    scanf("%d", &NumTurismoC2);

    // Cálculos
    if (AreaC1 > 0) DensidPC1 = PopulacaoC1 / AreaC1;
    if (AreaC2 > 0) DensidPC2 = PopulacaoC2 / AreaC2;

    // Menu
    printf("\n--- MENU DE COMPARAÇÃO ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparação: ");
    scanf("%d", &opcao);

    printf("\n--- Comparação ---\n");
    switch(opcao) {
        case 1:
            printf("Comparando População:\n");
            printf("%s (%d) vs %s (%d)\n", NomeCidadeC1, PopulacaoC1, NomeCidadeC2, PopulacaoC2);
            if (PopulacaoC1 > PopulacaoC2)
                printf("Venceu: %s (%s)\n", NomeCidadeC1, EstadoC1);
            else if (PopulacaoC2 > PopulacaoC1)
                printf("Venceu: %s (%s)\n", NomeCidadeC2, EstadoC2);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Comparando Área:\n");
            printf("%s (%.2f km²) vs %s (%.2f km²)\n", NomeCidadeC1, AreaC1, NomeCidadeC2, AreaC2);
            if (AreaC1 > AreaC2)
                printf("Venceu: %s (%s)\n", NomeCidadeC1, EstadoC1);
            else if (AreaC2 > AreaC1)
                printf("Venceu: %s (%s)\n", NomeCidadeC2, EstadoC2);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Comparando PIB:\n");
            printf("%s (%.2f) vs %s (%.2f)\n", NomeCidadeC1, PIBC1, NomeCidadeC2, PIBC2);
            if (PIBC1 > PIBC2)
                printf("Venceu: %s (%s)\n", NomeCidadeC1, EstadoC1);
            else if (PIBC2 > PIBC1)
                printf("Venceu: %s (%s)\n", NomeCidadeC2, EstadoC2);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Comparando Pontos Turísticos:\n");
            printf("%s (%d) vs %s (%d)\n", NomeCidadeC1, NumTurismoC1, NomeCidadeC2, NumTurismoC2);
            if (NumTurismoC1 > NumTurismoC2)
                printf("Venceu: %s (%s)\n", NomeCidadeC1, EstadoC1);
            else if (NumTurismoC2 > NumTurismoC1)
                printf("Venceu: %s (%s)\n", NomeCidadeC2, EstadoC2);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Comparando Densidade Demográfica (MENOR vence):\n");
            printf("%s (%.2f) vs %s (%.2f)\n", NomeCidadeC1, DensidPC1, NomeCidadeC2, DensidPC2);
            if (DensidPC1 < DensidPC2)
                printf("Venceu: %s (%s)\n", NomeCidadeC1, EstadoC1);
            else if (DensidPC2 < DensidPC1)
                printf("Venceu: %s (%s)\n", NomeCidadeC2, EstadoC2);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
