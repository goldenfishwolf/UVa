#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
string s, t;
unordered_map<int, unordered_map<int, int> > dp;
unordered_map<int, unordered_map<int, int> > redp;


int trans(int x, int y)
{
  if(x == n)
  {
    return m-y;
  }
  if(y == m)
  {
    return n-x;
  }
  if (!dp[x].count(y)) {
    if(s[x] == t[y])
    {
      dp[x][y] = trans(x+1,y+1);
      redp[x][y] = 0;
    }
    else
    {
      int r = trans(x+1,y+1);
      int d = trans(x+1,y);
      int i = trans(x,y+1);
    
      dp[x][y] = min(min(r,d),i) + 1;
      if(dp[x][y] == r+1)
      {
        redp[x][y] = 3;
      }
      else if(dp[x][y] == d+1)
      {
        redp[x][y] = 2;
      }
      else
      {
        redp[x][y] = 1;
      }
    }
  }

  return dp[x][y];
}

int step;

void print_ans(int x, int y, int slen)
{

  step++;
  if(x == n)
  {
    for(; y < m; y++, step++)
    {
      cout<< step <<" Insert "<< y+1 <<","<< t[y] <<endl;
    }
  }
  if(y == m)
  {
    for(; x < n; x++,step++)
    {
      cout<< step <<" Delete "<< slen <<endl;
    }
    return;
  }

  if(redp[x][y] == 0)
  {
      step--;
      print_ans(x+1,y+1,slen+1);
  } 
  else if(redp[x][y] == 1)
  {
      cout<< step <<" Insert "<< slen <<","<< t[y] <<endl;
      print_ans(x,y+1,slen+1);
  }
  else if(redp[x][y] == 2)
  {
      cout<< step <<" Delete "<< slen <<endl;
      print_ans(x+1,y,slen);
  }
  else if(redp[x][y] == 3)
  {
      cout<< step <<" Replace "<< slen <<","<< t[y] <<endl;
      print_ans(x+1,y+1,slen+1);
  }


}

void Ans()
{
  step = 0;
  n = s.length();
  m = t.length();
  cout<< trans(0,0) <<endl;
  print_ans(0,0,1);
}

int main()
{
  bool first = false;
  for(;getline(cin,s) && getline(cin,t);)
  {
    if(first)cout<<"\n";
    else first = true;
    dp.clear();
    redp.clear();
    Ans();
    
  }
  return 0;
}
