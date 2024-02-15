#include "DrawVector.hpp"

void DrawVector(const std::vector<int>& vec, sf::RenderWindow& window, int compareIndex1, int compareIndex2, int delayMillis) {
    window.clear(sf::Color::Black);

    int rectangleSize = 16;
    int padding = 3;

    std::vector<sf::RectangleShape> rectangles;

    for (int i = 0; i < vec.size(); i++) {
        sf::RectangleShape rectangle(sf::Vector2f(rectangleSize, rectangleSize + vec[i] * 5));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(i * rectangleSize + i * padding, 600 - rectangle.getSize().y);

        if (i == compareIndex1 || i == compareIndex2) {
            rectangle.setFillColor(sf::Color::Red);
        }

        rectangles.push_back(rectangle);
    }

    for (const auto& rectangle : rectangles) {
        window.draw(rectangle);
    }

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
}

void DrawVectorMerge(const std::vector<int>& vec, sf::RenderWindow& window, size_t highlightStart, size_t highlightEnd, int delayMillis) {
    window.clear(sf::Color::Black);

    int rectangleSize = 16;
    int padding = 3;

    std::vector<sf::RectangleShape> rectangles;

    for (size_t i = 0; i < vec.size(); i++) {
        sf::RectangleShape rectangle(sf::Vector2f(rectangleSize, rectangleSize + vec[i] * 5));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(i * rectangleSize + i * padding, 600 - rectangle.getSize().y);

        if (i >= highlightStart && i <= highlightEnd) {
            rectangle.setFillColor(sf::Color::Red);
        }

        rectangles.push_back(rectangle);
    }

    for (const auto& rectangle : rectangles) {
        window.draw(rectangle);
    }

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
}

void DrawVectorQuick(const std::vector<int>& vec, sf::RenderWindow& window, size_t highlight1, size_t highlight2, size_t partitionIndex, int delayMillis) {
    window.clear(sf::Color::Black);

    int rectangleSize = 16;
    int padding = 3;

    std::vector<sf::RectangleShape> rectangles;

    for (size_t i = 0; i < vec.size(); i++) {
        sf::RectangleShape rectangle(sf::Vector2f(rectangleSize, rectangleSize + vec[i] * 5));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(i * rectangleSize + i * padding, 600 - rectangle.getSize().y);

        if (i == highlight1 || i == highlight2) {
            rectangle.setFillColor(sf::Color::Red);
        } else if (i == partitionIndex) {
            rectangle.setFillColor(sf::Color::Green);
        }

        rectangles.push_back(rectangle);
    }

    for (const auto& rectangle : rectangles) {
        window.draw(rectangle);
    }

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
}

void DrawVectorHeap(const std::vector<int>& vec, sf::RenderWindow& window, int highlight1, int highlight2, int heapifyIndex, int delayMillis) {
    window.clear(sf::Color::Black);

    int rectangleSize = 16;
    int padding = 3;

    std::vector<sf::RectangleShape> rectangles;

    for (size_t i = 0; i < vec.size(); i++) {
        sf::RectangleShape rectangle(sf::Vector2f(rectangleSize, rectangleSize + vec[i] * 5));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(i * rectangleSize + i * padding, 600 - rectangle.getSize().y);

        if (static_cast<int>(i) == highlight1 || static_cast<int>(i) == highlight2) {
            rectangle.setFillColor(sf::Color::Red);
        } else if (static_cast<int>(i) == heapifyIndex) {
            rectangle.setFillColor(sf::Color::Green);
        }

        rectangles.push_back(rectangle);
    }

    for (const auto& rectangle : rectangles) {
        window.draw(rectangle);
    }

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
}