//n-queen problem���� ��Ʈ��ŷ�� �õ��ϸ� �ѹ� ������ �� �Ʒ��� ������ ���� ��ġ�� �����.
//�׷��ٸ� ü���� int 2���� �迭�� ���� ����ġ�� ���� �������μ� �Ʒ��� ������ ���Ե� ��ġ�� +1,
//�� ������ dfs�� ���� �� �ٽ� -1�� ���ִ� ������ �����ϰ� �ȴ�.
//bool �迭�� ������� �ʴ� ������ ��Ʈ��ŷ�� ���� ��� �������� ��� ���� ��ġ�� +1�� ��ø�Ǿ�
//���Ǵµ� bool ������ �ƹ��� 1�� ���ص� true����, �ű⼭ -1�� �ϸ� �ٷ� false�� �Ǳ⿡ �����߻�
#include <iostream>
using namespace std;
int n, ans = 0;
int t[15][15];
bool valid(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < n;
}
void check(int flag, int r, int c)
{
    int i = r, j = c;
    while (valid(i, j))
    {
        t[i][j] += flag;
        i++;
    }
    i = r, j = c;
    while (valid(i, j))
    {
        t[i][j] += flag;
        i++, j++;
    }
    i = r, j = c;
    while (valid(i, j))
    {
        t[i][j] += flag;
        i++, j--;
    }
}
void f(int r, int c)
{
    if (r == n - 1)
    {
        ++ans;
        return;
    }
    check(1, r, c);
    for (int i = 0; i < n; i++)
    {
        if (!t[r + 1][i])
            f(r + 1, i);
    }
    check(-1, r, c);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        f(0, i);
    cout << ans;
    return 0;
}