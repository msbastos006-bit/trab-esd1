#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX 50000

void inserir(int numero);
void inicializar();
int verificarVazia();
int verificarCheia();
void imprimir();
int remover();
int numeroAleatorio(int low, int high);
int obterDado(int tamanho);
void exibirDado(int p);

typedef struct fila
{
	int vetor[TAM_MAX];
	int final;
} Fila;

Fila f;



int numeroAleatorio(int low, int high)
{
    int k;
    double d;
    d = (double)rand() / ((double)high + 1);
    k = d * (high - low + 1);
    return low + k;
}

int obterDado(int tamanho)
{
    return numeroAleatorio(0, tamanho);
}

void exibirDado(int p)
{
    printf("\nElemento: %i", p);
}

void inicializar()
{
	f.final = -1;
}

int verificarVazia()
{
	if (f.final == -1)
		return 1;
	else
		return 0;
}

int verificarCheia()
{
	if (f.final == TAM_MAX - 1)
		return 1;
	else
		return 0;
}

void inserir(int numero)
{
	// verificar se a fila nao estah cheia
	if (!verificarCheia())
	{
		// atualiza o final da fila
		f.final++;
		// insere o numero no vetor no final
		f.vetor[f.final] = numero;
	}
	else
	{
		// informa o usuario que a fila estah cheia
		printf("\nA fila estah cheia.");
	}
}

void imprimir()
{
	// verificar se a fila nao estah vazia
	if (!verificarVazia())
	{
		int i;
		printf("\nOs elementos na fila sao: ");
		// percorrer o vetor de 0 ateh f.final
		for (i = 0; i <= f.final; i++)
			// imprimir o elemento na posicao i
			printf(" %d", f.vetor[i]);
	}
	else
	{
		printf("\nA fila estah vazia.");
	}
}

int remover()
{
	// verificar se a fila n�o estah vazia
	if (!verificarVazia())
	{
		int aux, i;
		// aux ir� guardar o elemento do in�cio da fila
		aux = f.vetor[0];
		// translada os elementos do inicio ao fim -1
		for (i = 0; i <= f.final - 1; i++)
			// a posi��o i receber o valor da posi��o i+1
			f.vetor[i] = f.vetor[i + 1];
		// atualizar o final da fila
		f.final--;
		return aux;
	}
	else
	{
		printf("A fila estah vazia.");
	}
}

int main(int argc, char *argv[])
{
	inicializar();
	srand(time(NULL));
	int temp, opcao;
	double start, finish, elapsed;
	int quantidade;

	printf("Digite a quantidade de elementos para testar: ");
    scanf("%d", &quantidade);
	do
	{
		// exibir o menu
		printf("\n    MENU");
		printf("\n1. Inserir");
		printf("\n2. Remover");
		printf("\n3. Imprimir");
		printf("\n4. Sair");
		printf("\nDigite a opcao desejada: ");

		// ler a opcao desejada pelo usuario
		scanf("%d", &opcao);

		// processar a funcionalidade
		switch (opcao)
		{

		case 1:
			start = (double)clock();
			for (int i = 0; i < quantidade; i++)
			{
				temp = obterDado(quantidade);
				inserir(temp);
				exibirDado(f.vetor[i]);
			}
			finish = (double)clock();
			elapsed = finish - start;
			printf("\nForam utilizados %.2f clocks", elapsed);
			break;
		case 2:
			start = (double)clock();
            for (int i = 0; i < quantidade; i++){
                temp = remover();
				if (temp == -1){
					printf("remoção falhou");
				}else{
					exibirDado(temp);
				}
				
            }
            finish = (double)clock();
            elapsed = finish - start;
            printf("\nForam utilizados %.2f clocks", elapsed);
            break;
		case 3:
			start = (double)clock();
			for (int i = 0; i < quantidade; i++)
			{
				exibirDado(f.vetor[i]);
			}
            
            finish = (double)clock();
            elapsed = finish - start;
            printf("\nForam utilizados %.2f clocks", elapsed);
            break;

		case 4:
			printf("Encerrando o programa...");
			return 0;
		default:
			printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}

	} while (opcao != 5);
}
