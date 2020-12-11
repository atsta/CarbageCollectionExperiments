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
      int newdata[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      for(i = 0;i < 100;i = i + 10) {
        node_arr[i] = NewNode(newdata);
        int *temp = node_arr[i].data ;
      }

      struct Node* tempNodeA = new Node;
      struct Node* tempNodeB = new Node;
      *tempNodeA = node_arr[0];
      *tempNodeB = node_arr[50];
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;

      *tempNodeA = node_arr[50];
      *tempNodeB = node_arr[90];
      tempNodeA->next = tempNodeB;
      tempNodeB->prev = tempNodeA;


      delete[] node_arr;

      int *temp = (*tempNodeA->next).data ;
      cout << *(temp + 5);


    return 0;
}