class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        int reversed = 0;

        while (n != 0) {
            int num = n % 10;
            reversed = reversed * 10 + num;
            n /= 10;
        }
        return reversed;
    }
};
