/*#include<iostream>
#include<string>
#include<fstream>

using namespace std;

fstream f;

bool check_not(string s)
{
  size_t pos;
  int sum;
  pos = s.find("A");
  if(pos != string::npos && s.find("A",pos+1) != string::npos)
  {
    sum++;
  }
  pos = s.find("C");
  if(pos != string::npos && s.find("C",pos+1) != string::npos)
  {
    sum++;
  }
  pos = s.find("T");
  if(pos != string::npos && s.find("T",pos+1) != string::npos)
  {
    sum++;
  }
  pos = s.find("G");
  if(pos != string::npos && s.find("G",pos+1) != string::npos)
  {
    sum++;
  }
  if(sum)
  {
    ;
  }
  else
  {
    return false;
  }
}


int check(string s,string t)
{
  if(t.empty())
  {
    return 0;
  }
  int n = 0;

  size_t pos = s.find(t,0);
  while(pos != string::npos)
  {
    pos = s.find(t,pos + 1);
    n++;
  }
  return n;
}

string Ans(string s, string t)
{
  int len = t.length();
  //cout<<"s = "<<s<<"\nt = "<<t<<endl;
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
        if(s1.length() > s2.length())
        {
          return string(s1);
        }
        else if(s1.length() < s2.length())
        {
          return string(s2);
        }
        else
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
  f.open("test",ios::out);
  cin >> n;
  cin.get();
  for(int i = 0; i < n; i++)
  {
    getline(cin,s);
    t = string(s);
    t = Ans(s,t);

    if(t.empty())
    {
      //cout<<"No repetitions found!\n";
      f<<"No repetitions found!\n";
    }
    else
    {
      //cout<< t << " " << check(s,t)<<endl;
      f<< t << " " << check(s,t)<<endl;
    }
  }
  return 0;
}*/


#include<iostream>
#include<string>
#include<fstream>

using namespace std;


void Ans(string s)
{
  bool trie[1001][6];
}

int main()
{
  int n;
  string s,t;
  f.open("test",ios::out);
  cin >> n;
  cin.get();
  for(int i = 0; i < n; i++)
  {
    getline(cin,s);
    t = Ans(s);

    if(t.empty())
    {
      //cout<<"No repetitions found!\n";
      f<<"No repetitions found!\n";
    }
    else
    {
      //cout<< t << " " << check(s,t)<<endl;
      f<< t << " " << check(s,t)<<endl;
    }
  }
  return 0;
}




