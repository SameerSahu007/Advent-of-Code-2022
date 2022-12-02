#include <bits/stdc++.h>
using namespace std;

int checkWinner(string &a, string &b)
{
    int sum = 0;
    if (b == "X")
        sum += 1;
    if (b == "Y")
        sum += 2;
    if (b == "Z")
        sum += 3;

    if (a == "A")
        a = "X";
    if (a == "B")
        a = "Y";
    if (a == "C")
        a = "Z";

    if (a == b)
    {
        sum += 3;
    }
    else if (b == "X")
    {
        if (a == "Z")
            sum += 6;
    }
    else if (b == "Y")
    {
        if (a == "X")
            sum += 6;
    }
    else if (b == "Z")
    {
        if (a == "Y")
            sum += 6;
    }
    else
    {
        sum += 0;
    }

    return sum;
}

int checkWinner2(string &a, string &b)
{
    int sum = 0;

    if (b == "Y")
    {
        sum += 3;
        if(a == "A") sum += 1;
        if(a == "B") sum += 2;
        if(a == "C") sum += 3;
    }
    else if (b == "X")
    {
        if(a == "A") sum += 3;
        if(a == "B") sum += 1;
        if(a == "C") sum += 2;
        
    }
    else
    {
        sum += 6;
        if(a == "A") sum += 2;
        if(a == "B") sum += 3;
        if(a == "C") sum += 1;
    }

    return sum;
}

int main()
{
    string temp = "";
    int total_score = 0;
    ifstream file;
    file.open("input.txt");

    while (!file.eof())
    {
        getline(file, temp);
        string a = temp.substr(0, temp.find_first_of(" "));
        string b = temp.substr(temp.find_first_of(" ") + 1, temp.size());
        // total_score +=  checkWinner(a, b);
        total_score += checkWinner2(a, b);
    }

    file.close();
    cout<<total_score<<"\n";
    return 0;
}