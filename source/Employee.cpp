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

void Employee::setName(std::string name)
{
	int size = name.size();
	
	for (int i = 0; i < size; i++)
	{
		if(!isalpha(name[i]) && name[i] != ' ')	//only allow characters and white space
		{
			Logger.log("No digits or any special characters allowed.", Logger::Warning, false);
			break;
		}
		else if (i == (size - 1))
			mName = name;
	}
}

void Employee::setDepartment(std::string department)
{
	int size = department.size();
	
	for (int i = 0; i < size; i++)
	{
		if(!isalpha(department[i]) && department[i] != ' ')	//only allow characters and white space
		{
			Logger.log("No digits or any special characters allowed.", Logger::Warning, false);
			break;
		}
		else if (i == (size - 1))
			mDepartment = department;
	}
}

void Employee::setJobTitle(std::string jobTitle)
{
	int size = jobTitle.size();
	
	for (int i = 0; i < size; i++)
	{
		if(!isalpha(jobTitle[i]) && jobTitle[i] != ' ')	//only allow characters and white space
		{
			Logger.log("No digits or any special characters allowed.", Logger::Warning, false);
			break;
		}
		else if (i == (size - 1))
			mJobTitle = jobTitle;
	}
}

void Employee::setSalary(int salary) //no error checking implemented yet
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

std::string Employee::dateOfBirth::toString()
{
	std::string dayString = std::to_string(mDayOfBirth);
	std::string monthString = std::to_string(mMonthOfBirth);
	std::string yearString = std::to_string(mYearOfBirth);
	
	std::string string = dayString + "." + monthString + "." + yearString;
	return string;
}


//function is deprecated!
/*
Employee::dateOfBirth Employee::toDateOfBirth(std::string userInputString)
{
	
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
*/
