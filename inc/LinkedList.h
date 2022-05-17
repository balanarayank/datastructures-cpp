#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <string>

//Node for Linked List
template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
};

//Linked List abstract
template <typename T>
class LinkedList {
    private:
        virtual Node<T> *GetNewNode(T data) = 0;
    public:
        virtual ~LinkedList() {}
        virtual Node<T> *GetFirstNode() = 0; //Get first node
        virtual Node<T> *GetLastNode() = 0; //Get last node
        virtual void InsertAtHead(T new_data) = 0; //Insert new data at head
        virtual void InsertAtTail(T new_data) = 0; //Insert new data at tail
        virtual bool DeleteData(T dataToDelete) = 0; //Delete the first node from head that contains data
        virtual bool DeleteNode(Node<T>* nodeToDelete) = 0; //Delete a particular node
        virtual std::string Display() = 0; //Display Linked List
        virtual std::string DisplayReverse() = 0; //Display Linked List in Reverse
        virtual size_t GetSize() = 0; //Get the size
};

#endif