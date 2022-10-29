class Solution {
public:
    int myAtoi(string s) {
        int res = 0 ;
        int sign = 0;
        int i = 0;
        while(s[i] == ' ') i++;
        if(s[i] == '-' || s[i] == '+') {
            sign = -1 * (s[i++] == '-'); 
        }
        while(s[i] >= '0' && s[i] <= '9'){
            if (res >  INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7)) {
                if (sign == 0) return INT_MAX;
                else return INT_MIN;
            }
            res = res * 10 + (s[i++] - '0');
        }
        if(sign == 0) return res;
        return res * sign;
    }
};