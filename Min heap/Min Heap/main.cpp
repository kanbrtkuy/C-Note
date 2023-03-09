

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Heap{
public:
    vector<int> arr;
    int count;

    void swap(vector<int>& arr, int idx, int parent) {
        int temp = arr[idx];
        arr[idx] = arr[parent];
        arr[parent] = temp;
    }

    void push(int val) {
        arr.push_back(val);
        count += 1;
        int idx = count;
        int parent = idx / 2;
        while(idx != 1) {

            if(arr[idx] < arr[parent]) {
                //swap(arr, idx, parent);
                int temp = arr[idx];
                arr[idx] = arr[parent];
                arr[parent] = temp;
            } else {
                return;
            }
            idx = parent;
            parent = idx / 2;

        }

    }

    void pop() {
        int level = int(log(count)/log(2));
        int levelmax = pow(2, level);
        int last = 0;
        int parent = 1;
        int left = parent * 2;
        int right = parent * 2 + 1;

        while(true) {
            if(levelmax <= last) {
                arr[parent] = arr[count];
                break;
            } else if(left <= count && (right > count || arr[left] <= arr[right])) {
                arr[parent] = arr[left];
                parent = left;
                left = parent * 2;
                right = parent * 2 + 1;
                last = left;
            } else {
                arr[parent] = arr[right];
                parent = right;
                left = parent * 2;
                right = parent * 2 + 1;
                last = right;
            }
        }
        count -= 1;
    }

    int top() {
        return arr[1];
    }



    Heap() :count(0) {
        arr.push_back(0);
    };
    virtual ~Heap() {

    }
};

int main() {
    Heap heap;
    int n = 0;

    for(int i = 0; i < 10; i++) {
        n = rand() % 100;
        heap.push(n);
        //cout << n << endl;
    }
//
//    for(int hp : heap.arr) {
//        cout << hp << endl;
//    }

    for(int i = 0; i < 10; i++) {
        cout << heap.top() << endl;
        heap.pop();
    }

    return 0;
}

