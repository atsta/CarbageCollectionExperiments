#include<iostream>
#include<chrono>
using namespace std;

using namespace std::chrono;

struct Node {
    struct Node *prev;
    int *data;
    struct Node *next;
};

struct Node* head = NULL;
struct Node* head2 = NULL;

void insert(int newdata[150]) {
    struct Node* newNode = new Node;
    newNode->data = newdata;
    newNode->next = head;
    head = newNode;
}

int deleted_nodes = 0;

//delete every list node that its data is not divided by 1000
void deleteNode() {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && *((*temp).data + 0) % 1000 !=0) {
        head= temp->next;
        delete [] temp->data;
        delete temp;
        deleted_nodes++;
        return;
    }

    while (temp != NULL && *((*temp).data + 0)  % 1000 ==0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete [] temp->data;
    delete temp;
    deleted_nodes++;
}

//get the nth-element of the linked list,
//and re-arrange its previous element to point to its next.
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
    return NULL;
}

void display(struct Node* head) {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< *((*ptr).data + 0)  <<" ";
      ptr = ptr->next;
   }
   cout << endl;
}

int main() {
    int i, j, count, back, front;
    int items = 100000;

    for (i = 0;i <= items; i++) {
        int *newdata = new int[150];
        for (j = 0;j < 150;j++) {
             newdata[j] = i;
        }
        insert(newdata);
    }

    for (i = 0;i <= items; i++) {
        deleteNode();
    }

    count = items - deleted_nodes;
    i = front = 1;
    back = count - 1;
    struct Node* tempNode;

    //new linked list *head2, with the remaining items of the first linked list, in mixed order
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

    //count time taken for operations in the final "sparse" list
    auto start = high_resolution_clock::now();

    display(head2);

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

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration AC++: "<< duration.count() << " microseconds" << endl;
    return 0;
}