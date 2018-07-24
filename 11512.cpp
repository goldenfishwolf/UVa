#include<iostream>
#include<string>

using namespace std;

int check(string s,string t)
{
  int n = 0;

  size_t pos = s.find(t,0);
  while(pos != string::npos)
  {
    pos = s.find(t,pos + t.length());
    n++;
  }
  return n;
}

string Ans(string s, string t)
{
  int len = t.length();
  cout<<"s = "<<s<<"\nt = "<<t<<endl;
  if(len == 1)
  {
    if(check(s,t) > 1)
    {
      return string(t);
    }
    else
    {
      return string("");
    }
  }
  string s1,s2;
  s1 = t.substr(1,len-1);
  s2 = t.substr(0,len-1);
  int n = check(s,s1);
  int m = check(s,s2);
  if(max(n,m) > 1)
  {
    if(n == m)
    {
      if(string(s1) > string(s2))
      {
        return string(s2);
      }
      else
      {
        return string(s1);
      }
    }
    else if(n > 1)
    {
      return string(s1);
    }
    else
    {
      return s2;
    }
  }
  else
  {
    s1 = Ans(s,s1);
    s2 = Ans(s,s2);
    n = check(s,s1);
    m = check(s,s2);
    if(max(n,m) > 1)
    {
      if(n == m)
      {
        if(string(s1) > string(s2))
        {
          return string(s2);
        }
        else
        {
          return string(s1);
        }
      }
      else if(n > 1)
      {
        return string(s1);
      }
      else
      {
        return string(s2);
      }
    }
    else
    {
      return string("");
    }
  }
}

int main()
{
  int n;
  string s,t;
  cin >> n;
  cin.get();
  for(int i = 0; i < n; i++)
  {
    getline(cin,s);
    t = string(s);
    t = Ans(s,t);
    if(s.empty())
    {
      cout<<"No repetitions found!\n";
    }
    else
    {
      cout<< t << " " << check(s,t)<<endl;
    }
  }
  return 0;
}
