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

void Employee::setName(std::string name)	//no error checking implemented yet
{
	mName = name;
}

void Employee::setDepartment(std::string department)	//no error checking implemented yet
{
	mDepartment = department;
}

void Employee::setJobTitle(std::string jobTitle)	//no error checking implemented yet
{
	mJobTitle = jobTitle;
}

void Employee::setSalary(int salary)	//no error checking implemented yet
{
	mSalary = salary;
}

void Employee::setDateOfBirth(int day, int month, int year)	//no error checking implemented yet
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

std::string Employee::dateOfBirth::toString()
{
	std::string dayString = std::to_string(mDayOfBirth);
	std::string monthString = std::to_string(mMonthOfBirth);
	std::string yearString = std::to_string(mYearOfBirth);
	
	std::string string = dayString + "." + monthString + "." + yearString;
	return string;
}
