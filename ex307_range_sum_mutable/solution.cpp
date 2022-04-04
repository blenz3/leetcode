static const int SEGMENT_SIZE = 50;

struct SegmentNode {
public:
    SegmentNode(const vector<int>& numbers, int start, int end)
        : startRange(start)
        , endRange(end) 
        , sum(0)
    {
        int segmentSize = std::min(SEGMENT_SIZE, (int)::sqrt(numbers.size()));
        if (end - start < segmentSize) {
            for (int i = start; i <= end; ++i){ 
                children.push_back(new SegmentNode(numbers[i], i, i));
                sum += numbers[i];
            }
        } else {
            // biforcate the range by half each time until we get to a batch of 10
            int mid = (start + end) / 2;
            auto* lower = new SegmentNode(numbers, start, mid);
            auto* higher = new SegmentNode(numbers, mid + 1, end);
            children = { lower, higher };
            sum = lower->sum + higher->sum;
        }   
    }
    
    SegmentNode(int val, int start, int end)
        : startRange(start)
        , endRange(end)
        , sum(val)
    {

    }
    
    void update(int index, int val) {
        auto* leaf = getLeafNode(index);
        int diff = abs(val - leaf->sum);
        int sign = (val < leaf->sum) ?  -1 : 1;
        diff *= sign;
        
        // diff = (leaf->sum < val) ? val - leaf->sum : leaf->sum - val;
        // printf("DIFF: prev val %d new val %d diff %d\n", leaf->sum, val, diff);
        leaf->sum = val;
        
        propagateChanges(index, diff);
    }
    
    SegmentNode* getLeafNode(int index) {
        if (index == startRange && index == endRange && children.empty()) 
            return this;
        
        for (auto& child : children) {
            if (index >= child->startRange && index <= child->endRange) {
                return child->getLeafNode(index);
            }
        }
        
        return nullptr;
    }
    
    SegmentNode* getNextChild(int index) {
        for (auto& child : children) {
            if (index >= child->startRange && index <= child->endRange) {
                return child;
            }
        }
        return nullptr;
    }
    
    int rangeSum(int start, int end) {
        // Entire range is included
        if (start <= startRange && end >= endRange) {
            return sum;
        }
        
        int total(0);
        for (auto child : children) {
            if (start <= child->startRange && end >= child->endRange) { // The entire range of the child is included
                total += child->sum;
            } else if ((start <= child->startRange) || (end >= child->startRange)) { 
                total += child->rangeSum(start, end);
            }
        }
        // printf("total at [%d, %d] is %d\n", startRange, endRange, total);
        return total;
    }
    
    void printTree(int depth=0) {
        if (children.empty())
            return; 
        
        printf("level %d has sum %d with elements {", depth, sum);
        for (auto* child : children) {
            printf("[%d, %d :: %d], ", child->startRange, child->endRange, child->sum);
        }
        printf("\n");
        
        for (auto* child : children)
            child->printTree(depth + 1);
        
    }

 private:
    void propagateChanges(int index, int diff) {
        // Base case - we've reached the leaf node - no changes to make
        if (children.empty()) {
            return;
        }
        sum += diff;
        
        // Continue to the next level
        auto* child = getNextChild(index);
        if (child == nullptr) {
            return;
        }
        
        
        child->propagateChanges(index, diff);
    }

    int startRange;
    int endRange;
    int sum;
    vector<SegmentNode*> children;
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        segmentTree = new SegmentNode(nums, 0, nums.size() - 1);
        // segmentTree->printTree();
    }

    void update(int index, int val) {
        segmentTree->update(index, val);
    }

    int sumRange(int left, int right) {
        // printf("new start\n\n");
        return segmentTree->rangeSum(left, right);
    }
private:
    SegmentNode* segmentTree;
};

#if 0
// Brute Force
class NumArray {
public:
    NumArray(vector<int>& nums) : numbers(nums) {
        
    }
    
    void update(int index, int val) {
        numbers[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum(0);
        for (int i = left; i <= right; ++i) {
            sum += numbers[i];
        }
        
        return sum;
    }
    
private: 
    vector<int>& numbers;
};
#endif
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
