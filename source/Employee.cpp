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
//------------------------
//------------------------

//Validation
//------------------------
bool Employee::isValidString(std::string input)
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

bool Employee::isValidNumber(std::string input)
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

bool Employee::isValidDate(std::string &year, std::string &month, std::string &day)
{
	int yearAsInteger = std::stoi(year);
	int monthAsInteger = std::stoi(month);
	int dayAsInteger = std::stoi(day);
	
	bool yearValid = false;
	bool monthValid = false;
	bool dayValid = false;
	
	if(isValidNumber(year))
	{
		if (yearAsInteger < 1900 || yearAsInteger > 2022)
		{
			Logger.log("Year out of range!", Logger::Warning, false);
			yearValid = false;
		}else
			yearValid = true;
	}
	
	if(isValidNumber(month))
	{
		if (monthAsInteger < 1 || monthAsInteger > 12)
		{
			Logger.log("Month out of range!", Logger::Warning, false);
			monthValid = false;
		}else
			monthValid = true;
	}
	
	if (isValidNumber(day))
	{
		if (dayAsInteger < 1 || dayAsInteger > 31)
		{
			Logger.log("Day out of range!", Logger::Warning, false);
			dayValid = false;
		}
		else
		{
			switch (monthAsInteger)
			{
				case (1):
					if (dayAsInteger > 31)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (2):
					if (dayAsInteger > 28)	//No leap year implemented yet
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (3):
					if (dayAsInteger > 31)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case(4):
					if (dayAsInteger > 30)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (5):
					if (dayAsInteger > 31)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (6):
					if (dayAsInteger > 30)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (7):
					if (dayAsInteger > 31)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (8):
					if (dayAsInteger > 31)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (9):
					if (dayAsInteger > 30)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (10):
					if (dayAsInteger > 31)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (11):
					if (dayAsInteger > 30)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
					
				case (12):
					if (dayAsInteger > 31)
					{
						Logger.log("Day out of range!", Logger::Warning, false);
						dayValid = false;
					}else
						dayValid = true;
					break;
			}
		}
	}
	
	if (yearValid && monthValid && dayValid)
		return true;
	else
		return false;
}
//------------------------
//------------------------

//Setter
//------------------------
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
//------------------------
//------------------------

//Getter
//------------------------

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
//------------------------
//------------------------

void Employee::print(bool withHeadRow)
{
	std::string name = this->getName();
	std::string department = this->getDepartment();
	std::string jobTitle = this->getJobTitle();
	std::string salary = std::to_string(this->getSalary());
	std::string dayOfBirth = std::to_string(this->getDayOfBirth());
	std::string monthOfBirth = std::to_string(this->getMonthOfBirth());
	std::string yearOfBirth = std::to_string(this->getYearOfBirth());
	
	std::string str = "                    ";

	for (int i = 0; i < name.size(); i++)
	{
		str.pop_back();
	}
	name.append(str);
	
	str = "                    ";

	for (int i = 0; i < department.size(); i++)
	{
		str.pop_back();
	}
	department.append(str);

	str = "                    ";

	for (int i = 0; i < jobTitle.size(); i++)
	{
		str.pop_back();
	}
	jobTitle.append(str);
	
	str = "                    ";
	salary.append(" EUR");
	
	for (int i = 0; i < salary.size(); i++)
	{
		str.pop_back();
	}
	salary.append(str);
	
	str = "                    ";
	std::string birthday = dayOfBirth + "." + monthOfBirth + "." + yearOfBirth;
	
	for (int i = 0; i < birthday.size(); i++)
	{
		str.pop_back();
	}
	
	if (withHeadRow)
		std::cout << "NAME................" << "DEPARTMENT.........." << "JOB TITLE..........." << "SALARY.............." << "DATE OF BIRTH......." << std::endl;
	
	std::cout << name << department << jobTitle << salary << birthday << std::endl;
}
