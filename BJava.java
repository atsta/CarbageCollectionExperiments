import java.io.*;
import java.util.*;
import java.util.concurrent.TimeUnit;


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
        int i, j, k, m, count =0, back, front;
        int items = 10000000, data_items = 10;
        Node ptr;

        long startTime = System.nanoTime();

        List l1 = new List();
        for (i = 0;i <= items; i++) {
            int [] newdata = new int[data_items];
            for (j = 0;j < data_items;j++) {
                newdata[j] = i;
            }
            l1.insert(newdata);
        }

        for (m = 0;m < 4;m++) {
                List l2 = new List();
                for (i = 0;i <= items; i++) {
                    int [] newdata = new int[data_items];
                    for (j = 0;j < data_items;j++) {
                        newdata[j] = i;
                    }
                    l2.insert(newdata);
                }
            l2 = null;

            ptr = l1.head;
            count = 0;
            while (ptr != null) {
                count++;
                ptr = ptr.next;
            }
            System.out.println(count);
        }

        long endTime   = System.nanoTime();
        long totalTime = endTime - startTime;
        System.out.println("Duration BJava: " + TimeUnit.NANOSECONDS.toMillis(totalTime) + " microseconds");
    }
}
