#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

typedef struct Jogador {

        char nome[21];
        int pontuacao;

        } JOGADOR;

extern JOGADOR jogadorAtual, ranking[10];

void moveXY(int x, int y, char t[100]);
void printRanking(JOGADOR ranking[10]);
void initRanking(JOGADOR ranking[10]);
void abreRanking();

#endif // RANKING_H_INCLUDED
