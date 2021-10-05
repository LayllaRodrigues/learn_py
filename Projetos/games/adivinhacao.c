#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 3

int main() {
	printf("************************************\n");
	printf("* Bem vindo ao Jogo de AdivinhaÃ§Ã£o *\n");
	printf("************************************\n");

	int chute;
	double pontos = 1000;

	int nivel;
	int totaldetentativas;

	int acertou;
	
	srand(time(0));
	int numerosecreto = rand() % 100;

	printf("Qual o nÃ­vel de dificuldade?\n");
	printf("(1) FÃ¡cil (2) MÃ©dio (3) DifÃ­cil\n\n");
	printf("Escolha: ");

	scanf("%d", &nivel);

	if(nivel == 1) {
		totaldetentativas = 20;
	} else if (nivel == 2) {
		totaldetentativas = 15;
	} else {
		totaldetentativas = 6;
	}

	for(int i = 1; i <= totaldetentativas; i++) {

		printf("Tentativa %d de %d\n", i, totaldetentativas);

		printf("Qual Ã© o seu %do. chute? ", i);
		scanf("%d", &chute);

		if(chute < 0) {
			printf("VocÃª nÃ£o pode chutar nÃºmeros negativos\n");
			continue;
		}

		printf("Seu %do. chute foi %d\n", i, chute);

		int acertou = chute == numerosecreto;
		int maior = chute > numerosecreto;

		if(acertou) {
			printf("ParabÃ©ns! VocÃª acertou!\n");
			break;
		} else if(maior) {
			printf("Seu chute foi maior do que o nÃºmero secreto!\n");
		} else {
			printf("Seu chute foi menor do que o nÃºmero secreto!\n");
		}

		double pontosperdidos = abs(chute - numerosecreto) / 2.0;
		pontos = pontos - pontosperdidos;
	}

	printf("Você fez %.2f pontos", pontos);
	printf("Obrigado por jogar!\n");

}