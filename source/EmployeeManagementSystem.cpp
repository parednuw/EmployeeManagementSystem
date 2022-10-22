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
		
		//Testing methods
		viewEmployee();
		
		modifyEmployee();
		
		viewEmployee();
		
		deleteEmployee();
		
		viewEmployee();
		//Done Testing methods
		
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
	//Simulating user-input
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
	
	//Simulating finished
	newEmployee->set(name, department, jobTitle, salary, dateOfBirth);
	entries.push_back(std::move(newEmployee));
	std::cout << "Added employee." << std::endl;
}

void EmployeeManagementSystem::deleteEmployee()
{
	Logger.Log("Deleting...", Logger::Info, false);
	
	if (entries.size() == 0)
	{
		Logger.Log("No entry stored!", Logger::Warning, false);
		
	}else if (entries.size() != 0)
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
	
	if (entries.size() == 0)
	{
		Logger.Log("No entry stored!", Logger::None, false);
		
	}else if (entries.size() != 0)
	{
		Employee* employeeToView = entries[0].get();
		employeeToView->print();
	}
	Logger.Log("Viewing Employee finished\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::modifyEmployee()
{
	Logger.Log("Modifying Employee...", Logger::Info, false);
	
	if (entries.size() == 0)
	{
		Logger.Log("No entry stored!", Logger::None, false);
		
	}else if (entries.size() != 0)
	{
		Employee* employeeToModify = entries[0].get();
		employeeToModify->setDateOfBirth(20, 20, 2020);
		Logger.Log("Modified entry.", Logger::Info, false);
	}
	
	Logger.Log("Modifying Employee finished.\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::searchEmployee()
{
	
}

/*bool EmployeeManagementSystem::isEmpty()
{
	if (entries.size() == 0)
		return true;
	else
		return false;
	
	
}*/

void EmployeeManagementSystem::setLoopRunning(bool isLoopRunning)
{
	loopIsRunning = isLoopRunning;
}
