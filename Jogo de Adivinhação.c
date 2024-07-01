#include <stdio.h>

int main()
{
    printf("**************************************** \n\n");
    printf("*BEM VINDO AO NOSSO JOGO DE ADIVINHACAO* \n\n");
    printf("**************************************** \n\n");

    int numeroSecreto = 42;
    int chute;

    for (int i = 1; i <= 3; i++)

    {
    printf("TENTATIVA %d de 3 \n", i);
    printf("QUAL E O SEU CHUTE? \n\n");
    scanf("%d", &chute);
    printf("\nSEU CHUTE FOI: %d \n\n", chute);

    int acertou = chute == numeroSecreto;

    if (acertou) {
    printf("Parabens, voce acertou!!!\n\n");
    printf("Jogue denovo, voce e um bom jogador!!!\n\n"); }

    else
    {
    int maior = chute > numeroSecreto;

    if (maior) {
    printf("O SEU CHUTE FOI MAIOR QUE O NUMERO SECRETO \n\n"); }

    else {
    printf("O SEU CHUTE FOI MENOR QUE O NUMERO SECRETO \n\n"); }

    }

    }

    printf("FIM DE JOGO.\n");

}
