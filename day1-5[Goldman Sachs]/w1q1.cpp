#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        // set<multiset<char>> s;
        vector<vector<string>> v;
        map<multiset<char>,vector<string>>h;
        for(int i=0;i<string_list.size();i++){
            multiset<char> t;
            for( auto c : string_list[i]){
                t.insert(c);
            }
            h[t].push_back(string_list[i]);
        }
        for(auto i : h){
            v.push_back(i.second);
        }
        return v;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}