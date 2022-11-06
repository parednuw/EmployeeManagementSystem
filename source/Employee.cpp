#include "Employee.hpp"

Employee::Employee() : mName("Empty"),
mDepartment("Empty"),
mJobTitle("Empty"),
mSalary(0),
mDateOfBirth{00, 00, 0000}
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

void Employee::print()
{
	std::string employeeToViewName = this->getName();
	std::string employeeToViewDepartment = this->getDepartment();
	std::string employeeToViewJobTitle = this->getJobTitle();
	int employeeToViewSalary = this->getSalary();
	std::string employeeToViewSalaryString = std::to_string(employeeToViewSalary);
	Employee::dateOfBirth employeeToViewDateOfBirth = this->getDateOfBirth();
	
	std::cout << "NAME................" << "DEPARTMENT.........." << " JOB TITLE..........." << "SALARY.............." << "DATE OF BIRTH......." << std::endl;
	
	std::cout << employeeToViewName << employeeToViewDepartment << employeeToViewJobTitle << employeeToViewSalaryString << employeeToViewDateOfBirth.toString() << std::endl;
}

Employee::dateOfBirth Employee::toDateOfBirth(std::string userInputString)
{
	//TODO: if input of user is already int, none of the following would be necessary. break user input for date of birth into multiple input-requests would be perfect, because with a GUI the values are int and seperately nevertheless.
	
	Employee::dateOfBirth dateOfBirth;
	userInputString = "10.20.3030";	//placeholder input
	
	std::string::size_type index = 0;
	int size = userInputString.size();
	
	index = userInputString.find('.', index);
	std::string day = userInputString.substr(0, index);
	std::string month = userInputString.substr(index + 1, 2);
	
	std::string substring = userInputString.substr(index + 1, size);
	index = substring.find('.', index);
	std::string year = substring.substr(index + 1, size);
	
	dateOfBirth.mDayOfBirth = std::stoi(day);
	dateOfBirth.mMonthOfBirth = std::stoi(month);
	dateOfBirth.mYearOfBirth = std::stoi(year);
	std::cout << std::endl << dateOfBirth.mYearOfBirth << std::endl << dateOfBirth.mMonthOfBirth << std::endl << dateOfBirth.mDayOfBirth << std::endl;
	return dateOfBirth;
}

std::string Employee::dateOfBirth::toString()
{
	std::string dayString = std::to_string(mDayOfBirth);
	std::string monthString = std::to_string(mMonthOfBirth);
	std::string yearString = std::to_string(mYearOfBirth);
	
	std::string string = dayString + "." + monthString + "." + yearString;
	return string;
}
