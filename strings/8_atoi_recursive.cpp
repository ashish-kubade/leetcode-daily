// class Solution {
// public:
//     int myAtoi(string s) {
//         long res = 0;
//         int sign = 1;
//         int i = 0;

//         //skip the leading whitespaces
//         while(i<s.length() && s[i] == ' ') i++;

//         if (i == s.size()) return 0;

    
//         //check for the sign
//         if(i<s.length() && (s[i] == '-' || s[i] == '+')){
//             sign = (s[i] == '-') ? -1 : 1;
//             i++;
//         }

//         while(i<s.size() && isdigit(s[i])){
//             res = res * 10 + s[i] - '0';

//             if(sign * res > INT_MAX) return INT_MAX;
//             if(sign * res < INT_MIN) return INT_MIN;
            
//             i++;
//         }
//         return (int) (sign * res);
//     }
// };


class Solution{
    public:
        int myAtoi(string s){
            int idx = 0, sign = 1, res = 0;
            return atoiHelper(s, idx, sign, res);
        }
    private:
        int atoiHelper(string s, int idx, int sign, int res){
            if(idx >= s.size()){
                return (int) res * sign;
            }
            if(s[idx] == ' ' and idx==0){
                return atoiHelper(s.substr(1), idx, sign, res);
            }

            if(s[idx] == '+' and idx == 0){
                sign = 1;
                return atoiHelper(s, idx+1, sign, res);
            }
            if(s[idx] == '-' and idx == 0) {
                sign = -1;
                return atoiHelper(s, idx+1, sign, res);
            }
            if(isdigit(s[idx])){
                int digit = s[idx] - '0';
                if (res > (INT_MAX - digit) / 10)
                {   
                    return  sign ==1 ? INT_MAX : INT_MIN;
                  
                }
                res = res * 10 + digit;

                return atoiHelper(s, idx+1, sign, res);
            }
            return (int) res * sign;
        }
};
