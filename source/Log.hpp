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
	
	enum LogType
	{
		Info = 0,
		Warning = 1,
		Error = 2
	};
	
	void Log(std::string message, LogType logType, bool logWithTime)
	{
		if ( logType == 0)
		{
			string = "[INFO] ";
		}else if ( logType == 1)
		{
			string = "[WARNING] ";
		}else if (logType == 2)
		{
			string = "[ERROR] ";
		}
		
		if (logWithTime)
		{
			const std::time_t t_c = getTime();
			std::cout << std::put_time(std::localtime(&t_c), "%F %T ") << string << message << std::endl;
			//TODO: Add ticks
		}else if (! logWithTime)
		{
			std::cout << string << message << std::endl;
		}
		
	}
	
	std::time_t getTime()
	{
		const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
		return std::chrono::system_clock::to_time_t(now);
	}

private:
	std::string string;
	
};

//TODO: Measurement of the duration of computation
