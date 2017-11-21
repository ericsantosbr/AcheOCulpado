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
void *creditos, *creditos_m, *iniciar, *iniciar_m, *opcoes, *opcoes_m, *sair, *sair_m;

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
	// Imagens da tela inicial terão um padrão de altura 60, com largura definida pela função escala()
	int scale = escala(619, 175, 40);
	int tam = imagesize(0, 0, scale, 60);
	iniciar = malloc(tam);
	readimagefile(".//cortes//iniciar.gif", 0, 0, scale, 60);
	
	getimage(0, 0, scale - 1, 59, iniciar);
	iniciar_m = malloc(tam);
	readimagefile(".//cortes//iniciar_m.gif", 0, 0, scale, 60);
	getimage(0, 0, scale - 1, 59, iniciar_m);
	
	
	scale = escala(787, 203, 40);
	tam = imagesize(0, 0, scale, 60);
	creditos = malloc(tam);
	readimagefile(".//cortes//creditos.gif", 0, 0, scale, 60);
	getimage(0, 0, scale - 1, 59, creditos);

	creditos_m = malloc(tam);
	readimagefile(".//cortes//creditos_m.gif", 0, 0, scale, 60);
	getimage(0, 0, scale - 1, 59, creditos_m);


	scale = escala(629, 239, 40);
	tam = imagesize(0, 0, scale, 60);
	opcoes = malloc(tam);
	readimagefile(".//cortes//opcoes.gif", 0, 0, scale, 60);
	getimage(0, 0, scale - 1, 59, opcoes);

	opcoes_m = malloc(tam);
	readimagefile(".//cortes//opcoes_m.gif", 0, 0, scale, 60);
	getimage(0, 0, scale - 1, 59, opcoes_m);
	

	scale = escala(384, 168, 40);
	tam = imagesize(0, 0, scale, 60);
	sair = malloc(tam);
	readimagefile(".//cortes//sair.gif", 0, 0, scale, 60);
	getimage(0, 0, scale - 1, 59, sair);

	getch();
	
	sair_m = malloc(tam);
	readimagefile(".//cortes//sair_m.gif", 0, 0, scale, 60);
	getimage(0, 0, scale - 1, 59, sair_m);
}

// Calcula as escalas das imagens da tela de inicio
int escala(int x, int y, int maxy){
	int saida;
	saida = (x * maxy) / y;
	printf("\n%d\n", saida);
	return saida;
}

// Tela inicial do jogo
void inicio(){
	int i, j, x, y, keep, passoy;
	passoy = 90;
	keep = 1;
	x = 10;
	y = 10;
	while(keep == 1){
		if(getactivepage() == 0) setactivepage(1);
		else setactivepage(0);
		cleardevice();
		if(GetKeyState(VK_ESCAPE) & 0x80) keep = 0;
				
		// Fundo
		
		// Plot das Opcoes
		x = 150;
		y = 60;
		
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
		
		if(getactivepage() == 0) setvisualpage(0);
		else setvisualpage(1);
	}
}
