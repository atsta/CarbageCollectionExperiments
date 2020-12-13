#include<iostream>
using namespace std;

struct Node {
    struct Node *prev;
    int *data;
    struct Node *next;
};

Node NewNode(int newdata[10]) {
    struct Node* newNode = new Node;
    newNode->data = newdata;
    newNode->prev = NULL;
    newNode->next = NULL;
    return *newNode;
}

int main() {
      int i;
      Node *node_arr = new Node[100];
      int newdata[5] = { 1, 2, 3, 4, 5 };

      int *temp;

      for(i = 0;i < 100;i++) {
        node_arr[i] = NewNode(newdata);
      }

      struct Node* head = new Node;
      struct Node* tempNodeA = new Node;
      struct Node* tempNodeB = new Node;
      head = node_arr+0;
      tempNodeA = node_arr + 50;
      head->next = tempNodeA;
      tempNodeA->prev = head;

      tempNodeB = node_arr + 90;
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;

      tempNodeA = node_arr + 60;
      tempNodeA->prev = tempNodeB;
      tempNodeB->next = tempNodeA;

      tempNodeB = node_arr + 10;
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;

      tempNodeA = node_arr + 80;
      tempNodeA->prev = tempNodeB;
      tempNodeB->next = tempNodeA;

      tempNodeB = node_arr + 40;
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;

      tempNodeA = node_arr + 70;
      tempNodeA->prev = tempNodeB;
      tempNodeB->next = tempNodeA;

      tempNodeB = node_arr + 30;
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;

      tempNodeA = node_arr + 20;
      tempNodeA->prev = tempNodeB;
      tempNodeB->next = tempNodeA;

      delete[] node_arr;

      /*for(i = 0;i < 100;i = i + 1) {
          cout << "in"<< endl;

         if (i%10 != 0) {
            cout << "in"<< endl;

            delete *node_arr[i];
            cout << "out"<< endl;

         }
       }*/

     tempNodeA = head;
              temp = (*head).data ;
              cout << *(temp + 3)<< endl;
     while(tempNodeA != NULL) {
        temp = (*tempNodeA).data ;
         cout << *(temp + 3)<< endl;
        tempNodeA = tempNodeA->next;
     }



    return 0;
}