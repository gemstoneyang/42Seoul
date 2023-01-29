#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact {

public:
	Contact(void);
	Contact(std::string phoneNumber, std::string firstName,
		std::string	lastName, std::string nickName, std::string darkestSecret);

	std::string	getPhoneNumber(void);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);

private:
	std::string	phoneNumber;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;

};

#endif