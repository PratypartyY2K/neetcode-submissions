#include <climits>
#include <iostream>
using namespace std;

void swap(int *x, int *y);

class MaxHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:
    MaxHeap(int capacity);

    void MaxHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return (2 * i + 1); }
    int right(int i)  { return (2 * i + 2); }

    int extractMax();
    void increaseKey(int i, int new_val);
    int getMax() { return harr[0]; }
    void deleteKey(int i);
    void insertKey(int k);
};

MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Bubble up if parent is smaller than child
    while (i != 0 && harr[parent(i)] < harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::increaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] < harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MaxHeapify(0);

    return root;
}

void MaxHeap::deleteKey(int i)
{
    // Force element to root by setting to infinity, then extract
    increaseKey(i, INT_MAX);
    extractMax();
}

void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heap_size && harr[l] > harr[i])
        largest = l;
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&harr[i], &harr[largest]);
        MaxHeapify(largest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    MaxHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    cout << "Extracted Max: " << h.extractMax() << endl; // Prints 45
    cout << "Current Max: "   << h.getMax() << endl;       // Prints 15

    h.increaseKey(2, 50);
    cout << "New Max after increase: " << h.getMax() << endl; // Prints 50

    return 0;
}


// A recursive method to max-heapify a subtree with the root at given index i
void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    // Compare root with left child
    if (l < heap_size && harr[l] > harr[i])
        largest = l;

    // Compare largest so far with right child
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        swap(&harr[i], &harr[largest]);
        MaxHeapify(largest);
    }
}
