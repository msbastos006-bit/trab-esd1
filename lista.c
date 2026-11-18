#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


#define TAM_MAX 50000

typedef struct lista
{
    int vetor[TAM_MAX];
    int final;
} Lista;

Lista l;

void inserir(int numero, int posicao);
void imprimir();
int remover(int posicao);
void inicializar();
int verificarVazia();
int verificarCheia();
int numeroAleatorio(int low, int high);
int obterDado(int tamanho);
void exibirDado(int p);

void inicializar()
{
    l.final = -1;
}

int verificarVazia()
{
    if (l.final == -1)
        return 1;
    else
        return 0;
}

int verificarCheia()
{
    if (l.final == TAM_MAX - 1)
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

void inserir(int numero, int posicao)
{
    // verificar se a lista nao estah cheia
    if (!verificarCheia())
    {
        // verifica se a posicao eh maior ao final
        if (posicao > l.final)
        {
            // atualiza final
            l.final++;
            // guarda elemento na posicao final
            l.vetor[l.final] = numero;
        }
        else
        {
            int i;
            // deixar a posicao livre translando os elementos
            for (i = l.final; i >= posicao; i--)
                l.vetor[i + 1] = l.vetor[i];
            // guarda elemento na posicao desejada
            l.vetor[posicao] = numero;
            // atualiza final
            l.final++;
        }
    }
    else
    {
        // se ela estiver cheia, avisar usuario
        printf("\nA lista estah cheia.");
    }
}

void imprimir()
{
    // verificar se a lista n�o est� vazia
    if (!verificarVazia())
    {
        // define uma vari�vel auxiliar
        int i;
        printf("\nOs numeros na lista sao: ");
        // percorrer o vetor do inicio ateh final
        for (i = 0; i <= l.final; i++)
            // imprimir o elemento na posicao i
            printf("%d ", l.vetor[i]);
    }
    else
    {
        // se estiver vazia, informa o usuario
        printf("\nA lista esta vazia");
    }
}

int remover(int posicao)
{
    // verifica se a lista nao estah vazia
    if (!verificarVazia())
    {
        // verifica se existe elemento valido na posicao desejada
        if (posicao <= l.final)
        {
            int i;
            // define uma variavel auxiliar
            int aux = 0;
            // variavel auxiliar guarda o elemento da posicao
            aux = l.vetor[posicao];
            // transladar os elementos da posicao ate final - 1
            for (i = posicao; i < l.final; i++)
                l.vetor[i] = l.vetor[i + 1];
            // atualiza o final da lista
            l.final--;
            // retorna elemento removido
            return aux;
        }
        else
        {
            // se nao existe elemento na posicao, informa o usuario
            printf("\nNao existe elemento na posicao indicada.");
        }
    }
    else
    {
        // se lista vazia, informa o usuario
        printf("\nA lista estah vazia.");
    }
    return 0;
}

int main(int argc, char *argv[])
{
    inicializar();
    srand(time(NULL));
    int opcao, temp, posicao;
    double start, finish, elapsed;
    int quantidade;

    printf("Digite a quantidade de elementos para testar: ");
    scanf("%d", &quantidade);
    do
    {
        // exibir o menu
        printf("\n MENU");
        printf("\n1. Inserir");
        printf("\n2. Remover");
        printf("\n3. Exibir");
        printf("\n4. Sair");
        printf("\nDigite a opcao desejada: ");
        // pedir a opcao ao usuario
        scanf("%i", &opcao);

        // processar a opcao desejada
        switch (opcao)
        {
        case 1:
            start = (double)clock();
            for (int i = 0; i < quantidade; i++)
            {
                int p = obterDado(quantidade);
                inserir(p, i);
                exibirDado(l.vetor[i]);
            }
            finish = (double)clock();
            elapsed = finish - start;
            printf("\nForam utilizados %.2f clocks", elapsed);
            break;
        case 2:
            start = (double)clock();
            for (int i = 0; i < quantidade; i++){
                temp = remover(i);
                exibirDado(temp);
            }
            finish = (double)clock();
            elapsed = finish - start;
            printf("\nForam utilizados %.2f clocks", elapsed);
            break;
        case 3:
            start = (double)clock();
            for (int i = 0; i < quantidade; i++){
                obterDado(l.vetor[i]);
            }
            finish = (double)clock();
            elapsed = finish - start;
            printf("\nForam utilizados %.2f clocks", elapsed);
            break;
        case 4:
            printf("\nSaindo do programa...");
            return 0;
        default:
            printf("\nEscolha uma opcao valida!");
        }

    } while (opcao != 5);
    return 0;
}