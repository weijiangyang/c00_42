#include "PhoneBook.hpp"
#include <iostream>

/**
 * 程序入口点：主控制循环
 * 负责接收用户指令并分发给 PhoneBook 对象进行处理
 */
int main()
{
    PhoneBook   phoneBook; // 实例化电话簿对象（包含 8 个 Contact 槽位）
    std::string command;   // 用于存储用户输入的指令字符串

    // 无限循环，直到用户输入 EXIT 或发生中断
    while(1)
    {
        // 打印提示符
        std::cout << "Enter command (ADD, SEARCH or EXIT): ";
        
        // 使用 getline 获取完整行输入，防止空格导致解析错误
        if (!std::getline(std::cin, command))
        {
            // 处理 Ctrl+D (EOF) 情况，防止程序进入死循环
            break ;
        }

        // 根据输入的命令调用相应的成员函数
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            // 正常退出循环
            break ;
        }
        // 如果输入了非预期命令，循环会继续，重新提示输入
    }

    // 程序结束，所有局部变量（包括 phoneBook）将被自动销毁
    return (0);
}