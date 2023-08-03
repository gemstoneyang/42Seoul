#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

class PmergeMe {
 public:
  PmergeMe(void);
  PmergeMe(PmergeMe const& pmergeme);
  ~PmergeMe(void);

  PmergeMe& operator=(PmergeMe const& pmergeme);

 private:
};

#endif

// push swap 처럼 파싱 -> 중복 처리는 알아서 -> 정민은 금지함..
// 포드존슨 구현하기.. -> 자료구조 정하고 구현
// 구현하고 시간 측정
// 다른 자료구조로 다시 구현 -> 정민은 벡터와 데크로 함..