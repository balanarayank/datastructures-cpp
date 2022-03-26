#include <iostream>
#include "SinglyLinkedList/SinglyLinkedList.h"
#include "DoublyLinkedList/DoublyLinkedList.h"

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

	DoublyLinkedList<int> dIntObj;
	dIntObj.InsertAtHead(40);
	dIntObj.InsertAtHead(30);
	dIntObj.InsertAtHead(20);
	dIntObj.InsertAtTail(10);
	dIntObj.InsertAtTail(5);
	std::cout << dIntObj.Display() << '\n';
	std::cout << dIntObj.DisplayReverse() << '\n';
	dIntObj.Delete(20);
	std::cout << dIntObj.Display() << '\n';
	std::cout << dIntObj.DisplayReverse() << '\n';
	dIntObj.Delete(5);
	std::cout << dIntObj.Display() << '\n';
	std::cout << dIntObj.DisplayReverse() << '\n';
	return EXIT_SUCCESS;
}
