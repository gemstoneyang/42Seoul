#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

// Display Timestamp
void	Account::_displayTimestamp(void) {
	time_t	timer = time(NULL);
	tm		*t = localtime(&timer);

	std::cout << '[' << t->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_mon + 1;
	std::cout << std::setw(2) << t->tm_mday << '_';
	std::cout << std::setw(2) << t->tm_hour;
	std::cout << std::setw(2) << t->tm_min;
	std::cout << std::setw(2) << t->tm_sec << "] ";
}

// Static variable Initialize & Getter
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';'
			  << "total:" << getTotalAmount() << ';'
			  << "deposits:" << getNbDeposits() << ';'
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

// Constructor & Destructor
Account::Account(void)
	: _accountIndex(-1),
	  _amount(0),
	  _nbDeposits(0),
	  _nbWithdrawals(0) {}

Account::Account(int initial_deposit) 
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0) {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "created" << std::endl;
	_nbAccounts += 1;
	_totalAmount += _amount;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "closed" << std::endl;
}

// Instance Method
void	Account::makeDeposit(int deposit) {
	int	p_amount = _amount;

	_amount += deposit;
	_nbDeposits += 1;

	_totalAmount += deposit;
	_totalNbDeposits += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << p_amount << ';'
			  << "deposits:" << deposit << ';'
			  << "amount:" << _amount << ';'
			  << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount = _amount;

	if (withdrawal > _amount)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << p_amount << ';'
			  << "withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals += 1;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << p_amount << ';'
			  << "withdrawal:" << withdrawal << ';'
			  << "amount:" << _amount << ';'
			  << "nb_withdrawals:" << _nbDeposits << std::endl;
	return true;
}

int		Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "deposits:" << _nbDeposits << ';'
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}
