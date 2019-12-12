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
		std::cout << "�������� m ��� ���������� �������� ��� ������, �������� q ��� ������" << std::endl;
		std::cin >> option;
		switch (option) {
		case 'q':
			break;
		case 'm':
			std::cout << "1) �������� ������� � ����\n"
				<< "2) ������� ������� �� �����\n"
				<< "3) ������� ������� � ��������� �������\n"
				<< "4) ����������� ���������� �����\n"
				<< std::endl;
			break;
		case '1': {
			std::cout << "������� ���������� ������ ���������: " << std::endl;
			pent.Read(std::cin);
			stack.push(pent);
			break;
		}
		case '2': {
			stack.pop();
			break;
		}
		case '3': {
			std::cout << "�������� ������� ��� ��������: ";
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
			std::cout << "�� ���������� ������ �����, ���������� ������ �����" << std::endl;
			break;
		}
	}
	return 0;
}