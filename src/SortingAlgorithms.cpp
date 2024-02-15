#include "SortingAlgorithms.hpp"
#include "DrawVector.hpp"

void SelectionSort(std::vector<int>& vec, int size, sf::RenderWindow& window){
    for(int step = 0; step < size-1; step++){
        int min_idx = step;
        for(int i = step+1; i < size; i++){
            DrawVector(vec, window, min_idx, i);
            if(vec[i] < vec[min_idx])
            min_idx = i;
        }
        Swap(&vec[min_idx], &vec[step]);
        DrawVector(vec, window, min_idx, step);
    }
}

void InsertionSort(std::vector<int>& vec, int n, sf::RenderWindow& window){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = vec[i];
        j = i - 1;

        while (j >= 0 && vec[j] > key) {
            DrawVector(vec, window, j, i);
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
        DrawVector(vec, window, j+1, i);
    }
}

void Merge(std::vector<int>& vec, size_t p, size_t q, size_t r, sf::RenderWindow& window){

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
        DrawVectorMerge(vec, window, p+i, q+1+j);
        if (L[i] <= M[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = M[j];
            j++;
        }
        k++;
        DrawVectorMerge(vec, window, p, r);
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

    DrawVectorMerge(vec, window, p, r);

    delete [] L;
    delete [] M;
}

void MergeSort(std::vector<int>& vec, size_t const begin, size_t const end, sf::RenderWindow& window){
     if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    MergeSort(vec, begin, mid, window);
    MergeSort(vec, mid + 1, end, window);
    Merge(vec, begin, mid, end, window);
}

void Swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(std::vector<int>& vec, int low, int high, sf::RenderWindow& window){
    int pivot = vec[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        DrawVectorQuick(vec, window, i+1, j, high);
        if(vec[j] <= pivot){
            i++;
            Swap(&vec[i], &vec[j]);
        }
    }
    Swap(&vec[i+1], &vec[high]);

    DrawVectorQuick(vec, window, i+1, high, i+1);

    return(i+1);
}

void QuickSort(std::vector<int>& vec, size_t low, size_t high, sf::RenderWindow& window){
    if (low < high) {
        int pi = Partition(vec, low, high, window);
        
        if (pi > 0) {
            QuickSort(vec, low, pi-1, window);
        }

        QuickSort(vec, pi+1, high, window);
    }
}

void BubbleSort(std::vector<int>& vec, sf::RenderWindow& window){
    for(int i = 0; i < vec.size() - 1; i++){
        for(int j = 0; j < vec.size() - i - 1; j++){
            DrawVector(vec, window, j, j+1, 25);
            if(vec[j] > vec[j+1]){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
            DrawVector(vec, window, j, j+1, 25);
        }
    }
}

void Heapify(std::vector<int>& vec, int n, int i, sf::RenderWindow& window){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    DrawVectorHeap(vec, window, left, right, i);
  
    if (left < n && vec[left] > vec[largest])
      largest = left;
  
    if (right < n && vec[right] > vec[largest])
      largest = right;
  
    if (largest != i) {
      Swap(&vec[i], &vec[largest]);
      Heapify(vec, n, largest, window);
    }
}

void HeapSort(std::vector<int>& vec, int n, sf::RenderWindow& window){
    for (int i = n / 2 - 1; i >= 0; i--){
      Heapify(vec, n, i, window);
    }
    for (int i = n - 1; i >= 0; i--) {
      Swap(&vec[0], &vec[i]);
      Heapify(vec, i, 0, window);
    }
}