#define _CRT_SECURE_NO_WARNINGS  
#include <bits/stdc++.h> 
//map 
//����� : 0 
//������ : 1 
//�Ʒ����� ���� : 2 
//������ ���� : 3 
//x : �Ƹ��� �� �ε��� y : �Ƹ��� �� �ε��� 
int n, x = 0, y = 0, ** map, cnt = 0;
//button : ����ġ ��ġ ��� light : �Һ��� ���ߴ� �� ��� 
bool** button, ** light;
char c[51]; //�Ƹ��� ������ ��� 
//�Ƹ��� ����� ����ġ�� true���� 
bool action() { //�ش���ġ������ �ൿ�� ���� 
  //1. ������Ȯ�� 
  //������ġ�� ����ġ���ִٸ� 
    if (button[x][y]) {
        light[x][y] = true; //������ġ�� ���� 
        //��ȿ�ѹ����� ���� ���� 
        if (y >= 1) light[x][y - 1] = true;
        if (x >= 1 && y >= 1) light[x - 1][y - 1] = true;
        if (x >= 1) light[x - 1][y] = true;
        if (x >= 1 && y <= n - 2) light[x - 1][y + 1] = true;
        if (y <= n - 2) light[x][y + 1] = true;
        if (x <= n - 2 && y <= n - 2) light[x + 1][y + 1] = true;
        if (x <= n - 2) light[x + 1][y] = true;
        if (x <= n - 2 && y >= 1) light[x + 1][y - 1] = true;
        button[x][y] = false; //���� ����ġ ���� 
    }
    //2. ������ġ ����Ȯ��  
    //���� �����ִ���쿡 ����� �����ƴٸ� 
    if (!light[x][y] && (map[x][y] == 2 || map[x][y] == 3)) {
        printf("Aaaaaah!");
        return true;
    }
    //3. ���� �̵� 
    //�Ʒ����� ���� : 2 
    //������ ���� : 3 
    //�̵��� �Ʒ��������� 4 
    //�̵��� ���������� 5 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 2) { //�Ʒ����� �����϶� 
                if (i + 1 <= n - 1) { //��ȿ�Ѱ�? 
                    map[i][j] = 0; //������ġ �ʱ�ȭ 
                    map[i + 1][j] = 4; //���� �̵� 
                }
                else { //����������� (��ȿ�����������) 
                    map[i][j] = 5; //180�� ������ȯ 
                }
            }
            else if (map[i][j] == 3) { //������ �����϶� 
                if (i - 1 >= 0) {
                    map[i][j] = 0;
                    map[i - 1][j] = 5;
                }
                else {
                    map[i][j] = 4;
                }
            }
        }
    }
    //4. �̵��� �������͵� ������ 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == 4)
                map[i][j] = 2;
            else if (map[i][j] == 5)
                map[i][j] = 3;
    //5. �����̵��� �ٽ� Ȯ��  
    if (!light[x][y] && (map[x][y] == 2 || map[x][y] == 3)) {
        printf("Aaaaaah!");
        return true;
    }
    return false;
}
//�Ƹ��� ����� �����ƴٸ� true���� 
bool playGame() {
    //�Ʒ� 1   ���� 2   �� 3   ������ 4 
    int view_dir = 1;
    for (int i = 0; i < cnt; i++) {
        char order = c[i];
        if (order == 'F') {
            if (view_dir == 1) {
                if (x + 1 < n) //�̵������Ѱ�츸 
                    x++;
            }
            else if (view_dir == 2) {
                if (y - 1 > -1)
                    y--;
            }
            else if (view_dir == 3) {
                if (x - 1 > -1)
                    x--;
            }
            else if (view_dir == 4) {
                if (y + 1 < n)
                    y++;
            }
        }
        else if (order == 'L') { //�������� ������ ư�� 
            view_dir--;
            if (view_dir == 0)
                view_dir = 4;
        }
        else if (order == 'R') { //���������� ������ ư�� 
            view_dir++;
            if (view_dir == 5)
                view_dir = 1;
        }
        //�ൿ�� �� 
        if (action()) //���� �����ߴٸ� �������� 
            return true;
    }
    return false;
}
int main(void) {
    scanf("%d%s", &n, &c);
    map = new int* [n]; //�� 
    light = new bool* [n]; //������� 
    button = new bool* [n]; //����ġ ��ġ ��� 
    for (int i = 0; i < n; i++) {
        map[i] = new int[n];
        light[i] = new bool[n];
        button[i] = new bool[n];
        char temp[16];
        scanf("%s", &temp);
        for (int j = 0; j < n; j++) {
            light[i][j] = false;
            button[i][j] = false;
            if (temp[j] == 'O') { //����� 
                map[i][j] = 0;
            }
            else if (temp[j] == 'S') { //������ 
                button[i][j] = true;;
            }
            else if (temp[j] == 'Z') { //���� 
                map[i][j] = 2; //ó���� ��� �Ʒ��� �����ִ�. 
            }
        }
    }
    //��ɾ��� �Ѱ����� �� 
    for (int i = 0; i < 51; i++)
        if (c[i] == '\0')
            break;
        else
            cnt++;
    if (!playGame()) //�Ƹ��� �������� ��Ƴ��Ҵٸ� false���� 
        printf("Phew...");
    return 0;
}