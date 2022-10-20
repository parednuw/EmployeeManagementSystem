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
		if (input == 1)	//without error-checking
			addEmployee();
		
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
	
}

void EmployeeManagementSystem::viewEmployee()
{
	
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
