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
      int *temp;

      for(i = 0;i < 100;i = i + 10) {
        int newdata[5] = { i, i, i, i, i };
        node_arr[i] = NewNode(newdata);
         temp= (node_arr[i]).data ;
              cout << *(temp + 3) << endl;
      }

      struct Node* head = new Node;
      struct Node *tempNodeA = new Node;
      struct Node *tempNodeB = new Node;
      head = node_arr+10;
      *tempNodeA = node_arr[50];
      *tempNodeB = node_arr[90];
      head->next = tempNodeA;
      tempNodeA->prev = head;
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;

      temp = (*head).data ;
      cout << *(temp + 3)<< endl;

      *tempNodeA = node_arr[10];
      *tempNodeB = node_arr[80];
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;

       temp = (*tempNodeB).data ;
       cout << *(temp + 3) << endl;

      *tempNodeB = node_arr[40];
      tempNodeA->prev = tempNodeB;
      tempNodeB->next = tempNodeA;

      *tempNodeA = node_arr[80];
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;

      delete[] node_arr;

       temp = (*tempNodeB).data ;
      cout << *(temp + 3) << endl;


    return 0;
}