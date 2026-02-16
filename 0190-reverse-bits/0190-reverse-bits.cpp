class Solution {
public:
    int reverseBits(int n) {

        string str = "";
        
        while(n > 0){
            str += (n % 2 == 0) ? '0' : '1';
            n /= 2;
        }

        int m = str.size();

        string temp(32- m, '0');

        str += temp;

        int ans = 0;

        for(int i = 0; i < 32; i++){
            ans += (str[i] == '1') ? pow(2, str.size() - 1 - i): 0;
        }

        return ans;
    }
};