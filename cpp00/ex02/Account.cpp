#include "Account.hpp"
#include <string>
#include <iostream>
#include <chrono>

Account::Account(void) {}

Account::Account(int initial_deposit)
{
/* 	++_nbAccounts; */
/* 	_accountIndex = ++_nbAccounts; */
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
/* 	for (size_t i = 0; i < _nbAccounts; i++)
	{
		_displayTimestamp();
	} */
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
/* 	std::cout << "[" << clock::now () << "]";	 */
   std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n";
}