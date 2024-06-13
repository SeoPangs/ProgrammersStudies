#include "�ù��ް������ϱ�.h"
#include <string>
#include <vector>

using namespace std;

void �ù��ް������ϱ�::����()
{
    //�ù� ������� �뷮
    int cap = 0;

    //�ù� ����� ������ ��
    int n = 3;

    //������ ����ؾ��ϴ� ������ �迭
    vector<int> deliveries = { 1, 2, 3 };

    //������ �����ؾ��ϴ� ������ �迭
    vector<int> pickup = { 1, 1, 1 };

    cout << "Solution " << solution(cap, n, deliveries, pickup) << endl;
}

long long �ù��ް������ϱ�::solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    //����� ��
    long long answer = -1;

    //�̵��� �Ÿ��� ��
    long long& distance = answer;

    //���� ������ �ִ� �ù� ����� �뷮
    int curCapacity = cap;

    //���, �����ؾ��� �ù��� ��
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
    
    //����� �����մϴ�.


    int index = 0;
    while (needDelivery > 0)
    {
        needDelivery -= deliveries[index];
        if (index >= n) index = 0;
    }


#pragma endregion


    



    return answer;
}