#pragma once
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

void SelectionSort(std::vector<int>& vec, int size, sf::RenderWindow& window);
void InsertionSort(std::vector<int>& vec, int size, sf::RenderWindow& window);
void Merge(std::vector<int>& vec, size_t p, size_t q, size_t r, sf::RenderWindow& window);
void MergeSort(std::vector<int>& vec, size_t l, size_t r, sf::RenderWindow& window);
void Swap(int* a, int* b);
int Partition(std::vector<int>& vec, int low, int high, sf::RenderWindow& window);
void QuickSort(std::vector<int>& vec, size_t low, size_t high, sf::RenderWindow& window);
void BubbleSort(std::vector<int>& vec, sf::RenderWindow& window);
void Heapify(std::vector<int>& vec, int n, int i, sf::RenderWindow& window);
void HeapSort(std::vector<int>& vec, int n, sf::RenderWindow& window);