//��� ���������� n>=m �̱� ������ ���� ����� ������� ���� �� �� ������, ���� �װ��� �� �� ���� ������ ū �� n�� ū �� m�� �������� �����ϰ� ��.
//�� ��, ���� ū ���� ������������ �ε��Ҽ������� ���� �ݵ�� ������ ������ �� �ۿ� ����
//�ڷ��� ����(type wrapping for operator overloading)
//%lld->signed long long, %llu->unsigend long long
//%15lld�� ��ĭ 15ĭ�� ����� �ű⿡ longlong�� ������ �����ʺ��� ä��������
//%015lld�� 15ĭ�� 0���� ä��� �������� ������ longlong�� ä���ִ´�.
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef struct _ll
{
    long long BIGNUM = 1e15;
    long long carry;
    long long remainder;
    struct _ll operator+(struct _ll a)
    {
        carry += a.carry;
        remainder += a.remainder;
        if (remainder > BIGNUM)
        {
            carry += remainder / BIGNUM;
            remainder %= BIGNUM;
        }
        return *this;
    }
} ll;
int main()
{
    int n, m;
    cin >> n >> m;
    ll table[101][101];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < m; j++)
            table[i][j].carry = table[i][j].remainder = 0;
    for (int i = 1; i <= n; i++)
    {
        table[i][0].remainder = table[i][i].remainder = 1;
        for (int j = 1; j < i; j++)
        {
            table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        }
    }
    if (table[n][m].carry == 0)
    {
        cout << table[n][m].remainder;
    }
    else
    {
        cout << table[n][m].carry;
        printf("%015lld", table[n][m].remainder);
    }
    return 0;
}