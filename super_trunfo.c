#include <stdio.h>
#include <string.h>

int main() {
    int PopulacaoC1, PopulacaoC2, NumTurismoC1, NumTurismoC2;
    float AreaC1, AreaC2, PIBC1, PIBC2;
    char EstadoC1, EstadoC2, CodC1[4], CodC2[4], NomeCidadeC1[50], NomeCidadeC2[50];

    printf("---*Carta 1---*\n");

    printf("Digite uma letra que representa o Estado da Carta: \n");
    scanf(" %c", &EstadoC1);

    printf("Digite o código da carta seguindo esse padrão (exemplo: A01, B02, C03): \n");
    scanf("%s", CodC1);

    printf("Digite o nome da cidade: \n");
    getchar(); 
    fgets(NomeCidadeC1, sizeof(NomeCidadeC1), stdin);
    NomeCidadeC1[strcspn(NomeCidadeC1, "\n")] = '\0'; 

    printf("Digite o número da população da cidade em número inteiro: \n");
    scanf("%d", &PopulacaoC1);

    printf("Digite a área da cidade em número decimal: \n");
    scanf("%f", &AreaC1);

    printf("Digite o número do PIB da cidade em número decimal: \n");
    scanf("%f", &PIBC1);

    printf("Digite o número de Pontos turísticos da cidade em número inteiro: \n");
    scanf("%d", &NumTurismoC1);

    // Carta 2
    printf("---*Carta 2---*\n");

    printf("Digite uma letra que representa o Estado da Carta: \n");
    scanf(" %c", &EstadoC2);

    printf("Digite o código da carta seguindo esse padrão (exemplo: A01, B02, C03): \n");
    scanf("%s", CodC2);

    printf("Digite o nome da cidade: \n");
    getchar(); 
    fgets(NomeCidadeC2, sizeof(NomeCidadeC2), stdin);
    NomeCidadeC2[strcspn(NomeCidadeC2, "\n")] = '\0';

    printf("Digite o número da população da cidade em número inteiro: \n");
    scanf("%d", &PopulacaoC2);

    printf("Digite a área da cidade em número decimal: \n");
    scanf("%f", &AreaC2);

    printf("Digite o número do PIB da cidade em número decimal: \n");
    scanf("%f", &PIBC2);

    printf("Digite o número de Pontos turísticos da cidade em número inteiro: \n");
    scanf("%d", &NumTurismoC2);

    // Saídas
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c \n", EstadoC1);
    printf("Código: %s \n", CodC1);
    printf("Nome da Cidade: %s \n", NomeCidadeC1);
    printf("População: %d \n", PopulacaoC1);
    printf("Área: %.2f km²\n", AreaC1);
    printf("PIB: %.2f bilhões\n", PIBC1);
    printf("Número de pontos turísticos: %d \n", NumTurismoC1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c \n", EstadoC2);
    printf("Código: %s \n", CodC2);
    printf("Nome da Cidade: %s \n", NomeCidadeC2);
    printf("População: %d \n", PopulacaoC2);
    printf("Área: %.2f km²\n", AreaC2);
    printf("PIB: %.2f bilhões\n", PIBC2);
    printf("Número de pontos turísticos: %d \n", NumTurismoC2);

    return 0;
}
