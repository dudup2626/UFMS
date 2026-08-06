/*
Suponha que em um determinado galpão estejam armazenados os materiais de construção de
uma loja que vende tais materiais. O galpão é quadrado, medindo 20 × 20 = 400m²,
em cada 2 × 2 = 4m² há uma certa quantidade de um material armazenado. 
O galpão está totalmente ocupado. O encarregado do setor tem uma tabela representando 
o galpão, contendo, em cada célula, o código do material, seu preço e sua quantidade. 
Observe que um mesmo material pode encontrar-se em mais que um local no galpão.

Escreva funções para:
Listar o código, quantidade total e preço de cada material disponível no galpão. 
Cada material deve ser listado apenas uma vez.

Listar o código, quantidade total e preço de cada material disponível no galpão, 
ordenados pelo valor preço * quantidade. Cada material deve ser listado apenas uma vez.
*/

#include <stdio.h>

void preenche(int cod[][10], int quant[][10], float preco[][10], int cod1[]){
	int i, j;
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			cod[i][j] = i * 10 + j;
			quant[i][j] = i * 10 + j * 10;
			preco[i][j] = i * 100 + j * 10;
			cod1[i * 10 + j] = cod[i][j];
		}
	}
}

void verifica_repetido(int cod[][10], int quant[][10], float preco[][10], int cod1[], int cod_nao_rep[], int quant1[]){
	int i, j, k;
	k = 0;
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			cod_nao_rep[k] = cod[i][j];
		}
	}
}

void mostra_ocup_galpao(int cod[][10], int quant[][10], float preco[][10]){
	int i, j;
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			printf("\ngalpao[%d][%d]:", i, j);
			printf("\ncodigo: %d", cod[i][j]);
			printf("\nquantidade: %d", quant[i][j]);
			printf("\npreco: %f\n", preco[i][j]);
		}
	}	
}

int main(void){
	int cod[10][10], quant[10][10], cod1[100], cod_nao_rep[50], quant1[100];
	float preco[10][10];
	
	preenche(cod, quant, preco, cod1);
	verifica_repetido(cod, quant, preco, cod1, cod_nao_rep, quant1);
	mostra_ocup_galpao(cod, quant, preco);
	
	return 0;
}