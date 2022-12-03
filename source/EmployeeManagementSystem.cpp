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
		modifyEmployee();
		viewEmployee();
		searchEmployee();
		
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
	int salary;
	std::string dateOfBirthString;
	Employee::dateOfBirth dateOfBirth;
	
	//Get user-input
	//-----------------
	std::cout << "Please enter the name: ";
	std::getline(std::cin, name);
	newEmployee->setName(name);	//TODO: here and in the following setter-lines is one copy-instruction to much
	std::cout << "Please enter the department: ";
	std::cin >> department;
	newEmployee->setDepartment(department);
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Please enter the jobtitle: ";
	std::cin >> jobTitle;
	newEmployee->setJobTitle(jobTitle);
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Please enter the salary: ";
	std::cin >> salary;
	newEmployee->setSalary(salary);
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Please enter the day of the date of birth (DD): ";
	std::cin >> dateOfBirth.mDayOfBirth;
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Please enter the month of the date of birth (MM): ";
	std::cin >> dateOfBirth.mMonthOfBirth;
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Please enter the year of the date of birth (YYYY): ";
	std::cin >> dateOfBirth.mYearOfBirth;
	newEmployee->setDateOfBirth(dateOfBirth.mDayOfBirth, dateOfBirth.mMonthOfBirth, dateOfBirth.mYearOfBirth);
	std::cin.ignore(INT_MAX, '\n');
	
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
		entries[0].reset();		//necessary?
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
		employeeToModify->setDateOfBirth(20, 20, 2020);
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
