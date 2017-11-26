/*
TODO: CONSERTAR AS ESCALAS DAS IMAGENS

DONE: INSERIR LINKS PARA AS IMAGENS
	  
*/

#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#include<graphics.h>

#define MAX_TEXTO 50

// Imagens
void *creditos, *creditos_m, *iniciar, *iniciar_m, *opcoes, *opcoes_m, *sair, *sair_m, *logo, *logo_m;

// Structs

// Funcoes
void configura();
void imagens();
int escala(int x, int y, int maxy);
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
}

void imagens(){
	setactivepage(3);
	// Imagens da tela inicial terão um padrão de altura 40, com largura definida pela função escala()
	int maxalt = 40;
	int scale = escala(619, 175, maxalt);
	int tam = imagesize(0, 0, scale, maxalt);
	iniciar = malloc(tam);
	readimagefile(".//cortes//iniciar.gif", 0, 0, scale, maxalt);
	
	getimage(0, 0, scale - 1, maxalt - 1, iniciar);
	iniciar_m = malloc(tam);
	readimagefile(".//cortes//iniciar_m.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, iniciar_m);
	
	
	scale = escala(787, 203, maxalt);
	tam = imagesize(0, 0, scale, 60);
	creditos = malloc(tam);
	readimagefile(".//cortes//creditos.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, creditos);

	creditos_m = malloc(tam);
	readimagefile(".//cortes//creditos_m.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, creditos_m);


	scale = escala(629, 239, maxalt);
	tam = imagesize(0, 0, scale, maxalt);
	opcoes = malloc(tam);
	readimagefile(".//cortes//opcoes.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, opcoes);

	opcoes_m = malloc(tam);
	readimagefile(".//cortes//opcoes_m.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, opcoes_m);
	

	scale = escala(384, 168, maxalt);
	tam = imagesize(0, 0, scale, maxalt);
	sair = malloc(tam);
	readimagefile(".//cortes//sair.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, sair);
	
	sair_m = malloc(tam);
	readimagefile(".//cortes//sair_m.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, sair_m);
	
	// Logo do jogo	
	maxalt = 200;
	scale = escala(673, 344, maxalt);
	tam = imagesize(0, 0, scale, maxalt);
	logo = malloc(tam);
	readimagefile(".//cortes//logo.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, logo);

	logo_m = malloc(tam);
	readimagefile(".//cortes//logo_m.gif", 0, 0, scale, maxalt);
	getimage(0, 0, scale - 1, maxalt - 1, logo_m);
	
	setactivepage(0);
}

// Calcula as escalas das imagens da tela de inicio
int escala(int x, int y, int maxy){
	int saida;
	saida = x / y * maxy;
	printf("\n%d\n", saida);
	return saida;
}

// Tela inicial do jogo
void inicio(){
	int i, j, x, y, keep, passoy, sel;
	char *pos, *buff1, *buff2, *saida;
	buff1 = (char *) malloc(sizeof(char) * 4);
	buff2 = (char *) malloc(sizeof(char) * 4);
	saida = (char *) malloc(sizeof(char) * 15);
	pos = (char *) malloc(sizeof(char) * 10);
	int bx = 0;
	int by = 0;
	int lb = 20;
	int pb = 2;
	passoy = 60;
	keep = 1;
	x = 100;
	y = 220;
	printf("\n%d e %d\n", getmaxy() - lb, getmaxx() - lb);
	sel = 0;
	while(keep == 1){
		if(getactivepage() == 0) setactivepage(1);
		else setactivepage(0);
		cleardevice();
		if(GetKeyState(VK_ESCAPE) & 0x80) keep = 0;
		
		// Fundo
		putimage(400, 50, logo_m, AND_PUT);
		putimage(400, 50, logo, OR_PUT);
		
		// Plot das Opcoes		
		putimage(x, y, iniciar_m, AND_PUT);
		putimage(x, y, iniciar, OR_PUT);
		
		y += passoy;
		putimage(x, y, opcoes_m, AND_PUT);
		putimage(x, y, opcoes, OR_PUT);
		
		y += passoy;
		putimage(x, y, creditos_m, AND_PUT);
		putimage(x, y, creditos, OR_PUT);
		
		y += passoy;
		putimage(x, y, sair_m, AND_PUT);
		putimage(x, y, sair, OR_PUT);
		
		x = 100;
		y = 220;
		
		
		// TESTE: INSERE BARRA PARA TESTAR POSICOES
		if(GetKeyState(VK_UP) & 0x80 && by > 0) by -= pb;
		if(GetKeyState(VK_DOWN) & 0x80 && by < getmaxy() - lb) by += pb;
		if(GetKeyState(VK_LEFT) & 0x80 && bx > 0) bx -= pb;
		if(GetKeyState(VK_RIGHT) & 0x80 && bx < getmaxx() - lb) bx += pb;
		
		setfillstyle(1, WHITE);
		bar(bx, by, bx + lb, by + lb);
		
		// TESTE: PLOT DA POSICAO
		sprintf(saida, "(%d, %d)", bx, by);
		outtextxy(getmaxx() - 80, getmaxy() - 20, saida);
		
		if(getactivepage() == 0) setvisualpage(0);
		else setvisualpage(1);
		
	}
}
