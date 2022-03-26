#ifndef __SINGLY__LINKED__LIST__H__
#define __SINGLY__LINKED__LIST__H__

#include <sstream>

//Node for Singly Linked List
template <typename T>
class SLLNode {
	public:
		T data; //data
		SLLNode<T> *next; //address of next node
};

template <typename T>
class SinglyLinkedList {
	private:
		SLLNode<T> *head; //start of the Singly Linked List
		//Create new node
		SLLNode<T> *GetNewNode(T new_data) {
			SLLNode<T> *newNode = new SLLNode<T> ();
			newNode->data = new_data;
			newNode->next = nullptr;
			return newNode;
		}
	public:
		//New Singly Linked List should have no data (head = NULL)
		SinglyLinkedList() : head(nullptr) {}
		//Delete each node to avoid memory leaks
		~SinglyLinkedList() {
			SLLNode<T> *nodeToDelete = head;
			while(nodeToDelete != nullptr) {
				SLLNode<T> *nextNode = nodeToDelete->next; //store next node
				delete nodeToDelete; //delete current node
				nodeToDelete = nextNode; //proceed to delete next node
			}
		}
		//Insert new data to head
		bool InsertAtHead(T new_data) {
			bool returnStatus = false;
			try {
				SLLNode<T> *newNode = GetNewNode(new_data); //get new node
				newNode->next = head; //new node should point to existing head
				head = newNode; //modify head
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
				//if linked list is empty, insert data at head
				if(head == nullptr) {
					returnStatus = InsertAtHead(new_data);
				}
				else {
					SLLNode<T> *newNode = GetNewNode(new_data); //get new node
					SLLNode<T> *nodeRef = *(&head);
					while(nodeRef->next != nullptr) { //iterate towards the last node
						nodeRef = nodeRef->next;
					}
					nodeRef->next = newNode; //new node will now be the last node
					returnStatus = true;
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
						SLLNode<T> *nodeToDelete = head->next;
						head->data = head->next->data; //next node will be new head
						head->next = head->next->next;
						delete nodeToDelete; //delete next node info at old head
						returnStatus = true;
						Delete(dataToDelete, returnStatus); //Recursive call to delete other nodes
					}
					else {
						//if head is the only node, simply delete it
						delete head;
						head = nullptr;
						returnStatus = true;
					}
				}
				else {
					//head doesn't contain data to be deleted
					SLLNode<T> *currNode = head;
					while(currNode->next != nullptr) {
						if(currNode->next->data == dataToDelete) {
							//if next node contains data to be deleted
							SLLNode<T> *nodeToDelete = currNode->next;
							currNode->next = currNode->next->next; //move the next node
							delete nodeToDelete; //delete the node containing data
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
		//Display contents of linked list
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