#include<iostream>
#include<string>
#include<cctype>
#include<map>
#include<algorithm>

using namespace std;

string Ans(string t)
{
  t.erase(remove(t.begin(), t.end(), ' '), t.end());
  map<int, map<int , int>> starts;
  int n = t.length();
  for(int i = 0, start = -1, oper = 0; i < n; i++)
  {
    if(t[i] == ' ')
    {
      continue;
    }
    if(isalpha(t[i]))
    {
      oper++;
      starts[start][1] = oper;
    }
    else
    {
      start++;
      starts[start][0] = i;
      if(start != 0)
      {
        starts[start-1][1] = oper;
      }
      oper = 0;
    }
    for(;oper == 2 && start > -1;)
    {
      for(int j = starts[start][0]; j < i; j++)
      {
        swap(t[j],t[j+1]);
      }
      start--;
      oper = starts[start][1];
      oper++;
      starts[start][1] = oper;
    }
  }
  for(int i = 1; i < n; i++)
  {
    t.insert(i," ");
    n++;
    i++;
  }
  return string(t);
}

int main()
{
  string s,t;
  getline(cin,s);
  getline(cin,t);
  cout<<"INFIX   => "<<s<<endl;
  cout<<"PREFIX  => "<<t<<endl;
  cout<<"POSTFIX => "<<Ans(t)<<endl;

  return 0;
}
