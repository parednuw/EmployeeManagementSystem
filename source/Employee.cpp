#include "Employee.hpp"

Employee::Employee() : mName("Empty"),
mDepartment("Empty"),
mJobTitle("Empty"),
mSalary(0),
mDateOfBirth()
{
	
}

Employee::~Employee()
{
	
}

void Employee::setName(std::string name)
{
	
}

void Employee::setDepartment(std::string department)
{
	
}

void Employee::setJobTitle(std::string jobTitle)
{
	
}

void Employee::setSalary(int salary)
{
	
}

void Employee::setDateOfBirth(Employee::DateOfBirth)
{
	
}

std::string Employee::getName()
{
	return mName;
}

std::string Employee::getDepartment()
{
	return mDepartment;
}

std::string Employee::getJobTitle()
{
	return mJobTitle;
}

int Employee::getSalary()
{
	return mSalary;
}

Employee::DateOfBirth Employee::getDateOfBirth()
{
	return mDateOfBirth;
}
