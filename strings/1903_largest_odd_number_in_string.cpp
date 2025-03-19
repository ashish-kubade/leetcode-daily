class Solution {
public:
    string largestOddNumber(string num) {
        while(num.size() > 0){
            char c = num[num.size()-1];
            int digit = c - '0'; //remember stoi for strings, for chars, we can substract '0'
            if(digit % 2) return num;
            else{
                num.erase(num.size()-1); //remember this string manipulation function, erase
            }
        }
        return num;
    }
};
