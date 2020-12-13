#include<iostream>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node* head = NULL;
struct Node* head2 = NULL;

void insert(int newdata) {
    struct Node* newNode = new Node;
    newNode->data = newdata;
    newNode->next = head;
    head = newNode;
}

int deleted_nodes = 0;

void deleteNode() {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data % 1000 !=0) {
        head= temp->next;
        delete temp;
        deleted_nodes++;
        return;
    }

    while (temp != NULL && temp->data % 1000 ==0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete temp;
    deleted_nodes++;
}

Node* GetNth(Node* head, int index) {
    Node* current = head;
    Node* nth;
    int count = 0;
    while (current->next != NULL) {
        if (count == index - 1) {
            nth = current->next;
            current->next = current->next->next;
            return nth;
        }
        count++;
        current = current->next;
    }
}

void display(struct Node* head) {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

int main() {
    int i, newdata, count, back, front;

    for (i = 0;i <= 100000; i++) {
        newdata = i;
        insert(newdata);
    }

    for (i = 0;i <= 100000; i++) {
        deleteNode();
    }

    count = 100000 - deleted_nodes;
    i = front = 1;
    back = count - 1;
    struct Node* tempNode;

    while (front < back) {
        if (i % 2 == 1) {
            tempNode = GetNth(head, back);
            tempNode->next = head2;
            head2 = tempNode;
            back = back - 2;
        } else {
                tempNode = GetNth(head, front);
                tempNode->next = head2;
                head2 = tempNode;
                front = front + 2;
        }
        i++;
    }

    display(head2);

    return 0;
}