class Solution {
  public:
    int atMostK(string & s, int k){
        if(k<0) return 0;
        
        int i=0, j=0, count=0, res = 0;
        int m[26] = {0};
        int n=s.size();
        while(j<n){

            m[s[j] -'a']++;
            if(m[s[j]-'a'] == 1){
                count++;
            } 
            
            while (count > k) {
                
                m[s[i]-'a']--;
                if(m[s[i] -'a'] == 0) count --;
                i++;
            }
            res += (j-i+1); //number of substrings in the range
            j++;
        }
        return res;
    }
    int countSubstr(string& s, int k) {
        // code here.
        return atMostK(s, k) - atMostK(s, k-1);
    }
};
