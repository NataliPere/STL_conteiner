#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

//STL ����������
//vector - ������, ������
//forward list - ���������������� ������
//list - ���������� (���������������) ������
//queue - �������
//stack - ����
//map - ���
//set - ����� ��������
// unordered_map - ��������������� ���
// unordered_set - ��������������� ���
//  
//priority_queue - ������������ �������
//multiset - 
//miltimap - 

int main() {

	//int arr[] = { 123, 65 };
	std::vector<int> arr = {123, 65};
	arr.push_back(670);
	arr.reserve(20); // ������� �������� ������ �� 20 ��������� (���������� ����� �����������)
	arr.shrink_to_fit(); //����� ����������� �� size
	std::vector<int> vec;
	arr.push_back(22); // ���� ����� ��������� ������ ���� �����
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << "  ";
	}
	std::cout << "\n";
	std::cout << "================\n";
	std::vector<int>::iterator it; //�������� it ������� (�������� ��������� �� ������ - ��� ���������, ������������� ������������ �� ��������� �������)
	for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); it++) { //arr.begin() ���������� �������� ������ �������
		//arr.end() - ��������, ����������� �� ����� ����� ���������� ��������
		std::cout << *it << "  ";
	}
	std::cout << "\n";


	std::vector<int> abc(10, 3);
	for (size_t i = 0; i < abc.size(); i++) {
		std::cout << abc[i] << " ";
	}
	std::cout << "\n";
	std::cout << "================\n";


	std::cout << "\n";
	std::cout << "arr size: " << arr.size() << "\n"; //������ - ���-�� ���� ���������, ���. ����� � �������
	std::cout << "arr capacity: " << arr.capacity() << "\n"; //����� ���������� ������ (�����������)

	std::cout << "================\n";
	std::cout << "================\n";
	std::cout << "================\n";

	std::vector<int> my_vector = { 42, 65, 77 };
	std::cout << *my_vector.begin() << "\n"; //�������� ������� ��������� �� ������ - �� ������ ������� 42 � �������
	//std::cout << *my_vector.end(); //������ ���������� - ��������� �� ����� ���������� �������� (�� ��, ��� �������� �� ��������).
	//��� ������ �� ������������� ��������.
	std::cout << "================\n";

	//��������� �������� � ��������:

	my_vector.emplace(my_vector.begin() + 1, 33); // � ����� ������ �������� 33, ���� + 1 �� �� ������ �����
	for (size_t i = 0; i < my_vector.size(); i++) {
		std::cout << my_vector[i] << " ";
	}
	std::cout << "\n";
	std::cout << "================\n";

	my_vector.erase(my_vector.begin() + 1); // �������� ��������
	for (size_t i = 0; i < my_vector.size(); i++) {
		std::cout << my_vector[i] << " ";
	}
	std::cout << "\n";
	std::cout << "================\n";

	//��������� �� �������
	//random access (��������� ������) O(1) - const time, ��������� ������ � ������� (�� ������� ��� ���������)
	//  - ������ ���� � ���� ����� 
	
	//������� / �������� O(n), n == vector.size(); //������ � �������� ������� �� ������� �������, O - �����
	//��� ������ ������, ��� ������ ������� �������� ������� � �������� ���������
	//size(1) 100ms
	//size(2) 200ms
	//[][][][][][]...[][][][][][][] // ���� ������ ������ � ��������� (memmove) 
	//���������� ��������� �(n^2) - ������� ���������, � ���� ��������� ��������

	//��������� ������

	std::vector<std::vector<int>> vec2d(5, std::vector<int>(10, 5)); // ��������� ������ - ��������� ����������� �� �������
	std::cout << "================\n";
	for (size_t i = 0; i < vec2d.size(); i++) {
		for (size_t j = 0; j < vec2d[i].size(); j++) {
			std::cout << vec2d[i][j] << " ";
		}
		std::cout << "\n";
	}

	//��������� �������
	std::cout << "================\n";

	std::queue<int> q; //FIFO First In First Out
	q.push(5);
	q.push(3);
	q.push(1);
	std::cout << "q.front(): " << q.front() << "\n";
	q.pop(); // ����� ������ ������� �� �������
	std::cout << "q.front(): " << q.front() << "\n";
	q.push(4);
	q.push(8);
	q.push(55);


	//����� � �������� ��������� �� �������
	//all operations of queue == O(1)
	while (!q.empty()) { //������� �������� �� ��� ��� ���� ������� �� �����

		std::cout << q.front() << " "; //������� ����� ��������, �-� 1 
		q.pop(); //������� ���� �������, �-� 1
	}

	std::cout << "\n";
	std::cout << "================\n";

	//����
	std::stack<std::string> my_stack; //LIFO Last In First Out
	my_stack.push("hello");
	my_stack.push("how are you?");
	my_stack.push("goodbye");

	while (!my_stack.empty()){
		std::cout << my_stack.top() << " ";
		my_stack.pop(); //�������� ��� ������� �����
	}

	//��� - ������������� ���������, ���������, ������� ������ � ���� ���� (����-��������) ��� ���� ���� ������ ���� ����������
	// �������� ��� ����� id, ����� �������� O(logN)
	std::map<int, std::string> my_map;
	my_map.insert({ 1, "Vadim" });
	my_map.insert({ 2, "Andrew" });
	my_map.insert({ 3, "Bob" });
	my_map.insert({ 42, "Alex" });

	std::cout << "================\n";

	std::cout << my_map[1] << "\n";
	std::cout << my_map[42] << "\n";


}
