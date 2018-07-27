#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>

using namespace std;

map <int, map<int, int> > play;
vector<pair<int , int>> space;
pair<int , int> xy;


bool check_win()
{
  for(int i = 0; i < 4; i++)
  {
    if( (play[i][0] == 1 && play[i][1] == 1 && play[i][2] == 1 && play[i][3] == 1) ||
        (play[0][0] == 1 && play[1][1] == 1 && play[2][2] == 1 && play[3][3] == 1) ||
        (play[3][0] == 1 && play[2][1] == 1 && play[1][2] == 1 && play[0][3] == 1) ||
        (play[0][i] == 1 && play[1][i] == 1 && play[2][i] == 1 && play[3][i] == 1) )
    {
      return true;
    }
    if( (play[i][0] == 2 && play[i][1] == 2 && play[i][2] == 2 && play[i][3] == 2) ||
        (play[0][0] == 2 && play[1][1] == 2 && play[2][2] == 2 && play[3][3] == 2) ||
        (play[3][0] == 2 && play[2][1] == 2 && play[1][2] == 2 && play[0][3] == 2) ||
        (play[0][i] == 2 && play[1][i] == 2 && play[2][i] == 2 && play[3][i] == 2) )
    {
      return false;
    }
  }
  return false;
}

bool cal()
{
  pair<int , int> temp;

  for(int i = 0; i < space.size(); i++)
  {
    temp = space.front();
    play[temp.first][temp.second] = 2;
    space.erase(remove(space.begin(),space.end(),temp),space.end());
    if(space.empty())
    {
      if(check_win());
    }
    
  }


}


void Ans()
{
  //vector<pair<int , int>>::iterator it;
  pair<int, int> temp;
  for(int i = 0; i < space.size(); i++)
  {
    temp = space.at[i];
    play[temp.front][temp.second] = 1;
    space.erase(remove(space.begin(),space.end(),temp),space.end());
    if(check_win() || cal())
    {
      xy = pair(temp);
      return;
    }
    space.insert(space.begin() + i,pair(temp));
  }
}

int main()
{
  char c;
  while(true)
  {
    cin>>c;
    if(c == '$')
    {
      break;
    }
    cin.get();
    space = 0;
    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        cin>>c;
        switch(c)
        {
          case '.':
            play[i][j] = 0;
            space.push_back(make_pair(i,j));
            break;
          case 'x':
            play[i][j] = 1;
            break;
          case 'o':
            play[i][j] = 2;
            break;
        }
      }
    }
    xy.first = -1;
    xy.second = -1;
    Ans();
    if(xy.first != -1 && xy.second != -1)
    {
      cout<< "(" << xy.first << "," << xy.second << ")\n";
    }
    else
    {
      cout<<"#####\n";
    }
  }
  return 0;
}

