#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//������ �� ����� ��������
//int bills[] = { 1, 5, 10, 20, 50, 100, 200, 500, 1000 };
//������ ������ �������  sizeof(deno) - ������ ����� ������� � ������ ����� �� ������ ������ ��������
//int bills_size = sizeof(bills) / sizeof(bills[0]);

//������� ������� ���������� ���������� �������� ��� �������� ����� ��������� V ��� ������� ������� ��������� �����
void countBills(int V, int bills_size, int bills[])
{
    //�������������� ������ ��� �������� ���������� �������
    //������� ������ ��� ��� �� ����� ��������� �������� ���� ������ � ������� �� �������
    vector<int> optin_bills;
    int bils_count[bills_size]; //� ���� ������� ����� ������� ���������� �������

    //�������� �� ����� ������� � �������� �������� � ����� ��� ��� ����� ������� ������ � ��� � ����� �������
    for (int i = bills_size - 1; i >= 0; i--) {

        bils_count[i] = 0; //�� ��������� ������ �������� �� ���������� 0 ���

        //��������� ���� ��������� �������� �������� ��� ����� �����
        //��������� � ����� ��� ��� ��� ������� ����� ������������ ������ ����� �������������
        while (V >= bills[i]) { //������� ��������� ���� �������� ������ �����

            V -= bills[i]; //�������� ���������� �������� �� ����� �����(��� ������� �� �����)

            bils_count[i]++; //� ������ �������� �������������� ���������� ������� �� ������� ��������� �����

            optin_bills.push_back(bills[i]); //co������� ���������� �������� � ��� ������
        }
    }

    if (V > 0) { //��������� ������� �� ������� ����� �������� ����� �� �������� (� ����� ������ � ��� ����� ������ ��� ��� �� �� ����� ������ ��������� ����� ��-�� �������� �������)
        cout << "������ ����� �� ����� ���� �������� ������������� ����������";

    } else {
        //������� ������ � ����������� �������� �� �����
        for (int i = 0; i < optin_bills.size(); i++) {
            cout << optin_bills[i] << "  ";
        }

       cout << endl;
       cout << "------------------------------------------------------------------------------------" <<endl;
        //������� ���������� ����������� �������
        for (int j = 0; j < bills_size; j++) {
            cout << bills[j] << "X" << bils_count[j] << endl;
        }
    }
}

int * sortArray(int size_arr, int arr1[])
{
    int temp; // ��������� ���������� ��� ������ ��������� �������

    // ���������� ������� ���������
    for (int i = 0; i < size_arr - 1; i++) {
        for (int j = 0; j < size_arr - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                // ������ �������� �������
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    // ����� ���������������� ������� �� �����
    cout << "��������������� ������: ";
    for (int i = 0; i < size_arr; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return arr1;
}

int main()
{
    setlocale(LC_ALL, "Russian"); //������������� Locale ��������� ����� ����� ���� ������� ����� �� �������

    int *arr; // ��������� ��� ��������� ������ ��� ������
    int size; // ���������� ��� ������ �������

    //���� ���������� ��������� �������
    cout << "������� ���������� ������� ";
    cin >> size;

    if (size <= 0) {
        // ������ ������ ������ ���� �������������
        cout << "������ ������� ������ ���� ������ 0!";

        return 1;
    }


    arr = new int[size]; // ��������� ������ ��� ������

    // ���������� �������
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    // ����� ���������������� ������� �� �����
    cout << "��������� ��������: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int * sort_array = sortArray(size, arr);
    int sum;
    cout << "������� ����� � ������� Enter: ";
    cin >> sum; //��������� ��������� ����� � ����������
    cout << "�������� ���� ����� " << sum << " ������� �� ��������� �����: ";
    countBills(sum, size, sort_array);

    return 0;
}
