#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{}

void rtrim(std::string &str)
{
	std::size_t end = str.find_last_not_of(" \t");
	if (end == std::string::npos)
		str = "";
	else
		str = str.substr(0, end + 1);
}

bool promptField(const std::string& prompt, std::string& field)
{
	do
	{
		std::cout << prompt;
		if (!std::getline(std::cin, field))
			return (false);
		rtrim(field);
	} while (field.find_first_not_of(" \t") == std::string::npos);
	return (true);
}

void Contact::setContact()
{
	if (!promptField("First name: ", firstName))
		return ;
	if (!promptField("Last name: ", lastName))
		return ;
	if (!promptField("Nick name: ", nickName))
		return ;
	
	if (!promptField("Phone number: ", phoneNumber))
		return ;
	if (!promptField("Darkest secret: ", darkestSecret))
		return ;
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