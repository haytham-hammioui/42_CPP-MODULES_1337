/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:23:49 by hhammiou          #+#    #+#             */
/*   Updated: 2026/01/26 15:19:27 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact{
    private:
        std::string  firstname;
        std::string  lastname;
        std::string  nickname;
        std::string  phonenumber;
        std::string  darkestsecret;
    public:
        void setfirstname(std::string str);
        std::string getfirstname() const;
        void setlastname(std::string str);
        std::string getlastname() const;
        void setnickname(std::string str);
        std::string getnickname() const;
        void setphonenumber(std::string str);
        std::string getphonenumber() const;
        void setdarkestsecret(std::string str);
        std::string getdarkestsecret() const;
};

class PhoneBook{
    private:
      Contact contacts[8];
	  int nextindex;
	  int storedcontacts;
	public:
		void addcontact(Contact c);
		void displaycontacts() const;
		void displaycontact(int index) const;
        int getstoredcontacts() const;
        PhoneBook();
};

#endif