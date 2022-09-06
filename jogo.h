#ifndef DISCOWINDOWS_H_INCLUDED
#define DISCOWINDOWS_H_INCLUDED

void aleatorio();
int parabola(float x);
void bordas();
int movimentaDisco(int contador, short* resetou);
void apaga(int somaCords, int contador);
int movimentaCanhao(char a, short reseta);
void desenhaCanhao();
int cronometro(int* timer);
void desenhaBala();
int movimentaBalas(char tecla, int xcanhao,int ybala, short balaandando, int xbalaandando);
int colisao(int xbalaandando, int ybala, int somaCords, int contador);
void pontuacao(int pontos);
void jogo(int dificuldade);
void desenhaCronometro();

#endif // DISCOWINDOWS_H_INCLUDED
