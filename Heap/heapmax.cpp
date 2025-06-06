#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;  //数组存储堆元素，从0开始索引

   
    void heapifyUp(int index) {
       while(index > 0 && heap[index] > heap[(index - 1) / 2]) {
          swap(heap[index], heap[(index - 1) / 2]);
          index = (index - 1) / 2;
       }
    }   //插入时，新元素在末尾，然后向上调整堆结构，直到满足最大堆的性质    


    void heapifyDown(int index) {
        int leftchild = index * 2 + 1;
        int rightchild = index * 2 + 2;
        int maxindex = index;
        if(leftchild < heap.size() && heap[leftchild] > heap[maxindex]) {
            maxindex = leftchild;
        }
        if(rightchild < heap.size() && heap[rightchild] > heap[maxindex]) {
            maxindex = rightchild;
        }
        if(maxindex != index) {
            swap(heap[index], heap[maxindex]);
            heapifyDown(maxindex);
        }
    }  //删除时，将末尾元素移动到根节点，然后向下调整堆结构，直到满足最小堆的性质  

public:
    MaxHeap() {}

    void buildHeap(const vector<int>& arr) {    
        heap = arr;
        for(int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void insert(int value) {
       heap.push_back(value);
       heapifyUp(heap.size() - 1);
    }

    int extractMax() {
       int maxnum = heap[0];
       heap[0] = heap.back();
       heap.pop_back();
       heapifyDown(0);
       return maxnum;
    }  //移除并返回堆顶元素（最大值），将堆的最后一个元素移动到堆顶，然后通过heapifyDown操作维护堆的性质。

    int getMax() const {
        return heap[0];
    }

    bool isEmpty() const {
       return heap.empty();
    }

    void printHeap() const {
        for(int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
    }
};

int main() {
    MaxHeap maxHeap;
    vector<int> num = {3,1,6,5,2,4};

    maxHeap.buildHeap(num);

    cout << "Max heap elements: ";
    maxHeap.printHeap();

    cout << "Maxnum element: " << maxHeap.getMax() << endl;
    cout << "Extracted maxnum element: " << maxHeap.extractMax() << endl;

    cout << "Max heap elements after extraction: ";
    maxHeap.printHeap();

    return 0;
}