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
public:
    List(): head {NULL} {}
    virtual void insert(int *newdata);
};

void List::insert(int *newdata) {
    Node* newNode = new Node(this->head, newdata);
    this->head = newNode;
}

int main() {
    int i, j, count, back, front;
    int items = 10000000, data_items = 150;

    List *l1 = new List();
    for (i = 0;i <= items; i++) {
        int *newdata = new int[data_items];
        for (j = 0;j < 150;j++) {
            newdata[j] = i;
        }
        l1->insert(newdata);
    }
    cout<< *((l1->head)->data + 0)  <<" " << endl;
    delete l1;

    List *l2 = new List();
    for (i = 0;i <= items; i++) {
        int *newdata = new int[data_items];
        for (j = 0;j < 150;j++) {
            newdata[j] = i;
        }
        l2->insert(newdata);
    }
    cout<< *((l2->head)->data + 0)  <<" " << endl;
    delete l2;

    List *l3 = new List();
    for (i = 0;i <= items; i++) {
        int *newdata = new int[data_items];
        for (j = 0;j < 150;j++) {
            newdata[j] = i;
        }
        l3->insert(newdata);
    }
    cout<< *((l3->head)->data + 0)  <<" " << endl;
    delete l3;

    List *l4 = new List();
    for (i = 0;i <= items; i++) {
        int *newdata = new int[data_items];
        for (j = 0;j < 150;j++) {
            newdata[j] = i;
        }
        l4->insert(newdata);
    }
    cout<< *((l4->head)->data + 0)  <<" " << endl;

    auto start = high_resolution_clock::now();

    /*display(head2);

    struct Node* ptr;
    ptr = head2;
    int sum = 0;
    while (ptr != NULL) {
        sum = sum + ptr->data[0];
        ptr = ptr->next;
    }

    ptr = head2;
    count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    cout<< "Sum of list's data first items: "<< sum << endl;
    cout<< "How many items list contains: "<< count << endl;
*/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration AC++: "<< duration.count() << " microseconds" << endl;
    return 0;
}