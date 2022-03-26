#ifndef __SINGLY__LINKED__LIST__UT__H__
#define __SINGLY__LINKED__LIST__UT__H__

#include "gtest/gtest.h"
#include "SinglyLinkedList/SinglyLinkedList.h"
#include <string>

/*
 * Singly Linked List Test Cases
 * 1) Print Empty Linked List
 * 2) Delete Empty Linked List
 * 3) Insert At Head, Delete and print empty linked list
 * 4) Insert At Tail, Delete and print empty linked list
 * 5) Insert 3 at head, 4 at tail, delete 3 and print 4 linked list
 */

//Print empty linked list
TEST(SinglyLinkedListIntTest, PrintEmpty) {
	SinglyLinkedList<int> sObj;
	EXPECT_EQ(sObj.Display(), "");
}

//Delete element from empty linked list
TEST(SinglyLinkedListIntTest, DeleteEmpty) {
	SinglyLinkedList<int> sObj;
	EXPECT_EQ(sObj.Delete(2), false);
	EXPECT_EQ(sObj.Display(), "");
}

//Insert data at head and delete
TEST(SinglyLinkedListIntTest, InsertAtHeadDelete) {
	SinglyLinkedList<int> sObj;
	EXPECT_EQ(sObj.InsertAtHead(5), true);
	EXPECT_EQ(sObj.Delete(5), true);
	EXPECT_EQ(sObj.Display(), "");
}

//Insert data at tail and delete
TEST(SinglyLinkedListIntTest, InsertAtTailDelete) {
	SinglyLinkedList<int> sObj;
	EXPECT_EQ(sObj.InsertAtTail(6), true);
	EXPECT_EQ(sObj.Delete(6), true);
	EXPECT_EQ(sObj.Display(), "");
}

//Delete data from head
TEST(SinglyLinkedListIntTest, DeleteDataFromHead) {
	SinglyLinkedList<int> sObj;
	EXPECT_EQ(sObj.InsertAtHead(6), true);
	EXPECT_EQ(sObj.InsertAtTail(5), true);
	EXPECT_EQ(sObj.InsertAtTail(4), true);
	EXPECT_EQ(sObj.Delete(6), true);
	EXPECT_EQ(sObj.Display(), "5 -> 4");
}

//Delete data from tail
TEST(SinglyLinkedListIntTest, DeleteDataFromTail) {
	SinglyLinkedList<int> sObj;
	EXPECT_EQ(sObj.InsertAtHead(6), true);
	EXPECT_EQ(sObj.InsertAtTail(5), true);
	EXPECT_EQ(sObj.InsertAtTail(4), true);
	EXPECT_EQ(sObj.Delete(4), true);
	EXPECT_EQ(sObj.Display(), "6 -> 5");
}

//Insert data at head and tail and delete
TEST(SinglyLinkedListIntTest, InsertAtHeadTailDelete) {
	SinglyLinkedList<int> sObj;
	EXPECT_EQ(sObj.InsertAtHead(1), true);
	EXPECT_EQ(sObj.InsertAtTail(2), true);
	EXPECT_EQ(sObj.InsertAtHead(3), true);
	EXPECT_EQ(sObj.InsertAtTail(4), true);
	EXPECT_EQ(sObj.InsertAtHead(5), true);
	EXPECT_EQ(sObj.InsertAtTail(6), true);
	EXPECT_EQ(sObj.Delete(3), true);
	EXPECT_EQ(sObj.Delete(6), true);
	EXPECT_EQ(sObj.Delete(3), false);
	EXPECT_EQ(sObj.Display(),"5 -> 1 -> 2 -> 4");
}

//Delete data occuring at multiple nodes
TEST(SinglyLinkedListIntTest, DeleteRecurringData) {
	SinglyLinkedList<int> sObj;
	EXPECT_EQ(sObj.InsertAtHead(1), true);
	EXPECT_EQ(sObj.InsertAtTail(2), true);
	EXPECT_EQ(sObj.InsertAtHead(3), true);
	EXPECT_EQ(sObj.InsertAtTail(4), true);
	EXPECT_EQ(sObj.InsertAtHead(5), true);
	EXPECT_EQ(sObj.InsertAtTail(6), true);
	EXPECT_EQ(sObj.InsertAtHead(1), true);
	EXPECT_EQ(sObj.InsertAtTail(2), true);
	EXPECT_EQ(sObj.InsertAtHead(3), true);
	EXPECT_EQ(sObj.InsertAtTail(4), true);
	EXPECT_EQ(sObj.InsertAtHead(5), true);
	EXPECT_EQ(sObj.InsertAtTail(6), true);
	EXPECT_EQ(sObj.Display(),"5 -> 3 -> 1 -> 5 -> 3 -> 1 -> 2 -> 4 -> 6 -> 2 -> 4 -> 6");
	EXPECT_EQ(sObj.Delete(5), true);
	EXPECT_EQ(sObj.Delete(1), true);
	EXPECT_EQ(sObj.Delete(5), false);
	EXPECT_EQ(sObj.Display(),"3 -> 3 -> 2 -> 4 -> 6 -> 2 -> 4 -> 6");
}


