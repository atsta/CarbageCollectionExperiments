#include<iostream>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

Node NewNode(int newdata) {
    struct Node* newNode = new Node;
    newNode->data = newdata;
    newNode->prev = NULL;
    newNode->next = NULL;
    return *newNode;
}

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
/*Node* GetNth(struct Node* head, int n) {
    if(head == NULL)
      return NULL;
    int count = 0;

    if (count == n)
        return head;

    return GetNth(head->next, n - 1);
} */

int GetNth(Node* head, int index) {

    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
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
    int i, newdata, count, j, k;

    for (i = 0;i <= 100000; i++) {
        newdata = i;
        insert(newdata);
    }

    for (i = 0;i <= 100000; i++) {
        deleteNode();
    }
    display(head);

    count = 100000 - deleted_nodes;
    i = k = 1;
    j = count - 1;
    struct Node* tempNode;

            tempNode = GetNth(head, 0);
            //cout<< tempNode->data <<" ";
            tempNode->next = head2;
            head2 = tempNode;
            cout<< head2->data <<" ";

                tempNode = GetNth(head->next->next, 10) ;
                tempNode->next = head2;
                head2 = tempNode;
                cout<< head2->data <<" ";

    /*while (i < count/2) {
    if (i % 2 == 1) {
        tempNode = GetNth(head, j);
        //cout<< tempNode->data <<" ";
        tempNode->next = head2;
        head2 = tempNode;
        //cout<< head2->data <<" ";
        j= j-2;
    } else {
            tempNode = GetNth(head, k);
            //cout<< tempNode->data <<" ";
            tempNode->next = head2;
            head2 = tempNode;
            //cout<< head2->data <<" ";
            k = k+2;
    }
    i++;
    } */

        //display(head2);

    return 0;
}