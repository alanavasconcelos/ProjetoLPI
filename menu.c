#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "jogo.h"
#include "ranking.h"

void creditos(){
        moveXY(15, 5, "Jogo feito pelos alunos de graduacao de engenharia de computacao..");
        moveXY(35, 7, "- Alana Vasconcelos");
        moveXY(35, 9, "- Arthur Bundchen");
        moveXY(35, 11, "- Eduardo Tavora");
        moveXY(35, 13, "- Matheus Araujo");
        moveXY(25, 15, "* Professor ministrante: Joabe Jesus\n\n");
        moveXY(25, 17, "");
        system("pause");
}


void instrucoes(){

        moveXY(35, 5, "O objetivo do jogo eh acertar os discos com tiros.");
        moveXY(35, 7, "* Para mirar use A para esquerda e D para direita.");
        moveXY(35, 9, "* Para atirar use espaco.");
        moveXY(35, 11, "* Pressione esc para sair do jogo a qualquer momento.");
        moveXY(35, 13, "* A dificuldade do jogo mudara o tempo ganho a cada acerto.");
        moveXY(35, 15, "* Aperte qualquer tecla para voltar ao menu.");
        moveXY(35, 17,"");
        system("pause");

}

int dificuldade(){

    char selecdif;
    int difAtual;

    moveXY(30, 5, "Pressione o numero correnspondente a dificuldade desejada: ");
    moveXY(50, 9, "1 - Facil");
    moveXY(50, 13, "2 - Moderado");
    moveXY(50, 17, "3 - Dificil\n\n");

    fflush(stdin);

    if(kbhit){
    selecdif = getch();

            switch(selecdif)
            {
            case '1':

                difAtual = 1;
                system("cls");
                moveXY(30, 5, "Selecionou: Facil");
                moveXY(30,7,"");
                system("pause");
                system("cls");

                break;
            case '2':
                difAtual = 2;
                system("cls");
                moveXY(30, 5, "Selecionou: Moderado");
                moveXY(30,7,"");
                system("pause");
                system("cls");

                break;
            case '3':
                difAtual = 3;
                system("cls");
                moveXY(30, 5, "Selecionou: Dificil");
                moveXY(30,7,"");
                system("pause");
                system("cls");

                break;

            default:
                system("cls");
                moveXY(30, 5, "Tecla invalida");
                moveXY(30, 7, "");
                system("pause");
                system("cls");
                dificuldade();
            }

    }

    return difAtual;

}

void opcoes()
{
    moveXY(43,5, "----TIRO AO ALVO----");
    moveXY(45,10," 1 - Jogar");
    moveXY(45,15," 2 - Instrucoes");
    moveXY(45,20," 3 - Ranking");
    moveXY(45,25," 4 - Dificuldade");
    moveXY(45,30," 5 - Creditos");
    moveXY(45,35," 6 - Sair");
}

void menu()
{

    int dif;
    short posX = 40, posY = 15;
    char a;

    system("color 1F");
    moveXY(posX,posY, "->");
    do
    {
        opcoes();
        moveXY(posX, posY, "->");
        a = toupper(getch());

        switch(a)
        {
            case 'H':
                if (posY > 10)
                {
                    moveXY(posX,posY, "  ");
                    posY-= 5;
                    moveXY(posX,posY, "->");
                }
            break;

            case 'P':
                if (posY < 10)
                {
                    moveXY(posX,posY, "  ");
                    posY+= 5;
                    moveXY(posX,posY, "->");
                }
                else if (posY < 35)
                {
                    moveXY(posX,posY, "  ");
                    posY+= 5;
                    moveXY(posX,posY, "->");
                }
            break;

            case 13:  // apertou a tecla enter
                if (posY == 10)// jogo rodando...
                {
                    system("cls");
                    jogo(dif);
                    trocaRank();
                }
                if (posY == 15)// apertou enter na segunda opção
                {
                    system("cls");
                    instrucoes();
                    system("cls");
                }
                if (posY == 20)// apertou enter na terceira opção
                {
                    system("cls");
                    abreRanking();
                    system("cls");
                }
                if (posY == 25)// apertou enter na quarta opção
                {
                    system("cls");
                    dif = dificuldade();
                    system("cls");
                }
                if (posY == 30)// apertou enter na quarta opção
                {
                    system("cls");
                    creditos();
                    system("cls");
                }
                if (posY == 35)// apertou enter na quinta opção
                {
                    system("cls");
                    exit(0);
                }
            break;
        }

    }while(1);
}
