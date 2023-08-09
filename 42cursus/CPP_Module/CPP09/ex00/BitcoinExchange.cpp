#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::map<std::string, double> BitcoinExchange::_database;

bool BitcoinExchange::isValidDate(const std::string& date) {
  if (date.length() != 10 or date[4] != '-' or date[7] != '-') return false;

  int year, month, day;
  std::stringstream ss(date.substr(0, 4));
  ss >> year;
  ss.clear();
  ss.str(date.substr(5, 2));
  ss >> month;
  ss.clear();
  ss.str(date.substr(8, 2));
  ss >> day;

  if (month < 1 or month > 12) return false;

  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year % 400 == 0 or (year % 100 != 0 and year % 4 == 0))
    daysInMonth[1] = 29;

  if (day < 1 or day > daysInMonth[month - 1]) return false;

  return true;
}

void BitcoinExchange::parseDBLine(std::string const& line, std::string& date,
                                  double& value) {
  std::string valueStr;
  std::stringstream lineStream(line);

  if (std::getline(lineStream, date, ',') and
      std::getline(lineStream, valueStr, '\n')) {
    if (BitcoinExchange::isValidDate(date) == false)
      throw std::runtime_error("invalid DB");
    char* endPtr;
    value = std::strtod(valueStr.c_str(), &endPtr);
    if (value < 0 or *endPtr != '\0') throw std::runtime_error("invalid DB");
  } else {
    throw std::runtime_error("invalid DB");
  }
}

void BitcoinExchange::readDatabase(void) {
  std::ifstream file("data.csv");
  if (!file.is_open()) throw std::runtime_error("invalid filename");

  std::string line;
  std::getline(file, line);

  while (std::getline(file, line)) {
    std::string date;
    double value;

    BitcoinExchange::parseDBLine(line, date, value);
    BitcoinExchange::_database[date] = value;
  }

  file.close();
}

void BitcoinExchange::parseInputLine(std::string const& line, std::string& date,
                                     double& value) {
  std::string valueStr;
  std::string sep;
  std::stringstream lineStream(line);

  if (std::getline(lineStream, date, ' ') and
      std::getline(lineStream, sep, ' ') and
      std::getline(lineStream, valueStr, '\n')) {
    if (BitcoinExchange::isValidDate(date) == false)
      throw std::runtime_error("bad input");
    if (sep != "|") throw std::runtime_error("bad input");

    char* endPtr;
    value = std::strtod(valueStr.c_str(), &endPtr);
    if (*endPtr != '\0') throw std::runtime_error("bad input");
  } else {
    throw std::runtime_error("bad input");
  }
}

void BitcoinExchange::printInputData(std::string const& date,
                                     double const& value) {
  std::map<std::string, double>::iterator it = _database.lower_bound(date);
  if (it == _database.begin() and it->first != date)
    throw std::runtime_error("invalid date");

  if (it == _database.end() or it->first != date) {
    --it;
  }
  std::cout << date << " => " << value << " = " << it->second * value
            << std::endl;
}

void BitcoinExchange::readInputData(char* argv) {
  std::ifstream file(argv);
  if (!file.is_open()) throw std::runtime_error("could not open file.");

  std::string line;
  std::getline(file, line);

  while (std::getline(file, line)) {
    std::stringstream lineStream(line);
    std::string date;
    double value;

    try {
      BitcoinExchange::parseInputLine(line, date, value);
      if (BitcoinExchange::isValidDate(date) == false)
        std::cout << "Error: bad input => " << date << std::endl;
      else if (value < 0)
        std::cout << "Error: not a positive number." << std::endl;
      else if (value > 1000)
        std::cout << "Error: too large a number." << std::endl;
      else
        BitcoinExchange::printInputData(date, value);
    } catch (std::exception& e) {
      std::cout << "Error: " << e.what() << " => " << date << std::endl;
    }
  }

  file.close();
}

void BitcoinExchange::print(std::map<std::string, double> data) {
  for (std::map<std::string, double>::iterator it = data.begin();
       it != data.end(); ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }
}

void BitcoinExchange::execute(char* argv) {
  BitcoinExchange::readDatabase();
  BitcoinExchange::readInputData(argv);
}
