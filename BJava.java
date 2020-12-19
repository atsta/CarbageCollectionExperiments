import java.io.*;
import java.util.*;

class Node {
    Node next;
    int[] data;

    public Node(Node next, int[] data) {
        this.next = next;
        this.data = data;
    }
}

class List {
    Node head = null;

    public List() {}

    void insert(int[] newdata) {
        Node newNode = new Node(this.head, newdata);
        this.head = newNode;
    }
}

public class BJava {
    public static void main(String[] args) {
        int i, j, count, back, front;
        int items = 10000000, data_items = 30;

        //count time taken for operations in the final "alive" list
        long startTime = System.nanoTime();

        List l1 = new List();
        for (i = 0;i <= items; i++) {
            int [] newdata = new int[data_items];
            for (j = 0;j < data_items;j++) {
                newdata[j] = i;
            }
            l1.insert(newdata);
        }
        l1.head = null;

        List l4 = new List();

        for (i = 0;i <= items; i++) {
            int [] newdata = new int[data_items];
            for (j = 0;j < data_items;j++) {
                newdata[j] = i;
            }
            l4.insert(newdata);
        }

        Node ptr;
        ptr = l4.head;
        int sum = 0;
        while (ptr != null) {
            sum = sum + ptr.data[0]/100000;
            ptr = ptr.next;
        }

        ptr = l4.head;
        count = 0;
        while (ptr != null) {
            count++;
            ptr = ptr.next;
        }

        List l2 = new List();
        for (i = 0;i <= items; i++) {
            int [] newdata = new int[data_items];
            for (j = 0;j < data_items;j++) {
                newdata[j] = i;
            }
            l2.insert(newdata);
        }
        l2.head = null;

        ptr = l4.head;
        count = 0;
        while (ptr != null) {
            count++;
            ptr = ptr.next;
        }

        List l3 = new List();
        for (i = 0;i <= items; i++) {
            int [] newdata = new int[data_items];
            for (j = 0;j < data_items;j++) {
                newdata[j] = i;
            }
            l3.insert(newdata);
        }

        l3.head = null;

        ptr = l4.head;
        count = 0;
        while (ptr != null) {
            count++;
            ptr = ptr.next;
        }

        List l5 = new List();
        for (i = 0;i <= items; i++) {
            int [] newdata = new int[data_items];
            for (j = 0;j < data_items;j++) {
                newdata[j] = i;
            }
            l5.insert(newdata);
        }

        l5.head = null;

        ptr = l4.head;
        count = 0;
        while (ptr != null) {
            count++;
            ptr = ptr.next;
        }

        /*for (i = 0;i < 10;i++) {
            List l5 = new List();
            for (i = 0;i <= items; i++) {
                int [] newdata = new int[data_items];
                for (j = 0;j < data_items;j++) {
                    newdata[j] = i;
                }
                l5.insert(newdata);
            }

            l5.head = null;

        } */

        System.out.println(sum);
        System.out.println(count);

        long endTime   = System.nanoTime();
        long totalTime = endTime - startTime;
        System.out.println(totalTime/1000000);
    }
}
