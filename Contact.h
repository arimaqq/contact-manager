#pragma once
#include <string>

class Contact
{
private:
    std::string name;
    std::string phone;
    std::string email;

public:

    Contact(const std::string& n = "", const std::string& p = "", const std::string& e = "");

//Геттеры
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;

//Сеттеры
    void setName(const std::string& n);
    void setPhone(const std::string& p);
    void setEmail(const std::string& e);

    void display() const;
};