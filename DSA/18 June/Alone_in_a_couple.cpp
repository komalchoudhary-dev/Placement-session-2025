// User function Template for C++

class Solution {
  public:
    int findSingle(vector<int> &arr) {
        // code here
         int result = 0;
        for (int num : arr) {
            result ^= num;  // XOR all elements
        }
        return result;
    }
};
