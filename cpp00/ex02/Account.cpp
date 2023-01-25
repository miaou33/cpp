#include "Account.hpp"
#include <string>
#include <iostream>

Account::Account(void) {}

Account::Account(int initial_deposit)
{
/* 	++_nbAccounts; */
	_accountIndex = ++_nbAccounts;
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

void	Account::displayAccountsInfos (void)
{
	std::cout << _nbAccounts << std::endl;
}

void	Account::makeDeposit (int deposit)
{

}

bool	Account::makeWithdrawal (int withdrawal)
{
	return 0;
}

int Account::checkAmount (void) const
{
	return 0;
}

void	Account::displayStatus (void) const
{

}

void	_displayTimestamp  (void)
{

}