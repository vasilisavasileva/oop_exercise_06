#include <iostream>
#include <algorithm>

#include "Pentagon.h"
#include "Stack.h"
#include "Allocator.h"

int main() {
	setlocale(LC_ALL, "rus");
	size_t N;
	char option = '0';
	containers::stack<Pentagon<int>, allocators::my_allocator<Pentagon<int>, 800>> stack;
	Pentagon<int> pent{};
	while (option != 'q') {
		std::cout << "выберите m для проведения действий над стеком, выберите q для выхода" << std::endl;
		std::cin >> option;
		switch (option) {
		case 'q':
			break;
		case 'm':
			std::cout << "1) добавить элемент в стек\n"
				<< "2) удалить элемент из стека\n"
				<< "3) удалить элемент с выбранной позиции\n"
				<< "4) распечатать содержимое стека\n"
				<< std::endl;
			break;
		case '1': {
			std::cout << "введите координаты нового пентагона: " << std::endl;
			pent.Read(std::cin);
			stack.push(pent);
			break;
		}
		case '2': {
			stack.pop();
			break;
		}
		case '3': {
			std::cout << "выберите позицию для удаления: ";
			std::cin >> N;
			stack.delete_by_index(N);
			break;
		}
		case '4': {
			//std::for_each(stack.begin(), stack.end(), [](Pentagon<int>& X) { X.Print(std::cout); });
			for (auto Figure : stack) {
				Figure.Print(std::cout);
			}
			break;
		}
		default:
			std::cout << "не существует данной опции, попробуйте другой номер" << std::endl;
			break;
		}
	}
	return 0;
}