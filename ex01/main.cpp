#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook   phoneBook; 
    std::string command; 

    while(1)
    {
        std::cout << "Enter command (ADD, SEARCH or EXIT): ";
        if (!std::getline(std::cin, command))
        {
            break ;
        }
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
            break ;
        }
    }
    return (0);
}