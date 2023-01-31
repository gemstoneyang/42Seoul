#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact {

public:
	Contact(void);
	Contact(std::string phoneNumber, std::string firstName,
		std::string	lastName, std::string nickName, std::string darkestSecret);

	std::string	getPhoneNumber(void) const;
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;

	void	printContactInfo(void) const;

private:
	std::string	phoneNumber;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;

};

#endif