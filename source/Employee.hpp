#pragma once

#include <stdio.h>
#include <iostream>

/*
 This class represents an employee.
 Objects of this can be added to the EmployeeManagementSystem.
 
 */

class Employee
{
public:

	
	Employee();
	~Employee();
	
	struct dateOfBirth
	{
		int mDayOfBirth;
		int mMonthOfBirth;
		int mYearOfBirth;
	};
	
	void setName(std::string name);
	void setDepartment (std::string department);
	void setJobTitle (std::string jobTitle);
	void setSalary (int salary);
	void setDateOfBirth (int dayOfBirth, int monthOfBirth, int yearOfBirth);
	
	std::string getName();
	std::string getDepartment();
	std::string getJobTitle();
	int getSalary();
	dateOfBirth getDateOfBirth();
	
private:
	std::string mName;
	std::string mDepartment;
	std::string mJobTitle;
	int mSalary;
	
	dateOfBirth mDateOfBirth;
};
