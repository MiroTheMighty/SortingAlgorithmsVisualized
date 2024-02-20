#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

void DrawVector(const std::vector<int>& vec, sf::RenderWindow& window, int compareIndex1 = -1, int compareIndex2 = -1, int delayMillis = 50);
void DrawVectorMerge(const std::vector<int>& vec, sf::RenderWindow& window, size_t highlightStart, size_t highlightEnd, int delayMillis = 50);
void DrawVectorQuick(const std::vector<int>& vec, sf::RenderWindow& window, size_t highlight1 = -1, size_t highlight2 = -1, size_t partitionIndex = -1, int delayMillis = 50);
void DrawVectorHeap(const std::vector<int>& vec, sf::RenderWindow& window, int highlight1 = -1, int highlight2 = -1, int heapifyIndex = -1, int delayMillis = 50);
void SortingDone(const std::vector<int>& vec, sf::RenderWindow& window, int delayMillis = 150);