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
    int i, j, m, count = 0, back, front;
    int items = 10000000, data_items = 10;
    Node* ptr;

    auto start = high_resolution_clock::now();

    List *l1 = new List();
    for (i = 0;i <= items; i++) {
        int *newdata = new int[data_items];
        for (j = 0;j < data_items;j++) {
            newdata[j] = i;
        }
        l1->insert(newdata);
    }

    for (m = 0;m < 4; m++) {
        List *l2 = new List();
        for (i = 0;i <= items; i++) {
            int *newdata = new int[data_items];
            for (j = 0;j < data_items;j++) {
                newdata[j] = i;
            }
            l2->insert(newdata);
        }
        delete l2;

        ptr = l1->head;
        count = 0;
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        cout<< "List contains "<< count << " items"<< endl;
    }
    delete l1;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Duration BC++: "<< duration.count() << " milliseconds" << endl;

    return 0;
}