//Print empty linked list
TEST(SinglyLinkedListStringTest, PrintEmpty) {
	SinglyLinkedList<std::string> sObj;
	EXPECT_EQ(sObj.Display(), "");
}

//Delete element from empty linked list
TEST(SinglyLinkedListStringTest, DeleteEmpty) {
	SinglyLinkedList<std::string> sObj;
	EXPECT_EQ(sObj.Delete("Hello"), false);
	EXPECT_EQ(sObj.Display(), "");
}

//Insert data at head and delete
TEST(SinglyLinkedListStringTest, InsertAtHeadDelete) {
	SinglyLinkedList<std::string> sObj;
	EXPECT_EQ(sObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(sObj.Display(), "Hello");
	EXPECT_EQ(sObj.Delete("Hello"), true);
	EXPECT_EQ(sObj.Display(), "");
}

//Insert data at tail and delete
TEST(SinglyLinkedListStringTest, InsertAtTailDelete) {
	SinglyLinkedList<std::string> sObj;
	EXPECT_EQ(sObj.InsertAtTail("Hello"), true);
	EXPECT_EQ(sObj.Display(), "Hello");
	EXPECT_EQ(sObj.Delete("Hello"), true);
	EXPECT_EQ(sObj.Display(), "");
}

//Delete data from head
TEST(SinglyLinkedListStringTest, DeleteDataFromHead) {
	SinglyLinkedList<std::string> sObj;
	EXPECT_EQ(sObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(sObj.InsertAtTail("World"), true);
	EXPECT_EQ(sObj.InsertAtTail("Cool"), true);
	EXPECT_EQ(sObj.Display(), "Hello -> World -> Cool");
	EXPECT_EQ(sObj.Delete("Hello"), true);
	EXPECT_EQ(sObj.Display(), "World -> Cool");
}

//Delete data from tail
TEST(SinglyLinkedListStringTest, DeleteDataFromTail) {
	SinglyLinkedList<std::string> sObj;
	EXPECT_EQ(sObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(sObj.InsertAtTail("World"), true);
	EXPECT_EQ(sObj.InsertAtTail("Cool"), true);
	EXPECT_EQ(sObj.Display(), "Hello -> World -> Cool");
	EXPECT_EQ(sObj.Delete("Cool"), true);
	EXPECT_EQ(sObj.Display(), "Hello -> World");
}

//Insert data at head and tail and delete
TEST(SinglyLinkedListStringTest, InsertAtHeadTailDelete) {
	SinglyLinkedList<std::string> sObj;
	EXPECT_EQ(sObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(sObj.InsertAtTail("World"), true);
	EXPECT_EQ(sObj.InsertAtHead("Good"), true);
	EXPECT_EQ(sObj.InsertAtTail("Morning"), true);
	EXPECT_EQ(sObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(sObj.InsertAtTail("World"), true);
	EXPECT_EQ(sObj.Display(), "Hello -> Good -> Hello -> World -> Morning -> World");
	EXPECT_EQ(sObj.Delete("World"), true);
	EXPECT_EQ(sObj.Delete("Morning"), true);
	EXPECT_EQ(sObj.Delete("World"), false);
	EXPECT_EQ(sObj.Display(),"Hello -> Good -> Hello");
}

//Delete data occuring at multiple nodes
TEST(SinglyLinkedListStringTest, DeleteRecurringData) {
	SinglyLinkedList<std::string> sObj;
	EXPECT_EQ(sObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(sObj.InsertAtTail("World"), true);
	EXPECT_EQ(sObj.InsertAtHead("Good"), true);
	EXPECT_EQ(sObj.InsertAtTail("Morning"), true);
	EXPECT_EQ(sObj.InsertAtHead("Rise"), true);
	EXPECT_EQ(sObj.InsertAtTail("Shine"), true);
	EXPECT_EQ(sObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(sObj.InsertAtTail("World"), true);
	EXPECT_EQ(sObj.InsertAtHead("Good"), true);
	EXPECT_EQ(sObj.InsertAtTail("Morning"), true);
	EXPECT_EQ(sObj.InsertAtHead("Rise"), true);
	EXPECT_EQ(sObj.InsertAtTail("Shine"), true);
	EXPECT_EQ(sObj.Display(),"Rise -> Good -> Hello -> Rise -> Good -> Hello -> World -> Morning -> Shine -> World -> Morning -> Shine");
	EXPECT_EQ(sObj.Delete("Rise"), true);
	EXPECT_EQ(sObj.Delete("Good"), true);
	EXPECT_EQ(sObj.Delete("Good"), false);
	EXPECT_EQ(sObj.Display(),"Hello -> Hello -> World -> Morning -> Shine -> World -> Morning -> Shine");
}

#endif
