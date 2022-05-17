#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

#include "LinkedList.h"
#include <sstream>

template <typename T>
class SinglyLinkedList : public LinkedList<T> {
    private:
        Node<T> *head; //head of linked list
        Node<T> *tail; //tail of linked list
        size_t sllSize; //size of linked list
        //Get new node with data
        Node<T> *GetNewNode(T data) override {
            Node<T> *newNode = new Node<T>;
            newNode->data = data;
            newNode->next = nullptr;
            return newNode;
        }
    public:
        //Initialize head, tail and size as null
        SinglyLinkedList() : head(nullptr), tail(nullptr), sllSize(0) {}
        //Delete each node to prevent memory leak
        ~SinglyLinkedList() {
            Node<T> *nodeToDelete = head;
            while(nodeToDelete != nullptr) {
                Node<T> *nextNode = nodeToDelete->next;
                delete nodeToDelete;
                nodeToDelete = nextNode;
            }
        }
        //Get First Node
        Node<T> *GetFirstNode() override {
            return head;
        }
        //Get Last Node
        Node<T> *GetLastNode() override {
            return tail;
        }
        //Insert new data at head
        void InsertAtHead(T new_data) override {
            Node<T> *newNode = GetNewNode(new_data);
            if(head == nullptr) { //if head is null, new node will be head and tail
                head = newNode;
                tail = newNode;
                sllSize++;
                return;
            }
            newNode->next = head; //new node should point to head
            head = newNode; //update new head as new node
            sllSize++;
            return;
        }
        //Insert new data at tail
        void InsertAtTail(T new_data) override {
            Node<T> *newNode = GetNewNode(new_data);
            if(tail == nullptr) { //if head is null, new node will be head
                head = newNode;
                tail = newNode;
                sllSize++;
                return;
            }
            tail->next = newNode; //insert new node at the last
            tail = newNode;
            sllSize++;
        }
        //Deletes the first node from head that contains data
        bool DeleteData(T dataToDelete) override {
            if(head == nullptr) {
                return false;
            }
            if(head->data == dataToDelete) {
                Node<T> *nodeToDelete = head;
                head = head->next;
                if(head == nullptr) {
                    tail = nullptr;
                }
                delete nodeToDelete;
                sllSize--;
                return true;
            }
            Node<T> *currNode = head;
            bool isDelete = false;
            while(currNode->next != nullptr) {
                if(currNode->next->data == dataToDelete) {
                    isDelete = true;
                    break;
                }
                currNode = currNode->next;
            }
            if(isDelete) {
                Node<T> *nodeToDelete = currNode->next;
                currNode->next = currNode->next->next;
                if(currNode->next == nullptr) {
                    tail = currNode;
                }
                delete nodeToDelete;
                sllSize--;
                return true;
            }
            return false;
        }
        //Delete a particular node
        bool DeleteNode(Node<T> *nodeToDelete) {
            if(head == nodeToDelete) {
                head = head->next;
                delete nodeToDelete;
                sllSize--;
                return true;                
            }
            Node<T> *currNode = head;
            bool isDelete = false;
            while(currNode->next != nodeToDelete) {
                currNode = currNode->next;
            }
            currNode->next = currNode->next->next;
            if(currNode->next == nullptr) {
                tail = currNode;
            }
            delete nodeToDelete;
            sllSize--;
            return true;
        }
        std::string Display() override {
            if(head == nullptr) {
                return "SinglyLinkedList is empty";
            }
            std::ostringstream oss;
            Node<T> *currNode = head;
            while(currNode != nullptr) {
                oss << currNode->data << " -> ";
                currNode = currNode->next;
            }
            return oss.str();
        }
        std::string DisplayReverse() override {
            return "Not supported for SinglyLinkedList";
        }
        size_t GetSize() override {
            return sllSize;
        }
};

#endif