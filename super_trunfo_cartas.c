#include <stdio.h>
#include <string.h>

int main() {
    int PopulacaoC1, PopulacaoC2, NumTurismoC1, NumTurismoC2;
    float AreaC1, AreaC2, PIBC1, PIBC2, DensidPC1 = 0, DensidPC2 = 0, PIBPerCapitaC1, PIBPerCapitaC2, SuperPoderC1, SuperPoderC2;
    char EstadoC1, EstadoC2, CodC1[4], CodC2[4], NomeCidadeC1[50], NomeCidadeC2[50];

    printf("---*Carta 1---*\n");
    printf("Digite uma letra que representa o Estado da Carta: \n");
    scanf(" %c", &EstadoC1);
    printf("Digite o código da carta: \n");
    scanf("%s", CodC1);
    printf("Digite o nome da cidade: \n");
    getchar(); // Consumir o '\n' antes do fgets
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

    printf("---*Carta 2---*\n");
    printf("Digite uma letra que representa o Estado da Carta: \n");
    getchar(); // Consumir o '\n' antes do próximo caractere
    scanf(" %c", &EstadoC2);
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
    PIBPerCapitaC1 = PIBC1 / PopulacaoC1;
    PIBPerCapitaC2 = PIBC2 / PopulacaoC2;
    SuperPoderC1 = PopulacaoC1 + AreaC1 + PIBC1 + NumTurismoC1 + PIBPerCapitaC1 + (DensidPC1 > 0 ? (1.0 / DensidPC1) : 0);
    SuperPoderC2 = PopulacaoC2 + AreaC2 + PIBC2 + NumTurismoC2 + PIBPerCapitaC2 + (DensidPC2 > 0 ? (1.0 / DensidPC2) : 0);

    // Saídas
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c \n", EstadoC1);
    printf("Código: %s \n", CodC1);
    printf("Nome da Cidade: %s \n", NomeCidadeC1);
    printf("População: %d \n", PopulacaoC1);
    printf("Área: %.2f km²\n", AreaC1);
    printf("PIB: %.2f bilhões\n", PIBC1);
    printf("Número de pontos turísticos: %d \n", NumTurismoC1);
    printf("Densidade Populacional: %f \n", DensidPC1);
    printf("PIB per Capita: %f \n", PIBPerCapitaC1);
    printf("Super Poder: %f \n", SuperPoderC1);


    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c \n", EstadoC2);
    printf("Código: %s \n", CodC2);
    printf("Nome da Cidade: %s \n", NomeCidadeC2);
    printf("População: %d \n", PopulacaoC2);
    printf("Área: %.2f km²\n", AreaC2);
    printf("PIB: %.2f bilhões\n", PIBC2);
    printf("Número de pontos turísticos: %d \n", NumTurismoC2);
    printf("Densidade Populacional: %f \n", DensidPC2);
    printf("PIB per Capita: %f \n", PIBPerCapitaC2);
    printf("Super Poder: %f \n", SuperPoderC2);
    
   // Comparação das cartas
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu\n", PopulacaoC1 > PopulacaoC2 ? 1 : 2);
    printf("Área: Carta %d venceu\n", AreaC1 > AreaC2 ? 1 : 2);
    printf("PIB: Carta %d venceu\n", PIBC1 > PIBC2 ? 1 : 2);
    printf("Pontos Turísticos: Carta %d venceu\n", NumTurismoC1 > NumTurismoC2 ? 1 : 2);
    printf("Densidade Populacional: Carta %d venceu\n", DensidPC1 < DensidPC2 ? 1 : 2);
    printf("PIB per Capita: Carta %d venceu\n", PIBPerCapitaC1 > PIBPerCapitaC2 ? 1 : 2);
    printf("Super Poder: Carta %d venceu\n", SuperPoderC1 > SuperPoderC2 ? 1 : 2);

    return 0;
}
