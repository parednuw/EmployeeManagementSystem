#include "Employee.hpp"

Employee::Employee() : mName("Empty"),
mDepartment("Empty"),
mJobTitle("Empty"),
mSalary(0)
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

void Employee::setDateOfBirth(int day, int month, int year)
{
	mDateOfBirth.mDayOfBirth = day;
	mDateOfBirth.mMonthOfBirth = month;
	mDateOfBirth.mYearOfBirth = year;
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

Employee::dateOfBirth Employee::getDateOfBirth()
{
	return mDateOfBirth;
}
