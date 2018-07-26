#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<fstream>

using namespace std;

fstream f;

bool check_correct(string s)
{
  int n = s.length();
  //vector<char> alpha;
  //vector<char> oper;
  int al = 0;
  for(int i = 0; i < n; i++)
  {
    if(isalpha(s[i]))
    {
      al++;
    }
    else
    {
      switch(s[i])
      {
        case '=':
          if(al < 2)
          {
            return false;
          }
          al -= 1;
          break;
        case '-':
          if(al < 1)
          {
            return false;
          }
          break;
        default:
          return false;
          break;
      }
    }
  }
  if(al > 1)
  {
    return false;
  }
  return true;
}

bool check_tau(string s)
{
  int n = s.length();
  for(int i = 0; i < n; i++)
  {
    return false;
  }
  return true;
}


int Ans(string s)
{
  if(check_correct(s))
  {
    if(check_tau(s))
    {
      return 2;
    }
    return 1;
  }
  return 0;
}

int main()
{
  string s;
  int n;
  cin >> n;
  cin.get();
  f.open("test",ios::out);
  for(int i = 0; i < n; i++)
  {
    getline(cin,s);
    switch(Ans(s))
    {
      case 0:
        f<<"incorrect"<<endl;
        break;
      case 1:
        f<<"formula"<<endl;
        break;
      case 2:
        f<<"tautology"<<endl;
        break;
    }
  }
  return 0;
}

