class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(auto x:s)if(isalnum(x)) temp+= tolower(x);
        string a="";
        for(int i=0;i<temp.size();i++){
            if(temp[i]==' ' )continue;
            else a+=temp[i];
        }
      //  cout<<a<<endl;
        string b=a;
        reverse(a.begin(), a.end());
        return a==b;
    }
};
