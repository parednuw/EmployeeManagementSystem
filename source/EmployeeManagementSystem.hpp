#pragma once

#include <stdio.h>
#include <iostream>
#include "Employee.hpp"

/*
 This class represents the System in which all employees with their entries are stored.
 */

class EmployeeManagementSystem
{
public:
	
	EmployeeManagementSystem();
	~EmployeeManagementSystem();
	
	void addEmployee();
	void deleteEmployee();
	void viewEmplyoee();
	void modifyEmployee();
	
	void search();
	
private:
	//TODO add dynamic array which include all objects of Employee
	//std::vector<Employee> entries;
};
