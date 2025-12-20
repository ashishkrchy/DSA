class Solution {
public:

    int n;

    bool isSorted(int col, vector<string>& strs){

        int i = 1;
        
        while(i < n){
            
            if(strs[i - 1][col] > strs[i][col]){
                return false;
            }
            i++;
        }

        return true;
    }

    int minDeletionSize(vector<string>& strs) {

        n = strs.size();
        
        int m = strs[0].size();

        int count = 0;

        for(int col = 0; col < m; col++){
            if(!isSorted(col, strs)){
                count++;
            }
        }

        return count;
    }
};