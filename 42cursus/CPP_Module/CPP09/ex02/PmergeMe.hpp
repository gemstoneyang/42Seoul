#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <deque>
#include <vector>

class PmergeMe {
 public:
  static void execute(int argc, char** argv);

 private:
  typedef std::vector<std::vector<int> >::iterator vecvec_iterator;
  typedef std::vector<int>::iterator vec_iterator;
  typedef std::vector<int>::reverse_iterator vec_reverse_iterator;

  static std::vector<int> _vec;
  static std::deque<int> _deq;

  static void checkInteger(int argc, char** argv);

  template <typename T>
  static bool isDuplicate(T const& arr) {
    T temp = arr;
    std::sort(temp.begin(), temp.end());

    for (size_t i = 1; i < temp.size(); ++i) {
      if (temp[i] == temp[i - 1]) {
        return true;
      }
    }
    return false;
  }

  static void checkDuplicate(void);
  static void checkArgument(int argc, char** argv);

  static int jacobsthal(int n);
  static std::vector<int> generateOrder(int max);
  static void binarySearch(std::vector<std::vector<int> >& vec,
                           std::vector<int> target);
  static void merge(std::vector<std::vector<int> >& vec);
  static void devide(std::vector<std::vector<int> >& vec);
  static void mergeInsertionSort(void);

  PmergeMe(void);
  PmergeMe(PmergeMe const& pmergeme);
  ~PmergeMe(void);

  PmergeMe& operator=(PmergeMe const& pmergeme);
};

#endif

// push swap 처럼 파싱 -> 중복 처리는 알아서 -> 정민은 금지함..
// 포드존슨 구현하기.. -> 자료구조 정하고 구현
// 구현하고 시간 측정
// 다른 자료구조로 다시 구현 -> 정민은 벡터와 데크로 함..

// 자코비스탈 숫자 구현
// 이분탐색 구현