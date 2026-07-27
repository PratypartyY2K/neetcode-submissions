class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHp;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) {
            minHp.push(num);
            if (minHp.size() > k) {
                minHp.pop();
            }
        }
    }
    
    int add(int val) {
        minHp.push(val);
        if (minHp.size() > k) {
            minHp.pop();
        }
        return minHp.top();
    }
};
