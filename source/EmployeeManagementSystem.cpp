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
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Do you want to add an employee? ";
		std::cin >> input;
		if (input == 1)	//without error-checking
			addEmployee();
		
		viewEmployee();
		
		deleteEmployee();
		
		viewEmployee();
		
		std::cin.ignore(INT_MAX, '\n');	//clears all previous input (buffer)
		std::cout << "Should loop run? ";
		std::cin >> isLoopRunning;
		setLoopRunning(isLoopRunning);
	}
	
}

void EmployeeManagementSystem::addEmployee()
{
	Logger.Log("In future all input regarding adding an employee gets here.", Logger::Info, false);
	std::unique_ptr<Employee> newEmployee = std::make_unique<Employee>();
	newEmployee->setDateOfBirth(10, 10, 1910);
	entries.push_back(std::move(newEmployee));
	std::cout << "Added employee." << std::endl;
}

void EmployeeManagementSystem::deleteEmployee()
{
	entries[0].reset();
	Logger.Log("Deleted Entry.", Logger::Info, false);
	entries.erase(entries.begin());
}

void EmployeeManagementSystem::viewEmployee()
{
	Logger.Log("Viewing Employee", Logger::Info, false);
	
	if (entries.size() == 0)
	{
		std::cout << "No entry stored!" << std::endl;
	}else if (entries.size() != 0)
	{
		//std::unique_ptr<Employee> employeeToView = std::make_unique<Employee>();
		Employee* employeeToView = entries[0].get();
		Employee::dateOfBirth employeeToViewDateOfBirth = employeeToView->getDateOfBirth();
		std::cout << "Date of Birth: " << employeeToViewDateOfBirth.toString() << std::endl;
	}
	
}

void EmployeeManagementSystem::modifyEmployee()
{
	
}

void EmployeeManagementSystem::searchEmployee()
{
	
}

void EmployeeManagementSystem::setLoopRunning(bool isLoopRunning)
{
	loopIsRunning = isLoopRunning;
}
