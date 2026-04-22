#include "selecao.h"

/* Função auxiliar privada para trocar a posição de dois elementos */
static void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int linear_search(int arr[], int n, int chave) {
    // Percorre o vetor elemento por elemento
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave) {
            return i; 
        }
    }
    return -1; 
}

static int particionar(int arr[], int low, int high) {
    int pivot = arr[high]; // O pivô é o último elemento
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            trocar(&arr[i], &arr[j]);
            i++;
        }
    }
    trocar(&arr[i], &arr[high]); // Coloca o pivô no seu lugar correto
    return i;
}

int quick_select(int arr[], int low, int high, int k) {
    // Validação básica do limite
    if (low <= high) {
        // Encontra a posição final do pivô
        int pi = particionar(arr, low, high);

        // Se o pivô estiver exatamente na posição procurada (k-1 porque k é base 1 e índice é base 0)
        if (pi == k - 1) {
            return arr[pi];
        }
        // Se a posição do pivô for maior que a procurada, buscar na metade esquerda
        else if (pi > k - 1) {
            return quick_select(arr, low, pi - 1, k);
        }
        // Se for menor, buscar na metade direita
        else {
            return quick_select(arr, pi + 1, high, k);
        }
    }
    return -1;
}