#include "EmployeeManagementSystem.hpp"

EmployeeManagementSystem::EmployeeManagementSystem()
{
	
}

EmployeeManagementSystem::~EmployeeManagementSystem()
{
	
}

void EmployeeManagementSystem::Run()
{
	setLoopRunning(true);
	
	while(loopIsRunning)
	{
		Logger.log("Entered while-loop", Logger::Info, false);
		bool isLoopRunning;
		
		bool input;
		std::cout << "Do you want to add an employee? ";
		std::cin >> input;
		std::cin.ignore(INT_MAX, '\n');
		if (input == 1)	//without error-checking
			addEmployee();
		
		viewEmployee();
		//modifyEmployee();
		//viewEmployee();
		//searchEmployee();
		deleteEmployee();
		
		std::cout << "Should loop run? ";
		std::cin >> isLoopRunning;
		std::cin.ignore(INT_MAX, '\n');	//clears all previous input (buffer)
		setLoopRunning(isLoopRunning);
	}
	
}

void EmployeeManagementSystem::addEmployee()
{
	std::unique_ptr<Employee> newEmployee = std::make_unique<Employee>();
	std::string name;
	std::string department;
	std::string jobTitle;
	std::string salary;
	std::string dayOfBirth;
	std::string monthOfBirth;
	std::string yearOfBirth;
	
	//Get user-input
	//-----------------
	std::cout << "Please enter the name: ";
	std::getline(std::cin, name);
	if(newEmployee->isInputValidString(name))
		newEmployee->setName(name);	//TODO: here and in the following setter-lines is one copy-instruction to much?
	std::cin.clear();
	
	std::cout << "Please enter the department: ";
	std::getline(std::cin, department);
	if(newEmployee->isInputValidString(department))
		newEmployee->setDepartment(department);
	std::cin.clear();
	
	std::cout << "Please enter the jobtitle: ";
	std::getline(std::cin, jobTitle);
	if(newEmployee->isInputValidString(jobTitle))
		newEmployee->setJobTitle(jobTitle);
	std::cin.clear();
	
	std::cout << "Please enter the salary: ";
	std::getline(std::cin, salary);
	if (newEmployee->isInputValidInteger(salary))
		newEmployee->setSalary(salary);
	std::cin.clear();
	
	std::cout << "Please enter the day of the date of birth (DD): ";
	std::getline(std::cin, dayOfBirth);
	if (newEmployee->isInputValidInteger(dayOfBirth))
		newEmployee->setDayOfBirth(dayOfBirth);
	std::cin.clear();
	
	std::cout << "Please enter the month of the date of birth (MM): ";
	std::getline(std::cin, monthOfBirth);
	if (newEmployee->isInputValidInteger(monthOfBirth))
		newEmployee->setMonthOfBirth(monthOfBirth);
	std::cin.clear();
	
	std::cout << "Please enter the year of the date of birth (YYYY): ";
	std::getline(std::cin, yearOfBirth);
	if (newEmployee->isInputValidInteger(yearOfBirth))
		newEmployee->setYearOfBirth(yearOfBirth);
	std::cin.clear();
	
	entries.push_back(std::move(newEmployee));
	
	std::cout << "Added employee." << std::endl;
}

void EmployeeManagementSystem::deleteEmployee()
{
	Logger.log("Deleting...", Logger::Info, false);
	
	if (entries.empty())
	{
		Logger.log("No entry stored!", Logger::Warning, false);
		
	}else if (!entries.empty())
	{
		entries.erase(entries.begin());
		Logger.log("Deleted Entry.", Logger::Info, false);
	}
	
	Logger.log("Deleting Employee finished\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::viewEmployee()
{
	Logger.log("Viewing Employee...", Logger::Info, false);
	
	if (entries.empty())
	{
		Logger.log("No entry stored!", Logger::None, false);
		
	}else if (!entries.empty())
	{
		for (std::size_t i = 0; i < entries.size(); i++)
		{
			Employee* employeeToView = entries[i].get();
			employeeToView->print();
		}
	}
	
	Logger.log("Viewing Employee finished\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::modifyEmployee()
{
	Logger.log("Modifying Employee...", Logger::Info, false);
	
	if (entries.empty())
	{
		Logger.log("No entry stored!", Logger::None, false);
		
	}else if (!entries.empty())
	{
		int userinput;
		std::cout << "Which employee do you want to modify? ";	//basic userinput to modify an entry
		std::cin >> userinput;
		
		Employee* employeeToModify = entries[userinput].get();
		employeeToModify->setDayOfBirth("20");
		Logger.log("Modified entry.", Logger::Info, false);
	}
	
	Logger.log("Modifying Employee finished.\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::searchEmployee()
{
	Logger.log("Searching Employee...", Logger::Info, false);
	
	std::string input = "Paul";
	
	for (std::size_t i = 0; i < entries.size(); i++)
	{
		Employee* employeeToSearch = entries[i].get();
		std::string employeeToSearchName = employeeToSearch->getName();
		if (input == employeeToSearchName)
			employeeToSearch->print();
	}
	
	Logger.log("Searching Employee finished.\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::setLoopRunning(bool isLoopRunning)
{
	loopIsRunning = isLoopRunning;
}
