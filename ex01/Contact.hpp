#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        void setContact();
        void displayContact();
        std::string getFirstName();
};

#endif