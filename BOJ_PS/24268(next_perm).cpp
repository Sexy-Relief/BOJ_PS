//vector�� reverse �Լ� ���

//next_permutation�� ���� vector(iterator�� ���ڷ� �����Ƿ� string�� ����)�� ���¿���
//�� ���� ���� ��Ÿ���� ������ �Ѵ�. �̹�ó�� d������ �� ī���ÿ��� ������ ��

//�� d������ 10������ ���� �� ���� �ڸ������� ����ϸ� ���� n���� ������ ����ؼ�
//���� �ʿ� ���� �ش� �ڸ��� ���� ���ϰ� �ű⿡ d�� ���ϰ� �ݺ��ϸ� �ȴ�

//vector �ĺ��� �ΰ��� �ٷ� �ε�ȣ�� ���ϸ� pair�� ���� ��ó�� ���� ���Һ��� �ϳ��� ����
//������ ���� ���Ҹ� ���ϴ� ������ �ؼ� ���Ѵ�. ���� ���{1,2,2}�� {1,2,3}�� �� ���͸� ���ϸ� ���� vector�� �� ū ���̴�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
int d_to_dec(int d, vector<int> &perm)
{
    int val = 0;
    for (const auto &k : perm)
    {
        val *= d;
        val += k;
    }
    return val;
}
int calc(int n, int d)
{
    while (n)
    {
        num.push_back(n % d);
        n /= d;
    }
    if (num.size() > d)
        return -1;
    num.resize(d);
    reverse(num.begin(), num.end());
    vector<int> perm;
    perm.push_back(1);
    perm.push_back(0);
    for (int i = 2; i < d; i++)
    {
        perm.push_back(i);
    }
    do
    {
        if (perm > num)
        {
            return d_to_dec(d, perm);
        }
    } while (next_permutation(perm.begin(), perm.end()));
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    cout << calc(n, d) << '\n';
    return 0;
}