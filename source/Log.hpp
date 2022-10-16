#pragma once

#include <stdio.h>
#include <iostream>

class Logger
{
public:
	
	Logger(){};
	~Logger(){};
	
	void LogInfo(std::string string)
	{
		std::cout << "[INFO] " << string << std::endl;
	}
	
	void LogWarning(std::string string)
	{
		std::cout << "[WARNING] " << string << std::endl;
	}
	
	void LogError(std::string string)
	{
		std::cout << "[ERROR] " << string << std::endl;
	}
};
