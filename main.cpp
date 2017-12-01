/*
TODO: CONSERTAR AS ESCALAS DAS IMAGENS

DONE: INSERIR LINKS PARA AS IMAGENS
	  
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#include<iostream>
#include<graphics.h>
#include<time.h>

#define MAX_TEXTO 50

// Enums
enum telas{
	CETAF = 0,
	ESTACAO,
	PARQUE,
	SHOPPING	
};

// Imagens
// Tela inicial
void *creditos, *creditos_m, *iniciar, *iniciar_m, *opcoes, *opcoes_m, *sair, *sair_m, *logo, *logo_m;

// Fases do jogo
void *cetaf, *cetaf_m, *estacao, *estacao_m, *parque, *parque_m, *shopping, *shopping_m;

// Structs
// Struct dos blocos das fases. Oc -> "ocupado"; c -> "cima"; b -> "baixo"; e -> "esquerda"; d -> "direita"
struct bloco{
	int oc, c, b, e, d;
	void *sprite;
};

struct ponto{
	int x, y;
};


// Funcoes
// Configuracoes basicas do jogo
void configura();
void configuramapas();
void imagens();
int escala(int x, int y, int maxy);
void falas_pt();
void falas_en();
void configuraimgs();

// Telas Inicial e Um Jogador
int inicio();
void single();
void plottext(char *texto, int limpa);

// Variaveis globais
struct bloco cetafb[10][20], estacaob[10][20], parqueb[10][20], shoppingb[10][20];
struct ponto pers;


int main(){
	int com, keep;
	initwindow(800, 600);
	configura();
	
	keep = 1;
	while(keep == 1){
		com = inicio();
		if(com == 1) single();
		else if(com == 0){
			keep = 0;
		}
	}
	closegraph();
	return 0;
}

void configura(){
	int i, j, quant;
	int keep = 1;	
	int ling = 0;
	
	// Configuração de imagens
	imagens();
	
	// Configuração de colisão dos mapas
	configuramapas();
}

void configuramapas(){
	int i, j, k, cont, tam;
	char buffer[50];
	FILE *arq;
	
	// Configura o CETAF
	arq = fopen(".//mapas//mapacetaf.txt", "r");
	if(arq == NULL){
		printf("\nArquivo de colisao do CETAF não encontrado!");
		exit(-1);
	}
	
	for(i = 0; i < 10; i++){
		memset(buffer, 0, 20);
		fgets(buffer, 30, arq);
		tam = strlen(buffer);
		buffer[tam] = '\0';
		for(j = 0; j < 20; j++){
			cetafb[i][j].oc = buffer[j] - 48;
			printf("%d", cetafb[i][j].oc);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	// Configura a Estacao
	arq = fopen(".//mapas//mapaestacao.txt", "r");
	if(arq == NULL){
		printf("\nArquivo de colisao da Estacao não encontrado!");
		exit(-1);
	}
	
	for(i = 0; i < 10; i++){
		memset(buffer, 0, 20);
		fgets(buffer, 30, arq);
		tam = strlen(buffer);
		buffer[tam] = '\0';
		for(j = 0; j < 20; j++){
			estacaob[i][j].oc = buffer[j] - 48;
			printf("%d", estacaob[i][j].oc);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	// Configura o Parque
	arq = fopen(".//mapas//mapaparque.txt", "r");
	if(arq == NULL){
		printf("\nArquivo de colisao do Parque não encontrado!");
		exit(-1);
	}
	
	for(i = 0; i < 10; i++){
		memset(buffer, 0, 20);
		fgets(buffer, 30, arq);
		tam = strlen(buffer);
		buffer[tam] = '\0';
		for(j = 0; j < 20; j++){
			parqueb[i][j].oc = buffer[j] - 48;
			printf("%d", parqueb[i][j].oc);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	// Configura o Shopping
	arq = fopen(".//mapas//mapashopping.txt", "r");
	if(arq == NULL){
		printf("\nArquivo de colisao do Shopping não encontrado!");
		exit(-1);
	}
	
	for(i = 0; i < 10; i++){
		memset(buffer, 0, 20);
		fgets(buffer, 30, arq);
		tam = strlen(buffer);
		buffer[tam] = '\0';
		for(j = 0; j < 20; j++){
			shoppingb[i][j].oc = buffer[j] - 48;
			printf("%d", shoppingb[i][j].oc);
		}
		printf("\n");
	}
	fclose(arq);
}

void imagens(){
	setactivepage(3);
	int maxtelax = 800;
	int maxtelay = 400;
	
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
	
	// Fases do jogo
	cetaf = malloc(imagesize(0, 0, 800, 400));
	readimagefile(".//assets//CetafAOC.gif", 0, 0, maxtelax, maxtelay);
	getimage(0, 0, maxtelax - 1, maxtelay - 1, cetaf);
	
	estacao = malloc(imagesize(0, 0, 800, 400));
	readimagefile(".//assets//EstacaoAOC.gif", 0, 0, maxtelax, maxtelay);
	getimage(0, 0, maxtelax - 1, maxtelay - 1, estacao);
	
	parque = malloc(imagesize(0, 0, 800, 400));
	readimagefile(".//assets/ParqueAOC.gif", 0, 0, maxtelax, maxtelay);
	getimage(0, 0, maxtelax - 1, maxtelay - 1, parque);
	
	shopping = malloc(imagesize(0, 0, 800, 400));
	readimagefile(".//assets//ShoppingAOC.gif", 0, 0, maxtelax, maxtelay);
	getimage(0, 0, maxtelax - 1, maxtelay - 1, shopping);
	
	setactivepage(0);
}

// Calcula as escalas das imagens da tela de inicio
int escala(int x, int y, int maxy){
	int saida;
	saida = x / y * maxy;
	return saida;
}

// Tela inicial do jogo
int inicio(){
	int i, j, x, y, keep, passoy, sel, numopc, lb, xb, yb, pb, ox, oy, t, tam, keep2, t2;
	long long int ult;
	char *pos, *buff1, *buff2, *saida;
	void *fundo;
	buff1 = (char *) malloc(sizeof(char) * 4);
	buff2 = (char *) malloc(sizeof(char) * 4);
	saida = (char *) malloc(sizeof(char) * 15);
	pos = (char *) malloc(sizeof(char) * 10);
	
	// Distanciamento entre o plot das opçoes
	passoy = 30;
	
	// Mantem o loop rodando
	keep = 1;
	
	// Posicao dos plots
	x = 80;
	y = 300;
	
	// Variaveis de controle do bloco de retorno da selecao atual
	lb = 15;
	xb = (x - lb);
	yb = y;
	pb = passoy;
	
	// Opcao atual
	sel = 0;
	
	// Origem X e Origem Y
	ox = x;
	oy = y;
	
	// Tempo em milisegundos para aceitar o comando de uma tecla novamente
	t = 100;
	t2 = 500;
	ult = clock();
	
	// Tamanho da imagem de fundo a ser capturada
	fundo = (void *) malloc(imagesize(0, 0, getmaxx(), getmaxy()));
	
	// Numero de Opcoes
	numopc = 3;
	while(keep == 1){
		if(getactivepage() == 0) setactivepage(1);
		else setactivepage(0);
		cleardevice();
		if(GetKeyState(VK_ESCAPE) & 0x80 && clock() - t2 > ult){
			keep = 0;
			ult = clock();
			return 0;
		}
		
		// Fundo
		putimage(400, 50, logo_m, AND_PUT);
		putimage(400, 50, logo, OR_PUT);
		
		// Plot das Opcoes
		settextstyle(0, HORIZ_DIR, 3);
		outtextxy(x, y, "Iniciar");
		
		y += passoy;
		outtextxy(x, y, "Opcoes");
		
		y += passoy;
		outtextxy(x, y, "Creditos");
		
		y += passoy;
		outtextxy(x, y, "Sair");
		
		x = ox;
		y = oy;
		
		// Imprime bloco de retorno de seleção atual
		setfillstyle(1, YELLOW);
		
		yb = (sel * pb) + oy;
		
		setfillstyle(1, YELLOW);
		bar(xb, yb, xb + lb, yb + lb);
		
		yb = oy;
		
		if(GetKeyState(VK_UP) & 0x80  && clock() - t > ult){
			if(sel > 0) sel -= 1;
			ult = clock();
		}
		if(GetKeyState(VK_DOWN) & 0x80 && clock() - t > ult){
			if(sel < numopc) sel += 1;
			ult = clock();
		}
		if(GetKeyState(VK_RETURN) & 0x80 && clock() - t > ult){
			if(sel == 0){
				return 1;
			}
		}
		
		if(getactivepage() == 0) setvisualpage(0);
		else setvisualpage(1);
		
	}
}

// Jogo em Si
void single(){
	void *freeze;
	int x, y, z, atual, keep, tamfreeze, t, t2;
	long long int ult;
	atual = ESTACAO;
	keep = 1;
	pers.x = 9;
	pers.y = 2;
	
	tamfreeze = imagesize(0, 0, getmaxx(), getmaxy());
	freeze = malloc(tamfreeze);
	
	// Controle de tempo e delay do jogo
	
	t = 100;
	t2 = 300;
	ult = clock();
	
	
	while(keep == 1){
		if (getactivepage() == 0) setactivepage(1);
		else setactivepage(0);
		cleardevice();
		
		// Desenha o mapa e a interface
		if(atual == ESTACAO) putimage(0, 0, estacao, COPY_PUT);
		else if(atual == CETAF) putimage(0, 0, cetaf, COPY_PUT);
		else if(atual == PARQUE) putimage(0, 0, parque, COPY_PUT);
		else if(atual == SHOPPING) putimage(0, 0, shopping, COPY_PUT);
		
		setfillstyle(1, BLUE);
		bar(0, 400, getmaxx(), getmaxy());
		
		setfillstyle(1, BLACK);
		bar(5, 405, getmaxx() - 5, getmaxy() - 5);
		
		setfillstyle(1, BLUE);
		bar(10, 410, getmaxx() - 10, getmaxy() - 10);
		
		// Desenha o personagem
		fillellipse((pers.x * 40)+ 20, (pers.y * 40)+ 20, 18, 18);
		
		// Controle do personagem
		if(GetKeyState(VK_UP) & 0x80 && clock() - t > ult){
			if(pers.y > 0){
				if(atual == CETAF) if(cetafb[pers.y - 1][pers.x].oc == 0) pers.y -= 1;
				if(atual == ESTACAO){
					if(pers.x == 10 && pers.y == 7) pers.y = 1;
					else if(estacaob[pers.y - 1][pers.x].oc == 0) pers.y -= 1;
				}
				if(atual == PARQUE) if(parqueb[pers.y - 1][pers.x].oc == 0) pers.y -= 1;
				if(atual == SHOPPING) if(shoppingb[pers.y - 1][pers.x].oc == 0) pers.y -= 1;
			}
			ult = clock();
		}
		
		if(GetKeyState(VK_DOWN) & 0x80 && clock() - t > ult){
			if(pers.y < 9){
				if(atual == CETAF) if(cetafb[pers.y + 1][pers.x].oc == 0) pers.y += 1;
				if(atual == ESTACAO){
					if(pers.x == 10 && pers.y == 1){
						pers.y = 7;
					}
					else if(estacaob[pers.y + 1][pers.x].oc == 0) pers.y += 1;
				}
				if(atual == PARQUE) if(parqueb[pers.y + 1][pers.x].oc == 0) pers.y += 1;
				if(atual == SHOPPING)if(shoppingb[pers.y + 1][pers.x].oc == 0) pers.y += 1;
				ult = clock();
			}
		}
		
		if(GetKeyState(VK_LEFT) & 0x80 && clock() - t > ult){
			if(pers.x > 0){
				if(atual == CETAF){
					if(cetafb[pers.y][pers.x - 1].oc == 0) pers.x -= 1;
				}
				
				if(atual == ESTACAO){
					if(estacaob[pers.y][pers.x - 1].oc == 0){
						pers.x -= 1;
					}
				}
				if(atual == PARQUE){
					if(parqueb[pers.y][pers.x - 1].oc == 0) pers.x -= 1;
				}
				if(atual == SHOPPING){
					if(shoppingb[pers.y][pers.x - 1].oc == 0) pers.x -= 1;
				}
			}
			ult = clock();
		}
		
		if(GetKeyState(VK_RIGHT) & 0x80 && clock() - t > ult){
			if(pers.x < 19){
				if(atual == CETAF){
					if(cetafb[pers.y][pers.x + 1].oc == 0) pers.x += 1;
				}
				if(atual == ESTACAO){
					if(estacaob[pers.y][pers.x + 1].oc == 0) pers.x += 1;
				}
				if(atual == PARQUE){
					if(parqueb[pers.y][pers.x + 1].oc == 0) pers.x += 1;
				}
				if(atual == SHOPPING){
					if(shoppingb[pers.y][pers.x + 1].oc == 0) pers.x += 1;
				}
			}
			ult = clock();
		}
		
		if(GetKeyState(VK_ESCAPE) & 0x80 && clock() - t2 > ult){
			delay(250);
			getimage(0, 0, getmaxx(), getmaxy(), freeze);
			putimage(0, 0, freeze, COPY_PUT);
			int keep2 = 1;
			while(keep2 == 1){
				if(getactivepage() == 0) setactivepage(1);
				else setactivepage(0);
				cleardevice();
				putimage(0, 0, freeze, COPY_PUT);
				
				setfillstyle(1, WHITE);
				bar(150, 120, getmaxx() - 150, getmaxy() - 120);
				
				setfillstyle(1, BLUE);
				bar(160, 130, getmaxx() - 160, getmaxy() - 130);
				
				settextstyle(0, HORIZ_DIR, 15);
				outtextxy(180, 150, "Deseja Sair?");
				
				settextstyle(0, HORIZ_DIR, 100);
				outtextxy(180, 190, "Enter - Sim");
				
				outtextxy(180, 210, "Esc - Não");
								
				if(GetKeyState(VK_ESCAPE) & 0x80){
					keep2 = 0;
				}
				
				if(GetKeyState(VK_RETURN) & 0x80){
					keep = 0;
					keep2 = 0;
				}
				
				if(getactivepage() == 0) setvisualpage(0);
				else(setvisualpage(1));
			}
			ult = clock();
		}
		
		if (getactivepage() == 0) setvisualpage(0);
		else setvisualpage(1);
	}
}

// Imprime na tela o texto caractere-a-caractere
void plottext(char *texto, int limpa){
	
}

