#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "jogo.h"
#include "ranking.h"

float a, b, c;
JOGADOR jogadorAtual, ranking[10];

void aleatorio()
{
    srand(time(NULL));

        a = (rand() % 100);

        while(a < 30 || a > 40)
        {
            a = (rand() % 100);
        }

        b = (rand() % 100);

        while(b == 0)
        {
            b = (rand() % 100);
        }
        c = (rand() % 100);

        while(c < 20 || c > 50)
        {
            c = (rand() % 100);
        }

        a = a / 100000;
        b = b / 1000;
        c = c / 10;

}

int parabola(float x)
{

    float fx;

    fx = a*(x*x) + b*x + c;

    return fx;

}

void bordas()
{

    int x, y;
    int  k = 1;
    int l = 1;

    for(y = 0; y <= 30; y++)
    {

        for(x = 0; x <= 120; x++)
        {

            //Cima
            if(x == l && y != 30 && x != 120)
            {

                moveXY(x, y, "-");
                l++;

                //Baixo
            }
            else if(y == 30 && x != 0 && x != 120)
            {

                moveXY(x, y, "-");

                //Esquerda
            }
            else if(y == k && y != 30)
            {

                moveXY(x, y, "|");
                k++;

                //Direita
            }
            else if(x == 120 && y != 30 && y != 0)
            {

                moveXY(x, y, "|");

            }

        }

    }

}

int movimentaDisco(int contador, short* resetou)
{

    int x, y, somaCords;
    float posAtual;


    for(y = 0; y <= 30; y++)
    {
        for(x = 0; x <= 117; x++)
        {

            posAtual = parabola(x);

            if(y == posAtual && x == contador && y != 0 && y != 30 && x != 0 && x != 120)
            {

                moveXY(x, y, "xxx");
                somaCords = x + y;


            }

        }

        if(resetou == 1)
        {
            x = 0;
            y = 0;
        }
    }
    if(somaCords != 0)
    {

        return somaCords;

    }
    else
    {

        return 0;

    }
}

void apaga(int somaCords, int contador)
{

    int x, y;

    y = somaCords - contador;

    x = somaCords - y;

    moveXY(x, y, "   ");


}

void desenhaCanhao()
{

    moveXY(56, 29, "|_|~*");

}

int movimentaCanhao(char tecla, short reseta)
{
    static int posX = 56;
    static int posY = 29;

    if(reseta == 1){

        posX = 56;
        posY = 29;

    }

    switch(tecla)
    {
    case 'A':
        if (posX > 13)
        {
            moveXY(posX, posY, "       ");
            posX-= 3;
            moveXY(posX, posY, " |_|~* ");
        }
        break;

    case'D':
            if (posX < 100)
            {
                moveXY(posX, posY, "       ");
                posX+= 3;
                moveXY(posX, posY, " |_|~* ");
            }
        break;
    }
    return posX;
}

int cronometro(int* timer)
{

    int posX = 112;
    int posY = 1;

    if (*timer == 60)
    {
        moveXY(posX, posY, "");
        printf("01:00");
    }
    else if (*timer <= 59 && *timer > 9)
    {
        moveXY(posX, posY, "");
        printf("00:%d", *timer);
    }
    else if(*timer <= 9 && *timer >= 0)
    {
        moveXY(posX, posY, "");
        printf("00:0%d", *timer);
    }
    else if(*timer <= 0)
    {

        return 1;

    }

        return 0;

}
void desenhaBala(){

    moveXY(0, 31, "Balas: o");

}

int movimentaBalas(char tecla, int xcanhao,int ybala, short balaandando, int xbalaandando){

    int xbala = 57;

    if (balaandando == 1){

        xbala = xbalaandando;

    }else if(xcanhao != 56) {

        xbala = xcanhao + 2;

    }


    moveXY(xbala, ybala, "o");

    return xbala;

}

