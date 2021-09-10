// 58
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = 0;
        for(int i = s.size()-1; i>=0;--i){
            if(s[i]==' '){
                if(j!=0)
                return j;
            }
            else
                ++j;
        }
        return j;
    }
};

// 66
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> tmp;
        int cur = 1;
        for(int i = digits.size()-1;i>=0;--i){
            int temp = digits[i]+cur;
            digits[i] = temp%10;
            cur = temp/10;
        }
        if(cur!=0){
            digits.insert(digits.begin(),cur);
        }
        return digits;
    }
};

// 67

class Solution {
public:
    char sum(char a, char b,char& cur){
        int a_ = (int)a-48;        
        int b_ = (int)b-48;
        int c_ = (int)cur-48;
        if(a_+b_+c_==0){
            cur = '0';
            return '0';
        }
        if(a_+b_+c_==1){
            cur = '0';
            return '1';
        }
        if(a_+b_+c_==2){
            cur = '1';
            return '0';
        }
        cur = '1';
        return '1';
        
    }
    string addBinary(string a, string b) {
        char cur = '0';
        string res;
        int a_s = a.size()-1;
        int b_s = b.size()-1;
        int i = 0;
        for(; i<a.size() && i<b.size();++i){
            res.push_back(sum(a[a_s-i],b[b_s-i],cur));
        }
        for(;i<a.size();++i){
            res.push_back(sum(a[a_s-i],'0',cur));
        }
        for(;i<b.size();++i){
            res.push_back(sum(b[b_s-i],'0',cur));
        }
        if(cur == '1'){
            res.push_back('1');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// 69
class Solution {
public:
    int mySqrt(int x) {
        long i = 0;
        while(i*i<x){
            ++i;
        }
        
        return i*i==x?i:i-1;
    }
};

// 6
class Solution {
public:
    std::string convert(std::string s, int numRows) {
    if(numRows == 1)
        return s;
    std::string answ = "";
    int size = (numRows - 2) + numRows;
    int cursize = size;
    for (int i = 0; i < numRows; ++i) {
        bool t = false;
        for (int j = i; j < s.size();) {
            answ += s[j];
            if (cursize == size || cursize == 0) {
                j += size;
            }
            else {
                if (!t) {
                    t = true;
                    j += cursize;
                }
                else {
                    t = false;
                    j += (size - cursize);
                }
            }

        }
        cursize -= 2;
    }
    return answ;

}
};
