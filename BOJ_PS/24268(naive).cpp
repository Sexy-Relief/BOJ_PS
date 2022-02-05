#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
int n_digit;            //�Է¹��� ���� d���� ��ȯ �� �����ϴ� �ڸ���
bool halt_flag = false; //�Ұ����� �� �۵��ϴ� flag
void dec_to_d(int n, int d)
{
    int j = 0;
    for (int i = n; i > 0; i /= d)
    {
        num[j++] = (i % d);
    }
    n_digit = j;
}
void calc(int n, int d)
{
    int *getnum = new int[d];
    int i = 0;
    while (1)
    {
        for (int j = 0; j < d; j++)
            getnum[j] = 0;

        //����� ���ڿ��� 1�� ���� ���� num�� ����ǵ��� ��
        i = 0;
        num[i]++;
        //�ڸ��� �ø�(carryout)
        while (num[i] == d)
        {
            num[i] = 0;
            if (i + 1 == d)
            {
                halt_flag = true;
                break;
            }
            num[i + 1]++;
            i++;
        }
        if (halt_flag)
            break;
        //0~d-1�� ��� ���� �ѹ��� �����ߴٸ� loop escape
        if (num[d - 1] == 0)
            continue;
        int j;
        for (j = 0; j < d; j++)
        {
            if (getnum[num[j]] > 0)
                break;
            else
                getnum[num[j]]++;
        }
        if (j == d)
            break;
    }
    delete[] getnum;
    return;
}
int pow(int d, int k)
{
    int mul = 1;
    while (k--)
    {
        mul *= d;
    }
    return mul;
}
int d_to_dec(int d)
{
    int ans = 0;
    for (int i = 0; i < d; i++)
        ans += pow(d, i) * num[i];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    num.assign(50, 0);
    //d���� ��ȯ
    dec_to_d(n, d);
    //��ȯ�� ���� �ڸ����� d���� Ŭ ��� �Ұ����ϹǷ� -1 ���
    if (n_digit > d)
    {
        cout << "-1\n";
        return 0;
    }
    //������ �信 �ش��ϴ� d������ ���� ã�´�.
    calc(n, d);
    if (halt_flag)
    {
        cout << "-1\n";
        return 0;
    }
    //d������ ���� 10������ �ٲپ� ����Ѵ�.
    cout << d_to_dec(d) << '\n';
    return 0;
}