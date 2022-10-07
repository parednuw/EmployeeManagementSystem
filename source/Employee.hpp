#pragma once

#include <stdio.h>
#include <iostream>

/*
 This class represents an employee. Objects can be added to the management system
 
 */

class Employee
{
public:
	
	enum DateOfBirth : int
	{
		day,
		month,
		year
	};
	
	Employee();
	~Employee();
	
	void setName(std::string name);
	void setDepartment (std::string department);
	void setJobTitle (std::string jobTitle);
	void setSalary (int salary);
	void setDateOfBirth (DateOfBirth);
	
	std::string getName();
	std::string getDepartment();
	std::string getJobTitle();
	int getSalary();
	DateOfBirth getDateOfBirth();
	
private:
	std::string mName;
	std::string mDepartment;
	std::string mJobTitle;
	int mSalary;
	DateOfBirth mDateOfBirth;
	
};
