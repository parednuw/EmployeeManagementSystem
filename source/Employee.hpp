#pragma once

#include <stdio.h>
#include <iostream>
#include "Log.hpp"

/*
 This class represents an employee.
 Objects of this can be added to the EmployeeManagementSystem.
 
 */

class Employee
{
public:

	
	Employee();
	~Employee();
	
	bool isInputValidString(std::string input);
	bool isInputValidInteger(std::string input);
	
	void setName(std::string name);
	void setDepartment(std::string department);
	void setJobTitle(std::string jobTitle);
	void setSalary(std::string salary);
	void setDayOfBirth(std::string day);
	void setMonthOfBirth(std::string month);
	void setYearOfBirth(std::string year);
	
	std::string getName();
	std::string getDepartment();
	std::string getJobTitle();
	int getSalary();
	int getDayOfBirth();
	int getMonthOfBirth();
	int getYearOfBirth();
	
	void print();
	
private:
	std::string mName;
	std::string mDepartment;
	std::string mJobTitle;
	int mSalary;
	int mDayOfBirth;
	int mMonthOfBirth;
	int mYearOfBirth;
	
	Logger Logger;
};
