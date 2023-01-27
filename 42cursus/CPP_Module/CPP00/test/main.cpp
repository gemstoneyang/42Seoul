#include <iostream>

class Animal {
  private:
    int food;
    int weight;

  public:
    Animal(int _food, int _weight) : food(_food), weight(_weight) {}
    void increase_food(int inc);
    void view_stat(void);
};

void Animal::increase_food(int inc) {
  food += inc;
  weight += (inc / 3);
}
void Animal::view_stat(void) {
  std::cout << "food stat : " << food << std::endl;
  std::cout << "weight stat : " << weight << std::endl;
}

int	main(void)
{
  Animal animal(10, 100);
  animal.view_stat();
  animal.increase_food(10);
  animal.view_stat();
  return 0;
}
