// Sam Borick <sb205@uakron.edu>
// University of Akron

#include <iostream>

int main()
{
	int i = 1;
	std::string s;
	int nameLength;
	std::string name;
	while(std::getline(std::cin, s)){
		nameLength = s.find('\t');
		if(nameLength != 0){
			name = s.substr(0, nameLength);
			std::cout << name << "\n";
		}else{
			//do nothing
		}
	}
	return 0;
}
