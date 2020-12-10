#include<iostream>
using namespace std;

struct Node {
    struct Node *prev;
    int[] *data;
    struct Node *next;
}

Node* newNode(int[] *val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->prev = temp->next = nullptr;
   return temp;
}

//link node with node neighbor
void insert(Node** neighbor, int node_data) {
   Node* temp = newNode(node_data);
   temp->next = *neighbor;
   (*neighbor)->prev = temp;
   (*neighbor) = temp;
}


int main() {

    return 0;
}