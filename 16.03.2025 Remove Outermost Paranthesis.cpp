class Solution {
public:
    string removeOuterParentheses(string s) {
        string output = "";
        int ocount = 0, ccount = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                ocount++;
            } else {
                ccount++;
            }

            if(ocount == ccount) {
                output += s.substr(i-(ocount*2-1)+1, ocount*2-2);
                ocount = 0;
                ccount = 0;
            }
        }
        return output;

    }
};
