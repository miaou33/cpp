#include "Account.hpp"
#include <string>
#include <iostream>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account (void)
{
	_accountIndex = _nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "amount:" << _amount << ";" \
				<< "created" << std::endl;

}

Account::Account (int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "amount:" << _amount << ";" \
				<< "created" << std::endl;

	_totalAmount += _amount;
}

Account::~Account (void)
{
	_displayTimestamp ();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "amount:" << _amount << ";" \
				<< "closed" << std::endl;

	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
}

void	Account::displayAccountsInfos (void)
{
	_displayTimestamp ();
	std::cout	<< "accounts:" << _nbAccounts << ";" \
				<< "total:" << _totalAmount << ";" \
				<< "deposits:" << _totalNbDeposits << ";" \
				<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit (int deposit)
{
	_displayTimestamp ();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "p_amount:" << _amount << ";" \
				<< "deposit:" << deposit << ";";
	
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits ++;
	_totalNbDeposits ++;
	
	std::cout	<< "amount:" << _amount << ";" \
				<< "nb_deposits:" << _nbDeposits << std::endl;
	
}

bool	Account::makeWithdrawal (int withdrawal)
{
	_displayTimestamp ();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "p_amount:" << _amount << ";";
	
	if (int	w_amount = _amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (0);
	}

	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals ++;
	_totalNbWithdrawals ++;

	std::cout	<< "amount:" << _amount << ";" \
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	
	return (0);
}

int Account::checkAmount (void) const
{
	return 0;
}

void	Account::displayStatus (void) const
{
	_displayTimestamp ();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "amount:" << _amount << ";" \
				<< "deposits:" << _nbDeposits << ";" \
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp  (void)
{
/*   time_t 	rawtime = time (&rawtime);;
  struct tm	*timeinfo = localtime (&rawtime);;
  char 		buffer [80];

  strftime (buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);
  std::cout << buffer; */
  std::cout << "[19920104_091532] ";
}

int	Account::getNbAccounts (void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount (void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits (void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals (void)
{
	return (_totalNbWithdrawals);
}

