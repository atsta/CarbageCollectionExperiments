import java.io.*;
import java.util.*;

class Node {
    private Node next;
    private int[] data;

    public Node(Node next, int[] data) {
        this.next = next;
        this.data = data;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public int[] getData() {
        return data;
    }

    public void setData(int[] data) {
        this.data = data;
    }
}

class List {
    private Node head = null;
    private int deleted_nodes = 0;

    public List() {
    }

    public Node getHead() {
        return head;
    }

    public void setHead(Node head) {
        this.head = head;
    }

    public int getDeleted_nodes() {
        return deleted_nodes;
    }

    void insert(int[] newdata) {
        Node newNode = new Node(this.head, newdata);
        this.head = newNode;
    }

    void deleteNode() {
        Node temp = this.head;
        Node prev = null;

        if (temp != null && temp.getData()[0] % 1000 != 0) {
            this.head = temp.getNext();
            this.deleted_nodes++;
            return;
        }
        while (temp != null && temp.getData()[0] % 1000 == 0) {
            prev = temp;
            temp = temp.getNext();
        }
        if (temp == null)
            return;
        prev.setNext(temp.getNext());
        this.deleted_nodes++;
    }

    void display() {
        Node ptr;
        ptr = this.head;
        while (ptr != null) {
            System.out.print(ptr.getData()[0] + " ");
            ptr = ptr.getNext();
        }
        System.out.println(" ");
    }

    Node GetNth(int index) {
        Node current = this.head;
        Node nth;
        int count = 0;
        while (current.getNext() != null) {
            if (count == index - 1) {
                nth = current.getNext();
                current.setNext((current.getNext()).getNext());
                return nth;
            }
            count++;
            current = current.getNext();
        }
        return null;
    }

}

public class AJava {
    public static void main(String[] args) {
        int i, j, count, back, front;
        int items = 1000000;

        List l1 = new List();
        for (i = 0;i <= items; i++) {
            int [] newdata = new int[150];
            for (j = 0;j < 150;j++) {
                newdata[j] = i;
            }
            l1.insert(newdata);
        }

        for (i = 0;i <= items; i++) {
            l1.deleteNode();
        }

        System.out.println(l1.getDeleted_nodes());

        count = items - l1.getDeleted_nodes();
        i = front = 1;
        back = count - 1;
        Node tempNode;
        List l2 = new List();

        while (front < back) {
            if (i % 2 == 1) {
                tempNode = l1.GetNth(back);
                tempNode.setNext(l2.getHead());
                l2.setHead(tempNode);
                back = back - 2;
            } else {
                tempNode = l1.GetNth(front);
                tempNode.setNext(l2.getHead());
                l2.setHead(tempNode);
                front = front + 2;
            }
            i++;
        }

        l2.display();

        Node ptr;
        ptr = l2.getHead();
        int sum = 0;
        while (ptr != null) {
            sum = sum + ptr.getData()[0];
            ptr = ptr.getNext();
        }

        ptr = l2.getHead();
        count = 0;
        while (ptr != null) {
            count++;
            ptr = ptr.getNext();
        }

        System.out.println(sum);
        System.out.println(count);

    }
}