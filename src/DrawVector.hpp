#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

void DrawVector(const std::vector<int>& vec, sf::RenderWindow& window, int delayMillis = 100);