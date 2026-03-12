#include "Contact.hpp"
#include <iostream>

/**
 * 设置联系人信息
 * 使用 do-while 循环确保用户输入的每一个字段都不为空
 * 这是 42 项目中常见的防止非法/空输入的方法
 */
void Contact::setContact()
{
    // 获取名字，如果输入为空则重复提示
    do
    {
        std::cout << "First name: ";
        std::getline(std::cin, firstName);
    } while (firstName.empty());

    // 获取姓氏
    do
    {
        std::cout << "Last name: ";
        std::getline(std::cin, lastName);
    } while (lastName.empty());

    // 获取昵称
    do
    {
        std::cout << "Nick name: ";
        std::getline(std::cin, nickName);
    } while (nickName.empty());

    // 获取电话号码
    do
    {
        std::cout << "Phone Number: ";
        std::getline(std::cin, phoneNumber);
    } while (phoneNumber.empty());

    // 获取最阴暗的秘密
    do
    {
        std::cout << "Darkest secret: ";
        std::getline(std::cin, darkestSecret);
    } while (darkestSecret.empty());
};

/**
 * 完整显示联系人的所有详细信息
 * 通常用于用户输入 SEARCH 并选择特定索引后的展示
 */
void Contact::displayContact()
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nick Name: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
};

/* --- Getter 函数：用于在 PhoneBook 类中访问私有成员变量 --- */

std::string Contact::getFirstName()
{
    return (firstName);
}

std::string Contact::getLastName()
{
    return (lastName);
}

std::string Contact::getNickName()
{
    return (nickName);
}