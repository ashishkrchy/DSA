class Solution {
public:
    bool isPrime(int n){
        if(n == 1 || n == 0) return false;

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {

        int count = 0;

        for(int i = left; i <= right; i++){

            int n = 0;
            int x = i;

            while(x > 0){
                if(x % 2 == 1) n++;

                x /= 2;
            }

            if(isPrime(n)) count++;
        }

        return count;
        
    }
};