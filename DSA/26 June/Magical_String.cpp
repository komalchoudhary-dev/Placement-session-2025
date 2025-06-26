class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1; 

        vector<int> s = {1, 2, 2};
        int count = 1;  
        int i = 2;      
        int next = 1;   

        while (s.size() < n) {
            int groupLen = s[i];
            for (int j = 0; j < groupLen; ++j) {
                s.push_back(next);
                if (next == 1 && s.size() <= n)
                    count++;
            }
            next = 3 - next;  
            i++;
        }

        return count;
    }
};
