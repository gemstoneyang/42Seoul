#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::map<std::string, double> BitcoinExchange::_database;

bool BitcoinExchange::isValidDate(const std::string& date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

  int year, month, day;
  std::stringstream ss(date.substr(0, 4));
  ss >> year;
  ss.clear();
  ss.str(date.substr(5, 2));
  ss >> month;
  ss.clear();
  ss.str(date.substr(8, 2));
  ss >> day;

  if (month < 1 || month > 12) return false;

  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
    daysInMonth[1] = 29;

  if (day < 1 || day > daysInMonth[month - 1]) return false;

  return true;
}

void BitcoinExchange::readDatabase(void) {
  std::ifstream file("data.csv");
  if (!file.is_open()) throw std::runtime_error("invalid filename");

  std::string line;
  std::getline(file, line);

  while (std::getline(file, line)) {
    std::stringstream lineStream(line);
    std::string date;
    std::string valueStr;

    if (std::getline(lineStream, date, ',') &&
        std::getline(lineStream, valueStr, '\n')) {
      if (!BitcoinExchange::isValidDate(date))
        throw std::runtime_error("invalid date");
      char* endPtr;
      double value = std::strtod(valueStr.c_str(), &endPtr);
      if (*endPtr != '\0') throw std::runtime_error("invalid value");
      BitcoinExchange::_database[date] = value;
    }
  }

  file.close();
}

void BitcoinExchange::readInputData(char* argv) {
  std::string filename = argv;
  std::ifstream file(filename);
  if (!file.is_open()) throw std::runtime_error("invalid filename");

  std::string line;
  std::getline(file, line);

  while (std::getline(file, line)) {
    std::stringstream lineStream(line);
    std::string date;
    std::string valueStr;

    if (std::getline(lineStream, date, '|') &&
        std::getline(lineStream, valueStr, '\n')) {
      if (!BitcoinExchange::isValidDate(date))
        throw std::runtime_error("invalid date");
      char* endPtr;
      double value = std::strtod(valueStr.c_str(), &endPtr);
      if (*endPtr != '\0') throw std::runtime_error("invalid value");
      BitcoinExchange::_database[date] = value;
    }
  }
  // todo

  file.close();
}