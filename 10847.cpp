#include<iostream>
#include<string>
#include<cctype>
#include<map>
#include<fstream>

using namespace std;

//fstream f;
map< char, bool > alph;

bool check_correct(string s)
{
  int n = s.length();
  int al = 0, op = 0;
  for(int i = 0; i < n; i++)
  {
    if(isalpha(s[i]))
    {
      al++;
      if(alph.find(s[i]) == alph.end())
      {
        alph[s[i]] = false;
      }
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
          //op = 1;
          break;
        case '-':
          if(al < 1)
          {
            return false;
          }
          //op = 1;
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

bool substitute(string s)
{
  int n = s.length();
  bool var[201] = {false};
  for(int i = 0,start = -1; i < n; i++)
  {
    if(isalpha(s[i]))
    {
      start++;
      var[start] = alph[s[i]];
    }
    else
    {
      switch(s[i])
      {
        case '=':
          start--;
          var[start] = (var[start] == var[start+1]);
          break;
        case '-':
          var[start] = !var[start];
          break;
      }
    }
  }
  return var[0];
}

bool check_tau(string s)
{
  int n = s.length();
  for(int i = 0, j = 0; i < (1<<alph.size()); i++)
  {
    j = 0;
    for(map<char,bool>::iterator it = alph.begin(); it != alph.end(); ++it, j++)
    {
      it->second = (i&(1<<j));
    }
    if(!substitute(s))
    {
      return false;
    }
  }
  return true;
}


int Ans(string s)
{
  
  alph.clear();
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
  //f.open("test",ios::out);
  for(int i = 0; i < n; i++)
  {
    getline(cin,s);
    switch(Ans(s))
    {
      case 0:
        cout<<"incorrect"<<endl;
        break;
      case 1:
        cout<<"formula"<<endl;
        break;
      case 2:
        cout<<"tautology"<<endl;
        break;
    }
  }
  return 0;
}

