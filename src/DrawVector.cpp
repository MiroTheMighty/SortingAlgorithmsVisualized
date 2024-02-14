#include "DrawVector.hpp"

void DrawVector(const std::vector<int>& vec, sf::RenderWindow& window, int delayMillis) {
    window.clear(sf::Color::Black);

    int rectangleSize = 16;
    int padding = 3;

    std::vector<sf::RectangleShape> rectangles;

    for (int i = 0; i < vec.size(); i++) {
        sf::RectangleShape rectangle(sf::Vector2f(rectangleSize, rectangleSize + vec[i] * 5));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(i * rectangleSize + i * padding, 600 - rectangle.getSize().y);
        rectangles.push_back(rectangle);
    }

    for (const auto& rectangle : rectangles) {
        window.draw(rectangle);
    }

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
}