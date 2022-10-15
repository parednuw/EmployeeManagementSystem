#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Employee.hpp"

/*
 This class represents the System in which all employees with their entries are stored.
 */

class EmployeeManagementSystem
{
public:
	
	EmployeeManagementSystem();
	~EmployeeManagementSystem();
	
	void Run();
	
	void addEmployee();
	void deleteEmployee();
	void viewEmployee();
	void modifyEmployee();
	
	void searchEmployee();
	
	void setLoopRunning(bool isLoopRunning);
	
private:
	//TODO add dynamic array which include all objects of Employee
	//use unique_ptr to obejcts! objects don't need to be in a continous memory block
	std::vector<std::unique_ptr<Employee>> entries;
	
	bool loopIsRunning = false;
};
