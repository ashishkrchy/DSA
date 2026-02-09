class Solution {
public:
    int countMonobit(int n) {

        int x = n;

        int count = 0;

        while(n > 0){
            n /= 2;
            count++;
        }

        if(!(x & (x + 1))) return count + 1;

        return count;
    }
};