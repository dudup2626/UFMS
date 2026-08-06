#include <stdio.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
    char nome[50];
    float salario;
    Data d;
    char sexo;
    float ind_prod;
    float grat;
} Funcionario;

void Inclui_funcionario(Funcionario f[], int *cont_f){
    /* scanf(" %49[^\n]", f[*cont_f].nome);
    // scanf("%f", &f[*cont_f].salario);
    // scanf("%d/%d/%d", &f[*cont_f].d.dia, &f[*cont_f].d.mes, &f[*cont_f].d.ano);
    // scanf(" %c", &f[*cont_f].sexo);
    // scanf("%f", &f[*cont_f].ind_prod);
    // (*cont_f)++;*/

    strcpy(f[*cont_f].nome, "Eduardo Pereira");
    f[*cont_f].salario = 1000.00;
    f[*cont_f].d.dia = 04;
    f[*cont_f].d.mes = 12;
    f[*cont_f].d.ano = 2006;
    f[*cont_f].sexo = 'M';
    f[*cont_f].ind_prod = 0.5;
    (*cont_f)++;

    strcpy(f[*cont_f].nome, "Pedro Alves");
    f[*cont_f].salario = 2000.50;
    f[*cont_f].d.dia = 22;
    f[*cont_f].d.mes = 10;
    f[*cont_f].d.ano = 2020;
    f[*cont_f].sexo = 'M';
    f[*cont_f].ind_prod = 1.0;
    (*cont_f)++;

    strcpy(f[*cont_f].nome, "Pedro Carbone");
    f[*cont_f].salario = 3000.50;
    f[*cont_f].d.dia = 05;
    f[*cont_f].d.mes = 02;
    f[*cont_f].d.ano = 2010;
    f[*cont_f].sexo = 'M';
    f[*cont_f].ind_prod = 0.1;
    (*cont_f)++;

    strcpy(f[*cont_f].nome, "Matheus Mariano");
    f[*cont_f].salario = 4000.50;
    f[*cont_f].d.dia = 20;
    f[*cont_f].d.mes = 01;
    f[*cont_f].d.ano = 2015;
    f[*cont_f].sexo = 'M';
    f[*cont_f].ind_prod = 0.7;
    (*cont_f)++;
}

/*
void Mostrar_funcionario(Funcionario f[], int cont_f){
    int i;
    for(i = 0; i < cont_f; i++){
        printf("Nome: %s\n", f[i].nome);
        printf("Salario: %.2f\n", f[i].salario);
        printf("Data de admissao: %02d/%02d/%04d\n", f[i].d.dia, f[i].d.mes, f[i].d.ano);
        printf("Sexo: %c\n", f[i].sexo);
        printf("Indice de produtividade: %.2f\n", f[i].ind_prod);
    }
}
*/

