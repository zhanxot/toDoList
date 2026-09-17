#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include "Todolist.h"

void PrintTasks(const std::vector<Task> &tasks) {
	for (const auto& s : tasks) {
		std::cout << s.id << '\t' << s.description << '\t';
		if (s.completed) std::cout << "Выполнено\n";
		else std::cout << "Не выполнено\n";
	}

}

void AddTask(std::vector<Task> &tasks, unsigned short& currentTaskId) {
	std::string description;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, description);
	Task current = { currentTaskId, description, false };
	tasks.push_back(current);
	currentTaskId++;
}

bool ChangeCorrected(std::vector<Task>& tasks, const unsigned short& currentTaskId) {
	auto it = std::find_if(tasks.begin(), tasks.end(), [currentTaskId](const Task& task) {return task.id == currentTaskId;});
	if (it == tasks.end()) return false;

	it->completed = true;
	return true;
}

void RunMenu() {
	std::cout << "1.Добавить задачу и вывести весь список задач\n";
	std::cout << "2. Поставить отметку выполнено для задачи по ее id\n";
	std::cout << "3. Удалить задачу\n";
	std::cout << "4. Вывести список всех задач\n";
	std::cout << "5. Выйти из меню\n";
}

bool DeleteTask(std::vector<Task>& tasks, const unsigned short& currentTaskId) {

	auto it = std::find_if(tasks.begin(), tasks.end(), [currentTaskId](const Task& task) {return task.id == currentTaskId; });
	if (it == tasks.end()) {
		return false; // не нашли задачу с таким id
	}

	tasks.erase(it); // erase получает именно итератор, найденный find_if
	return true;
} 

unsigned short ChoiceMenuButton() {
	unsigned short choice;
	std::cout << "Введите цифру ";
	std::cin >> choice; //пока без проверки
	std::cout << "\n"; 
	return choice;
}

int main() {
	setlocale(LC_ALL, "ru");

	unsigned short id = 1;

	std::vector<Task> tasks;
	bool running = true; 
	
	while (running) {
		RunMenu();
		unsigned short choice = ChoiceMenuButton();
		switch (choice) {
			case 1:	
				AddTask(tasks,id);
				break;
			case 2: 
				unsigned short idForChangeCorrected;
				std::cout << "Введите id задачи ";
				std::cin >> idForChangeCorrected; std::cout << '\n';
				ChangeCorrected(tasks, idForChangeCorrected);
				break;
			case 3: 
				unsigned short idForDelete;
				std::cout << "Введите id задачи которую хотите удалить ";
				std::cin >> idForDelete; std::cout << '\n';
				DeleteTask(tasks, idForDelete);
				break;

			case 4:
				PrintTasks(tasks);
				break;
			case 5:
				running = false;
				break;
			default: 
				std::cout << "Такого пункта нет в меню\n";
				break;
		}
	}
}