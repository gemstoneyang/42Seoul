#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <map>
#include <string>

class BitcoinExchange {
 public:
  static void readDatabase(void);

 private:
  static std::map<std::string, double> _database;

  static bool isValidDate(const std::string& date);

  BitcoinExchange(void);
  BitcoinExchange(BitcoinExchange const& rhs);
  ~BitcoinExchange(void);
  BitcoinExchange& operator=(BitcoinExchange const& rhs);
};

#endif

// db parsing -> 날짜 처리(굉장 복잡) 함수 만들기 : 시세
// 입력 파싱 -> 섞어 섞어 처리 : 구매
// 찾을 때 없으면 가장 가까운 전 날짜 데이터 -> 1월 2일 ㅡㅡ 1월 5일 : 알고리즘
// bound 관련 함수