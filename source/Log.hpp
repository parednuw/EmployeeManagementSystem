#pragma once

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

class Logger
{
public:
	
	Logger(){};
	~Logger(){};
	
	void LogInfo(std::string string)
	{
		std::cout << "[INFO] " << string << std::endl;
	}
	
	void LogInfoAndTime(std::string string)
	{
		const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
		const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
		std::cout << std::put_time(std::localtime(&t_c), "%F %T ") << "[INFO] " << string << std::endl;
		//TODO: Add ticks
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

//TODO: Measurement of the duration of computation
