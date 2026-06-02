#include "Contact.h"
#include <iostream>

Contact::Contact(const std::string& n, const std::string& p, const std::string& e)
    : name(n), phone(p), email(e) {
}

//Геттеры
std::string Contact::getName() const { return name;}
std::string Contact::getPhone() const { return phone; }
std::string Contact::getEmail() const { return email; }

//Сеттеры
void Contact::setName(const std::string& n) {
        name = n;
}
void Contact::setPhone(const std::string& p) {
    phone = p;
}
void Contact::setEmail(const std::string& e) {
    email = e;
}

void Contact::display() const {
    std::cout << "Name: " << name
    << " | Phone: " << phone
    << " | Email: " << email
    << std::endl;
}