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
		
		//Testing methods
		viewEmployee();
		
		modifyEmployee();
		
		viewEmployee();
		
		deleteEmployee();
		
		viewEmployee();
		//Done Testing methods
		
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
	newEmployee->setName("Toni Test");
	newEmployee->setDepartment("Sales");
	newEmployee->setJobTitle("Head");
	newEmployee->setSalary(3000);
	newEmployee->setDateOfBirth(10, 10, 1910);
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
		std::cout << "No entry stored!" << std::endl;
		
	}else if (entries.size() != 0)
	{
		Employee* employeeToView = entries[0].get();
		std::string employeeToViewName = employeeToView->getName();
		std::string employeeToViewDepartment = employeeToView->getDepartment();
		std::string employeeToViewJobTitle = employeeToView->getJobTitle();
		int employeeToViewSalary = employeeToView->getSalary();
		std::string employeeToViewSalaryString = std::to_string(employeeToViewSalary);
		Employee::dateOfBirth employeeToViewDateOfBirth = employeeToView->getDateOfBirth();
		
		std::cout << "Name: " << employeeToViewName << std::endl;
		std::cout << "Department: " << employeeToViewDepartment << std::endl;
		std::cout << "Job Title: " << employeeToViewJobTitle << std::endl;
		std::cout << "Salary: " << employeeToViewSalaryString << std::endl;
		std::cout << "Date of Birth: " << employeeToViewDateOfBirth.toString() << std::endl;
	}
	Logger.Log("Viewing Employee finished\n###############", Logger::Info, false);
}

void EmployeeManagementSystem::modifyEmployee()
{
	Logger.Log("Modifying Employee...", Logger::Info, false);
	
	if (entries.size() == 0)
	{
		std::cout << "No entry stored!" << std::endl;
		
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

void EmployeeManagementSystem::setLoopRunning(bool isLoopRunning)
{
	loopIsRunning = isLoopRunning;
}
