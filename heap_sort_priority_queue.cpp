#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

class PriorityQueue {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < heap.size() && heap[l] > heap[maxIndex])
            maxIndex = l;

        if (r < heap.size() && heap[r] > heap[maxIndex])
            maxIndex = r;

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        siftUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            throw runtime_error("Priority Queue is empty");
        }
        
        int result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            siftDown(0);
        }
        
        return result;
    }

    int getMax() {
        if (heap.empty()) {
            throw runtime_error("Priority Queue is empty");
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    void printHeap() {
        cout << "[ ";
        for (int i : heap) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    cout << "--- Heap Sort Example ---" << endl;
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array:   ";
    for (int i : arr) cout << i << " ";
    cout << endl << endl;

    cout << "--- Priority Queue Example (Max Heap) ---" << endl;
    PriorityQueue pq;
    vector<int> tasks = {3, 10, 5, 1};
    
    cout << "Inserting priorities: ";
    for(int t : tasks) cout << t << " ";
    cout << endl;

    for (int t : tasks) {
        pq.insert(t);
    }

    cout << "Current Heap: ";
    pq.printHeap();

    cout << "Extracting Max: " << pq.extractMax() << endl;
    cout << "Heap after extraction: ";
    pq.printHeap();

    cout << "Extracting Max: " << pq.extractMax() << endl;
    cout << "Heap after extraction: ";
    pq.printHeap();

    return 0;
}



