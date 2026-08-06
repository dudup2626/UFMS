/*
Escreva uma função que recebe duas cadeias de caracteres (strings): uma
contendo uma palavra e outra contendo uma frase. A função deve deter-
minar a quantidade de vezes que a palavra ocorre na frase, buscando da
esquerda para a direita.
*/

#include <stdio.h>

int verifica_ocorrencia(char palavra[], char frase[]){
    int i, j, cont = 0;
    int tam_palavra = 0, tam_frase = 0;

    /* Calcula o tamanho da palavra */ 
    while(palavra[tam_palavra] != '\0'){
        tam_palavra++;
    }

    /* Calcula o tamanho da frase */
    while(frase[tam_frase] != '\0'){
        tam_frase++;
    }

    /* Verifica ocorrencias da palavra na frase */
    for(i = 0; i <= tam_frase - tam_palavra; i++){
        for(j = 0; j < tam_palavra; j++){
            if(frase[i + j] != palavra[j]){
                break;
            }
        }
        if(j == tam_palavra){
            cont++;
        }
    }

    printf("A palavra '%s' ocorre %d vezes na frase.\n", palavra, cont);
    
    return cont;
}

int main(void){
	char frase[100], palavra[20];

    scanf(" %[^\n]s", palavra);
    scanf(" %[^\n]s", frase);

    verifica_ocorrencia(palavra, frase);
	
	return 0;
}