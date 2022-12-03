#include<bits/stdc++.h>
using namespace std;


int check(string &a, string &b){
    int score = 0;
    unordered_set<char> s;

    for(char x: a){
        s.insert(x);
    }

    char ans;

    for(char x: b){
        if(s.find(x) != s.end()) ans =x;
    }

    if(islower(ans)){
        score += (ans - 96);
    }
    else{
       score += (ans - 64) + 26;
    }



    return score;
}


int main(){

    int total_sum =0;
    string temp;
    ifstream file;
    file.open("input.txt");

    while (!file.eof())
    {
        getline(file, temp);
        string firsthalf = temp.substr(0, temp.size()/2);
        string secondhalf  = temp.substr(temp.size()/2 , temp.size());
        total_sum += check(firsthalf, secondhalf);
        
    }

    file.close();
    cout<<total_sum;
    return 0;
}