#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip> // 用于 std::setw
#include <sstream> // 用于 std::stringstream

// 构造函数：初始化索引和计数器
PhoneBook::PhoneBook()
{
    index = 0; // 记录下一个要写入的槽位
    total = 0; // 记录当前电话簿中实际存储的联系人总数（最大为 8）
};

/**
 * 添加联系人
 * 实现循环存储逻辑：当超过 8 个时，覆盖最早的那个（index 从 0 再次开始）
 */
void PhoneBook::addContact()
{
    // 调用当前索引位置 Contact 对象的成员函数进行输入
    contacts[index].setContact();
    
    // 更新索引：(0+1)%8 = 1 ... (7+1)%8 = 0
    index = (index + 1) % 8;
    
    // 增加总数计数，但上限为 8
    if (total < 8)
        total++;
};

/**
 * 格式化辅助函数
 * 如果字符串长度超过 10，截断并在第 10 位显示点号 '.'
 */
std::string format(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + '.'); // 取前 9 位 + '.'
    return (str);
}

/**
 * 搜索并显示联系人
 * 1. 打印预览表格
 * 2. 接收用户输入的索引并校验内容
 */
void PhoneBook::searchContact()
{
    int index;
    std::string line;

    // 打印表头：setw(10) 确保每个字段占 10 个字符宽度
    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nick name"
              << std::endl;

    // 遍历已存在的联系人并打印缩略信息
    for (int i = 0; i < total; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << format(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << format(contacts[i].getLastName()) << "|"
                  << std::setw(10) << format(contacts[i].getNickName())
                  << std::endl;
    };

    // 获取用户输入的索引
   	while (true)
	{
		std::cout << "Enter index: ";
		if (!std::getline(std::cin, line))
			return ;
		std::stringstream ss(line);
		if (!(ss >> index))
		{
			std::cout << "Invald index"<< std::endl;
			continue;
		}
		if ((index >= total || index < 0) && total)
		{
			std::cout << "There is not this index in the list of contacts" << std::endl;
			continue;
		}
		if (total == 0)
		{
			std::cout << "There is not any contact in the list" << std:: endl;
			break;
		}
		break;
	}
    // 检查通过，显示该联系人的完整详情
    if (total > 0)
        contacts[index].displayContact();
}