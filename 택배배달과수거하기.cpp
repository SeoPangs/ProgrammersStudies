#include "택배배달과수거하기.h"
#include <string>
#include <vector>

using namespace std;

void 택배배달과수거하기::진행()
{
    //택배 용달차의 용량
    int cap = 0;

    //택배 배달할 가구의 수
    int n = 3;

    //물건을 배달해야하는 가구의 배열
    vector<int> deliveries = { 1, 2, 3 };

    //물건을 수거해야하는 가구의 배열
    vector<int> pickup = { 1, 1, 1 };

    cout << "Solution " << solution(cap, n, deliveries, pickup) << endl;
}

long long 택배배달과수거하기::solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    //출력할 답
    long long answer = -1;

    //이동한 거리가 답
    long long& distance = answer;

    //현재 가지고 있는 택배 배달의 용량
    int curCapacity = cap;

    //배달, 수거해야할 택배의 수
    int needDelivery = 0;
    for(auto delivery : deliveries)
    {
        needDelivery += delivery;
    }
    for (auto pickup : pickups)
    {
        needDelivery += pickup;
    }

    distance = 1;
    
#pragma region Greedy
    
    //배달을 시작합니다.


    int index = 0;
    while (needDelivery > 0)
    {
        needDelivery -= deliveries[index];
        if (index >= n) index = 0;
    }


#pragma endregion


    



    return answer;
}