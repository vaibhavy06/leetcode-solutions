class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1; // int end = s.length() - 1;

        while(end >= 0 && s[end] == ' '){ // while( end >= 0 && s[end] == ''){ end  --}
            end--;
        }

        int start = end; // int s
        while(start >= 0 && s[start] != ' '){
            start --;
        }

        return end - start;
    }
};