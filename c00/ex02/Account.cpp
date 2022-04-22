/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:48:14 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/10 13:55:13 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream> 
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0; //INICIALIZAR VAR
int Account::_totalAmount = 0; //INICIALIZAR VAR
int Account::_totalNbDeposits = 0; //INICIALIZAR VAR
int Account::_totalNbWithdrawals = 0; //INICIALIZAR VAR


Account::~Account()
{
	_displayTimestamp();
	std::cout <<  "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
};

Account::Account(int initial_deposit)
{
	static int i = 0;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_accountIndex = i++;
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	return;
}

void Account::_displayTimestamp( void )
{
	time_t timer;
	struct tm * timeinfo;
	
	time(&timer);
	timeinfo = localtime(&timer);
	std::cout << "[" << std::setw(2) << std::setfill('0') << 1900 + timeinfo->tm_year << std::setw(2) << std::setfill('0') << 1 + timeinfo->tm_mon << std::setw(2) << std::setfill('0') << timeinfo->tm_mday << "_" << std::setw(2) << std::setfill('0') << timeinfo->tm_hour << std::setw(2) << std::setfill('0') << timeinfo->tm_min << std::setw(2) << std::setfill('0') << timeinfo->tm_sec << "] "; 
	return;
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int  Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int  Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int     Account::checkAmount( void ) const
{
	return ( _amount);
}

void Account::displayAccountsInfos( void )
{	
	_displayTimestamp();
	std::cout <<  "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()  << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void    Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex  << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
	return;
}

bool    Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex  << ";p_amount:" << _amount;
	if(checkAmount() < withdrawal)
	{
		std::cout << ";withdrawal:" << "refused"  << std::endl;//refused y no suma drawall	
		return(1);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:"<< _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (0);
}

void    Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex  << ";p_amount:" << _amount;
	 _amount += deposit;
	 _totalAmount += deposit;
	 _nbDeposits++;
	 _totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:"<< _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	return;
}
