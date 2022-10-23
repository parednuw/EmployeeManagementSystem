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
		Logger.Log("Entered while-loop", Logger::Info, false);
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
	Logger.Log("In future all input regarding adding an employee gets here.", Logger::Info, false);
	
	std::unique_ptr<Employee> newEmployee = std::make_unique<Employee>();
	std::string name;
	std::string department;
	std::string jobTitle;
	int salary;
	Employee::dateOfBirth dateOfBirth;
	
	//Get user-input
	//-----------------
	std::cout << "Please enter the name: ";
	std::getline(std::cin, name);
	std::cout << "Please enter the department: ";
	std::cin >> department;
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Please enter the jobtitle: ";
	std::cin >> jobTitle;
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Please enter the salary: ";
	std::cin >> salary;
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "Please enter the date of birth: ";
	dateOfBirth = {10, 10, 1910};

	newEmployee->setName(name);
	newEmployee->setDepartment(department);
	newEmployee->setJobTitle(jobTitle);
	newEmployee->setSalary(salary);
	newEmployee->setDateOfBirth(dateOfBirth.mDayOfBirth, dateOfBirth.mMonthOfBirth, dateOfBirth.mYearOfBirth);
	
	entries.push_back(std::move(newEmployee));
	
	std::cout << "Added employee." << std::endl;
}

void EmployeeManagementSystem::deleteEmployee()
{
	Logger.Log("Deleting...", Logger::Info, false);
	
	if (entries.empty())
	{
		Logger.Log("No entry stored!", Logger::Warning, false);
		
	}else if (!entries.empty())
	{
		entries[0].reset();		//necessary?
		entries.erase(entries.begin());
		Logger.Log("Deleted Entry.", Logger::Info, false);
	}
	
	Logger.Log("Deleting Employee finished\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::viewEmployee()
{
	Logger.Log("Viewing Employee...", Logger::Info, false);
	
	if (entries.empty())
	{
		Logger.Log("No entry stored!", Logger::None, false);
		
	}else if (!entries.empty())
	{
		for (std::size_t i = 0; i < entries.size(); i++)
		{
			Employee* employeeToView = entries[i].get();
			employeeToView->print();
		}
		
	}
	
	Logger.Log("Viewing Employee finished\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::modifyEmployee()
{
	Logger.Log("Modifying Employee...", Logger::Info, false);
	
	if (entries.empty())
	{
		Logger.Log("No entry stored!", Logger::None, false);
		
	}else if (!entries.empty())
	{
		int userinput;
		std::cout << "Which employee do you want to modify? ";	//basic userinput to modify an entry
		std::cin >> userinput;
		
		Employee* employeeToModify = entries[userinput].get();
		employeeToModify->setDateOfBirth(20, 20, 2020);
		Logger.Log("Modified entry.", Logger::Info, false);
	}
	
	Logger.Log("Modifying Employee finished.\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::searchEmployee()
{
	Logger.Log("Searching Employee...", Logger::Info, false);
	
	std::string input = "Paul";
	
	for (std::size_t i = 0; i < entries.size(); i++)
	{
		Employee* employeeToSearch = entries[i].get();
		std::string employeeToSearchName = employeeToSearch->getName();
		if (input == employeeToSearchName)
			employeeToSearch->print();
	}
	
	Logger.Log("Searching Employee finished.\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::setLoopRunning(bool isLoopRunning)
{
	loopIsRunning = isLoopRunning;
}
