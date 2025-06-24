#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtIndex(int index, int val) {
        if (index == 0) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Index out of bounds\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtIndex(int index) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (index == 0) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp; ++i)
            temp = temp->next;

        if (!temp || !temp->next) {
            cout << "Index out of bounds\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void deleteByValue(int val) {
        if (!head) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            cout << "Value not found\n";
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
