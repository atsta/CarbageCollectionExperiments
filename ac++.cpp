#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

class Node {
public:
    Node *next;
    int *data;
public:
    Node(Node *next, int *data):  next {next}, data {data} {}
};

class List {
public:
    Node* head;
    int deleted_nodes;
public:
    List(): head {NULL}, deleted_nodes {0} {}
    virtual void insert(int *newdata);
    virtual void deleteNode();
    virtual Node* GetNth(int index);
    virtual void display();
};

void List::insert(int *newdata) {
    Node* newNode = new Node(this->head, newdata);
    this->head = newNode;
}

//delete every list node that its data is not divided by 10000
void List::deleteNode() {
    Node* temp = this->head;
    Node* prev = NULL;

    if (temp != NULL && *((*temp).data + 0) % 10000 !=0) {
        this->head= temp->next;
        delete [] temp->data;
        delete temp;
        this->deleted_nodes++;
        return;
    }

    while (temp != NULL && *((*temp).data + 0)  % 10000 ==0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete [] temp->data;
    delete temp;
    this->deleted_nodes++;
}

//get the nth-element of the linked list,
//and re-arrange its previous element to point to its next.
Node* List::GetNth(int index) {
    Node* current = this->head;
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
    return NULL;
}

void List::display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< *((*ptr).data + 0)  <<" ";
      ptr = ptr->next;
   }
   cout << endl;
}

int main() {
    int i, j, m, count, back, front;
    int items = 11000000;

    List *l1 = new List();
    for (i = 0;i <= items; i++) {
        int *newdata = new int[10];
        for (j = 0;j < 10;j++) {
            newdata[j] = i;
        }
        l1->insert(newdata);
    }

    for (i = 0;i <= items; i++) {
        l1->deleteNode();
    }

    count = items - l1->deleted_nodes;
    i = front = 1;
    back = count - 1;
    Node* tempNode;

    List *l2 = new List();
    //new linked list with the remaining items of the first linked list, in mixed order
    //order is defined like this: item in position i, where i is odd, take the item from the end of List l1
    //item in position i, where i is even, take the item from the beginning of List l1

    while (front < back) {
        if (i % 2 == 1) {
            tempNode = l1->GetNth(back);
            tempNode->next = l2->head;
            l2->head = tempNode;
            back = back - 2;
        } else {
                tempNode = l1->GetNth(front);
                tempNode->next = l2->head;
                l2->head = tempNode;
                front = front + 2;
        }
        i++;
    }
    delete l1;

    //count time taken for operations in the final "sparse" list
    auto start = high_resolution_clock::now();

    Node* ptr;
    for (m = 0;m < 40;m++) {
        ptr = l2->head;
        count = 0;
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
    }
    delete l2;

    cout<< "List contains "<< count << " items"<< endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Operations duration AC++: "<< duration.count() << " milliseconds" << endl;

    return 0;
}