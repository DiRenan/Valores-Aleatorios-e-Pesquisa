#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int nomeVetor[], procura=0, tam, inicio, meio, fim, vet[];

void pesquisa(int nomeVetor[], int procura, int tam);
void bolha(int vet[], int tam);

int main()
{
	int numeros[20], i, busca;

	time_t t;
	srand((unsigned) time(&t));
	
	printf("Vetor desordenado: \n\n");
	
	for(i=0;i<20;i++)
	{
		numeros[i] = rand() % 100;
		printf("%d ", numeros[i]);
	}
	
	bolha(numeros, 20);
	
	printf("\n\nVetor ordenado por Bubble Sort: \n\n");
	
	for(i=0;i<20;i++)
	{
		printf("%d ", numeros[i]);
	}
	
	printf("\n\nEscolha um numero para procurar no vetor: ");
	scanf("%d", &busca);
	
	pesquisa(numeros, busca, 20);
}

void pesquisa(int nomeVetor[], int procura, int tam)
{ 	
	inicio=0; 
	fim= tam - 1; 
	meio=(inicio + fim)/2;
	
	while(procura != nomeVetor[meio] && inicio != fim)
	{ 
		if(procura > nomeVetor[meio])
		{ 
			inicio=meio+1;
		} 
		else 
		{
			fim=meio;
		} 
		meio=(inicio+fim)/2; 
	}
	if(nomeVetor[meio]==procura)
	{
		printf("\nValor encontrado\n"); 
	} 
	else 
	{ 
		printf("\nValor nao encontrado\n"); 
	}
}

void bolha(int vet[], int tam)
{	
	int j, i, aux;
	
	for(i=0;i<tam-1;i++)
	{
		for(j=tam-1;j>i;j--)
		{
			if(vet[j]<vet[j-1])
			{
				aux=vet[j];
				vet[j]=vet[j-1];
				vet[j-1]=aux;
			}
		}
	}
}
