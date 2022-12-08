#include "Employee.hpp"

Employee::Employee() : mName("Empty"),
mDepartment("Empty"),
mJobTitle("Empty"),
mSalary(0),
mDayOfBirth(0),
mMonthOfBirth(0),
mYearOfBirth(0)
{
	
}

Employee::~Employee()
{
	
}

bool Employee::isInputValidString(std::string input)
{
	int size = input.size();
	
	for (int i = 0; i < size; i++)
	{
		if(!isalpha(input[i]) && input[i] != ' ')	//only allow characters and white space
		{
			Logger.log("No digits or any special characters allowed.", Logger::Warning, false);
			return false;
		}
	}
	return true;
}

bool Employee::isInputValidInteger(std::string input)
{
	int size = input.size();
	
	for (int i = 0; i < size; i++)
	{
		if(!isdigit(input[i]))	//only allow digits
		{
			Logger.log("No characters, whitespaces or any special characters allowed.", Logger::Warning, false);
			return false;
		}
	}
	return true;
}


void Employee::setName(std::string name)
{
	mName = name;
}

void Employee::setDepartment(std::string department)
{
	mDepartment = department;
}

void Employee::setJobTitle(std::string jobTitle)
{
	mJobTitle = jobTitle;
}

void Employee::setSalary(std::string salary)
{
	
	mSalary = std::stoi(salary);
}

void Employee::setDayOfBirth(std::string day)
{
	mDayOfBirth = std::stoi(day);
}

void Employee::setMonthOfBirth(std::string month)
{
	mMonthOfBirth = std::stoi(month);
}

void Employee::setYearOfBirth(std::string year)
{
	mYearOfBirth = std::stoi(year);
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

int Employee::getDayOfBirth()
{
	return mDayOfBirth;
}

int Employee::getMonthOfBirth()
{
	return mMonthOfBirth;
}

int Employee::getYearOfBirth()
{
	return mYearOfBirth;
}

void Employee::print()
{
	std::string name = this->getName();
	std::string department = this->getDepartment();
	std::string jobTitle = this->getJobTitle();
	std::string salary = std::to_string(this->getSalary());
	std::string dayOfBirth = std::to_string(this->getDayOfBirth());
	std::string monthOfBirth = std::to_string(this->getMonthOfBirth());
	std::string yearOfBirth = std::to_string(this->getYearOfBirth());
	
	std::cout << "NAME................" << "DEPARTMENT.........." << " JOB TITLE..........." << "SALARY.............." << "DATE OF BIRTH......." << std::endl;
	
	std::cout << name << department << jobTitle << salary << dayOfBirth << monthOfBirth << yearOfBirth << std::endl;
}
