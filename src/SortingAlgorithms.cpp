#include "SortingAlgorithms.hpp"

void SelectionSort(std::vector<int> vec, int size){
    for(int step = 0; step < size-1; step++){
        int min_idx = step;
        for(int i = step+1; i < size; i++){
            if(vec[i] < vec[min_idx])
            min_idx = i;
        }
        Swap(&vec[min_idx], &vec[step]);
    }
}

void InsertionSort(std::vector<int> vec, int size){
    for (int step = 1; step < size; step++) {
    int key = vec[step];
    int j = step - 1;

    while (key < vec[j] && j >= 0) {
      vec[j + 1] = vec[j];
      --j;
    }
    vec[j + 1] = key;
  }
}

void Merge(std::vector<int> vec, size_t p, size_t q, size_t r){

    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1];
    int *M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = vec[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = vec[q + 1 + j];


    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = M[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int> vec, size_t l, size_t r){
    int m = l + (r - l) / 2;

    MergeSort(vec, l, m);
    MergeSort(vec, m + 1, r);


    Merge(vec, l, m, r);
}

void Swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(std::vector<int> vec, int low, int high){
    int pivot = vec[high];
    int i = (low -1);

    for(int j = low; j < high; j++){
        if(vec[j] <= pivot){
            i++;
            Swap(&vec[i], &vec[j]);
        }
    }
    Swap(&vec[i+1], &vec[high]);

    return(i+1);
}

void QuickSort(std::vector<int> vec, size_t low, size_t high){
    if(low < high){
        int pi = Partition(vec, low, high);
        QuickSort(vec, low, pi-1);
        QuickSort(vec, pi+1, high);
    }
}

void BubbleSort(std::vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size() - i; j++){
            if(vec[j] > vec[j+1]){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}

void Heapify(std::vector<int> vec, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && vec[left] > vec[largest])
      largest = left;
  
    if (right < n && vec[right] > vec[largest])
      largest = right;
  
    if (largest != i) {
      Swap(&vec[i], &vec[largest]);
      Heapify(vec, n, largest);
    }
}

void HeapSort(std::vector<int> vec, int n){
    for (int i = n / 2 - 1; i >= 0; i--){
      Heapify(vec, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
      Swap(&vec[0], &vec[i]);
      Heapify(vec, i, 0);
    }
}