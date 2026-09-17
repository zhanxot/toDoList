#pragma once

#include <string>
#include <vector>

struct Task {
	unsigned short id;
	std::string description;
	bool completed;
};

class ToDoList {
private:
	std::vector<Task> tasks;

public:
	void AddTask(unsigned short& currentTaskId);
	bool ChangeCorrected(const unsigned short& currentTaskId);
	bool DeleteTask(const unsigned short& currentTaskId);
	void PrintTasks();

};

