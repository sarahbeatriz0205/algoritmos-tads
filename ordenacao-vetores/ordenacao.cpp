#include "ordenacao.hpp"

bool ordenado(int a[],  unsigned int t){
    int i;
    for (i = 0; i < (t - 1); i++){ // Percorrer array A
            if (a[i] > a[i+1]){ // Compara antecessor e sucessor
                return false;
            }
        }
    return true;
}
    
void selecao(int a[],  unsigned int t){ // Desempenho: O(n²)
    int i, j, menor_atual, auxiliar;
    for (i = 0; i < (t-1); i++){
        menor_atual = i; // outro auxiliar
        for (j = i+1; j < t; j++){
            if (a[j] < a[menor_atual]){
                menor_atual = j;
            }
        }
        if (a[i] !=  a[menor_atual]){ // bota no lugar certo
            auxiliar = a[i]; // para que o valor do indice atual vá para o indice do menor_atual logo depois
            a[i] = a[menor_atual]; // substitui o menor atual pelo oq está nesse indice
            a[menor_atual] = auxiliar;
        }
    }
}

/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
   
}


void merge_sort(int a[], int primeiro, int ultimo){
   int meio;
   if (primeiro < ultimo){
    meio = (primeiro + ultimo) / 2;
    merge_sort(a, primeiro, meio);
    merge_sort(a, meio+1, ultimo);
    merge(a, primeiro, meio, meio+1, ultimo);
   }
}

void merge(int a[], int i1, int j1, int i2, int j2){
    // i1 = índice inicial do 1º vetor
    // j1 = índice final do 1º vetor
    // i2 = índice inicial do 2º vetor
    // j2 = índice final do 2º vetor
    int j = 0;
    int inicio = i1;
    int size = ((j1 - i1) + (j2 - i2) + 2); // define o tamanho do vetor ordenado
    int* temp = new int[size]; 
    int k = 0; // serve para percorrer o vetor ordenado
    while (i1 <= j1 && i2 <= j2){ // enquanto esse AND não for falso, ele continuará rodando  
        if (a[i1] < a[i2]){ // percorre os dois vetores ao mesmo tempo. quando um dos dois acabar, ele faz a verificação dos outros while pro caso do array restante ainda não ter acabado
            temp[k++] = a[i1++];
        }
        else{
            temp[k++] = a[i2++];
        }
    }
    while (i1 <= j1){ // copia o restante do 1º vetor pra temp caso o 2º vetor tenha acabado primeiro
        temp[k++] = a[i1++];
    }
    while (i2 <= j2){ // copia o restante do 2º vetor pra temp caso o 1º vetor tenha acabado primeiro
        temp[k++] = a[i2++];
    }
    for (int i = inicio, j; i <= j2; i++, j++){ // altera o vetor original
        a[i] = temp[j];
    }
    delete[] temp;
}

