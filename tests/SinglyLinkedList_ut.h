#ifndef __SINGLY_LINKED_LIST_UT_H__
#define __SINGLY_LINKED_LIST_UT_H__

#include "gtest/gtest.h"
#include "SinglyLinkedList.h"

TEST(SinglyLinkedListIntTest, EmptyLinkedList) {
    LinkedList<int> *sllIntObj = new SinglyLinkedList<int>;
    ASSERT_EQ(sllIntObj->GetFirstNode(), nullptr);
    ASSERT_EQ(sllIntObj->GetLastNode(), nullptr);
    ASSERT_EQ(sllIntObj->GetSize(), 0);
    ASSERT_EQ(sllIntObj->DeleteData(2), false);
    ASSERT_EQ(sllIntObj->Display(), "SinglyLinkedList is empty");
    ASSERT_EQ(sllIntObj->DisplayReverse(), "Not supported for SinglyLinkedList");
    delete sllIntObj;
}

TEST(SinglyLinkedListIntTest, InsertAtHeadAndDeleteData) {
    LinkedList<int> *sllIntObj = new SinglyLinkedList<int>;
    sllIntObj->InsertAtHead(1);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 1);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 1);
    ASSERT_EQ(sllIntObj->GetSize(), 1);
    ASSERT_EQ(sllIntObj->Display(), "1 -> ");
    
    ASSERT_EQ(sllIntObj->DeleteData(2), false);
    ASSERT_EQ(sllIntObj->DeleteData(1), true);
    ASSERT_EQ(sllIntObj->GetFirstNode(), nullptr);
    ASSERT_EQ(sllIntObj->GetLastNode(), nullptr);
    ASSERT_EQ(sllIntObj->GetSize(), 0);
    ASSERT_EQ(sllIntObj->Display(), "SinglyLinkedList is empty");
    delete sllIntObj;
}

TEST(SinglyLinkedListIntTest, InsertAtTailAndDeleteData) {
    LinkedList<int> *sllIntObj = new SinglyLinkedList<int>;
    sllIntObj->InsertAtTail(10);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 10);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 10);
    ASSERT_EQ(sllIntObj->GetSize(), 1);
    ASSERT_EQ(sllIntObj->Display(), "10 -> ");
    
    ASSERT_EQ(sllIntObj->DeleteData(20), false);
    ASSERT_EQ(sllIntObj->DeleteData(10), true);
    ASSERT_EQ(sllIntObj->GetFirstNode(), nullptr);
    ASSERT_EQ(sllIntObj->GetLastNode(), nullptr);
    ASSERT_EQ(sllIntObj->GetSize(), 0);
    ASSERT_EQ(sllIntObj->Display(), "SinglyLinkedList is empty");
    delete sllIntObj;
}

class SinglyLinkedListIntTestF : public ::testing::Test
{
  protected:
    LinkedList<int> *sllIntObj;

    virtual void SetUp() {
        sllIntObj = new SinglyLinkedList<int>;
        sllIntObj->InsertAtHead(1);
        sllIntObj->InsertAtHead(2);
        sllIntObj->InsertAtHead(3);
        sllIntObj->InsertAtTail(4);
        sllIntObj->InsertAtTail(5);
        sllIntObj->InsertAtHead(6);
        sllIntObj->InsertAtTail(7);
        sllIntObj->InsertAtHead(8);
    }

    virtual void TearDown() {
        delete sllIntObj;
    }
};

TEST_F(SinglyLinkedListIntTestF, InsertDataAndPrint) {
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 8);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 7);
    ASSERT_EQ(sllIntObj->GetSize(), 8);
    ASSERT_EQ(sllIntObj->Display(), "8 -> 6 -> 3 -> 2 -> 1 -> 4 -> 5 -> 7 -> ");
}

TEST_F(SinglyLinkedListIntTestF, DeleteDataAtHead) {
    ASSERT_EQ(sllIntObj->DeleteData(8), true);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 6);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 7);
    ASSERT_EQ(sllIntObj->GetSize(), 7);
    ASSERT_EQ(sllIntObj->Display(), "6 -> 3 -> 2 -> 1 -> 4 -> 5 -> 7 -> ");
}

TEST_F(SinglyLinkedListIntTestF, DeleteNodeAtHead) {
    ASSERT_EQ(sllIntObj->DeleteNode(sllIntObj->GetFirstNode()), true);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 6);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 7);
    ASSERT_EQ(sllIntObj->GetSize(), 7);
    ASSERT_EQ(sllIntObj->Display(), "6 -> 3 -> 2 -> 1 -> 4 -> 5 -> 7 -> ");
}

