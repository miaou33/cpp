#include "Account.hpp"
#include <string>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) {}

Account::Account(int initial_deposit)
{
/* 	++_nbAccounts; */
	_accountIndex = ++_nbAccounts;
	(void)initial_deposit;
}

void	Account::displayAccountsInfos (void)
{
/* 	for (size_t i = 0; i < _nbAccounts; i++)
	{
		_displayTimestamp();
	} */
}

/* void	Account::makeDeposit (int deposit)
{

} */

/* bool	Account::makeWithdrawal (int withdrawal)
{
	return 0;
} */

int Account::checkAmount (void) const
{
	return 0;
}

void	Account::displayStatus (void) const
{

}

void	_displayTimestamp  (void)
{
 /*   std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n"; */
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

