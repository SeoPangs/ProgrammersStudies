#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;
    
    for (auto player : players)
    {
        answer.push_back(player);
    }

    return answer;
}

int main(int argc, char argv[])
{
    vector<string> players = {
      "mumu", "soe", "poe", "kai", "mine"
    };
    vector<string> callings = {
     "kai", "kai", "mine", "mine"
    };
    

    for (auto player : solution(players, callings))
    {
        cout << player << endl;
    }
}
