#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {

public:
    // 类型别名，方便在类内或类外引用 Account 类型
    typedef Account     t;

    // --- 静态成员函数 (Static Methods) ---
    // 这些函数属于类级别，用于获取所有账户的全局统计信息
    static int  getNbAccounts( void );      // 获取总账户数
    static int  getTotalAmount( void );     // 获取所有账户的总金额
    static int  getNbDeposits( void );      // 获取所有账户的总存款次数
    static int  getNbWithdrawals( void );   // 获取所有账户的总取款次数
    static void displayAccountsInfos( void ); // 打印全局统计信息（对应那个包含 total 的 log 行）

    // --- 构造与析构 ---
    Account( int initial_deposit ); // 创建账户时必须提供初始存款
    ~Account( void );

    // --- 实例成员函数 (Instance Methods) ---
    // 这些函数作用于具体的某个账户对象
    void    makeDeposit( int deposit );       // 存款
    bool    makeWithdrawal( int withdrawal ); // 取款（如果余额不足返回 false）
    int     checkAmount( void ) const;        // 查看当前余额
    void    displayStatus( void ) const;      // 打印当前账户的状态（index, amount, deposits, withdrawals）

private:
    // --- 静态私有变量 ---
    // 存储全局数据，所有 Account 对象共享这些变量
    static int  _nbAccounts;
    static int  _totalAmount;
    static int  _totalNbDeposits;
    static int  _totalNbWithdrawals;

    // 辅助函数：打印时间戳 [YYYYMMDD_HHMMSS]
    static void _displayTimestamp( void );

    // --- 实例私有变量 ---
    // 每个账户对象独有的数据
    int             _accountIndex;    // 账户索引（从 0 开始）
    int             _amount;          // 当前余额
    int             _nbDeposits;      // 当前账户的存款次数
    int             _nbWithdrawals;   // 当前账户的取款次数

    // 私有化默认构造函数：禁止创建不带初始金额的账户
    Account( void );

};

#endif /* __ACCOUNT_H__ */