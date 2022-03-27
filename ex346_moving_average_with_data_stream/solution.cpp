// Circular Array Strategy
class MovingAverage {
public:
    MovingAverage(int size) : bufferIndex(0), bufferElements(0), currentSum(0), maxWindowSize(size) {
        circularBuffer = new int[maxWindowSize];
        ::memset(circularBuffer, 0, maxWindowSize * sizeof(int));
    }
    
    double next(int val) {
        currentSum += val;
        currentSum -= circularBuffer[bufferIndex];
        circularBuffer[bufferIndex] = val;
        if (bufferIndex + 1 == maxWindowSize) {
            bufferIndex = 0;    
        } else {
            bufferIndex++;
        }
        
        bufferElements = std::min(bufferElements + 1, maxWindowSize);
        return currentSum / static_cast<double>(bufferElements);
    }
    
private:
    int* circularBuffer;
    size_t bufferIndex;
    int bufferElements;
    
    int currentSum;
    const int maxWindowSize;
};

#if 0
// Classic Deque strategy
class MovingAverage {
public:
    MovingAverage(int size) : currentSum(0), maxWindowSize(size) {

    }
    
    double next(int val) {
        currentSum += val;
        window.push_back(val);
        if (window.size() > maxWindowSize) {
            currentSum -= window.front();
            window.pop_front();
        }
        
        return currentSum / static_cast<double>(window.size());
    }
    
private:
    deque<int> window;
    int currentSum;
    const int maxWindowSize;
};
#endif
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
