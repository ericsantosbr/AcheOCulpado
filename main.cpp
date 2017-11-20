#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#include<graphics.h>

#define MAX_TEXTO 50

// Variaveis
char **menu_en;
char **menu_pt;

// Imagens
void *creditos, *creditos_m, *iniciar, *iniciar_m, *opcoes, *opcoes_m, *sair, *sair_m;

// Structs

// Funcoes
void configura();
void imagens();
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
	
	// Configuração de imagens
	imagens();
	
	// Configuração de textos do menu em PT-BR
	falas_pt();
}

void imagens(){
	setactivepage(3);
	int tam = imagesize(0, 0, 211, 59);
	// TESTE: REMOVER O SETVISUALPAGE
	setvisualpage(3);
	setfillstyle(2, WHITE);
	bar(0, 0, getmaxx(), getmaxy());
	iniciar = malloc(tam);
	iniciar_m = malloc(tam);
	readimagefile(".//cortes//iniciar.gif", 0, 0, 212, 60);
	getimage(0, 0, 211, 59, iniciar);
	getch();
	readimagefile(".//cortes//iniciar_m.gif", 0, 0, 212, 60);
	getimage(0, 0, 211, 59, iniciar_m);
	getch();
	setactivepage(0);
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
	int i, j, x, y, keep;
	keep = 1;
	x = 10;
	y = 10;
	while(keep == 1){
		if(getactivepage() == 0) setactivepage(1);
		else setactivepage(0);
		cleardevice();
		if(GetKeyState(VK_ESCAPE) & 0x80) keep = 0;
		
		putimage(60, 60, iniciar_m, AND_PUT);
		putimage(60, 60, iniciar, OR_PUT);
		
		x = 10;
		y = 10;
		if(getactivepage() == 0) setvisualpage(0);
		else setvisualpage(1);
	}
}
