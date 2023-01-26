/*
    Ernest Izdebski
    2023-01-24

    A class with several methods useful for Arrays.
*/

import java.util.Random;
import java.util.Arrays;

public class AllArray {
    public Random rand;
    // constructor to init random
    AllArray(Random rand) {
        this.rand = (rand == null) ? new Random() : rand;
    }

    // creates and returns an array with the given size
    // and with numbers in the given range
    public int[] createArray(int size, int range) {
        Random rand = new Random();
        int[] resp = new int[size];
        for (int i = 0; i < size; ++i) {
            resp[i] = rand.nextInt(range);
        }
        return resp;
    }

    // uses system libraries to display an array
    public static void displayArray(int[] arr) {
        System.out.println(Arrays.toString(arr));
    }

    // method that sequentially searches for an item in an array and
    // returns the first matching index
    public static int sequentialSearch(int[] arr, int query) {
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] == query) return i;
        }
        return -1;
    }
    
    // method that (inefficiently) sorts an array
    public static void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr.length; ++j) {
                if (arr[i] < arr[j]) {
                    // swap the two elements
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // method that performs binary search on a (sorted) array
    // returns index of item if found, else -1
    public static int recursiveBinarySearch(int[] arr, int query, int start, int end) {
        if (end < start) return -1;
        int i = (start + end) / 2;
        int mid = arr[i];
        if (query == mid) return i;
        if (query < mid) return AllArray.recursiveBinarySearch(arr, query, start, --i);
        if (query > mid) return AllArray.recursiveBinarySearch(arr, query, ++i, end);
        return -1; // all cases should have been handled by this point,
                   // but the compiler is not aware
    }
    
    // recursiveBinarySearch overload for not manually entering a start, end value
    public static int recursiveBinarySearch(int[] arr, int query) {
        return recursiveBinarySearch(arr, query, 0, arr.length);
    }

    // there was no description in the assignment for how the class should
    // behave if executed as a program, so I have omitted the main function
}
