
#ifndef _FOGEFOGE_h_
#define _FOGEFOGE_h_

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define COMANDO_BOMBA 'b'

int Acabou();
int ehDirecao(char direcao);
void Fantasmas();
void Move(char direcao);
void ExplodeBomba();
void ExplodeDirecao(int x, int y, int somaX, int somaY, int qtd);

#endif