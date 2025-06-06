#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;  //数组存储堆元素，从0开始索引

    /**
     * @brief 上浮堆操作
     *
     * 将堆中指定索引的元素上浮到正确的位置，以保持堆的性质。
     *
     * @param index 需要上浮的元素的索引
     */
    void heapifyUp(int index) {
        while (index != 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }   //插入时，新元素在末尾，然后向上调整堆结构，直到满足最小堆的性质    


    void heapifyDown(int index) {
        int size = heap.size();
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }  //删除时，将末尾元素移动到根节点，然后向下调整堆结构，直到满足最小堆的性质  

public:
    MinHeap() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        int root = heap[0];
        heap[0] = heap.back();   //将最后一个元素移动到堆顶
        heap.pop_back();
        heapifyDown(0);
        return root;
    }  //移除并返回堆顶元素（最小值），将堆的最后一个元素移动到堆顶，然后通过heapifyDown操作维护堆的性质。

    int getMin() const {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void printHeap() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;
    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(6);
    minHeap.insert(5);
    minHeap.insert(2);
    minHeap.insert(4);

    cout << "Min heap elements: ";
    minHeap.printHeap();

    cout << "Minimum element: " << minHeap.getMin() << endl;
    cout << "Extracted minimum element: " << minHeap.extractMin() << endl;

    cout << "Min heap elements after extraction: ";
    minHeap.printHeap();

    return 0;
}