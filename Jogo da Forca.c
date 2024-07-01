#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

char palavrasecreta [20];
char chutes [26];
int chutesdados = 0;

void abertura(){
printf("*******************************************\n");
printf("*               JOGO DA FORCA             *\n");
printf("*******************************************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);
    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca() {

int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");


for (int i = 0; i < strlen(palavrasecreta); i++) {
    int achou = jachutou(palavrasecreta[i]);

    if (achou) {
        printf("%c ", palavrasecreta[i]);
    } else {
        printf("_ "); }
    }
    printf("\n");

}

void adicionapalavra() {

char quer;


printf("\nVOCE DESEJA ADICIONAR UMA NOVA PALAVRA AO NOSSO JOGO? (S/N)\n\n");
scanf(" %c", &quer);

if (quer == 'S') {

    char novapalavra[TAMANHO_PALAVRA];
    printf("\nQUAL A NOVA PALAVRA?\n\n");
    scanf("%s",  &novapalavra);

    FILE* f;

    f = fopen("palavras.txt", "r+");
    if (f ==0) {
        printf("Desculpe. Banco de dados nao disponivel.\n\n");
        exit(1);
    }
    int qtd;

    fscanf(f, "%d", &qtd);
    qtd++;

    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "%s", novapalavra);

    fclose(f);
}

    }

void escolhepalavra (){
    FILE* f;

    f = fopen("palavras.txt", "r");
    if (f ==0) { printf("Desculpe. Banco de dados nao disponivel.\n\n");
    exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);
    srand(time(0));

    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int acertou () {

for (int i = 0; i < strlen(palavrasecreta); i++) {
    if (!jachutou(palavrasecreta[i])) {
        return 0;
    }
}
    return 1;

}

int chuteserrados() {
    int erros = 0;

    for (int i = 0; i < chutesdados; i++) {
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++) {
            if (chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }
        if (!existe) erros++;
    }
    return erros;
}

int enforcou() {
        return chuteserrados() >= 5;
    }

int jachutou (char letra) {
    int achou = 0;
    for (int j = 0; j < chutesdados; j++){
        if (chutes[j] == letra){
            achou = 1;
            break;
        }
        }
        return achou;
}

int main(){

escolhepalavra(palavrasecreta);

abertura();

do{

desenhaforca();
chuta();

} while (!acertou() && !enforcou());

if (acertou()) {
        printf("\nParabens, voce ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

}
else {
        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");

}
adicionapalavra();
}
