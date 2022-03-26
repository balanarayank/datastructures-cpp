#include <iostream>
#include "SinglyLinkedList/SinglyLinkedList.h"

int main(int argc, char* argv[]) {
	SinglyLinkedList<int> sIntObj;
	sIntObj.InsertAtHead(10);
	sIntObj.InsertAtHead(20);
	sIntObj.InsertAtHead(30);
	sIntObj.InsertAtTail(30);
	std::cout << sIntObj.Display() << '\n';
	sIntObj.Delete(20);
	sIntObj.Delete(30);
	std::cout << sIntObj.Display() << '\n';

	SinglyLinkedList<std::string> sStrObj;
	sStrObj.InsertAtHead("Hi");
	sStrObj.InsertAtTail("This");
	sStrObj.InsertAtTail("Works!");
	std::cout << sStrObj.Display() << '\n';
	sStrObj.Delete("Hi");
	std::cout << sStrObj.Display() << '\n';
	return EXIT_SUCCESS;
}
