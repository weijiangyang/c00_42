#include "Contact.hpp"
#include <iostream>

void rtrim(std::string &str)
{
	std::size_t end = str.find_last_not_of(" \t");
	if (end == std::string::npos)
		str = "";
	else
		str = str.substr(0, end + 1);
}

void Contact::setContact()
{
	do
	{
		std::cout << "First name: ";
		if (!std::getline(std::cin, firstName))
			return;
		rtrim(firstName);
	} while (firstName.find_first_not_of(" \t") == std::string::npos);
	do
	{
		std::cout << "Last name: ";
		if (!std::getline(std::cin, lastName))
			return;
		rtrim(lastName);
	} while (lastName.find_first_not_of(" \t") == std::string::npos);
	do
	{
		std::cout << "Nick name: ";
		if (!std::getline(std::cin, nickName))
			return;
		rtrim(nickName);
	} while (nickName.find_first_not_of(" \t") == std::string::npos);
	do
	{
		std::cout << "Phone Number: ";
		if (!std::getline(std::cin, phoneNumber))
			return;
		rtrim(phoneNumber);
	} while (phoneNumber.find_first_not_of(" \t") == std::string::npos);
	do
	{
		std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, darkestSecret))
			return;
		rtrim(darkestSecret);
	} while (darkestSecret.find_first_not_of(" \t") == std::string::npos);
};

void Contact::displayContact()
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nick Name: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
};

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