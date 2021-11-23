#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"

char desenhofantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoheroi[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhobomba[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void ImprimeParte(char desenho[4][7], int parte) {
    printf("%s", desenho[parte]);
}

void ImprimeMapa(Mapa* m) {
	for(int i = 0; i < m->linhas; i++) {

        for(int parte = 0; parte < 4; parte++) {

            for(int j = 0; j < m->colunas; j++) {
                switch (m->matriz[i][j])
                {
                case FANTASMA: ImprimeParte(desenhofantasma, parte);
                    break;
                case HEROI: ImprimeParte(desenhoheroi, parte);
                    break;
                case BOMBA: ImprimeParte(desenhobomba, parte);
                    break;
                case PAREDE_VERTICAL:
                case PAREDE_HORIZONTAL:
                    ImprimeParte(desenhoparede, parte);
                    break;
                case VAZIO: ImprimeParte(desenhovazio, parte);
                    break;
                }
            }

            printf("\n");
        }
	}
}