TEST_F(SinglyLinkedListIntTestF, DeleteDataAtTail) {
    ASSERT_EQ(sllIntObj->DeleteData(7), true);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 8);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 5);
    ASSERT_EQ(sllIntObj->GetSize(), 7);
    ASSERT_EQ(sllIntObj->Display(), "8 -> 6 -> 3 -> 2 -> 1 -> 4 -> 5 -> ");
}

TEST_F(SinglyLinkedListIntTestF, DeleteNodeAtTail) {
    ASSERT_EQ(sllIntObj->DeleteNode(sllIntObj->GetLastNode()), true);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 8);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 5);
    ASSERT_EQ(sllIntObj->GetSize(), 7);
    ASSERT_EQ(sllIntObj->Display(), "8 -> 6 -> 3 -> 2 -> 1 -> 4 -> 5 -> ");
}

TEST_F(SinglyLinkedListIntTestF, DeleteDataInside) {
    ASSERT_EQ(sllIntObj->DeleteData(4), true);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 8);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 7);
    ASSERT_EQ(sllIntObj->GetSize(), 7);
    ASSERT_EQ(sllIntObj->Display(), "8 -> 6 -> 3 -> 2 -> 1 -> 5 -> 7 -> ");
}

TEST_F(SinglyLinkedListIntTestF, DeleteNodeInside) {
    Node<int> *llNode = sllIntObj->GetFirstNode();
    ASSERT_EQ(sllIntObj->DeleteNode(llNode->next->next->next->next->next), true);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 8);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 7);
    ASSERT_EQ(sllIntObj->GetSize(), 7);
    ASSERT_EQ(sllIntObj->Display(), "8 -> 6 -> 3 -> 2 -> 1 -> 5 -> 7 -> ");
}

TEST_F(SinglyLinkedListIntTestF, DeleteMultipleData) {
    ASSERT_EQ(sllIntObj->DeleteData(4), true);
    ASSERT_EQ(sllIntObj->DeleteData(8), true);
    ASSERT_EQ(sllIntObj->DeleteData(6), true);
    ASSERT_EQ(sllIntObj->DeleteData(7), true);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 3);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 5);
    ASSERT_EQ(sllIntObj->GetSize(), 4);
    ASSERT_EQ(sllIntObj->Display(), "3 -> 2 -> 1 -> 5 -> ");
}

TEST_F(SinglyLinkedListIntTestF, DeleteMultipleNodes) {
    Node<int> *llNode = sllIntObj->GetFirstNode();
    ASSERT_EQ(sllIntObj->DeleteNode(llNode->next->next->next->next->next), true);
    ASSERT_EQ(sllIntObj->DeleteNode(llNode), true);
    llNode = sllIntObj->GetFirstNode();
    ASSERT_EQ(sllIntObj->DeleteNode(llNode), true);
    llNode = sllIntObj->GetLastNode();
    ASSERT_EQ(sllIntObj->DeleteNode(llNode), true);
    ASSERT_EQ(sllIntObj->GetFirstNode()->data, 3);
    ASSERT_EQ(sllIntObj->GetLastNode()->data, 5);
    ASSERT_EQ(sllIntObj->GetSize(), 4);
    ASSERT_EQ(sllIntObj->Display(), "3 -> 2 -> 1 -> 5 -> ");
}

TEST(SinglyLinkedListStringTest, EmptyLinkedList) {
    LinkedList<std::string> *sllStrObj = new SinglyLinkedList<std::string>;
    ASSERT_EQ(sllStrObj->GetFirstNode(), nullptr);
    ASSERT_EQ(sllStrObj->GetLastNode(), nullptr);
    ASSERT_EQ(sllStrObj->GetSize(), 0);
    ASSERT_EQ(sllStrObj->DeleteData("Hello"), false);
    ASSERT_EQ(sllStrObj->Display(), "SinglyLinkedList is empty");
    ASSERT_EQ(sllStrObj->DisplayReverse(), "Not supported for SinglyLinkedList");
    delete sllStrObj;
}

TEST(SinglyLinkedListStringTest, InsertAtHeadAndDeleteData) {
    LinkedList<std::string> *sllStrObj = new SinglyLinkedList<std::string>;
    sllStrObj->InsertAtHead("Hello");
    ASSERT_EQ(sllStrObj->GetFirstNode()->data, "Hello");
    ASSERT_EQ(sllStrObj->GetLastNode()->data, "Hello");
    ASSERT_EQ(sllStrObj->GetSize(), 1);
    ASSERT_EQ(sllStrObj->Display(), "Hello -> ");
    
    ASSERT_EQ(sllStrObj->DeleteData("World"), false);
    ASSERT_EQ(sllStrObj->DeleteData("Hello"), true);
    ASSERT_EQ(sllStrObj->GetFirstNode(), nullptr);
    ASSERT_EQ(sllStrObj->GetLastNode(), nullptr);
    ASSERT_EQ(sllStrObj->GetSize(), 0);
    ASSERT_EQ(sllStrObj->Display(), "SinglyLinkedList is empty");
    delete sllStrObj;
}

