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
    int deleted_nodes = 0;

    void insert(int[] newdata) {
        Node newNode = new Node(this.head, newdata);
        this.head = newNode;
    }

    void deleteNode() {
        Node temp = this.head;
        Node prev = null;

        if (temp != null && temp.data[0] % 10000 != 0) {
            this.head = temp.next;
            this.deleted_nodes++;
            return;
        }
        while (temp != null && temp.data[0] % 10000 == 0) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null)
            return;
        prev.next = temp.next;
        this.deleted_nodes++;
    }

    void display() {
        Node ptr;
        ptr = this.head;
        while (ptr != null) {
            System.out.print(ptr.data[0] + " ");
            ptr = ptr.next;
        }
        System.out.println(" ");
    }

    Node GetNth(int index) {
        Node current = this.head;
        Node nth;
        int count = 0;
        while (current.next != null) {
            if (count == index - 1) {
                nth = current.next;
                current.next = ((current.next).next);
                return nth;
            }
            count++;
            current = current.next;
        }
        return null;
    }
}

public class AJava {
    public static void main(String[] args) {
        int i, j, m, count, back, front;
        int items = 11000000;

        List l1 = new List();
        for (i = 0;i <= items; i++) {
            int [] newdata = new int[10];
            for (j = 0;j < 10;j++) {
                newdata[j] = i;
            }
            l1.insert(newdata);
        }

        for (i = 0;i <= items; i++) {
            l1.deleteNode();
        }

        count = items - l1.deleted_nodes;
        i = front = 1;
        back = count - 1;
        Node tempNode;
        List l2 = new List();

        while (front < back) {
            if (i % 2 == 1) {
                tempNode = l1.GetNth(back);
                tempNode.next = l2.head;
                l2.head = tempNode;
                back = back - 2;
            } else {
                tempNode = l1.GetNth(front);
                tempNode.next = l2.head;
                l2.head = tempNode;
                front = front + 2;
            }
            i++;
        }

        long startTime = System.nanoTime();

        Node ptr;
        for (m = 0;m < 40;m++) {
            ptr = l2.head;
            count = 0;
            while (ptr != null) {
                count++;
                ptr = ptr.next;
            }
        }

        System.out.println("List contains " + count + " items");

        long endTime   = System.nanoTime();
        System.out.println("Operations duration AJava: " + TimeUnit.NANOSECONDS.toMillis(endTime - startTime) + " milliseconds");    }
}