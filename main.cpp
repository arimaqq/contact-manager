#include <iostream>
#include <limits>
#include "ContactManager.h"
#include <string>

int main() {

    ContactManager manager("contacts.txt");
    int choice;
    std::string name, phone, email;

    while (true) {
        std::cout << "\nContact Manager\n";
        std::cout << "1. Add new contact\n";
        std::cout << "2. Show all existing contacts\n";
        std::cout << "3. Find contact by name\n";
        std::cout << "4. Find contact by number\n";
        std::cout << "5. Delete contact by name\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore(32727, '\n');

        switch (choice) {
            case 1:
                std::cout << "Name: ";
                std::getline(std::cin, name);
                std::cout << "Phone number: ";
                std::getline(std::cin, phone);
                std::cout << "Email: ";
                std::getline(std::cin, email);
                manager.addContact(Contact(name, phone, email));
                std::cout << "Contact was successfully added\n";
                break;
            case 2:
                manager.showAllContacts();
                break;
            case 3:
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                manager.searchByName(name);
                break;
            case 4:
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phone);
                manager.searchByPhone(phone);
                break;
            case 5:
                std::cout << "For deleting contact enter name: ";
                std::getline(std::cin, name);
                if (manager.deleteContact(name)) {
                    std::cout << "Contact deleted.\n";
                } else {
                    std::cout << "Contact not found.\n";
                }
                break;
            case 0:
                std::cout << "Bye\n";
                return 0;
            default:
                std::cout << "Incorrect selection, try again.\n";
        }
    }
}