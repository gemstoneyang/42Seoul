#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <map>
#include <string>

class BitcoinExchange {
 public:
  static void execute(char* argv);

 private:
  static std::map<std::string, double> _database;

  static bool isValidDate(const std::string& date);

  static void parseDBLine(std::string const& line, std::string& date,
                          double& value);
  static void readDatabase(void);

  static bool isValidInput(void);
  static void parseInputLine(std::string const& line, std::string& date,
                             double& value);
  static void printInputData(std::string const& date, double const& value);
  static void readInputData(char* argv);

  static void print(std::map<std::string, double> data);

  BitcoinExchange(void);
  BitcoinExchange(BitcoinExchange const& rhs);
  ~BitcoinExchange(void);
  BitcoinExchange& operator=(BitcoinExchange const& rhs);
};

#endif