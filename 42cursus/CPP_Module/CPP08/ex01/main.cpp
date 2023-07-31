#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <list>

#include "Span.hpp"

int main() {
  std::cout << "----------< subject test >----------" << std::endl;
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "----------< range addNumber test >----------" << std::endl;
  {
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) vec.push_back(i);

    Span sp = Span(5);
    std::cout << "before Span size: " << sp.getSize() << std::endl;
    sp.print();

    sp.addNumber(vec.begin(), vec.end());

    std::cout << "after Span size: " << sp.getSize() << std::endl;
    sp.print();
  }
  std::cout << std::endl;

  std::cout << "----------< list addNumber test >----------" << std::endl;
  {
    std::list<int> list;
    for (int i = 1; i <= 5; ++i) list.push_back(i);

    Span sp = Span(5);
    std::cout << "before Span size: " << sp.getSize() << std::endl;
    sp.print();

    sp.addNumber(list.begin(), list.end());

    std::cout << "after Span size: " << sp.getSize() << std::endl;
    sp.print();
  }
  std::cout << std::endl;

  std::cout << "----------< addNumber exception test >----------" << std::endl;
  {
    try {
      Span sp = Span(3);
      sp.addNumber(42);
      sp.addNumber(42);
      sp.addNumber(42);
      sp.addNumber(42);
      sp.addNumber(42);
      sp.print();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;

  std::cout << "----------< range addNumber exception test >----------"
            << std::endl;
  {
    try {
      std::vector<int> vec;
      for (int i = 1; i <= 5; ++i) vec.push_back(i);

      Span sp = Span(3);
      sp.addNumber(vec.begin(), vec.end());

      sp.print();
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;

  std::cout << "----------< member function exception test >----------"
            << std::endl;
  {
    Span sp = Span(5);
    sp.addNumber(42);
    try {
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    sp.addNumber(20);
    try {
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;

  std::cout << "----------< stress test >----------" << std::endl;
  {
    std::srand(std::time(0));
    std::vector<int> vec;
    for (int i = 0; i < 20000; ++i) vec.push_back(std::rand() % 100000);

    Span sp = Span(20000);

    sp.addNumber(vec.begin(), vec.end());

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
