#include "택배배달과수거하기.h"
#include <string>
#include <vector>

using namespace std;

void 택배배달과수거하기::진행()
{
    //택배 용달차의 용량
    int cap = 4;

    //택배 배달할 가구의 수
    int n = 5;

    //물건을 배달해야하는 가구의 배열
    vector<int> deliveries = { 1, 0, 3, 1, 2 };

    //물건을 수거해야하는 가구의 배열
    vector<int> pickup = { 0, 3, 0, 4, 0 };

    cout << "Solution " << solution(cap, n, deliveries, pickup) << endl;
}

#define INDEX_MAX 1000000

long long 택배배달과수거하기::solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    //출력할 답
    long long answer = -1;

    //이동한 거리가 답
    long long& distance = answer;

    //최대  가질 수 있는 택배 배달의 용량
    int max_cap = cap;
    //현재 가지고 있는 택배 배달의 용량
    int cur_cap = 0;

    //배달해야할 택배의 수
    int needDelivery = 0;
    for(auto delivery : deliveries)
    {
        needDelivery += delivery;
    }

    //수거해야할 택배의 수
    int needPickup = 0;
    for (auto pickup : pickups)
    {
        needPickup += pickup;
    }

    
#pragma region 단순

    //배달을 시작합니다.

    
    int index = -1; //현재 택배가 어디를 향하고 있는지에 따른 인덱스 값
    int direction = 1; //현재 택배가 어느 방향으로 가는지 1 or -1
    int turning_point = n;

    //현재 운반해야할 물건이 없으면
    while (needDelivery > 0 || needPickup > 0) 
    {   
        //인덱스 범위 안에 없으면
        if (index < 0)
        {
            //모든 물건을 다시 채우기
            cur_cap = max_cap;
            direction = 1;
            index = 0; //시작점으로 가기
        }
        else if (index > (n - 1))
        {
            direction = -1;
            index = n - 1;
        }

        
        


        //앞으로 가면 택배 배달하기
        if (direction > 0)
        {
            //운반해야할 크기
            int deliveryAmount = min(cur_cap, deliveries[index]);

            //택배차에 물건 내려놓기
            deliveries[index] -= deliveryAmount; // 배송해야될 물건을 배송했으니 감소
            cur_cap -= deliveryAmount; //택배 용량 생겼으니 용량 증가
            needDelivery -= deliveryAmount; //배송해야될 물건을 배송했으니 감소
        }

        //뒤로 가면 택배 수거하기
        if (direction < 0)
        {
            //운반해야할 크기
            int pickupAmount = min(max_cap - cur_cap, pickups[index]);

            //택배차에 물건 싣기
            pickups[index] -= pickupAmount;
            needPickup -= pickupAmount;
            cur_cap += pickupAmount;
            
        }
#if true
        cout << "index: " << index << endl;
        cout << "cur_cap: " << cur_cap << endl;
        cout << "Deliveries: ";
        for (auto i : deliveries)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "Pickups: ";
        for (auto i : pickups)
        {
            cout << i << " ";
        }
        cout << endl << endl;
        cout << "Direction: " << direction << endl;
        cout << "needDelivery: " << needDelivery << endl;
        cout << "needPickup: " << needPickup << endl;
#endif

        index += direction; //다음 방향으로 가기
        distance++; //이동 거리 계산

    }


#pragma endregion


    



    return answer;
}