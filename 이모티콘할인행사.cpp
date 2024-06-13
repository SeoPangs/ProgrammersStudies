#include "이모티콘할인행사.h"

#include <string>
#include <vector>

using namespace std;

void 이모티콘할인행사::진행()
{
    //물건을 배달해야하는 가구의 배열
    vector<vector<int>> users = { {1, 2} };

    //물건을 수거해야하는 가구의 배열
    vector<int> emoticaons = { 0, 3, 0, 4, 0 };

    cout << "Solution: ";
    for (auto& i : solution(users, emoticaons))
    {
        cout << i << " ";
    }
    cout << endl;
}

#define INDEX_MAX 1000000

vector<int> 이모티콘할인행사::solution(vector<vector<int>> users, vector<int> emoticons) 
{
    vector<int> answer;


    return answer;
}