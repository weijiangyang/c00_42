#include "Contact.hpp"
#include <iostream>

void Contact::setContact()
{
    std::cout << "First name: ";
    std::getline(std::cin, firstName);
    std::cout << "Last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Nick name: ";
    std::getline(std::cin, nickName);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkestSecret);
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
