/*
	EmployeeManagementSystem

	Created by Paul Wunder on 30.09.22.
*/

#include <iostream>
#include "Employee.hpp"
#include "EmployeeManagementSystem.hpp"

int main(int argc, const char * argv[]) {
	
	std::cout << "Program started." << std::endl;
	int exit = 0;
	
	do{
		
		EmployeeManagementSystem mEmployeeManagementSystem;
		mEmployeeManagementSystem.Run();	//TODO move while loop into Run()
		
		std::cout << "Entered Dowhile-loop." << std::endl;
		std::cout << "0: exit, 1: one more loop. ... ";
		std::cin >> exit;
		
	}while(exit == 1);
	
	std::cout << "Program will exit now." << std::endl;
	
	return 0;
}
