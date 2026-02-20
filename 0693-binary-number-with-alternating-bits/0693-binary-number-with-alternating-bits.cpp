class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        string b = "";

        while(n > 0){
            if(n % 2 == 0) b += '0';
            else b += '1';

            n /= 2;
        }

        reverse(b.begin(), b.end());

        int i = 1;

        while(i < b.size() && b[i - 1] != b[i]) i++;

        

        return  i == b.size() ? true : false;
    }
};