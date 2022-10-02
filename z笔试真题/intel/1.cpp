#include <bit/stdc++.h>

using namespace std;

bool check(string a, string b)
{
  for (int i = 0; i < b.size(); i ++ )
  {
    if (b[i] != '?')
    {
      if (b[i] != a[i]) return false;
    }
  }
  return true;
}


int main()
{

}
//xxxx-xx-xx
string get_date(string s)
{
  string year = s.substr(0, 4);
  string mon = s.substr(5, 2);
  string day = s.substr(8);

  string mp[2000];
  int n = 0;
  for (int i = 1000; i <= 2022; i ++ )
    mp[n ++ ] = to_string(i);
  
  for (int i = n - 1; i; i -- )
  {
    if (check(mp[i], year))
    {
      year = mp[i];
      break;
    }
  }
  
  if (mon[0] == '0')
  {
    if (mon[1)
  }
  else if (mon[0] == '1')
  {

  }
  else{

  }


}

