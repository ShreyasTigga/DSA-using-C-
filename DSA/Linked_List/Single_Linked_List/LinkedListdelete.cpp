#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};

class LinkedList {
    Node *head;

public:
    LinkedList() : head(NULL) {}

    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data) {
        Node *newNode = new Node(data);
        if (!head) { head = newNode; return; }
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    
    void deleteFirstOccurence(int value) {
        if (!head) return;

        if (head->data == value) {
            cout << "\nDeleting head node with value = " << head->data << endl;
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            cout << "\nDeleting node with value = " << current->next->data << endl;
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        } else {
            cout << "\nNo node with value " << value << " found in Linked List" << endl;
        }
    }
    
    void findNodeNumber(int value) {
        Node *current = head;
        int count = 1;  
        
        while (current) {
            if (value == current->data) {
                cout << "\nNode " << count << " has value = " << current->data << endl;
                return;
            }
            current = current->next;
            count++;
        }
        
        cout << "\nNo node with value " << value << " found in Linked List" << endl; 
    }

    void print() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);

    cout << "Initial List: ";
    list.print();

    list.deleteFirstOccurence(5);
    list.print();

    list.deleteFirstOccurence(2);
    list.print(); 

    list.deleteFirstOccurence(2); 
    list.print();

    list.findNodeNumber(7);
    list.findNodeNumber(2);

    return 0;
}
