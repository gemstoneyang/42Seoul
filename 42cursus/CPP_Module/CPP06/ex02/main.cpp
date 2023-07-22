#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void) {
  int i = rand() % 3;
  char const arr[3] = {'A', 'B', 'C'};

  std::cout << "generate: " << arr[i] << std::endl;
  if (i == 0)
    return new A();
  else if (i == 1)
    return new B();
  else
    return new C();
}

void identify(Base *p) {
  std::cout << "pointer cast: ";
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  std::cout << "reference cast: ";
  try {
    A &a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    (void)a;
  } catch (std::exception &e) {
    try {
      B &b = dynamic_cast<B &>(p);
      std::cout << "B" << std::endl;
      (void)b;
    } catch (std::exception &e) {
      try {
        C &c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        (void)c;
      } catch (std::exception &e) {
        std::cout << "Error" << std::endl;
      }
    }
  }
}

int main(void) {
  srand(time(0));

  Base *base = generate();
  identify(base);
  identify(*base);

  delete base;

  return 0;
}
