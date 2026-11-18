#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX 50000

typedef struct pilha
{
	int vetor[TAM_MAX];
	int topo;
} Pilha;

Pilha p;

void push(int numero);
int pop();
void imprimir();
int verificarCheia();
int verificarVazia();
void inicializar();
int numeroAleatorio(int low, int high);
int obterDado(int tamanho);
void exibirDado(int p);

void inicializar()
{
	p.topo = -1;
}

int verificarVazia()
{
	if (p.topo == -1)
		return 1;
	else
		return 0;
}

int verificarCheia()
{
	if (p.topo == TAM_MAX - 1)
		return 1;
	else
		return 0;
}

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

void push(int numero)
{
	// verificar se a pilha nao estah cheia
	if (!verificarCheia())
	{
		// atualiza o topo da pilha
		p.topo++;
		// insere o elemento no vetor na posi��o topo
		p.vetor[p.topo] = numero;
	}
	else
	{
		// se estiver cheia, informa o usu�rio
		printf("\nNao eh possivel inserir, pilha cheia.");
	}
}

int pop()
{
	// verificar se a pilha nao estah vazia
	if (!verificarVazia())
	{
		// define vari�vel uma variavel auxiliar
		int aux;
		// variavel auxiliar ira guardar o elemento do topo da pilha
		aux = p.vetor[p.topo];
		// atualiza o topo da pilha
		p.topo--;
		// retorna o numero removido
		return aux;
	}
	else
	{
		// se estiver vazia, informa o usu�rio
		printf("\nA pilha estah vazia.");
		return 0;
	}
}

void imprimir()
{
	// verificar se a pilha n�o est� vazia
	if (!verificarVazia())
	{
		// define uma vari�vel auxiliar
		int i;
		printf("\nOs elementos na pilha sao:");
		// percorrer o vetor do topo ate a base
		for (i = p.topo; i >= 0; i--)
			// imprimir o elemento na posicao i
			printf("\n%d", p.vetor[i]);
	}
	else
	{
		// se estiver vazia, informa o usuario
		printf("\nA pilha esta vazia.");
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
				push(temp);
				exibirDado(p.vetor[i]);
			}
			finish = (double)clock();
			elapsed = finish - start;
			printf("\nForam utilizados %.2f clocks", elapsed);
			break;

		case 2:
			start = (double)clock();
            for (int i = 0; i < quantidade; i++){
                temp = pop();
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
				exibirDado(p.vetor[i]);
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
