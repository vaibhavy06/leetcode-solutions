class Solution {
public:
    void backtrack(vector<string>& ans, int& n, int l, int r, string& curs) {
        if (l == n && r == n) {
            ans.push_back(curs);
            return;
        }
        
        if (l < n) {
            curs += '(';                        
            backtrack(ans, n, l + 1, r, curs);  
            curs.pop_back();                    
        }

        if (r < l) {
            curs += ')';                        
            backtrack(ans, n, l, r + 1, curs);  
            curs.pop_back();                    
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        backtrack(ans, n, 0, 0, temp);
        return ans;
    }
};