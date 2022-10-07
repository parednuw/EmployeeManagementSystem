#pragma once

#include <stdio.h>
#include <iostream>

class Employee
{
public:
	
	Employee();
	~Employee();
	
	void setName(std::string name);
	void setDepartment (std::string department);
	void setJobTitle (std::string jobTitle);
	void setSalary (int salary);
	void setDateOfBirth (int day, int month, int year);
	
	std::string getName();
	std::string getDepartment();
	std::string getJobTitle();
	int getSalary();
	void getDateOfBirth();
	
private:
	std::string name;
	std::string department;
	std::string jobTitle;
	int salary;
	
	enum dateOfBirth : int
	{
		day,
		month,
		year
	};
};
