#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// --- 静态成员变量初始化 ---
// 注意：静态变量属于类本身，不属于某个对象，必须在类外定义
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * 打印时间戳 [YYYYMMDD_HHMMSS]
 * 使用 <ctime> 获取系统时间，使用 <iomanip> 格式化输出
 */
void Account::_displayTimestamp()
{
    std::time_t now = std::time(0);
    std::tm *t = std::localtime(&now);
    
    std::cout << "["
              << (t->tm_year + 1900) // 年份从 1900 开始计算
              << std::setw(2) << std::setfill('0') << t->tm_mon + 1 // 月份 0-11
              << std::setw(2) << std::setfill('0') << t->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << t->tm_hour
              << std::setw(2) << std::setfill('0') << t->tm_min
              << std::setw(2) << std::setfill('0') << t->tm_sec
              << "] ";
};

// 构造函数：创建新账户
Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts; // 当前账户索引即为之前的账户总数
    _nbAccounts++;               // 全局账户数递增
    _amount = initial_deposit;    // 账户余额
    _totalAmount += initial_deposit; // 全局总金额递增
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
};

// 析构函数：关闭账户
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
    
    // 注意：通常析构时会更新全局静态变量，但在 42 的测试脚本中，
    // 静态变量的递减逻辑有时根据题目要求（如测试 log 的匹配）来微调。
    _nbAccounts--;
    _totalAmount -= _amount;
}

// 静态函数：显示全局银行业务概览
void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
};

// 显示单个账户的状态
void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

// 存款逻辑
void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;    // 更新全局总额
    _totalNbDeposits++;         // 更新全局存款次数
    
    std::cout << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

// 取款逻辑
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    
    if (withdrawal > _amount) // 余额不足
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;    // 更新全局总额
    _totalNbWithdrawals++;         // 更新全局取款次数
    
    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (_amount);
}