TEST(SinglyLinkedListStringTest, InsertAtTailAndDeleteData) {
    LinkedList<std::string> *sllStrObj = new SinglyLinkedList<std::string>;
    sllStrObj->InsertAtTail("World");
    ASSERT_EQ(sllStrObj->GetFirstNode()->data, "World");
    ASSERT_EQ(sllStrObj->GetLastNode()->data, "World");
    ASSERT_EQ(sllStrObj->GetSize(), 1);
    ASSERT_EQ(sllStrObj->Display(), "World -> ");
    
    ASSERT_EQ(sllStrObj->DeleteData("Hello"), false);
    ASSERT_EQ(sllStrObj->DeleteData("World"), true);
    ASSERT_EQ(sllStrObj->GetFirstNode(), nullptr);
    ASSERT_EQ(sllStrObj->GetLastNode(), nullptr);
    ASSERT_EQ(sllStrObj->GetSize(), 0);
    ASSERT_EQ(sllStrObj->Display(), "SinglyLinkedList is empty");
    delete sllStrObj;
}

class SinglyLinkedListStringTestF : public ::testing::Test
{
  protected:
    LinkedList<std::string> *sllStrObj;

    virtual void SetUp() {
        sllStrObj = new SinglyLinkedList<std::string>;
        sllStrObj->InsertAtHead("Hello");
        sllStrObj->InsertAtHead("World");
        sllStrObj->InsertAtHead("Good");
        sllStrObj->InsertAtTail("Morning");
        sllStrObj->InsertAtTail("Test");
        sllStrObj->InsertAtHead("This");
        sllStrObj->InsertAtTail("Great");
        sllStrObj->InsertAtHead("Day");
    }

    virtual void TearDown() {
        delete sllStrObj;
    }
};

TEST_F(SinglyLinkedListStringTestF, InsertDataAndPrint) {
    ASSERT_EQ(sllStrObj->GetFirstNode()->data, "Day");
    ASSERT_EQ(sllStrObj->GetLastNode()->data, "Great");
    ASSERT_EQ(sllStrObj->GetSize(), 8);
    ASSERT_EQ(sllStrObj->Display(), "Day -> This -> Good -> World -> Hello -> Morning -> Test -> Great -> ");
}

TEST_F(SinglyLinkedListStringTestF, DeleteDataAtHead) {
    ASSERT_EQ(sllStrObj->DeleteData("Day"), true);
    ASSERT_EQ(sllStrObj->GetFirstNode()->data, "This");
    ASSERT_EQ(sllStrObj->GetLastNode()->data, "Great");
    ASSERT_EQ(sllStrObj->GetSize(), 7);
    ASSERT_EQ(sllStrObj->Display(), "This -> Good -> World -> Hello -> Morning -> Test -> Great -> ");
}

TEST_F(SinglyLinkedListStringTestF, DeleteDataAtTail) {
    ASSERT_EQ(sllStrObj->DeleteData("Great"), true);
    ASSERT_EQ(sllStrObj->GetFirstNode()->data, "Day");
    ASSERT_EQ(sllStrObj->GetLastNode()->data, "Test");
    ASSERT_EQ(sllStrObj->GetSize(), 7);
    ASSERT_EQ(sllStrObj->Display(), "Day -> This -> Good -> World -> Hello -> Morning -> Test -> ");
}

TEST_F(SinglyLinkedListStringTestF, DeleteDataInside) {
    ASSERT_EQ(sllStrObj->DeleteData("Morning"), true);
    ASSERT_EQ(sllStrObj->GetFirstNode()->data, "Day");
    ASSERT_EQ(sllStrObj->GetLastNode()->data, "Great");
    ASSERT_EQ(sllStrObj->GetSize(), 7);
    ASSERT_EQ(sllStrObj->Display(), "Day -> This -> Good -> World -> Hello -> Test -> Great -> ");
}

TEST_F(SinglyLinkedListStringTestF, DeleteMultipleData) {
    ASSERT_EQ(sllStrObj->DeleteData("Good"), true);
    ASSERT_EQ(sllStrObj->DeleteData("Hello"), true);
    ASSERT_EQ(sllStrObj->DeleteData("Day"), true);
    ASSERT_EQ(sllStrObj->DeleteData("This"), true);
    ASSERT_EQ(sllStrObj->DeleteData("Great"), true);
    ASSERT_EQ(sllStrObj->GetFirstNode()->data, "World");
    ASSERT_EQ(sllStrObj->GetLastNode()->data, "Test");
    ASSERT_EQ(sllStrObj->GetSize(), 3);
    ASSERT_EQ(sllStrObj->Display(), "World -> Morning -> Test -> ");
}

#endif