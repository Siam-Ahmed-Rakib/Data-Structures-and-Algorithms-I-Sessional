#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s; 
    
    string ans="";
    for(int i=0; i<s.length(); i++)
    {
        int j=i;
        int cnt=0;
        while(j<s.length() && s[j]==s[i])
        {
            cnt++;
            j++;
        }
        i=j-1;
        ans+=s[i];
        ans+=to_string(cnt);
    }
    cout<<ans<<endl;
    if(ans.length()>s.length())
    {
        cout<<s<<endl;
    }
   

    return 0;
}