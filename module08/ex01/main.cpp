#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    // Basic test
    {
        std::cout << "\n--- Basic Test ---\n";
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Range add test
    {
        std::cout << "\n--- Range Add Test ---\n";
        Span sp(10);
        std::vector<int> v;
        for (int i = 0; i < 10; ++i)
            v.push_back(i * 2);
        sp.addNumber(v.begin(), v.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Exception: Too many numbers
    {
        std::cout << "\n--- Exception: Overfill ---\n";
        try {
            Span sp(2);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3); // Should throw
        } catch (std::exception &e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    // Exception: Not enough numbers
    {
        std::cout << "\n--- Exception: Not enough elements ---\n";
        try {
            Span sp(5);
            sp.addNumber(42);
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    // Large dataset
    {
        std::cout << "\n--- Large Dataset Test ---\n";
        Span sp(10000);
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(std::rand());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Duplicate numbers
    {
        std::cout << "\n--- Duplicate Numbers ---\n";
        Span sp(4);
        sp.addNumber(7);
        sp.addNumber(7);
        sp.addNumber(7);
        sp.addNumber(7);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should be 0
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Should be 0
    }

    // Negative numbers
    {
        std::cout << "\n--- Negative Numbers ---\n";
        Span sp(6);
        sp.addNumber(-50);
        sp.addNumber(100);
        sp.addNumber(0);
        sp.addNumber(-100);
        sp.addNumber(25);
        sp.addNumber(-75);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    return 0;
}
