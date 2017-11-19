#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#include<graphics.h>

#define MAX_TEXTO 50

// Variaveis
char **menu_en;
char **menu_pt;

// Structs

// Funcoes
void configura();
void falas_pt();
void falas_en();
void configuraimgs();
void inicio();

int main(){
	initwindow(800, 550);
	configura();
	inicio();
	getch();
	closegraph();
	return 0;
}

void configura(){
	int i, j, quant;
	int keep = 1;	
	int ling = 0;
	
	// Configuração de textos do menu em PT-BR
	falas_pt();
}

// Configuracao das falas em PT-BR
void falas_pt(){
	int i;
	int cont = 0;
	int max_char = 50;
	char buffer[max_char];
	
	// Alocação de memória
	for(i = 1; i <= 5; i++)	{
		menu_pt = (char **) realloc (menu_pt, sizeof(char *) * i);
		menu_pt[i - 1] = (char *) malloc(sizeof(char) * max_char);
	}
	
	// Associação dos textos
	strcpy(menu_pt[0], "Iniciar");
	strcpy(menu_pt[1], "Opções");
	strcpy(menu_pt[2], "Créditos");
	strcpy(menu_pt[3], "Sair");
}

// Tela inicial do jogo
void inicio(){
	int i, j, x, y;
	x = 10;
	y = 10;
	for(i = 0; i < 4; i++){
		outtextxy(x, y, menu_pt[i]);
		y += 20;
	}
}
