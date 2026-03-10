#include "Contact.hpp"
#include <iostream>

void Contact::setContact()
{
    do
    {
        std::cout << "First name: ";
        std::getline(std::cin, firstName);
    } while (firstName.empty());
    do
    {
        std::cout << "Last name: ";
        std::getline(std::cin, lastName);
    } while (lastName.empty());
    do
    {
        std::cout << "Nick name: ";
        std::getline(std::cin, nickName); /* code */
    } while (nickName.empty());
    do
    {
        std::cout << "Phone Number: ";
        std::getline(std::cin, phoneNumber); /* code */
    } while (phoneNumber.empty());
    do
    {
        std::cout << "Darkest secret: ";
        std::getline(std::cin, darkestSecret); /* code */
    } while (darkestSecret.empty());
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