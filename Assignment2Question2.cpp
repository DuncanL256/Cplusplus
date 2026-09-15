#include <iostream>
#include <vector> 
#include <stack>        // needed to do the non recursive one
using namespace std;

//______Recursive section_____________

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];  //Choose last element as pivot

    int i = low -1; //keeps track of where to plane next small element

    for(int j=low; j<high; j++){ //go through elements low to high
        if(arr[j] <= pivot){
            i++;    // move boundary of the smaller elements
            swap(arr[i], arr[j]);   //swap to put small element on the left
        }
    }

    swap(arr[i+1], arr[high]); // places the pivot in its correct position
    return i+1; // return the position where the pivot ended up
}

//Recursive quicksort function
void quicksortRecursive(vector<int>& arr, int low, int high){
    if(low<high){
        int pivotIndex = partition(arr,low,high);
        quicksortRecursive(arr, low, pivotIndex-1);
        quicksortRecursive(arr, pivotIndex+1, high);
    }
}


//_______Non Recursive Section_____________
void quicksortIterative(vector<int>& arr, int low, int high){
    stack<pair<int, int>> stack;    // we push work onto this stack instead of recursive calls
    stack.push({low, high});    //pushing initial range onto stack
    while(!stack.empty()){  //Keep going until stack is empty
        pair<int, int> range = stack.top();
        stack.pop();

        int currentLow = range.first;
        int currentHigh = range.second;

        if(currentLow < currentHigh){
            int pivotIndex = partition(arr, currentLow, currentHigh); //Istead of recursive calls we push into two sub ranges
            stack.push({currentLow, pivotIndex -1});    //left subarray
            stack.push({pivotIndex+1, currentHigh});    //right subarray
        }
    }
}

// Helper function
void printArray(const vector<int>& arr){
    for (int num:arr){
        cout << num << "";
    }
    cout << endl;
}

// Main Function
int main() {
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};    //Create first test array
    vector<int> arr2 = arr1;    //A second array for the second test

    cout << "Original array: " << endl;
    printArray(arr1);
    cout << endl;

    cout << "===Recursive Quicksort===" << endl;
    quicksortRecursive(arr1, 0, arr1.size() -1);
    cout << "Sorted array (Recursive): " << endl;
    printArray(arr1);
    cout << endl;

    cout << "===Iterative Quicksort===" << endl;
    quicksortIterative(arr2, 0, arr2.size() -1);
    cout << "Sorted array (Iterative): " << endl; 
    printArray(arr2);
    cout << endl;

    cout << "Both methods produce the same result: " << (arr1 == arr2 ? "YES" : "NO") << endl;
    return 0;
}  