#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <cctype>

class Contact {

public:
	Contact(void);
	Contact(int idx);
	Contact(int idx, std:string phoneNumber, std::string firstName,
		std::string	lastName, std::string nickName, std::string darkestSecret);

	int			getIndex(void);
	std::string	getPhoneNumber(void);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);

private:
	int			index;
	std::string	phoneNumber
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;

};

#endif