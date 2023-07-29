#include <exception>

template <typename T>
Array<T>::Array(void) : arr(new T[0]()), n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), n(n) {}

template <typename T>
Array<T>::Array(Array const& array) : arr(new T[array.n]()), n(array.n) {
  for (unsigned int i = 0; i < this->n; i++) this->arr[i] = array.arr[i];
}

template <typename T>
Array<T>::~Array(void) {
  delete[] arr;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& array) {
  if (this == &array) return *this;

  if (this->arr != NULL) delete this->arr;

  this->arr = new T[array.n]();
  this->n = array.n;
  for (unsigned int i = 0; i < this->n; i++) this->arr[i] = array.arr[i];
  return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
  if (idx < 0 or idx >= n) throw std::out_of_range("Index out of range");
  return this->arr[idx];
}

template <typename T>
unsigned int const& Array<T>::size(void) const {
  return this->n;
}
