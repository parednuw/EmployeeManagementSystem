/*
	EmployeeManagementSystem

	Created by Paul Wunder on 30.09.22.
*/

#include <iostream>
#include "Employee.hpp"
#include "EmployeeManagementSystem.hpp"
#include "Log.hpp"

int main(int argc, const char * argv[]) {
	
	Logger Logger;
	Logger.Log("Program started.", Logger::Info, true);
	
	EmployeeManagementSystem mEmployeeManagementSystem;
	mEmployeeManagementSystem.Run();
	
	Logger.Log("Program will exit now.", Logger::Info, true);
	
	return 0;
}
