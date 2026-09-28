class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        // unordered map used in present code execution. 
        for(auto x: strs){
            string word = x; // the eleement has initialised to the extent and has no varibale scoping.
            sort(word.begin(), word.end()); // sort the element sort(word.begin(), word.end())
            mp[word].push_back(x); // mp[word].push_back(x);
        }
        
        vector<vector<string>> ans; // vector<vector<string s>> ans;
        for(auto x: mp){
            ans.push_back(x.second); // push_back(x.second )
        }
        return ans;
    }
};