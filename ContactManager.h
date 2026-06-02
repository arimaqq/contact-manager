#include <string>
#include <vector>
#include "Contact.h"
#pragma once

class ContactManager
{
private:
    std::vector<Contact> contacts;
    std::string fileName;

    void saveToFile() const;
    void loadFromFile();

public:
    ContactManager(const std::string& filename);
    ~ContactManager();

    void addContact(const Contact& contact);
    void showAllContacts() const;
    void searchByName(const std::string& name) const;
    void searchByPhone(const std::string& phone) const;
    void searchByEmail(const std::string& email) const;
    bool deleteContact(const std::string& name);
};