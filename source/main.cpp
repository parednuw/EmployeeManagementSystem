/*
	EmployeeManagementSystem

	Created by Paul Wunder on 30.09.22.
*/

#include <iostream>
#include "Employee.hpp"
#include "EmployeeManagementSystem.hpp"

int main(int argc, const char * argv[]) {
	
	
	std::cout << "Program started." << std::endl;

	EmployeeManagementSystem mEmployeeManagementSystem;
	mEmployeeManagementSystem.Run();
	
	std::cout << "Program will exit now." << std::endl;
	
	return 0;
}
