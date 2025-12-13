class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        int n = code.size();

        unordered_set<string> businessSet = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        vector<pair<string, string>> valid; // {business, code}

        auto isValid = [](const string& str) {
            if (str.empty()) return false;

            for (char c : str) {
                if (!isalnum(c) && c != '_')
                    return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (isActive[i] && businessSet.count(businessLine[i]) && isValid(code[i])) {
                valid.push_back({businessLine[i], code[i]});
            }
        }

        sort(valid.begin(), valid.end());

        vector<string> res;
        for (auto& p : valid) {
            res.push_back(p.second);
        }

        return res;
    }
};