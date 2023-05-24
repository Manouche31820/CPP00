#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
// class Contact;

class Phonebook 
{

public:

	Phonebook(void);
	~Phonebook(void);
	void start(void);

private:
	Contact _contacts[8];
	int _i;
	int _j;
	void add(void);
	void search(void);
};

#endif