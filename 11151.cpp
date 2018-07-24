#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;



int Ans(string s)
{
  string t(s.rbegin(),s.rend());
  unordered_map< int, unordered_map<int, int> > dp;
  for(int i = 0; i <= s.length(); i++)
  {
    for(int j = 0; j <= s.length(); j++)
    {
      if(i == 0 || j == 0)
      {
        dp[i][j] = 0;
        continue;
      }
      if(s[i-1] == t[j-1])
      {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[s.length()][s.length()];
}

int main()
{
  int n;
  string s;
  cin >> n;
  //cout<<"n = "<<n<<endl;
  cin.get();
  for(int i = 0; i < n; i++)
  {
    getline(cin,s);
    //cout<<"s = "<<s<<endl;
    cout<< Ans(s) <<endl;
  }
  return 0;
}
