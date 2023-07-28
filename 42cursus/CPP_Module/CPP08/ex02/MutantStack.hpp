#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack(void);
  MutantStack(MutantStack const& mutantstack);
  ~MutantStack(void);

  MutantStack& operator=(MutantStack const& mutantstack);

  typedef typename std::stack<T>::container_type container_type;
  typedef typename container_type::iterator iterator;
  typedef typename container_type::const_iterator const_iterator;
  typedef typename container_type::reverse_iterator reverse_iterator;
  typedef
      typename container_type::const_reverse_iterator const_reverse_iterator;

  iterator begin(void);
  const_iterator begin(void) const;

  iterator end(void);
  const_iterator end(void) const;

  reverse_iterator rbegin(void);
  const_reverse_iterator rbegin(void) const;

  reverse_iterator rend(void);
  const_reverse_iterator rend(void) const;

 private:
};

#include "MutantStack.tpp"

#endif