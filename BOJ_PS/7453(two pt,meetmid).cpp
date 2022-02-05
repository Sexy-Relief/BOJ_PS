#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[4000], B[4000], C[4000], D[4000];
vector<int> AA, BB;
int bin_search(int val, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (BB[mid] == val)
        return mid;
    else if (BB[mid] > val)
        return bin_search(val, start, mid - 1);
    else
        return bin_search(val, mid + 1, end);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AA.push_back(A[i] + B[j]);
            BB.push_back(C[i] + D[j]);
        }
    }
    sort(AA.begin(), AA.end());
    sort(BB.begin(), BB.end());
    long long ans = 0;
    int left = 0, right = n * n - 1, sum;
    //�׸����� �����ϸ�, �� �����Ͱ� �� ���ܿ��� ������ sum�� ũ�⿡ ���� �׿� ����
    //������ ����. ���� ��� �ʱ� ���¿��� sum�� 0���� ũ�ٸ� left�� �ƹ��� Ű����
    //���� right�� ���Ͽ� sum�� �� Ŀ���Ƿ� 0�� �� �� ����. �̷� ������ �� �迭��
    //�ѹ����� ������ ������.
    while (left < AA.size() && right >= 0)
    {
        sum = AA[left] + BB[right];
        if (sum > 0)
            right--;
        else if (sum < 0)
            left++;
        else
        {
            int x = AA[left], y = BB[right];
            long long xcount = 0, ycount = 0;
            while (AA[left] == x)
            {
                left++;
                xcount++;
                if (left >= AA.size())
                    break;
            }
            while (BB[right] == y)
            {
                right--;
                ycount++;
                if (right < 0)
                    break;
            }
            ans += xcount * ycount;
        }
    }
    cout << ans;
    return 0;
}