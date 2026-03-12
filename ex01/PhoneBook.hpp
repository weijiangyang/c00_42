#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

/**
 * PhoneBook 类：负责管理 Contact 对象数组
 * 逻辑限制：最多存储 8 个联系人，超过后循环覆盖最早的一个
 */
class PhoneBook
{
    private:
        // 包含 8 个 Contact 实例的固定数组
        Contact contacts[8];
        
        // 记录下一个即将被写入或覆盖的槽位下标 (0-7)
        int     index;
        
        // 记录当前电话簿中实际存储的有效联系人数量 (最大为 8)
        int     total;

    public:
        /**
         * 构造函数：初始化 index 和 total 为 0
         */
        PhoneBook();

        /**
         * ADD 指令的逻辑实现：
         * 获取用户输入，存入 contacts[index]，并更新 index 和 total
         */
        void addContact();

        /**
         * SEARCH 指令的逻辑实现：
         * 打印格式化表格，并根据用户输入的索引显示详细信息
         */
        void searchContact();
};

#endif