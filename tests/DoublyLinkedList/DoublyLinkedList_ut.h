#ifndef __DOUBLY__LINKED__LIST__UT__H__
#define __DOUBLY__LINKED__LIST__UT__H__

#include "gtest/gtest.h"
#include "DoublyLinkedList/DoublyLinkedList.h"
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
TEST(DoublyLinkedListIntTest, PrintEmpty) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.Display(), "");
    EXPECT_EQ(dObj.DisplayReverse(), "");
}

//Delete element from empty linked list
TEST(DoublyLinkedListIntTest, DeleteEmpty) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.Delete(2), false);
	EXPECT_EQ(dObj.Display(), "");
    EXPECT_EQ(dObj.DisplayReverse(), "");
}

//Insert data at head and delete
TEST(DoublyLinkedListIntTest, InsertAtHeadDelete) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.InsertAtHead(5), true);
    EXPECT_EQ(dObj.Display(), "5");
	EXPECT_EQ(dObj.Delete(5), true);
	EXPECT_EQ(dObj.Display(), "");
}

//Insert data at tail and delete
TEST(DoublyLinkedListIntTest, InsertAtTailDelete) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.InsertAtTail(6), true);
    EXPECT_EQ(dObj.Display(), "6");
	EXPECT_EQ(dObj.Delete(6), true);
	EXPECT_EQ(dObj.Display(), "");
}

//Delete data from head
TEST(DoublyLinkedListIntTest, DeleteDataFromHead) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.InsertAtHead(6), true);
	EXPECT_EQ(dObj.InsertAtTail(5), true);
	EXPECT_EQ(dObj.InsertAtTail(4), true);
	EXPECT_EQ(dObj.Delete(6), true);
	EXPECT_EQ(dObj.Display(), "5 -> 4");
    EXPECT_EQ(dObj.DisplayReverse(), "4 <- 5");
}

//Delete data from tail
TEST(DoublyLinkedListIntTest, DeleteDataFromTail) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.InsertAtHead(6), true);
	EXPECT_EQ(dObj.InsertAtTail(5), true);
	EXPECT_EQ(dObj.InsertAtTail(4), true);
	EXPECT_EQ(dObj.Delete(4), true);
	EXPECT_EQ(dObj.Display(), "6 -> 5");
    EXPECT_EQ(dObj.DisplayReverse(), "5 <- 6");
}

//Insert data at head and tail and delete
TEST(DoublyLinkedListIntTest, InsertAtHeadTailDelete) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.InsertAtHead(1), true);
	EXPECT_EQ(dObj.InsertAtTail(2), true);
	EXPECT_EQ(dObj.InsertAtHead(3), true);
	EXPECT_EQ(dObj.InsertAtTail(4), true);
	EXPECT_EQ(dObj.InsertAtHead(5), true);
	EXPECT_EQ(dObj.InsertAtTail(6), true);
	EXPECT_EQ(dObj.Delete(3), true);
	EXPECT_EQ(dObj.Delete(6), true);
	EXPECT_EQ(dObj.Delete(3), false);
	EXPECT_EQ(dObj.Display(),"5 -> 1 -> 2 -> 4");
    EXPECT_EQ(dObj.DisplayReverse(),"4 <- 2 <- 1 <- 5");
}

