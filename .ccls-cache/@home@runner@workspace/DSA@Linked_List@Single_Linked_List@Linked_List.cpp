#include <iostream>
#include <cmath>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    Node *head;

  public:
    Linkedlist() {
        head = NULL;
    }

    void insertAtHead(int data) {

        Node *newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = this->head;
        this->head = newNode;
    }

    void insertAtTail(int data) {

        Node *newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node *current = head;

        while(current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }

    void deleteAtHead() {

        Node *node = head->next;

        head = node;
    }

    void deleteAtTail() {

        Node *current = head;
        Node *previous = current;

        while(current->next != NULL) {
            previous = current;
            current = current->next;
        }

        previous->next = NULL;
    }

    int countNode() {

        Node *current = head;
        int count = 0;

        while(current != NULL) {
            count = count + 1;
            current = current->next;
        }

        return(count);
    }

    int* getArray(int max) {

        int* arr = new int[max];
        int i = 0;

        Node *current = head;

        while(current != NULL) {
            arr[i] = current->data;
            current = current->next;
            i = i + 1;
        }

        return arr;
    }

    void display() {
        Node *temp = head;

        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {

    Linkedlist list;
    int count = 0;
    int j = 0;

    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtTail(4);
    list.insertAtTail(3);
    list.insertAtTail(2);
    list.insertAtTail(1);

    cout << "Elements of the list are: ";

    list.display();
    cout << endl;

    list.deleteAtHead();
    list.display();
    cout << endl;

    list.deleteAtHead();
    list.display();
    cout << endl;

    list.deleteAtTail();
    list.display();
    cout << endl;

    list.deleteAtTail();
    list.display();
    cout << endl;

    count = list.countNode();
    cout << count;
    cout << endl;

    count = list.countNode();
    int* arr = list.getArray(count);

    cout << endl;

    for(int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}