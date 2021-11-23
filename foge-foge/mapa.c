#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void CopiaMapa(Mapa *copia, Mapa *original) {
	copia->linhas = original->linhas;
	copia->colunas = original->colunas;

	AlocaMapa(copia);
	for(int i = 0; i < original->linhas; i++) {
		strcpy(copia->matriz[i], original->matriz[i]);
	}
}

void LeMapa(Mapa *m) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do arquivo");
        exit(1);
    }

    fscanf(f, "%d %d", &m->linhas, &m->colunas);
    AlocaMapa(m);

    for(int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void AlocaMapa(Mapa* m) {
	m->matriz = malloc(sizeof(char*) * m->linhas);

	for(int i = 0; i < m->linhas; i++) {
		m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
	}
}

void LiberaMapa(Mapa* m) {
	for(int i = 0; i < m->linhas; i++) {
		free(m->matriz[i]);
	}

	free(m->matriz);
}

int EncontraMapa(Mapa* m, Posicao* p, char c) {

	for(int i = 0; i < m->linhas; i++) {
		for(int j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == c) {
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}

	return 0;
}

void andaNoMapa(Mapa *m, int origemX, int origemY, int destinoX, int destinoY) {
	char personagem = m->matriz[origemX][origemY];
	m->matriz[destinoX][destinoY] = personagem;
	m->matriz[origemX][origemY] = VAZIO;
}

int ehParede(Mapa* m, int x, int y) {
    return 
        m->matriz[x][y] == PAREDE_VERTICAL ||
        m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int ehPersonagem(Mapa* m, char personagem, int x, int y) {
    return
        m->matriz[x][y] == personagem;
}

int PodeAndar(Mapa* m, char personagem, int x, int y) {
    return 
        ehValida(m, x, y) && 
        !ehParede(m, x, y) &&
        !ehPersonagem(m, personagem, x, y);
}

int ehValida(Mapa *m, int x, int y) {
	if(x >= m->linhas)
		return 0;
	if(y >= m->colunas)
		return 0;
	
	return 1;
}

int ehVazia(Mapa *m, int x, int y) {
	return m->matriz[x][y] == VAZIO;
}