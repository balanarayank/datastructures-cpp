#ifndef __SINGLY__LINKED__LIST__H__
#define __SINGLY__LINKED__LIST__H__

#include <sstream>

template <typename T>
class SLLNode {
	public:
		T data;
		SLLNode<T> *next;
};

template <typename T>
class SinglyLinkedList {
	private:
		SLLNode<T> *head;
		SLLNode<T> *GetNewNode(T new_data) {
			SLLNode<T> *newNode = new SLLNode<T> ();
			newNode->data = new_data;
			newNode->next = nullptr;
			return newNode;
		}
	public:
		SinglyLinkedList() : head(nullptr) {}
		~SinglyLinkedList() {
			SLLNode<T> *nodeToDelete = head;
			while(nodeToDelete != nullptr) {
				SLLNode<T> *nextNode = nodeToDelete->next;
				delete nodeToDelete;
				nodeToDelete = nextNode;
			}
		}
		bool InsertAtHead(T new_data) {
			bool returnStatus = false;
			try {
				SLLNode<T> *newNode = GetNewNode(new_data);
				newNode->next = head;
				head = newNode;
				returnStatus = true;
			}
			catch(const std::exception &e) {
				std::cout << __FUNCTION__ << ": (" << __LINE__ << ") Caught Exception: " << e.what() << '\n';
			}
			return returnStatus;
		}
		bool InsertAtTail(T new_data) {
			bool returnStatus = false;
			try {
				if(head == nullptr) {
					returnStatus = InsertAtHead(new_data);
				}
				else {
					SLLNode<T> *newNode = GetNewNode(new_data);
					SLLNode<T> *nodeRef = *(&head);
					while(nodeRef->next != nullptr) {
						nodeRef = nodeRef->next;
					}
					nodeRef->next = newNode;
					returnStatus = true;
				}
			}
			catch(const std::exception &e) {
				std::cout << __FUNCTION__ << ": (" << __LINE__ << ") Caught Exception: " << e.what() << '\n';
			}
			return returnStatus;
		}
		bool Delete(T dataToDelete, bool returnStatus = false) {
			if(head != nullptr) {
				if(head->data == dataToDelete) {
					if(head->next != nullptr) {
						SLLNode<T> *nodeToDelete = head->next;
						head->data = head->next->data;
						head->next = head->next->next;
						delete nodeToDelete;
						returnStatus = true;
						Delete(dataToDelete, returnStatus);
					}
					else {
						delete head;
						head = nullptr;
						returnStatus = true;
					}
				}
				else {
					SLLNode<T> *currNode = head;
					while(currNode->next != nullptr) {
						if(currNode->next->data == dataToDelete) {
							SLLNode<T> *nodeToDelete = currNode->next;
							currNode->next = currNode->next->next;
							delete nodeToDelete;
							returnStatus = true;
						}
						else {
							currNode = currNode->next;
						}
					}
				}
			}
			return returnStatus;
		}
		std::string Display() {
			std::stringstream ss("");
			if(head != nullptr) {
				SLLNode<T> *currNode = head;
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
};

#endif