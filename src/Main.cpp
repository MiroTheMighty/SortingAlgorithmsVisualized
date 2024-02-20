#include <SFML/Graphics.hpp>
#include "SortingAlgorithms.hpp"
#include "DrawVector.hpp"
#include <random>

void GenerateVector(std::vector<int>& vec, int n){
    for(int i = 0; i < n; i++){
        vec.push_back(i);
    }
}

void ShuffleVector(std::vector<int>& vec, std::default_random_engine rng){
    std::shuffle(vec.begin(), vec.end(), rng);
}

void DrawWindow(std::vector<int>& vec, std::default_random_engine rng){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting algorithms");
    window.setFramerateLimit(60);

    sf::Font font;
    if(!font.loadFromFile("C:/Users/MiroTheMighty/Desktop/SortsVis/src/fonts/times new roman.ttf")){
        exit(1);
    }

    sf::Text menuText("1 - Bubble sort\n2 - Merge sort\n3 - Selection sort\n4 - Insertion sort\n5 - Quick sort\n6 - Heap sort", font, 35);
    menuText.setPosition(255, 150);
    menuText.setFillColor(sf::Color::White);

    bool finished = true;

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        window.draw(menuText);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed && finished) {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed && finished){
                switch(event.key.code){
                    case sf::Keyboard::Num1:
                        finished = false;
                        BubbleSort(vec, window);
                        SortingDone(vec, window);
                        ShuffleVector(vec, rng);
                        finished = true;
                        break;
                    case sf::Keyboard::Num2:
                        finished = false;
                        MergeSort(vec, 0, vec.size() - 1, window);
                        SortingDone(vec, window);
                        ShuffleVector(vec, rng);
                        finished = true;
                        break;
                    case sf::Keyboard::Num3:
                        finished = false;
                        SelectionSort(vec, vec.size(), window);
                        SortingDone(vec, window);
                        ShuffleVector(vec, rng);
                        finished = true;
                        break;
                    case sf::Keyboard::Num4:
                        finished = false;
                        InsertionSort(vec, vec.size(), window);
                        SortingDone(vec, window);
                        ShuffleVector(vec, rng);
                        finished = true;
                        break;
                    case sf::Keyboard::Num5:
                        finished = false;
                        QuickSort(vec, 0, vec.size()-1, window);
                        SortingDone(vec, window);
                        ShuffleVector(vec, rng);
                        finished = true;
                        break;
                    case sf::Keyboard::Num6:
                        finished = false;
                        HeapSort(vec, vec.size(), window);
                        SortingDone(vec, window);
                        ShuffleVector(vec, rng);
                        finished = true;
                        break;
                    default:
                        continue;
                        break;
                }
            }
        }
        window.display();
    }
}


int main(){
    auto rd = std::random_device {};
    auto rng = std::default_random_engine {rd()};
   
    int n = 42;
    std::vector<int> vec;
    GenerateVector(vec, n);
    ShuffleVector(vec, rng); 
    DrawWindow(vec, rng);
}