#include "ContactManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

ContactManager::ContactManager(const std::string& filename)
    : fileName(filename) {
    loadFromFile();
}

ContactManager::~ContactManager() {
    saveToFile();
}

//Добавление контакта
void ContactManager::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

//Показ всех контактов
void ContactManager::showAllContacts() const {
    if (contacts.empty()) {
        std::cout << "List of contacts is empty now\n";
        return;
    }

    for (size_t i=0; i<contacts.size(); i++) {
        std::cout << i+1 << " - ";
        contacts[i].display();
    }
}

// Поиск по имени
void ContactManager::searchByName(const std::string& name) const {
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getName() == name) {
            contact.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << name << " not found\n";
    }
}

// Поиск по номеру телефона
void ContactManager::searchByPhone(const std::string& phone) const {
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getPhone() == phone) {
            contact.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << phone << " not found\n";
    }
}

// Поиск по почте
void ContactManager::searchByEmail(const std::string& email) const {
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getEmail() == email) {
            contact.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << email << " not found\n";
    }
}

// Удаление контакта
bool ContactManager::deleteContact(const std::string& name) {
    for (auto i = contacts.begin(); i != contacts.end(); ++i) {
        if (i->getName() == name) {
            contacts.erase(i);
            return true;
        }
    }
    return false;
}

// Сохранение в файл 
// Формат: (Имя | Номер | Email)
void ContactManager::saveToFile() const {
    std::ofstream fout(fileName);
    if (!fout) {
        std::cerr << "Error while opening " << fileName << " file\n";
        return;
    }
    for (const auto& contact : contacts) {
        fout << contact.getName() << " | "
        << contact.getPhone() << " | "
        << contact.getEmail() << "\n";
    }
}

//Загрузка из файла (в файле не будет пробелов до и после разделителей)
void ContactManager::loadFromFile() {
    std::ifstream fin(fileName);
    if (!fin) {
        return;
    }
    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream stringstream(line);
        std::string name, phone, email;
        std::getline(stringstream, name, '|');
        std::getline(stringstream, phone, '|');
        std::getline(stringstream, email, '|');
        contacts.push_back(Contact(name, phone, email));
    }
}