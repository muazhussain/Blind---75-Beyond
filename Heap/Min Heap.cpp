// Problem link: https://www.naukri.com/code360/problems/min-heap_4691801

#include <bits/stdc++.h>
using namespace std;

int parent(int i) {
    return i / 2;
}

int leftChild(int i) {
    return i * 2;
}

int rightChild(int i) {
    return i * 2 + 1;
}

void heapifyUp(vector<int>& heap, int i) {
    while(i > 1 && heap[parent(i)] > heap[i]) {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void insert(vector<int>& heap, int e) {
    heap.push_back(e);
    heapifyUp(heap, heap.size() - 1); 
}

void heapifyDown(vector<int>& heap, int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;

    if(left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if(right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(heap, smallest);
    }
}

int remove(vector<int>& heap, int i) {
    if(heap.size() == 1) {
        return -1;
    }
    int el = heap[1];
    swap(heap[1], heap.back());
    heap.pop_back();
    heapifyDown(heap, 1);
    return el;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> res;
    vector<int> heap;
    heap.push_back(-1);
    for(int i = 0; i < q.size(); i++) {
        if(q[i][0] == 0) {
            insert(heap, q[i][1]);
        } else {
            res.push_back(remove(heap, 1));
        }
    }
    return res;
}
