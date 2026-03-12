#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

/**
 * Contact 类：用于存储单个联系人的所有信息。
 * 根据 42 CPP Module 00 的要求，所有属性必须为私有（Private）。
 */
class Contact
{
    private:
        // 私有成员变量：只能通过类内部的成员函数访问
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        /**
         * 交互式设置联系人信息
         * 会提示用户输入并填充上述私有成员
         */
        void setContact();

        /**
         * 打印联系人的所有详细信息（用于 SEARCH 选中后的完整显示）
         */
        void displayContact();

        /* --- Getters (访问器) --- 
         * 由于成员变量是私有的，外部类（如 PhoneBook）需要通过这些函数
         * 获取必要的信息来生成预览表格。
         */
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
};

#endif