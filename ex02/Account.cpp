#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t now = std::time(0);
    std::tm *t = std::localtime(&now);
    std::cout << "["
              << (t->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << t->tm_mon + 1
              << std::setw(2) << t->tm_mday
              << "_"
              << std::setw(2) << t->tm_hour
              << std::setw(2) << t->tm_min
              << std::setw(2) << t->tm_sec
              << "]" ;
};

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index: " << _accountIndex
              << "; amount:" << _amount
              << "; created"
              << std::endl;
};

Account:: ~Account(void)
{
    _displayTimestamp();
    std::cout << "index: " << _accountIndex
              << ";amount:" << _amount
              << ";closed"
              << std::endl;
}

void Account::displayAccountsInfos()
{
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits" << _totalNbDeposits
              << ";withdrawals" << _totalNbWithdrawals
              << std::endl;
};

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount" << _amount
              << ";deposits" << _nbDeposits
              << ";withdrawals" << _nbWithdrawals
              << std::endl;
}

void Account:: makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits" << _nbDeposits
              << std::endl;
}

bool Account:: makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << "; withdrawal:refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return (true);
}

int	Account:: checkAmount( void ) const
{
    return (_amount);
}