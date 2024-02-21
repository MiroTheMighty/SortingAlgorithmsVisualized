#pragma once
#include <random>
#include "SortingAlgorithms.hpp"
#include "DrawVector.hpp"

void GenerateVector(std::vector<int>& vec, int n);
void ShuffleVector(std::vector<int>& vec, std::default_random_engine rng);
void DrawWindow(std::vector<int>& vec, std::default_random_engine rng);
void RunApplication();