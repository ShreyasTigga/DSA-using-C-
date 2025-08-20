#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    int visited;
    Node(int data) : data(data), next(NULL), visited(0) {}
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

    void alterTheCourse(int data, int val) {
        Node *newNode = new Node(data);
        if (!head) { head = newNode; return; }
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;

        if (val != -1) {
            Node *target = head;
            while (target && target->data != val) target = target->next;
            if (target) newNode->next = target; 
        }
    }
    
    void print(int limit = 20) { 
        Node *temp = head;
        int count = 0;
        while (temp && count < limit) {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }

    void checkCycle() { 
        Node *temp = head;
        int count1 = 0;
        int count2 = 0;
        
        cout << endl;
        
        while (temp && temp->visited <= 1) {
            cout << temp->data << " ";
            if(temp->visited == 0) {
                count1++;
            }
            temp->visited++;
            count2++;
            temp = temp->next;
        }
        
        if(count2 != count1 && temp) {
            int count = count2 - count1 - 1;
            cout << endl << "There is a cycle at Node : " << count << ", with value : " << temp->data << endl;
        } 
        
        else {
            cout << endl << "There is no cycle" << endl;
        }
        
        temp = head;
        
        while (temp && temp->visited > 0) {
            temp->visited = 0;
            temp = temp->next;
        }
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
    list.alterTheCourse(8,4);
    
    cout << "List (limited print to avoid infinite loop): ";
    list.print();
    
    list.checkCycle();

    return 0;
}
