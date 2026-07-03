class Solution {
private:
    void solve(vector<int>& heap, int key, int k) {
        int n = heap.size();
        heap.push_back(key);
        heapifyUp(heap);
    }

    void heapifyUp(vector<int> &heap) {
        int n = heap.size();
        if (n == 1) return;
        int parent, child;
        child = n - 1;
        while (child > 0) {
            parent = (child - 1)/2;
            if (heap[parent] < heap[child]) {
                int temp = heap[child];
                heap[child] = heap[parent];
                heap[parent] = temp;
                child = parent;
            }
            else break;
        }
    }

    void remove(vector<int>& heap) {
        int n = heap.size();
        if (n == 0) return;
        heap[0] = heap[n - 1];
        heap.pop_back();
        if (heap.size() == 1) return;
        heapifyDown(heap, n - 1);
    }

    void heapifyDown(vector<int>& heap, int n) {
        int parent = 0;
        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int largest = parent;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest == parent) break;

            swap(heap[largest], heap[parent]);
            parent = largest;

        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        if (k > nums.size()) return -1;
        for (int i = 0;i<nums.size();i++) {
            solve(heap, nums[i], k);
        }
        for(int i = 0;i<k - 1;i++) {
            remove(heap);
        }
        return heap[0];
    }
};