#include "factoring_object.h"
#include <iostream>
#include <vector>
#include <string>

int main(){

	std::string N = "";	
	std::vector<std::string> s;	

	

	while(std::cin >> N){
		factoring_object f = factoring_object(N);
		s = f.pollard();
		for(auto a : s){
			std::cout << a << std::endl;	
		}
		std::cout << std::endl;
	}
	return 0;
}
