// this file is meant to be loaded via JShell for help with
// debugging AllArray.java - it is NOT compiled through /usr/bin/java

/open AllArray.java
AllArray all = new AllArray(null);
int[] arr = all.createArray(10, 50);
all.bubbleSort(arr);
int x = all.recursiveBinarySearch(arr, arr[3]);
