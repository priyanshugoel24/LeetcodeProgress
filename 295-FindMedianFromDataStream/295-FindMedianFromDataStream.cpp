// Last updated: 02/05/2026, 22:45:42
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {        
        
    }
    
    void addNum(int num) {
        
       if(maxHeap.empty() || num < maxHeap.top()){
        maxHeap.push(num);
       }else{
        minHeap.push(num);
       }

        if(maxHeap.size() > minHeap.size() + 1){            
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(maxHeap.size() < minHeap.size()){

            maxHeap.push(minHeap.top());
            minHeap.pop();
            
        }
    }
    
    double findMedian() {
        
        double median = 0.0;

        if(maxHeap.size() == minHeap.size()){
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }else{
            median = maxHeap.top();
        }

        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */