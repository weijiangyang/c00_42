#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while(1)
    {
        std::cout << "Enter command (ADD SEARCH EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.addContact();
        if (command == "SEARCH")
            phoneBook.searchContact();
        if (command == "EXIT")
            break ;
    }
    return (0);
}