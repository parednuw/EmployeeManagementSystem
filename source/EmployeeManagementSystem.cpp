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
		bool isLoopRunning;
		std::cout << "Entered while-loop" << std::endl;
		std::cout << "Should loop run? ";
		std::cin >> isLoopRunning;
		
		setLoopRunning(isLoopRunning);
		
		
		
	}
}

void EmployeeManagementSystem::addEmployee()
{
	std::unique_ptr<Employee> newEmployee = std::make_unique<Employee>();
	newEmployee->setDateOfBirth(10, 10, 1910);
	entries.push_back(std::move(newEmployee));
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
