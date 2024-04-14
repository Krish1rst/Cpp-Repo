
using namespace std;

tuple<int, int, int> maxSubarraySum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return make_tuple(0, -1, -1);
    
    int maxSum = nums[0];
    int currentSum = nums[0];
    int start = 0;
    int end = 0;
    int tempStart = 0;
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] > currentSum + nums[i]) {
            currentSum = nums[i];
            tempStart = i;
        } else {
            currentSum += nums[i];
        }
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }
    
    return make_tuple(maxSum, start, end);
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = maxSubarraySum(nums);
    cout << "Maximum sum subarray: " << get<0>(result) << endl;
    cout << "Start index: " << get<1>(result) << endl;
    cout << "End index: " << get<2>(result) << endl;
    return 0;
}
