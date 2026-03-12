#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

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
    int index;
    std::string line;
	
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
    if (total > 0)
        contacts[index].displayContact();
}