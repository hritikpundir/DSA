class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> have;
        int res = INT_MAX;
        for (int i = 0; i < text.length(); i++) {
            have[text[i]]++;
        }
        unordered_map<char, int> need;
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;

        for (auto it : need) {
            char c = it.first;
            int fneed = it.second;
            int fhave = have[c];
            int times = fhave / fneed;
            res = min(res, times);
        }
        return res;
    }
};