//Delete data occuring at multiple nodes
TEST(DoublyLinkedListIntTest, DeleteRecurringData) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.InsertAtHead(1), true);
	EXPECT_EQ(dObj.InsertAtTail(2), true);
	EXPECT_EQ(dObj.InsertAtHead(3), true);
	EXPECT_EQ(dObj.InsertAtTail(4), true);
	EXPECT_EQ(dObj.InsertAtHead(5), true);
	EXPECT_EQ(dObj.InsertAtTail(6), true);
	EXPECT_EQ(dObj.InsertAtHead(1), true);
	EXPECT_EQ(dObj.InsertAtTail(2), true);
	EXPECT_EQ(dObj.InsertAtHead(3), true);
	EXPECT_EQ(dObj.InsertAtTail(4), true);
	EXPECT_EQ(dObj.InsertAtHead(5), true);
	EXPECT_EQ(dObj.InsertAtTail(6), true);
	EXPECT_EQ(dObj.Display(),"5 -> 3 -> 1 -> 5 -> 3 -> 1 -> 2 -> 4 -> 6 -> 2 -> 4 -> 6");
    EXPECT_EQ(dObj.DisplayReverse(),"6 <- 4 <- 2 <- 6 <- 4 <- 2 <- 1 <- 3 <- 5 <- 1 <- 3 <- 5");
	EXPECT_EQ(dObj.Delete(5), true);
	EXPECT_EQ(dObj.Delete(1), true);
	EXPECT_EQ(dObj.Delete(5), false);
	EXPECT_EQ(dObj.Display(), "3 -> 3 -> 2 -> 4 -> 6 -> 2 -> 4 -> 6");
    EXPECT_EQ(dObj.DisplayReverse(), "6 <- 4 <- 2 <- 6 <- 4 <- 2 <- 3 <- 3");
}

//Delete consecutive data occuring at multiple nodes
TEST(DoublyLinkedListIntTest, DeleteConsecutiveData) {
	DoublyLinkedList<int> dObj;
	EXPECT_EQ(dObj.InsertAtHead(1), true);
    EXPECT_EQ(dObj.InsertAtHead(2), true);
    EXPECT_EQ(dObj.InsertAtHead(3), true);
    EXPECT_EQ(dObj.InsertAtHead(3), true);
    EXPECT_EQ(dObj.InsertAtHead(4), true);
    EXPECT_EQ(dObj.Display(), "4 -> 3 -> 3 -> 2 -> 1");
    EXPECT_EQ(dObj.DisplayReverse(), "1 <- 2 <- 3 <- 3 <- 4");
    EXPECT_EQ(dObj.Delete(3), true);
    EXPECT_EQ(dObj.Display(), "4 -> 2 -> 1");
    EXPECT_EQ(dObj.DisplayReverse(), "1 <- 2 <- 4");    
}

//Print empty linked list
TEST(DoublyLinkedListStringTest, PrintEmpty) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.Display(), "");
    EXPECT_EQ(dObj.DisplayReverse(), "");
}

//Delete element from empty linked list
TEST(DoublyLinkedListStringTest, DeleteEmpty) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.Delete("Hello"), false);
	EXPECT_EQ(dObj.Display(), "");
    EXPECT_EQ(dObj.DisplayReverse(), "");
}

//Insert data at head and delete
TEST(DoublyLinkedListStringTest, InsertAtHeadDelete) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(dObj.Display(), "Hello");
	EXPECT_EQ(dObj.Delete("Hello"), true);
	EXPECT_EQ(dObj.Display(), "");
    EXPECT_EQ(dObj.DisplayReverse(), "");
}

//Insert data at tail and delete
TEST(DoublyLinkedListStringTest, InsertAtTailDelete) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.InsertAtTail("Hello"), true);
	EXPECT_EQ(dObj.Display(), "Hello");
	EXPECT_EQ(dObj.Delete("Hello"), true);
	EXPECT_EQ(dObj.Display(), "");
    EXPECT_EQ(dObj.DisplayReverse(), "");
}

//Delete data from head
TEST(DoublyLinkedListStringTest, DeleteDataFromHead) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(dObj.InsertAtTail("World"), true);
	EXPECT_EQ(dObj.InsertAtTail("Cool"), true);
	EXPECT_EQ(dObj.Display(), "Hello -> World -> Cool");
    EXPECT_EQ(dObj.DisplayReverse(), "Cool <- World <- Hello");
	EXPECT_EQ(dObj.Delete("Hello"), true);
	EXPECT_EQ(dObj.Display(), "World -> Cool");
    EXPECT_EQ(dObj.DisplayReverse(), "Cool <- World");
}

//Delete data from tail
TEST(DoublyLinkedListStringTest, DeleteDataFromTail) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(dObj.InsertAtTail("World"), true);
	EXPECT_EQ(dObj.InsertAtTail("Cool"), true);
	EXPECT_EQ(dObj.Display(), "Hello -> World -> Cool");
    EXPECT_EQ(dObj.DisplayReverse(), "Cool <- World <- Hello");
	EXPECT_EQ(dObj.Delete("Cool"), true);
	EXPECT_EQ(dObj.Display(), "Hello -> World");
    EXPECT_EQ(dObj.DisplayReverse(), "World <- Hello");
}