float Media(Funcionario f[], int cont_f, char op){
    int i;
    float media = 0;
    if(op == 's'){
        for(i=0; i<cont_f; i++)
            media = media + f[i].salario;
    } if(op == 'g'){
        for(i=0; i<cont_f; i++)
            media = media + f[i].grat;
    }
    media = media / cont_f;
    return media;
}
float Maior(Funcionario f[], int cont_f, char op){
    int i;
    float maior = 0;
    if(op == 's'){
        for(i=0; i<cont_f; i++)
            if(f[i].salario > maior)
                maior = f[i].salario;
    } if(op == 'g'){
        for(i=0; i<cont_f; i++)
            if(f[i].grat > maior)
                maior = f[i].grat;
    }
    return maior;
}
float Menor(Funcionario f[], int cont_f, char op){
    int i;
    float menor = f[0].salario;
    if(op == 's'){
        for(i=0; i<cont_f; i++)
            if(f[i].salario < menor)
                menor = f[i].salario;
    } if(op == 'g'){
        for(i=0; i<cont_f; i++)
            if(f[i].grat < menor)
                menor = f[i].grat;
    }
    return menor;
}
void Quant(Funcionario f[], int cont_f, float media, char op){
    int i, acima = 0, abaixo = 0, igual = 0;

    if(op == 's'){
        for(i=0; i<cont_f; i++){
            if(f[i].salario > media)
                acima++;
            if(f[i].salario < media)
                abaixo++;
            if(f[i].salario == media)
                igual++;
        }
        printf("Quantidade de funcionários com salário acima da média: %d\n", acima);
        printf("Quantidade de funcionários com salário abaixo da média: %d\n", abaixo);
        printf("Quantidade de funcionários com salário igual a média: %d\n", igual);
    } if(op == 'g'){
        for(i=0; i<cont_f; i++){
            if(f[i].grat > media)
                acima++;
            if(f[i].grat < media)
                abaixo++;
            if(f[i].grat == media)
                igual++;
        }
        printf("Quantidade de funcionários com gratificação acima da média: %d\n", acima);
        printf("Quantidade de funcionários com gratificação abaixo da média: %d\n", abaixo);
        printf("Quantidade de funcionários com gratificação igual a média: %d\n", igual);
    }    
}
void Nome_funcionarios(Funcionario f[], int cont_f, float media){
    int i;
    printf("Funcionários com salário acima da média:\n");
    for(i=0; i<cont_f; i++)
        if(f[i].salario > media)
            printf("- %s\n", f[i].nome);
    printf("Funcionários com salário abaixo da média:\n");
    for(i=0; i<cont_f; i++)
        if(f[i].salario < media)
            printf("- %s\n", f[i].nome);
    printf("Funcionários com salário igual a média:\n");
    for(i=0; i<cont_f; i++)
        if(f[i].salario == media)
            printf("- %s\n", f[i].nome);      
}
void Relatorios_salarios(Funcionario f[], int cont_f){
    float media_sal, maior_sal, menor_sal;

    media_sal = Media(f, cont_f, 's');
    printf("Média salarial: %.2f\n", media_sal);

    maior_sal = Maior(f, cont_f, 's');
    printf("Maior salário: %.2f\n", maior_sal);

    menor_sal = Menor(f, cont_f, 's');
    printf("Menor salário: %.2f\n", menor_sal);

    Quant(f, cont_f, media_sal, 's');

    Nome_funcionarios(f, cont_f, media_sal);
    printf("\n");
}

void Calcula_gratificacao(Funcionario f[], int cont_f){
    int i;
    float media_sal, maior_sal;
    media_sal = Media(f, cont_f, 's');
    maior_sal = Maior(f, cont_f, 's');
    for(i=0; i<cont_f; i++){
        if(f[i].salario < media_sal){
            f[i].grat = f[i].ind_prod * 1.0;
        } else {
            if(f[i].salario < (media_sal + maior_sal) / 2)
                f[i].grat = f[i].ind_prod * 0.8;
            else
                f[i].grat = f[i].ind_prod * 0.5;
        }
    }
}
void Relatorios_gratificacao(Funcionario f[], int cont_f){
    float media_grat, menor_grat, maior_grat;

    Calcula_gratificacao(f, cont_f);

    media_grat = Media(f, cont_f, 'g');
    printf("Média de gratificação: %.2f\n", media_grat);

    menor_grat = Menor(f, cont_f, 'g');
    printf("Menor gratificação: %.2f\n", menor_grat);

    maior_grat = Maior(f, cont_f, 'g');
    printf("Maior gratificação: %.2f\n", maior_grat);

    Quant(f, cont_f, media_grat, 'g');

    Nome_funcionarios(f, cont_f, media_grat);
    printf("\n");
    media_grat = maior_grat - menor_grat;
}


int main(void){
    Funcionario f[10];
    int op, cont_f = 0;

    do{
    printf("Opcoes: \n");
    printf("1 - Incluir um novo funcionário na folha de pagamento.\n");
    printf("2 - Gerar relatório de salários.\n");
    printf("3 - Exibir relatório de gratificação.\n");
    printf("4 - Gerar relatório de pagamentos.\n");
    printf("0 - Sair do programa.\n");
    scanf("%d", &op);
    
    switch(op){
        case 1:
            Inclui_funcionario(f, &cont_f);
            break;
        case 2:
            Relatorios_salarios(f, cont_f);
            break;
        case 3:
            Relatorios_gratificacao(f, cont_f);
            break;
        case 0:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opção inválida.\n");
    } } while(op != 0);

return 0;
}