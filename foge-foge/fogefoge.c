#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

Mapa mapa;
Posicao heroi;
int temBomba = 0;

int DestinoFantasma(int atualX, int atualY, int *destinoX, int *destinoY) {
	
	int opcoes[4][2] = {
		{atualX, atualY + 1},
		{atualX + 1, atualY},
		{atualX, atualY - 1},
		{atualX - 1, atualY}
	};

	srand(time(0));
	for(int i = 0; i < 10; i++) {
		int posicao = rand() % 4;

        if(PodeAndar(&mapa, FANTASMA ,opcoes[posicao][0], opcoes[posicao][1])) 
		{
            *destinoX = opcoes[posicao][0];
            *destinoY = opcoes[posicao][1];
            return 1;
        }
	}

	return 0;
}

void Fantasmas() {
    Mapa copia;

    CopiaMapa(&copia, &mapa);

    for(int i = 0; i < copia.linhas; i++) {
        for(int j = 0; j < copia.colunas; j++) {
            if(copia.matriz[i][j] == FANTASMA) {

                int destinoX;
                int destinoY;

                int encontrou = DestinoFantasma(i, j, &destinoX, &destinoY);

                if(encontrou) {
                    andaNoMapa(&mapa, i, j, destinoX, destinoY);
                }
            }
        }
    }

    LiberaMapa(&copia);
}

int Acabou() {
	Posicao pos;
	int fogefogeNoMapa = EncontraMapa(&mapa, &pos, HEROI);
    return !fogefogeNoMapa;
}

int ehDirecao(char direcao) {
	return direcao == ESQUERDA ||
	   direcao == DIREITA ||
	   direcao == CIMA ||
	   direcao == BAIXO;

}
void Move(char direcao) {

	if(!ehDirecao(direcao)) {
		return;
	}
	
	int novox = heroi.x;
	int novoy = heroi.y;

	switch(direcao) {
		case ESQUERDA:
			novoy--;
			break;
		case CIMA:
			novox--;
			break;
		case BAIXO:
			novox++;
			break;
		case DIREITA:
			novoy++;
			break;
	}

	if(!PodeAndar(&mapa, HEROI, novox, novoy))
		return;

	if(ehPersonagem(&mapa, BOMBA, novox, novoy)) {
		temBomba = 1;
	}

	andaNoMapa(&mapa, heroi.x, heroi.y, novox, novoy);
	heroi.x = novox;
	heroi.y = novoy;
}

void ExplodeBomba() {

	ExplodeDirecao(heroi.x, heroi.y, 0, 1, 3); //direita
	ExplodeDirecao(heroi.x, heroi.y, 0, -1, 3); //esquerda
	ExplodeDirecao(heroi.x, heroi.y, 1, 0, 3); //baixo
	ExplodeDirecao(heroi.x, heroi.y, -1, 0, 3); //cima

	temBomba = 0;
}

void ExplodeDirecao(int x, int y, int somaX, int somaY, int qtd) {
	if(qtd == 0){
		return;
	}

	int novoX = x + somaX;
	int novoY = y + somaY;

	if(!ehValida(&mapa, novoX, novoY) || ehParede(&mapa, novoX, novoY)) {
		return;
	}

	mapa.matriz[novoX][novoY] = VAZIO;
	ExplodeDirecao(novoX, novoY, somaX, somaY, qtd - 1);	
	
}

int main () {
    LeMapa(&mapa);
	EncontraMapa(&mapa, &heroi, HEROI);

	do {

		printf("Tem bomba: %s\n", (temBomba ? "SIM" : "NAO"));
		ImprimeMapa(&mapa);

		char comando;
		scanf(" %c", &comando);
		if(temBomba && comando == COMANDO_BOMBA)
			ExplodeBomba();
		Fantasmas();
		Move(comando);
		
		
	} while (!Acabou());

    LiberaMapa(&mapa);

}