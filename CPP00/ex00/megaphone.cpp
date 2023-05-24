#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **argv)
{
	std::string str;
	std::string uppedstr;

	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
		for (int i = 1; i < ac; ++i)
		{
			str = argv[i];
			for (char c : str)
				uppedstr += toupper(c);
			std::cout << uppedstr;
			uppedstr.clear();
			if (i == ac - 1)
				std::cout << std::endl;
		}

	return(0);
}