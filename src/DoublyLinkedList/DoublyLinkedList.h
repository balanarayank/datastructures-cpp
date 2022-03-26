#ifndef __DOUBLY__LINKED__LIST__H__
#define __DOUBLY__LINKED__LIST__H__

#include <sstream>

//Node for Doubly Linked List
template <typename T>
class DLLNode {
    public:
        T data; //data
        DLLNode<T> *prev; //address of previous node
        DLLNode<T> *next; //address of next node
};

template <typename T>
class DoublyLinkedList {
    private:
        DLLNode<T> *head; //start of the doubly linked list
        DLLNode<T> *tail; //end of the doubly linked list
        //Create new node
        DLLNode<T> *GetNewNode(T new_data) {
            DLLNode<T> *newNode = new DLLNode<T> ();
            newNode->data = new_data;
            newNode->prev = nullptr;
            newNode->next = nullptr;
            return newNode;
        }
        DLLNode<T> *GetLastNode() {
            DLLNode<T> *currNode = head;
            while(currNode->next != nullptr) {
                currNode = currNode->next;
            }
            return currNode;
        }
    public:
        //New Doubly Linked List should have no data (head = NULL)
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}
        //Delete each node to avoid memory leak
        ~DoublyLinkedList() {
            DLLNode<T> *nodeToDelete = head;
            while(nodeToDelete != nullptr) {
                DLLNode<T> *nextNode = nodeToDelete->next; //store next node
                delete nodeToDelete; //delete current node
                nodeToDelete = nextNode; //proceed to delete next node
            }
        }
        //Insert new data at front
        bool InsertAtHead(T new_data) {
            bool returnStatus = false;
            try{
                DLLNode<T> *newNode = GetNewNode(new_data);
                if(head == nullptr) {
                    head = newNode; //if node is empty, head will be newNode
                    tail = newNode; //if node is empty, tail will also be newNode
                    returnStatus = true;
                }
                else {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                    tail = GetLastNode(); //update tail node
                    returnStatus = true;
                }
            }
            catch(const std::exception &e) {
                std::cout << __FUNCTION__ << ": (" << __LINE__ << ") Caught Exception: " << e.what() << '\n';
            }
            return returnStatus;
        }
        //Insert new data at tail
        bool InsertAtTail(T new_data) {
            bool returnStatus = false;
            try {
                if(head == nullptr) {
                    returnStatus = InsertAtHead(new_data);
                }
                else {
                    DLLNode<T> *newNode = GetNewNode(new_data);
                    tail->next = newNode;
                    newNode->prev = tail;
                    returnStatus = true;
                }
                if(returnStatus == true) {
                    tail = GetLastNode(); //update tail node
                }
            }
            catch(const std::exception &e) {
                std::cout << __FUNCTION__ << ": (" << __LINE__ << ") Caught Exception: " << e.what() << '\n';
            }
            return returnStatus;
        }
        //Delete node containing data
        bool Delete(T dataToDelete, bool returnStatus = false) {
            //if linked list is empty, do nothing
            if(head != nullptr) {
                //if head contains data to be deleted
                if(head->data == dataToDelete) {
                    if(head->next != nullptr) {
                        DLLNode<T> *nodeToDelete = head->next;
                        head->data = head->next->data; //next node will be new head
                        head->next = head->next->next;
                        head->next->prev = head; //change previous node of next node to point to head
                        delete nodeToDelete; //delete next node info at old head
                        returnStatus = true;
                        tail = GetLastNode();
                        Delete(dataToDelete, returnStatus); //Recursive call to delete other nodes
                    }
                    else {
                        delete head;
                        head = nullptr;
                        tail = nullptr;
                        returnStatus = true;
                    }
                }
                else {
                    //head doesn't contain data to be deleted
                    DLLNode<T> *currNode = head;
                    while(currNode->next != nullptr) {
                        if(currNode->next->data == dataToDelete) {
                            //if next node contains data to be deleted
                            DLLNode<T> *nodeToDelete = currNode->next;
                            currNode->next = currNode->next->next; //move the next node
                            if(currNode->next != nullptr) {
                                currNode->next->prev = currNode;
                            }
                            else {
                                tail->prev = currNode; //if its last node, change previous node of tail
                            }
                            delete nodeToDelete; //delete the node containing data
                            returnStatus = true;
                        }
                        else {
                            currNode = currNode->next;
                        }
                    }
                    if(returnStatus == true) {
                        tail = GetLastNode();
                    }
                }
            }
            return returnStatus;
        }
        //Display contents of linked list
		std::string Display() {
			std::stringstream ss("");
			if(head != nullptr) {
				DLLNode<T> *currNode = head;
				while(currNode != nullptr) {
					ss << currNode->data;
					currNode = currNode->next;
					if(currNode != nullptr) {
						ss << " -> ";
					}
				}
			}
			return ss.str();
		}
        //Display contents of linked list
		std::string DisplayReverse() {
			std::stringstream ss("");
			if(tail != nullptr) {
				DLLNode<T> *lastNode = tail;
				while(lastNode != nullptr) {
                    ss << lastNode->data;
                    lastNode = lastNode->prev;
                    if(lastNode != nullptr) {
                        ss << " <- ";
                    }
				}
			}
			return ss.str();
		}
};

#endif