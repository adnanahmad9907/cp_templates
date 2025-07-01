#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;
    void heapify_down(int i)
    {
        int n = heap.size();
        while (true)
        {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;
            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != i)
            {
                swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else
                break;
        }
    }
    void heapify_up(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heap[parent] > heap[i])
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
    }

public:
    MinHeap(const vector<int> &arr)
    {
        heap = arr;
        build_heap();
    }
    void build_heap()
    {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; --i)
        {
            heapify_down(i);
        }
    }
    void add_element(int val)
    {
        heap.push_back(val);
        heapify_up(heap.size() - 1);
    }
    void update_value(int index, int new_val)
    {
        if (index < 0 || index >= heap.size())
            return;
        int old_val = heap[index];
        heap[index] = new_val;
        if (new_val < old_val)
        {
            heapify_up(index);
        }
        else
        {
            heapify_down(index);
        }
    }
    void print_heap()
    {
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    int top()
    {
        return heap.empty() ? -1 : heap[0];
    }
    void pop()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }
};
