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
        Node *slow = head;
        Node *fast = head;
        Node *third = head;
        
        bool flag = false;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                flag = true;
                break;
            }
        }
        
        int count = 1;
        
        if(flag == true) {
            
            cout << "There is a Cycle\n";
            while(third != slow) {
                third = third->next;
                slow = slow->next;
                count++;
            }
            
            cout << "The loop starts at Node " << count << " with value : " << third->data << endl;
        }
        
        else {
            cout << "There is no Cycle\n";
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
    list.alterTheCourse(8, 4); 

    cout << "List (limited print to avoid infinite loop): ";
    list.print(); 

    list.checkCycle();

    return 0;
}