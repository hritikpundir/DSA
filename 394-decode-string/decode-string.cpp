class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<int> numStack;
        stack<string> strStack;
        string res = "";
        int num = 0;

        for(char c: s){
            if(c >= '0' && c <= '9'){           
                num = num * 10 + (c - '0');
            }

            else if(c == '['){
                numStack.push(num);
                strStack.push(res);
                num = 0;
                res = "";
            }

            else if(c == ']'){
                int cnt = numStack.top();
                numStack.pop();

                string temp = strStack.top();
                strStack.pop();

                for(int i=0; i<cnt; ++i){
                    temp += res;
                }
                res = temp;
            }

            else{
                res += c;
            }
        }
        return res;
    }
};