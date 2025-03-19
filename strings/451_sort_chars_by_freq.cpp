class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            mp[s[i]] ++;
        }

        priority_queue<pair<int, char>> hp;
        for(auto & [ch, count] : mp){ //interesting use of auto
            hp.push({count, ch});
        }
        while(!hp.empty()){
            int count = hp.top().first;
            char ch = hp.top().second;
            while(count--){
                ans += ch;
            }
            hp.pop();
        }
        return ans;

    }
};
