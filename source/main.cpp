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
	Logger.LogInfo("Program started.");

	EmployeeManagementSystem mEmployeeManagementSystem;
	mEmployeeManagementSystem.Run();
	
	Logger.LogInfo("Program will exit now.");
	
	return 0;
}
