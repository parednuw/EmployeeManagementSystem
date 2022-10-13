#include "EmployeeManagementSystem.hpp"

EmployeeManagementSystem::EmployeeManagementSystem()
{
	
}

EmployeeManagementSystem::~EmployeeManagementSystem()
{
	
}

void EmployeeManagementSystem::Run()
{
	
}

void EmployeeManagementSystem::addEmployee()
{
	std::unique_ptr<Employee> newEmployee = std::make_unique<Employee>();
	newEmployee->setDateOfBirth(10, 10, 1910);
	entries.push_back(newEmployee);
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
