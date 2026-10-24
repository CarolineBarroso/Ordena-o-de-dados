#include <stdio.h>

void bubble(int v[], int n) {

    int i, j, aux;

    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - 1; j++) {

            if (v[j] > v[j + 1]) {

                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void insertion(int v[], int n) {

    int i, j, aux;

    for (i = 1; i < n; i++) {

        aux = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > aux) {

            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = aux;
    }
}

void selection(int v[], int n) {

    int i, j, menor, aux;

    for (i = 0; i < n - 1; i++) {

        menor = i;

        for (j = i + 1; j < n; j++) {

            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void merge(int v[], int inicio, int meio, int fim) {

    int aux[10];
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {

        if (v[i] <= v[j]) {

            aux[k] = v[i];
            i++;

        } else {

            aux[k] = v[j];
            j++;
        }

        k++;
    }

    while (i <= meio) {

        aux[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim) {

        aux[k] = v[j];
        j++;
        k++;
    }

    for (i = inicio, k = 0; i <= fim; i++, k++) {

        v[i] = aux[k];
    }
}

void mergeSort(int v[], int inicio, int fim) {

    int meio;

    if (inicio < fim) {

        meio = (inicio + fim) / 2;

        mergeSort(v, inicio, meio);

        mergeSort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}

void quick(int v[], int inicio, int fim) {

    int i = inicio;
    int j = fim;
    int pivo;
    int aux;

    pivo = v[(inicio + fim) / 2];

    while (i <= j) {

        while (v[i] < pivo) {
            i++;
        }

        while (v[j] > pivo) {
            j--;
        }

        if (i <= j) {

            aux = v[i];
            v[i] = v[j];
            v[j] = aux;

            i++;
            j--;
        }
    }

    if (inicio < j) {
        quick(v, inicio, j);
    }

    if (i < fim) {
        quick(v, i, fim);
    }
}

void mostrar(int v[], int n) {

    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}

int main() {

    FILE *arquivo;

    int original[10];
    int v[10];

    int n;
    int i;
    int opcao;

    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {

        printf("Erro ao criar arquivo!\n");

        return 1;
    }


    printf("Quantos numeros deseja digitar? ");
    scanf("%d", &n);


    if (n < 1 || n > 10) {

        printf("Digite uma quantidade entre 1 e 10.\n");

        fclose(arquivo);

        return 1;
    }


    printf("\nDigite os numeros:\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &original[i]);

        fprintf(arquivo, "%d\n", original[i]);
    }

    fclose(arquivo);

    do {

        printf("Escolha a Ordenação\n");
        
        
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Quick Sort\n");
        printf("0 - Sair\n");

        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);


        /* Copia os numeros originais */

        for (i = 0; i < n; i++) {
            v[i] = original[i];
        }

        switch (opcao) {

            case 1:

                bubble(v, n);

                printf("\nBubble Sort escolhido.\n");

                break;


            case 2:

                insertion(v, n);

                printf("\nInsertion Sort escolhido.\n");

                break;


            case 3:

                selection(v, n);

                printf("\nSelection Sort escolhido.\n");

                break;


            case 4:

                mergeSort(v, 0, n - 1);

                printf("\nMerge Sort escolhido.\n");

                break;


            case 5:

                quick(v, 0, n - 1);

                printf("\nQuick Sort escolhido.\n");

                break;


            case 0:

                printf("\nPrograma encerrado.\n");

                break;


            default:

                printf("\nOpcao invalida.\n");
        }

        if (opcao >= 1 && opcao <= 5) {

            printf("\nNumeros ordenados:\n");

            mostrar(v, n);


            arquivo = fopen("resultado.txt", "w");

            if (arquivo == NULL) {

                printf("Erro ao criar resultado.txt!\n");

            } else {

                for (i = 0; i < n; i++) {

                    fprintf(arquivo, "%d\n", v[i]);
                }

                fclose(arquivo);

                printf("\nResultado salvo em resultado.txt\n");
            }
        }


    } while (opcao != 0);


    return 0;
}