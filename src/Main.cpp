#include <SFML/Graphics.hpp>
#include "SortingAlgorithms.hpp"
#include <random>


int main(){
    auto rd = std::random_device {};
    auto rng = std::default_random_engine {rd()};
   
    int n = 42;

    std::vector<int> vec;
    for(int i = 0; i < n; i++){
        vec.push_back(i);
    }
    std::shuffle(vec.begin(), vec.end(), rng);
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting algorithms");
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Num1:
                        BubbleSort(vec, window);
                        break;
                    case sf::Keyboard::Num2:
                        break;
                    case sf::Keyboard::Num3:
                        break;
                    case sf::Keyboard::Num4:
                        break;
                    case sf::Keyboard::Num5:
                        break;
                    case sf::Keyboard::Num6:
                        break;
                    default:
                        window.close();
                        break;
                }
            }
        }
    }
    //BubbleSort(vec);
    //SelectionSort(vec, vec.size());
    //InsertionSort(vec, vec.size());
    //MergeSort(vec, 0, vec.size()-1);
    //QuickSort(vec, 0, vec.size()-1);
    //HeapSort(vec, vec.size());
}