#include<bits/stdc++.h>
using namespace std;


int check(vector<string> &str ){
    int score = 0;
    
    char ans;

    for(char x : str[0]){

        bool c = true;
        for(int i = 1; i<str.size(); i++){
            if(str[i].find(x) == string::npos){
                c = false;
                break;
            }
        }

        if(c){
            ans = x;
        }

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
    vector<string> str;
    string temp;
    ifstream file;
    file.open("input.txt");

    while (!file.eof())
    {
        getline(file, temp);
        str.push_back(temp);
       if(str.size() == 3 ) {
        total_sum += check(str);
        str.clear();
       }
       
        
    }

    file.close();
    cout<<total_sum;
    return 0;
}