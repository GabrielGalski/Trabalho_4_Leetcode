//merge sort 
//alterar para ler as 3 arrays do codigo
void merge(int* vet, int* vet2, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* pLeft = (int*)malloc(n1* sizeof(int));
    int* pRight = (int*)malloc(n2* sizeof(int));
    int* pLeft2 = (int*)malloc(n1* sizeof(int));
    int* pRight2 = (int*)malloc(n2* sizeof(int));
    for (int i = 0; i < n1; i++) {
        pLeft[i] = vet[left + i];
        pLeft2[i] = vet2[left + i];
    }
    for (int i = 0; i < n2; i++) {
        pRight[i] = vet[mid + 1 + i];
        pRight2[i] = vet2[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (pLeft[i] < pRight[j]) {
            vet[k] = pLeft[i];
            vet2[k] = pLeft2[i];
            i++;
        } else {
            vet[k] = pRight[j];
            vet2[k] = pRight2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vet[k] = pLeft[i];
        vet2[k] = pLeft2[i];
        i++;
        k++;
    }
    while (j < n2) {
        vet[k] = pRight[j];
        vet2[k] = pRight2[j];
        j++;
        k++;
    }
}
void mergeSort(int* vet, int* vet2, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vet, vet2, left, mid);
        mergeSort(vet, vet2, mid + 1, right);
        merge(vet, vet2, left, mid, right);
    }
}

//basicamente cada trabalho tem um lucro baseado na dificuldade qt maior a dificuldade maior é o lucro cada um dos works pode ter um trabalho + os trabalhos podem ter mais de um trabalhador. o trabalho maximo que um trabalhador tem é baseado no seu nivel então um trabalhador 4 não pode ter um trabalho 5
//vou ordenar as 3 arrays 
//usar merge
//ordenar as 3 arrays usando a merge e depois tentar atribuir o emprego certo pra cada trabalhador
//

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    
    //chamar o merge pra ordenar a dificuldade e o lucro e armazenar 
    mergeSort(difficulty, profit, 0, difficultySize - 1); 
    int* temp = (int*)malloc(workerSize * sizeof(int));

    //ordenar em ordem crescente os trabalhadores
    mergeSort(worker, temp, 0, workerSize -1); 
    
    int max=0, total=0, j=0;
    //if pra ver qual maior trabalho que um trabalhador pode fazer
    for (int i = 0; i < workerSize; i++) {
        while (j < difficultySize && worker[i] >= difficulty[j]) {
            if (profit[j] > max) { 
                max = profit[j];
            }
            j++;
        }
        total += max;
    }
    return total; 
}
