#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <cstddef>
#include <ctime>
#include <deque>
#include <string>
#include <vector>

class PmergeMe {
 public:
  static void execute(int argc, char** argv);

 private:
  typedef std::vector<std::vector<int> > vecMatrix;
  typedef vecMatrix::iterator vecvec_iterator;
  typedef std::vector<int>::iterator vec_iterator;
  typedef std::vector<int>::reverse_iterator vec_reverse_iterator;
  typedef std::deque<std::deque<int> > deqMatrix;
  typedef deqMatrix::iterator deqdeq_iterator;
  typedef std::deque<int>::iterator deq_iterator;
  typedef std::deque<int>::reverse_iterator deq_reverse_iterator;

  static std::vector<int> _vec;
  static std::deque<int> _deq;
  static size_t _size;

  static void checkInteger(int argc, char** argv);
  static bool isDuplicate(std::vector<int> const& arr);
  static bool isDuplicate(std::deque<int> const& arr);
  static void checkDuplicate(void);
  static void checkArgument(int argc, char** argv);
  static void printArray(std::vector<int>& vec);
  static void printTime(clock_t time, std::string name);

  static void hardSort(vecMatrix& vec);
  static void merge(vecMatrix& vec);
  static int vectorJacobsthal(int n);
  static std::vector<int> vectorGenerateOrder(int max);
  static void binarySearchInsertion(vecMatrix& vec, std::vector<int> target);
  static void devide(vecMatrix& vec);
  static void divideAndConquer(vecMatrix& vec);
  static void vectorMergeInsertionSort(void);

  static void hardSort(deqMatrix& deq);
  static void merge(deqMatrix& deq);
  static int dequeJacobsthal(int n);
  static std::deque<int> dequeGenerateOrder(int max);
  static void binarySearchInsertion(deqMatrix& deq, std::deque<int> target);
  static void devide(deqMatrix& deq);
  static void divideAndConquer(deqMatrix& deq);
  static void dequeMergeInsertionSort(void);

  PmergeMe(void);
  PmergeMe(PmergeMe const& pmergeme);
  ~PmergeMe(void);
  PmergeMe& operator=(PmergeMe const& pmergeme);
};

#endif
