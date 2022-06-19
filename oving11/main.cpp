#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> myvector;





int main()
{
for (int i = 1; i < 6; i++) {
		myvector.push_back(std::to_string(i));
	}
	std::cout << "myvector contains:";
  	for (std::vector<std::string>::iterator it = myvector.begin() ; it != myvector.end(); it++)
    	std::cout << ' ' << *it;
  		std::cout << '\n';

	std::vector<std::string>::reverse_iterator it = myvector.rbegin();

	while (it != myvector.rend()){
		std::cout << *it << ", ";
		it++;	
	}

}
