#include "SinglyLinkedList.h"
#include <iostream>

int main(int argc, char* argv[]) {
    SinglyLinkedList<int> sllIntObj;
    sllIntObj.InsertAtHead(1);
    sllIntObj.InsertAtHead(3);
    sllIntObj.InsertAtTail(2);
    sllIntObj.InsertAtTail(4);
    sllIntObj.InsertAtHead(5);
    std::cout << "First Node Data: " << sllIntObj.GetFirstNode()->data << std::endl;
    std::cout << "Last Node Data: " << sllIntObj.GetLastNode()->data << std::endl;
    std::cout << "Linked List: " << sllIntObj.Display() << std::endl;
    std::cout << "Linked List Size: " << sllIntObj.GetSize() << std::endl;
    
    if(sllIntObj.DeleteData(5)) {
        std::cout << "Deleted 5\n";
    }
    std::cout << "First Node Data: " << sllIntObj.GetFirstNode()->data << std::endl;
    std::cout << "Last Node Data: " << sllIntObj.GetLastNode()->data << std::endl;
    std::cout << "Linked List: " << sllIntObj.Display() << std::endl;
    std::cout << "Linked List Size: " << sllIntObj.GetSize() << std::endl;
    
    if(sllIntObj.DeleteData(1)) {
        std::cout << "Deleted 1\n";
    }
    if(sllIntObj.DeleteData(100)) {
        std::cout << "Deleted 100\n";
    }
    std::cout << "First Node Data: " << sllIntObj.GetFirstNode()->data << std::endl;
    std::cout << "Last Node Data: " << sllIntObj.GetLastNode()->data << std::endl;
    std::cout << "Linked List: " << sllIntObj.Display() << std::endl;
    std::cout << "Linked List Size: " << sllIntObj.GetSize() << std::endl;

    sllIntObj.InsertAtTail(6);
    sllIntObj.InsertAtHead(7);
    std::cout << "First Node Data: " << sllIntObj.GetFirstNode()->data << std::endl;
    std::cout << "Last Node Data: " << sllIntObj.GetLastNode()->data << std::endl;
    std::cout << "Linked List: " << sllIntObj.Display() << std::endl;
    std::cout << "Linked List Size: " << sllIntObj.GetSize() << std::endl;

    if(sllIntObj.DeleteData(6)) {
        std::cout << "Deleted 6\n";
    }
    std::cout << "First Node Data: " << sllIntObj.GetFirstNode()->data << std::endl;
    std::cout << "Last Node Data: " << sllIntObj.GetLastNode()->data << std::endl;
    std::cout << "Linked List: " << sllIntObj.Display() << std::endl;
    std::cout << "Linked List Size: " << sllIntObj.GetSize() << std::endl;

    if(sllIntObj.DeleteNode(sllIntObj.GetFirstNode()->next->next)) {
        std::cout << "Deleted node\n";
    }
    std::cout << "First Node Data: " << sllIntObj.GetFirstNode()->data << std::endl;
    std::cout << "Last Node Data: " << sllIntObj.GetLastNode()->data << std::endl;
    std::cout << "Linked List: " << sllIntObj.Display() << std::endl;
    std::cout << "Linked List Size: " << sllIntObj.GetSize() << std::endl;
    std::cout << "Linked List in reverse: " << sllIntObj.DisplayReverse() << std::endl;

    SinglyLinkedList<std::string> sllStrObj;
    sllStrObj.InsertAtHead("Hello");
    std::cout << "Linked List: " << sllStrObj.Display() << std::endl;
    std::cout << "Linked List Size: " << sllStrObj.GetSize() << std::endl;
    sllStrObj.DeleteData("Hello");
    std::cout << "Linked List: " << sllStrObj.Display() << std::endl;
    std::cout << "Linked List Size: " << sllStrObj.GetSize() << std::endl;
    
    return EXIT_SUCCESS;
}