int colisao(int xbalaandando, int ybala, int somaCords, int contador){

    int xdisco, ydisco;

    ydisco = somaCords - contador;

    xdisco = somaCords - ydisco;

    if((xbalaandando == xdisco && ybala == ydisco)||
      (xbalaandando == xdisco + 1 && ybala == ydisco)||
      (xbalaandando == xdisco + 2 && ybala == ydisco)||
      (xbalaandando == xdisco + 3 && ybala == ydisco)||
      (xbalaandando == xdisco && ybala == ydisco - 1)||
      (xbalaandando == xdisco + 1 && ybala == ydisco - 1)||
      (xbalaandando == xdisco + 2 && ybala == ydisco - 1)||
      (xbalaandando == xdisco + 3 && ybala == ydisco- 1)){

        return 1;

    } else{

        return 0;

    }

}

void pontuacao(int pts){

    moveXY(0,32,"");
    printf("Pontos: %d", pts);

}
void desenhaCronometro(){

    moveXY(112, 1, "");
    printf("01:00");

}

void jogo(int dificuldade)
{
    static int xbalaandando = 57;
    int timer = 59;
    int xcanhao = 57;
    int somaCords, tempoextra;
    int contador = 0;
    int segundos = 0;
    int pts = 0;
    int ybala = 28;
    int ybalaantigo = 28;
    char tecla= '0';
    char difnome[9];
    short perdeu = 0;
    short resetadisco = 0;
    short balaandando = 0;
    short colidiu;

    switch(dificuldade){
        case 1:
            tempoextra = 12;
            strcpy(difnome, "Facil");
            break;
        case 2:
            tempoextra = 8;
            strcpy(difnome, "Moderado");
            break;
        case 3:
            tempoextra = 4;
            strcpy(difnome, "Dificil");
            break;
        default:
            tempoextra = 12;
            strcpy(difnome, "Facil");
            break;
    }



    aleatorio();

    bordas();
    desenhaCanhao();
    movimentaCanhao('W', 1);
    desenhaBala();
    desenhaCronometro();
    moveXY(0,33,"Dificuldade Atual: ");
    printf("%s, +%d segundos a cada acerto", difnome, tempoextra);


    while(!perdeu)
    {

        pontuacao(pts);

        somaCords = movimentaDisco(contador, &resetadisco);



        if(balaandando == 1){

            moveXY(xbalaandando, ybalaantigo, " ");

            movimentaBalas(tecla, xcanhao, ybala, balaandando, xbalaandando);
            ybalaantigo = ybala;
            ybala--;
        }

        if(kbhit())
        {

            tecla = toupper(getch());
            xcanhao = movimentaCanhao(tecla, 0);


            switch(tecla){
                case 32:

                    moveXY(7, 31, " ");
                    if(balaandando == 0){
                        xbalaandando = movimentaBalas(tecla, xcanhao, ybala, balaandando, xbalaandando);
                        balaandando = 1;

                    }
                    break;

                case 27:
                    perdeu = 1;
                    break;

                default:
                    break;
            }

        }

        if(segundos >= 1000)
        {

            perdeu = cronometro(&timer);
            timer--;
            segundos = 0;

        }

        if(resetadisco)
        {
            resetadisco = 0;
        }

        colidiu = colisao(xbalaandando, ybala, somaCords, contador);

        if(colidiu){

            apaga(somaCords, contador);
            aleatorio();
            resetadisco = 1;
            contador = 0;
            pts++;
            Beep(400, 50);
            Sleep(50);

            if((timer <= 48 && tempoextra == 12) || (timer <= 52 && tempoextra == 8) || (timer <= 56 && tempoextra == 4)){

                timer = timer +  tempoextra;

            } else {

                timer = 60;

            }

        }else{

            Sleep(100);

        }

        if(somaCords != 0)
        {
            apaga(somaCords, contador);
        }

        if(ybala <= 0 || colidiu){

            moveXY(xbalaandando, ybalaantigo, " ");\
            moveXY(0,0,"");
            ybala = 28;
            balaandando = 0;
            desenhaBala();
        }

        if(contador >= 120)
        {
            contador = 0;
            aleatorio();
            resetadisco = 1;
        }

        contador++;
        segundos = segundos + 100;

    }

    system("cls");
    moveXY(32, 10, "Sua pontuacao foi: ");
    printf("%d", pts);
    moveXY(32, 11, "Obrigado por jogar");
    moveXY(32, 13, "Digite seu nome: ");
    gets(jogadorAtual.nome);
    jogadorAtual.pontuacao = pts;

    system("cls");

}


