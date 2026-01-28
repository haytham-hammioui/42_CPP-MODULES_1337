/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:16:13 by hhammiou          #+#    #+#             */
/*   Updated: 2026/01/26 20:03:14 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::setfirstname(std::string str){ 
    firstname = str; 
}

std::string Contact::getfirstname() const{
    return firstname;
}

void Contact::setlastname(std::string str){
    lastname = str;
}

std::string Contact::getlastname() const{
    return lastname;
}

void Contact::setnickname(std::string str){
    nickname = str;
}

std::string Contact::getnickname() const{
    return nickname;
}

void Contact::setphonenumber(std::string str){
    phonenumber = str;
}

std::string Contact::getphonenumber() const{
    return phonenumber;
}

void Contact::setdarkestsecret(std::string str){
    darkestsecret = str;
}

std::string Contact::getdarkestsecret() const{
    return darkestsecret;
}

PhoneBook::PhoneBook(){
    nextindex = 0;
    storedcontacts = 0;
}

void PhoneBook::addcontact(Contact c) {
    contacts[nextindex] = c;
    nextindex = (nextindex + 1) % 8;
    if (storedcontacts < 8)
        storedcontacts++;
}

int PhoneBook::getstoredcontacts() const{
    return storedcontacts;
}

static std::string truncate(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displaycontacts() const {
    std::cout << "|"
              << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < storedcontacts; i++) {
        std::cout << "|"
                  << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getfirstname()) << "|"
                  << std::setw(10) << truncate(contacts[i].getlastname()) << "|"
                  << std::setw(10) << truncate(contacts[i].getnickname()) << "|" << std::endl;
    }
}

void PhoneBook::displaycontact(int index) const{
    std::cout << "First Name: " << contacts[index].getfirstname() << std::endl;
    std::cout << "Last Name: " << contacts[index].getlastname() << std::endl;
    std::cout << "Nickname: " << contacts[index].getnickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getphonenumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getdarkestsecret() << std::endl;
}

static bool is_digits_only(const std::string &str)
{
    if(str.empty())
        return 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return 0;
    }
    return 1;
}

static void get_input(const std::string &prompt, std::string &out) {
    std::cout << prompt;
    std::getline(std::cin, out);
    while (out.empty()) {
        std::cout << "Field cannot be empty. Try again: ";
        std::getline(std::cin, out);
    }
    if(prompt == "Enter phone number: "){
        while (!is_digits_only(out))
        {
            std::cout << "Phone number must contain only digits and cannot be empty. Try again: ";
            std::getline(std::cin, out);
        }
    }
}

void addnewcontact(PhoneBook &phonebook){
    Contact c;
    std::string input;
    
    get_input("Enter first name: ", input);
    c.setfirstname(input);
    get_input("Enter last name: ", input);
    c.setlastname(input);
    get_input("Enter nickname: ", input);
    c.setnickname(input);
    get_input("Enter phone number: ", input);
    c.setphonenumber(input);
    get_input("Enter darkest secret: ", input);
    c.setdarkestsecret(input);

    phonebook.addcontact(c);
    std::cout << "Contact added successfully!" << std::endl;
}

void searchfunct(PhoneBook &phonebook){
    std::string input;
    int index;
    
    if (phonebook.getstoredcontacts() == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return ;
    }
    phonebook.displaycontacts();
    std::cout << "Enter the index of the contact to view: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Error: Invalid index!" << std::endl;
        return;
    }
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i])){
            std::cout << "Error: Invalid index!" << std::endl;
            return;
        }
    }
    index = std::atoi(input.c_str());
    if (index < 0 || index >= phonebook.getstoredcontacts())
        std::cout << "Error: Invalid index!" << std::endl;
    else
        phonebook.displaycontact(index);
}

int main(int ac, char**av) {
    (void)av;
    if(ac == 1){
        PhoneBook phonebook;
        std::string command;
        
        while (1337) {
            std::cout << "Enter command: ";
            if (!std::getline(std::cin, command))
                break;
            if (command == "EXIT")
                break;
            else if (command == "ADD")
                addnewcontact(phonebook);
            else if (command == "SEARCH")
                searchfunct(phonebook);
        }
        return 0;
    }
    std::cout << "invalid arguments!" << std::endl;
    return 1;
}