//�� ������ �迭�� ������ ���� ���� �� ���� �� �� �����͸� ����Ѵ�. ����
//�ڿ����� �̷��� ���� �������� ���� ������ ���� � �������� �Ǵ��ϴ� ���� �� �����Ͱ� ���� ���ȴ�.
//�ڿ����� �ƴ϶�� ���׸�Ʈ Ʈ���� ������?
#include <iostream>
#include <vector>
using namespace std;
vector<bool> era;
vector<int> prime;
void eratos(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (era[i])
            continue;
        prime.push_back(i);
        for (int j = 2 * i; j <= n; j += i)
            era[j] = true;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, cnt = 0;
    cin >> n;
    era.assign(n + 1, false);
    eratos(n);
    int sum = 2, i = 0, j = 0;
    while (1)
    {
        if (i >= prime.size() || j >= prime.size())
            break;
        if (sum == n)
        {
            cnt++;
            sum -= prime[i];
            i++;
        }
        else if (sum < n)
        {
            j++;
            if (j < prime.size())
                sum += prime[j];
        }
        else
        {
            sum -= prime[i];
            i++;
        }
    }
    cout << cnt;
    return 0;
}