#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //para poder usar palavras com acentua��o

int main() //in�cio da fun��o
{
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentua��o
	int Tab[8][8] = { 0 }, a = 0, b = 0, c; //vari�veis do tipo inteiro
	int peao = 1, cav = 2, tor = 3; //vari�veis do tipo inteiro
	int bis = 4, rei = 5, rai = 6, semP = 0; //vari�veis do tipo inteiro
	int npeao = 0, ncav = 0, ntor = 0, nbis = 0; //vari�veis do tipo inteiro
	int nrei = 0, nrai = 0, nsemP = 0; //vari�veis do tipo inteiro

	//zerando todas as posi��es da matriz:
	for (a = 0; a < 8; a++) {
		for (b = 0; b < 8; b++) {
			Tab[a][b] = 0;
		}
	}

	//apresenta��o e menu para inser��o de pe�as no tabuleiro:
	printf("*********************** TABULEIRO DE XADREZ ***********************\n\n\n");
	printf("____________________MENU PARA INSER��O DE PE�AS____________________\n\n");
	printf("\t1 - Pe�o\n");
	printf("\t2 - Cavalo\n");
	printf("\t3 - Torre\n");
	printf("\t4 - Bispo\n");
	printf("\t5 - Rei\n");
	printf("\t6 - Rainha\n");
	printf("\t0 - N�o quero inserir pe�a nesta posi��o\n\n");
	printf("___________________________________________________________________\n\n");

	//pede para o usu�rio digitar um n�mero para cada posi��o no tabuleiro:
	for (a = 0; a < 8; a++) //linhas
	{
		for (b = 0; b < 8; b++) //colunas
		{
			printf("Digite o n�mero da pe�a que deseja colocar na posi��o [%d][%d]: ", a+1, b+1);
			scanf_s("%d", &Tab[a][b]);
			while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado

			//la�o de repeti��o para caso o usu�rio digite um n�mero menor que 0 ou maior que 6:
			while (Tab[a][b] < 0 || Tab[a][b] > 6) {
				printf("Digite um n�mero entre 0 e 6!\n");
				printf("Digite o n�mero da pe�a que deseja colocar na posi��o [%d][%d]: ", a, b);
				scanf_s("%d", &Tab[a][b]);
				while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
			}
		}
		printf("\n"); //para os n�meros n�o ficarem todos na mesma linha
	}

	printf("\n\n"); //para pular mais linhas

	//imprime o tabuleiro digitado pelo usu�rio:
	printf("***************** SEU TABULEIRO *****************\n\n");
	for (a = 0; a < 8; a++) //linhas
	{
		for (b = 0; b < 8; b++) //colunas
		{
			printf("  %d", Tab[a][b]); //espa�o antes do %d para os n�s n�o ficarem colados
		}
		printf("\n\n"); //para os caracteres n�o ficarem todos na mesma linha
	}

	//verifica a quantidade de cada pe�a no tabuleiro
	for (a = 0; a < 8; a++) {
		for (b = 0; b < 8; b++) {
			switch (Tab[a][b])
			{
			case 1: //quantos 1 o usu�rio inseriu
				npeao++; // soma 1 pe�o
				break;
			case 2: //quantos 2 o usu�rio inseriu
				ncav++; // soma 1 cavalo
				break;
			case 3: //quantos 3 o usu�rio inseriu
				ntor++; // soma 1 torre
				break;
			case 4: //quantos 4 o usu�rio inseriu
				nbis++; // soma 1 bispo
				break;
			case 5: //quantos 5 o usu�rio inseriu
				nrei++; // soma 1 rei
				break;
			case 6: //quantos 6 o usu�rio inseriu
				nrai++; // soma 1 rainha
				break;
			case 0: //quantos 0 o usu�rio inseriu
				nsemP++; // soma 1 espa�o vazio
				break;
			default:
				break;
			}
		}
	}

	//impress�o na tela da quantidade de cada tipo de pe�a inserida no tabuleiro:
	printf("\n\n***** QUANTIDADE DE CADA TIPO DE PE�A NO TABULEIRO *****\n\n");
	printf("Voc� inseriu %d pe�es no tabuleiro.\n", npeao);
	printf("Voc� inseriu %d cavalos no tabuleiro.\n", ncav);
	printf("Voc� inseriu %d torres no tabuleiro.\n", ntor);
	printf("Voc� inseriu %d bispos no tabuleiro.\n", nbis);
	printf("Voc� inseriu %d reis no tabuleiro.\n", nrei);
	printf("Voc� inseriu %d rainhas no tabuleiro.\n", nrai);
	printf("Voc� deixou %d posi��es sem pe�as.\n", nsemP);

	printf("\n\n"); //para pular 2 linhas

	system("pause");
	return 0;
} //fim da fun��o