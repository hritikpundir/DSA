class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() <= numRows) return s;

        vector<string> rows(numRows,"");
        int currRow = 0;
        bool goingDown = true;

        for(int i=0; i<s.length(); i++){
            rows[currRow] += s[i];

            if(currRow == numRows-1){
                goingDown = false;
            }
            if(currRow == 0){
                goingDown = true;
            }
            currRow = goingDown ? currRow+1 : currRow-1;
        }

        string res = "";
        for(int i=0; i<numRows; i++){
            res += rows[i];
        }
        return res;
    }
};