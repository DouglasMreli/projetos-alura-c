#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define FANTASMA 'F'
#define BOMBA 'B' 
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-' 

typedef struct mapa{
    char** matriz;
    int linhas;
    int colunas;
}Mapa;

void AlocaMapa(Mapa *m);
void CopiaMapa(Mapa *copia, Mapa *original); 
void LeMapa(Mapa *m);
void LiberaMapa(Mapa *m);
void andaNoMapa(Mapa *m, int origemX, int origemY, int destinoX, int destinoY);
int ehParede(Mapa* m, int x, int y);
int ehPersonagem(Mapa* m, char personagem, int x, int y);
int ehValida(Mapa *m, int x, int y);
int ehVazia(Mapa *m, int x, int y);
int PodeAndar(Mapa* m, char personagem, int x, int y);

typedef struct posicao
{
    int x;
    int y;
}Posicao;

int EncontraMapa(Mapa* m, Posicao* p, char c);

#endif