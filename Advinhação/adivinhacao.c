#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "portuguese");

   

    printf("          P  /_\\  P                               \n");
    printf("         /_\\_|_|_/_\\                             \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinha��o! \n");
    printf("    |" "  |  |_|  |"  " |                          \n");
    printf("    |_____| ' _ ' |_____|                          \n");
    printf("          \\__|_|__/                               \n\n\n");



	
	srand(time(0));
	int numerosecreto = rand()%100;
	float pontos = 1000;
	
	int numerotentativas;
	int nivel;
    printf("\n Qual o n�vel de dificuldade?\n");
    printf(" 1. F�cil\n 2. M�dio\n 3. Dif�cil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    
    switch (nivel){
    	case 1: numerotentativas = 20; break;
		case 2: numerotentativas = 15; break;	
    	case 3: numerotentativas = 6; break;
	}
	
	
	int chute;
	int acertou;
	int tentativas = 1;
	for(int i = 1; i <= numerotentativas; i++) {
		
		printf("\n---- Tentativa %d ----\n", tentativas);	

		printf("> Qual � o seu chute: ");
		scanf("%d",&chute);
		printf("> Seu chute foi: %d\n\n", chute);

		if(chute < 0) {
			printf("> Voc� deve digitar um n�mero positivo!\n\n");
			continue;
		}
		
		acertou = (chute == numerosecreto);
		int maior = (chute > numerosecreto);
		int menor = (chute < numerosecreto);
		
		if(acertou) {
			printf("> Parab�ns voc� acertou!\n");
			break;
		}else if(maior) {
			printf("> Voc� errou! O n�mero � menor que sua tentativa!\n\n");	
		}else if(menor){
			printf("> Voc� errou! O numero � maior que sua tentativa!\n\n");
		}		
		
		tentativas++;
		
		float pontosPerdidos = abs(chute - numerosecreto) / 2.0;
		pontos -= pontosPerdidos;
	}

	printf("\n------- FIM DE JOGO -------\n\n\n");
	
	if(acertou){
		printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
		printf("Voc� acertou em %d tentativas.\n", tentativas);
		printf("Sua pontua��o final �: %.1f.\n",pontos);
		
	}else{
		printf(" ------ Voc� perdeu! ------\n");
		printf("   O n�mero secreto era %d.\n",numerosecreto);
		
		printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        
	}
	

}
