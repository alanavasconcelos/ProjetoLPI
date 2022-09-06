#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "ranking.h"

JOGADOR jogadorAtual, ranking[10];

void moveXY(int x, int y, char t[100])
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout, position);
    printf("%s", t);
}


void printRanking(JOGADOR ranking[10]){

    int i;
    short posX = 35;
    short posY = 7;

    moveXY(35, 5, "");
    printf("NOME");
    moveXY(45, 5, "PONTUACAO");
    for(i = 0; i < 10; i++){

        moveXY(posX,posY,"");
        printf("%s", ranking[i].nome);
        moveXY(posX + 15,posY,"");
        printf("%d",ranking[i].pontuacao);
        posY++;

    }

}

void initRanking(JOGADOR ranking[10]){

    int i;
    FILE* arquivo;
    arquivo = fopen("ranking.txt", "r");

    if(arquivo == 0){
        printf("Banco de dados nao disponivel\n\n");
        exit(1);
    }


    for(i = 0; i < 20; i++){

        if(i < 10){

            fscanf(arquivo, "%s", &ranking[i].nome);

        } else{

                fscanf(arquivo, "%d", &ranking[i - 10].pontuacao);

            }
    }

    fclose(arquivo);

}

void trocaRank(){

    int i;
    int achou = 0;
    char teste[20];

    FILE* arquivo;
    arquivo = fopen("ranking.txt", "r+");

    if(arquivo == 0){
        printf("Banco de dados nao disponivel\n\n");
        exit(1);
    }

    for(i = 0; i < 20; i++){

        if(i < 10){

            fscanf(arquivo, "%s", &ranking[i].nome);

        } else{

                fscanf(arquivo, "%d", &ranking[i - 10].pontuacao);

                if(jogadorAtual.pontuacao > ranking[i - 10].pontuacao){

                    achou = i;

                }
            }

    }

if(achou != 0){

        for(i = 0; i < 20; i++){

            if(achou == i + 10){

                fprintf(arquivo, "%s", jogadorAtual.nome);
                break;
                }

            if(achou == i){

                fprintf(arquivo, "%d\n", jogadorAtual.pontuacao);

            }
        }




    }

    fclose(arquivo);

}

void abreRanking(){

    initRanking(ranking);
    printRanking(ranking);

    moveXY(35,18, "");
    system("pause");

}



