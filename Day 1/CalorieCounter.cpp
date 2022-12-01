#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<string> str;
    string temp = "";
    ifstream file;
    file.open("input.txt");

    while (!file.eof())
    {
        getline(file, temp);
        str.push_back(temp);
       
    }

    file.close();
    
    vector<int> total_calories;
    int topCalorires = 0;
    int m  = INT_MIN;
    int sum = 0;
    int elf = 0;
    int i = 0;
    int n = 3;

    for (auto x : str)
    {
      if( !x.length() ){

        i++;
        if(sum >= m){
            elf = i;
            m = sum;
        }
        
        total_calories.push_back(sum);
        sum = 0;
      }
      else{
        sum += stoi(x);
      }
    }

    cout<<m<<"\n";

    sort(total_calories.begin(), total_calories.end());
    while(n--){
      topCalorires += total_calories[total_calories.size() - n - 1];
    }

    cout<<topCalorires<<"\n";
    


    return 0;
}