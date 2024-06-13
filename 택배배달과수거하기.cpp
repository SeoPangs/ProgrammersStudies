#include "�ù��ް������ϱ�.h"
#include <string>
#include <vector>

using namespace std;

void �ù��ް������ϱ�::����()
{
    //�ù� ������� �뷮
    int cap = 4;

    //�ù� ����� ������ ��
    int n = 5;

    //������ ����ؾ��ϴ� ������ �迭
    vector<int> deliveries = { 1, 0, 3, 1, 2 };

    //������ �����ؾ��ϴ� ������ �迭
    vector<int> pickup = { 0, 3, 0, 4, 0 };

    cout << "Solution " << solution(cap, n, deliveries, pickup) << endl;
}

#define INDEX_MAX 1000000

long long �ù��ް������ϱ�::solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    //����� ��
    long long answer = -1;

    //�̵��� �Ÿ��� ��
    long long& distance = answer;

    //�ִ�  ���� �� �ִ� �ù� ����� �뷮
    int max_cap = cap;
    //���� ������ �ִ� �ù� ����� �뷮
    int cur_cap = 0;

    //����ؾ��� �ù��� ��
    int needDelivery = 0;
    for(auto delivery : deliveries)
    {
        needDelivery += delivery;
    }

    //�����ؾ��� �ù��� ��
    int needPickup = 0;
    for (auto pickup : pickups)
    {
        needPickup += pickup;
    }

    
#pragma region �ܼ�

    //����� �����մϴ�.

    
    int index = -1; //���� �ù谡 ��� ���ϰ� �ִ����� ���� �ε��� ��
    int direction = 1; //���� �ù谡 ��� �������� ������ 1 or -1
    int turning_point = n;

    //���� ����ؾ��� ������ ������
    while (needDelivery > 0 || needPickup > 0) 
    {   
        //�ε��� ���� �ȿ� ������
        if (index < 0)
        {
            //��� ������ �ٽ� ä���
            cur_cap = max_cap;
            direction = 1;
            index = 0; //���������� ����
        }
        else if (index > (n - 1))
        {
            direction = -1;
            index = n - 1;
        }

        
        


        //������ ���� �ù� ����ϱ�
        if (direction > 0)
        {
            //����ؾ��� ũ��
            int deliveryAmount = min(cur_cap, deliveries[index]);

            //�ù����� ���� ��������
            deliveries[index] -= deliveryAmount; // ����ؾߵ� ������ ��������� ����
            cur_cap -= deliveryAmount; //�ù� �뷮 �������� �뷮 ����
            needDelivery -= deliveryAmount; //����ؾߵ� ������ ��������� ����
        }

        //�ڷ� ���� �ù� �����ϱ�
        if (direction < 0)
        {
            //����ؾ��� ũ��
            int pickupAmount = min(max_cap - cur_cap, pickups[index]);

            //�ù����� ���� �Ʊ�
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

        index += direction; //���� �������� ����
        distance++; //�̵� �Ÿ� ���

    }


#pragma endregion


    



    return answer;
}