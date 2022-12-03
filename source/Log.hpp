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
		None = 0,
		Info = 1,
		Warning = 2,
		Error = 3
	};
	
	void log(std::string message, LogType logType, bool logWithTime)
	{
		switch (logType)
		{
			case None:
				logTypeString = "";
				break;
			case Info:
				logTypeString = "[INFO] ";
				break;
				
			case Warning:
				logTypeString = "[WARNING] ";
				break;
				
			case Error:
				logTypeString = "[ERROR] ";
				break;
				
			default:
				break;
		}
		
		if (logWithTime)
		{
			const std::time_t t_c = getTime();
			std::cout << std::put_time(std::localtime(&t_c), "%F %T ") << logTypeString << message << std::endl;
		}else if (! logWithTime)
		{
			std::cout << logTypeString << message << std::endl;
		}
	}
	
	std::time_t getTime()
	{
		const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
		return std::chrono::system_clock::to_time_t(now);
	}

private:
	std::string logTypeString;
	
};

//TODO: Measurement of the duration of computation
//TODO: Silencing output of specific LogTypes
