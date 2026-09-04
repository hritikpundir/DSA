class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty() || words.empty()) return res;
        int n = words.size();
        unordered_map<string, int> word_count;
        int word_len = words[0].length();
        int total_len = n * word_len;

        // Step 1: Count frequencies of target words
        for(string word: words){
            word_count[word]++;
        }

        //Loop through all possible starting offsets
        for(int i=0; i<word_len; i++){
            int left = i;
            int right = i;
            unordered_map<string,int> curr_count;
            int words_used = 0;

            while(right + word_len <= s.length()){
                //slide the window
                string word = s.substr(right, word_len);
                right = right+ word_len;

                if(word_count.find(word) != word_count.end()){
                    curr_count[word]++;
                    words_used++;

                    while(curr_count[word] > word_count[word]){
                        string left_word = s.substr(left, word_len);
                        curr_count[left_word]--;
                        words_used--;
                        left = left + word_len;
                    }

                    //words equal to total words
                    if(words_used == n){
                        res.push_back(left);
                    }
                }
                else{
                    curr_count.clear();
                    words_used = 0;
                    left = right;
                }
                
            }
        }
        return res;
    }

};