//Insert data at head and tail and delete
TEST(DoublyLinkedListStringTest, InsertAtHeadTailDelete) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(dObj.InsertAtTail("World"), true);
	EXPECT_EQ(dObj.InsertAtHead("Good"), true);
	EXPECT_EQ(dObj.InsertAtTail("Morning"), true);
	EXPECT_EQ(dObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(dObj.InsertAtTail("World"), true);
	EXPECT_EQ(dObj.Display(), "Hello -> Good -> Hello -> World -> Morning -> World");
    EXPECT_EQ(dObj.DisplayReverse(), "World <- Morning <- World <- Hello <- Good <- Hello");
	EXPECT_EQ(dObj.Delete("World"), true);
	EXPECT_EQ(dObj.Delete("Morning"), true);
	EXPECT_EQ(dObj.Delete("World"), false);
	EXPECT_EQ(dObj.Display(),"Hello -> Good -> Hello");
    EXPECT_EQ(dObj.DisplayReverse(), "Hello <- Good <- Hello");
}

//Delete data occuring at multiple nodes
TEST(DoublyLinkedListStringTest, DeleteRecurringData) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(dObj.InsertAtTail("World"), true);
	EXPECT_EQ(dObj.InsertAtHead("Good"), true);
	EXPECT_EQ(dObj.InsertAtTail("Morning"), true);
	EXPECT_EQ(dObj.InsertAtHead("Rise"), true);
	EXPECT_EQ(dObj.InsertAtTail("Shine"), true);
	EXPECT_EQ(dObj.InsertAtHead("Hello"), true);
	EXPECT_EQ(dObj.InsertAtTail("World"), true);
	EXPECT_EQ(dObj.InsertAtHead("Good"), true);
	EXPECT_EQ(dObj.InsertAtTail("Morning"), true);
	EXPECT_EQ(dObj.InsertAtHead("Rise"), true);
	EXPECT_EQ(dObj.InsertAtTail("Shine"), true);
	EXPECT_EQ(dObj.Display(),"Rise -> Good -> Hello -> Rise -> Good -> Hello -> World -> Morning -> Shine -> World -> Morning -> Shine");
    EXPECT_EQ(dObj.DisplayReverse(),"Shine <- Morning <- World <- Shine <- Morning <- World <- Hello <- Good <- Rise <- Hello <- Good <- Rise");
	EXPECT_EQ(dObj.Delete("Rise"), true);
	EXPECT_EQ(dObj.Delete("Good"), true);
	EXPECT_EQ(dObj.Delete("Good"), false);
	EXPECT_EQ(dObj.Display(),"Hello -> Hello -> World -> Morning -> Shine -> World -> Morning -> Shine");
    EXPECT_EQ(dObj.DisplayReverse(),"Shine <- Morning <- World <- Shine <- Morning <- World <- Hello <- Hello");
}

//Delete consecutive data occuring at multiple nodes
TEST(DoublyLinkedListStringTest, DeleteConsecutiveData) {
	DoublyLinkedList<std::string> dObj;
	EXPECT_EQ(dObj.InsertAtHead("Hello"), true);
    EXPECT_EQ(dObj.InsertAtTail("Good"), true);
    EXPECT_EQ(dObj.InsertAtTail("Morning"), true);
    EXPECT_EQ(dObj.InsertAtTail("Morning"), true);
    EXPECT_EQ(dObj.InsertAtTail("World"), true);
    EXPECT_EQ(dObj.Display(), "Hello -> Good -> Morning -> Morning -> World");
    EXPECT_EQ(dObj.DisplayReverse(), "World <- Morning <- Morning <- Good <- Hello");
    EXPECT_EQ(dObj.Delete("Morning"), true);
    EXPECT_EQ(dObj.Display(), "Hello -> Good -> World");
    EXPECT_EQ(dObj.DisplayReverse(), "World <- Good <- Hello"); 
}
#endif