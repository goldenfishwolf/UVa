#include<iostream>
#include<string>
#include<vector>

bool check(vector<string> v, string s)
{
  int n = v.size();
  int sum = 0;
  for(int i = 0; i < n; i++)
  {
    if(v.at(i).find(sum) != string::npos)
    {
      sum++;
    }
    if(sum == n/2 + 1)
    {
      return true;
    }
  }
  return false;
}

void Ans(vector<string> v)
{
  ;
}

int main()
{
  int n;
  string s;
  vector<string> v;
  for(;;)
  {
    cin << n;
    cin.get();
    if(n == 0)
    {
      break;
    }
    v.clear();
    for(int i = 0; i < n; i++)
    {
      getline(cin,s);
      v.push_back(s);
    }
    Ans(v);
  }
  return 0;
}
