import java.io.*;
import java.util.*;

public class AJava {
    public static void main(String[] args) {
        int[][] arr1 = new int[100][20];
        int[][] arr2 = new int[100][20];
        int[][] arr3 = new int[100][20];
        int[][] arr4 = new int[100][20];
        int[][] arr5 = new int[100][20];

        for (int i = 0;i < 100;i = i + 2) {
            for (int j = 0;j < 20; j = j + 3) {
                arr1[i][j] = 1;
                arr2[i][j] = 2;
                arr3[i][j] = 3;
                arr4[i][j] = 4;
                arr5[i][j] = 5;
            }
        }

        for (int i = 0;i < 100;i = i + 2) {
            for (int j = 0;j < 20; j = j + 3) {
                arr1[i][j] += arr2[i][j];
                arr2[i][j] += arr3[i][j];
                arr3[i][j] += arr4[i][j];
                arr4[i][j] += arr5[i][j];
                arr5[i][j] += arr1[i][j];
                System.out.println(arr1[i][j], arr2[i][j], arr3[i][j], arr4[i][j], arr5[i][j]);
            }
        }
    }
}