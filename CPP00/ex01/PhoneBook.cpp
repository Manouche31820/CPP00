#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <string>


Phonebook::Phonebook(void):_i(0),_j(0)
{
	// std::cout << "I create the repertoire" << std::endl;
	// return;
}

Phonebook::~Phonebook(void)
{
	// std::cout << "I destroyed the repertoire" << std::endl;
	// return;
}

void Phonebook::start(void){
	std::string buff;

	while(1){
		std::cout << "Please insert a command : ADD, SEARCH or EXIT :" << std::endl;
		std::getline(std::cin, buff);
		if (std::cin.eof())
			break ;
		if (buff == "ADD")
			this->add();
		else if (buff == "SEARCH")
			this->search();
		else if (buff == "EXIT")
			break ;
	}
	return ;
}

void Phonebook::add(void){
	std::string buff;

	if (_i >= 8){
		std::cout << "Your phonebook is full, you will erase a contact to create a new one" << std::endl;
		_i = 0;
	}
	std::cout << "Please insert First name :" << std::endl;
	std::getline(std::cin, buff);
	if (std::cin.eof())
		return ;
	if (buff.length() == 0){
		std::cout << "This field can't be empty." << std::endl;
		return ;
	}
	_contacts[_i].set_first_name(buff);
	std::cout << "Please insert Last name :" << std::endl;
	std::getline(std::cin, buff);
	if (std::cin.eof())
		return ;
	if (buff.length() == 0){
		std::cout << "This field can't be empty." << std::endl;
		return ;
	}
	_contacts[_i].set_last_name(buff);
	std::cout << "Please insert nickname :" << std::endl;
	std::getline(std::cin, buff);
	if (std::cin.eof())
		return ;
	if (buff.length() == 0){
		std::cout << "This field can't be empty." << std::endl;
		return ;
	}
	_contacts[_i].set_nickname(buff);
	std::cout << "Please insert Phone number :" << std::endl;
	std::getline(std::cin, buff);
	if (std::cin.eof())
		return ;
	if (buff.length() == 0){
		std::cout << "This field can't be empty." << std::endl;
		return ;
	}
	_contacts[_i].set_phone_number(buff);
		std::cout << "Please insert Darkest secret:" << std::endl;
	std::getline(std::cin, buff);
	if (std::cin.eof())
		return ;
	if (buff.length() == 0){
		std::cout << "This field can't be empty." << std::endl;
		return ;
	}
	_contacts[_i].set_darkest_secret(buff);
	_i++;
	if (_j < 8)
		_j++;
}

void Phonebook::search(void){
	int a;
	std::string word;
	std::string subword;
	int size;
	std::string choice;

	a = 0;
	size  = 0;
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|   INDEX  |FIRST NAME|LAST  NAME| NICKNAME |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	while (a < _j){
		std::cout << " ___________________________________________" << std::endl;
		word = _contacts[a].get_first_name();
		size = 10 - word.length();
		if (word.length() > 10){
			subword = word.substr(0, 10);
			subword[subword.length() - 1] = '.';
			size = 0;
			word = subword;
		}
		std::cout << "|" << std::string(9, ' ') << a + 1 << "|" << std::string(size, ' ') <<  word << "|";
		word = _contacts[a].get_last_name();
		size = 10 - word.length();
		if (word.length() > 10){
			subword = word.substr(0, 10);
			subword[subword.length() - 1] = '.';
			size = 0;
			word = subword;
		}
		std::cout << std::string(size, ' ') <<  word << "|";
		word = _contacts[a].get_nickname();
		size = 10 - word.length();
		if (word.length() > 10){
			subword = word.substr(0, 10);
			subword[subword.length() - 1] = '.';
			size = 0;
			word = subword;
		}
		std::cout << std::string(size, ' ') <<  word << "|" << std::endl;
		std::cout << "|___________________________________________|" << std::endl;
		a++;
	}
	std::cout << "Select an Index :" << std::endl;
	std::getline(std::cin, choice);
	if (std::cin.eof())
		return ;
	if (choice.length() != 1 || choice[0] < 1 + 48 || choice[0] > _j + 48){
		std::cout << "Index error" << std::endl;
		return ;
	}
	a = choice[0] - 48;
	std::cout << std::endl;
	std::cout << "Please find below the information about your contact number " << a << std::endl;
	std::cout << std::endl;
	std::cout << "First name : " << _contacts[a - 1].get_first_name() << std::endl;
	std::cout << "Last name : " <<_contacts[a - 1].get_last_name() << std::endl;
	std::cout << "Nickname : " <<_contacts[a - 1].get_nickname() << std::endl;
	std::cout << "Phone number : " <<_contacts[a - 1].get_phone_number() << std::endl;
	std::cout << "Darkest secret : " <<_contacts[a - 1].get_darkest_secret() << std::endl;
	std::cout << std::endl;

}
