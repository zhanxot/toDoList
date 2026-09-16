#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

void PrintTasks(const std::vector<std::string> &description) {
	for (const std::string s : description) {
		std::cout << s << "\n";
	}

}

void AddTask(std::vector<std::string> &description) {
	description.push_back("lol");
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

	std::vector<std::string> tasksDescription;
	bool running = true; 
	std::cout << "1.Добавить задачу и вывести весь список задач\n";
	std::cout << "2. Выйти из меню\n";

	while (running) {
		unsigned short choice = ChoiceMenuButton();
		switch (choice) {
			case 1:	
				AddTask(tasksDescription);
				PrintTasks(tasksDescription);
				break;
			case 2: 
				running = false;
				break;
			default: 
				std::cout << "Такого пункта нет в меню\n";
		}
	}
}