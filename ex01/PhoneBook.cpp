#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    index = 0;
    total = 0;
};

void PhoneBook::addContact()
{
    contacts[index].setContact();
    index = (index + 1) % 8;
    if (total < 8)
        total++;
};

std::string format(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + '.');
    return (str);
}

void PhoneBook::searchContact()
{
    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nick name"
              << std::endl;
    for (int i = 0; i < total; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << format(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << format(contacts[i].getLastName()) << "|"
                  << std::setw(10) << format(contacts[i].getNickName())
                  << std::endl;
    };
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    if (index >= 0 && index < 8)
        contacts[index].displayContact();
    else
        std::cout << "Invalid index" << std::endl;
}