#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

//STL контейнеры
//vector - вектор, массив
//forward list - однонаправленный список
//list - двусвязный (двунаправленный) список
//queue - очередь
//stack - стек
//map - мап
//set - набор объектов
// unordered_map - несортированный мап
// unordered_set - несортированный сет
//  
//priority_queue - приоритетная очередь
//multiset - 
//miltimap - 

int main() {

	//int arr[] = { 123, 65 };
	std::vector<int> arr = {123, 65};
	arr.push_back(670);
	arr.reserve(20); // заранее выделили память на 20 элементов (установили новую вместимость)
	arr.shrink_to_fit(); //ужать вместимость до size
	std::vector<int> vec;
	arr.push_back(22); // этот метод принимает только одно число
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << "  ";
	}
	std::cout << "\n";
	std::cout << "================\n";
	std::vector<int>::iterator it; //итератор it вектора (итератор указывает на начало - как указатель, универсальный путеводитель по элементам вектора)
	for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); it++) { //arr.begin() возвращает итератор начала вектора
		//arr.end() - итератор, указывающий на место после последнего элемента
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
	std::cout << "arr size: " << arr.size() << "\n"; //размер - кол-во всех элементов, кот. лежат в массиве
	std::cout << "arr capacity: " << arr.capacity() << "\n"; //объём выделяемой памяти (вместимость)

	std::cout << "================\n";
	std::cout << "================\n";
	std::cout << "================\n";

	std::vector<int> my_vector = { 42, 65, 77 };
	std::cout << *my_vector.begin() << "\n"; //итератор который указывает на начало - на первый элемент 42 в векторе
	//std::cout << *my_vector.end(); //Ошибка компиляции - указывает на после последнего элемента (на то, что хранится за вектором).
	//Эта память не контроируется вектором.
	std::cout << "================\n";

	//Вставляем элементы в середину:

	my_vector.emplace(my_vector.begin() + 1, 33); // в самое начало положили 33, если + 1 то на второе место
	for (size_t i = 0; i < my_vector.size(); i++) {
		std::cout << my_vector[i] << " ";
	}
	std::cout << "\n";
	std::cout << "================\n";

	my_vector.erase(my_vector.begin() + 1); // удаление элемента
	for (size_t i = 0; i < my_vector.size(); i++) {
		std::cout << my_vector[i] << " ";
	}
	std::cout << "\n";
	std::cout << "================\n";

	//Сложность по времени
	//random access (случайный доступ) O(1) - const time, случайный доступ в векторе (по индексу или итератору)
	//  - всегда одно и тоже время 
	
	//вставка / удаление O(n), n == vector.size(); //ставка и удаление зависит от размера вектора, O - время
	//чем больше вектор, тем больше времени занимает вставка и удаление элементов
	//size(1) 100ms
	//size(2) 200ms
	//[][][][][][]...[][][][][][][] // берём каждую ячейку и переносим (memmove) 
	//Существует сложность О(n^2) - опасная сложность, её надо стараться избегать

	//Двумерный вектор

	std::vector<std::vector<int>> vec2d(5, std::vector<int>(10, 5)); // двумерный массив - указатели указывающие на массивы
	std::cout << "================\n";
	for (size_t i = 0; i < vec2d.size(); i++) {
		for (size_t j = 0; j < vec2d[i].size(); j++) {
			std::cout << vec2d[i][j] << " ";
		}
		std::cout << "\n";
	}

	//Структура очередь
	std::cout << "================\n";

	std::queue<int> q; //FIFO First In First Out
	q.push(5);
	q.push(3);
	q.push(1);
	std::cout << "q.front(): " << q.front() << "\n";
	q.pop(); // выдаёт первый элемент из очереди
	std::cout << "q.front(): " << q.front() << "\n";
	q.push(4);
	q.push(8);
	q.push(55);


	//Вывод и удаление элементов из очереди
	//all operations of queue == O(1)
	while (!q.empty()) { //удаляем элементы до тех пор пока очередь не пуста

		std::cout << q.front() << " "; //выводим перый элементы, н-р 1 
		q.pop(); //удаляем этот элемент, н-р 1
	}

	std::cout << "\n";
	std::cout << "================\n";

	//Стек
	std::stack<std::string> my_stack; //LIFO Last In First Out
	my_stack.push("hello");
	my_stack.push("how are you?");
	my_stack.push("goodbye");

	while (!my_stack.empty()){
		std::cout << my_stack.top() << " ";
		my_stack.pop(); //показать что наверху стека
	}

	//Мэп - ассоциативный контейнер, контейнер, который хранит в себе пары (ключ-значение) при этом ключ должен быть уникальным
	// хранение имён людей id, любое значение O(logN)
	std::map<int, std::string> my_map;
	my_map.insert({ 1, "Vadim" });
	my_map.insert({ 2, "Andrew" });
	my_map.insert({ 3, "Bob" });
	my_map.insert({ 42, "Alex" });

	std::cout << "================\n";

	std::cout << my_map[1] << "\n";
	std::cout << my_map[42] << "\n";


}
