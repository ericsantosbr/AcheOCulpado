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
	FILE *arquivo;
	
	arquivo = fopen(".//falas//inicio-pt.txt", "r");
	
	if(arquivo == NULL){
		printf("\nArquivo de falas do menu nao existe!\nFavor inserir arquivos na pasta falas\n");
		exit(1);
	}
	
	if(fgets(buffer, max_char, arquivo) != NULL){
		cont++;
		menu_pt = (char **) realloc(menu_pt, sizeof(char *) * cont);
		menu_pt[cont -1] = (char *) malloc(sizeof(char) * MAX_TEXTO);
	}
	
	for(i=0; i < cont; i++) printf("%s\n", menu_pt[i]);
	
}

void inicio(){
//	outtextxy();
}
