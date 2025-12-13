class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        int n = code.size();

        unordered_set<string> businessSet = {"electronics", "grocery", "pharmacy", "restaurant"};

        multiset<pair<string, string>> st;

        auto isValid = [&](string str){

            if(str == "") return false;

            for(auto w: str){
                
                if((w >= 65 && w <= 90) || (w >= 97 && w <= 122) || (w == 95) || (w >= 48 && w <= 57)) continue;
                else return false;

            }
            return true;
        };

        for(int i = 0; i < n; i++){
            if(isActive[i] && businessSet.count(businessLine[i]) && isValid(code[i])){
                st.insert({businessLine[i], code[i]});
            }
        }

        vector<string> res;

        for(auto [business, cod]: st){
            res.push_back(cod);
        }

        return res;
    }
};