#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
#include<string>
#include <set>
#include<time.h>
#include <cstdio>
#define FR(i,n) for(int i=0;i<n;i++)
#define MAX 2005
#define MAXTIME 28800
#define mkp pair <int,int>
using namespace std;
typedef long long ll;
const int inf = 100000000;
const int maxn = 100000;
using namespace std;
FILE* fp;
int tree[maxn][30];//tree[i][j]��ʾ�ڵ�i�ĵ�j�����ӵĽڵ���
bool flagg[maxn];//��ʾ�Ըýڵ��β��һ������
int tot;//�ܽڵ���
string fil[maxn];
int tops = 0;
char s[100][maxn];
int top;
map <string, int > query;

vector<int>vec[maxn];

string key;
void ini() {

	printf("������Ҫ���ҵ���������\n");
	int n;
	scanf("%d", &n);
	printf("�������������ǵ������Իس�Ϊ�ֿ�\n");
	for (int i = 0; i < n; i++)
	{
		char na[maxn];
		scanf("%s", na);
		fil[tops++] = na;
	}
}

void in() {
	string shh = "";
	for (int i = 0; i < tops; i++) {
		char temp[maxn];// cout<<1<<endl;      /// �洢�ı���Ϣ
		int siz = fil[i].size();
		for (int j = 0; j < siz; j++)
		{
			temp[j] = fil[i][j];
		}
		temp[siz] = 0;
		fp = fopen(temp, "r+");
		int ans = 0;
		while (!feof(fp)) {
			char c;
			fscanf(fp, "%c", &c);
			// cout<<c;
			if (c == '\n') {
				if (!query[shh])
				{
					query[shh] = ++tot;
				}
				if (shh != "")
				{
					vec[query[shh]].push_back(i);
				}
				shh = "";
			}
			else {
				if (c == ' ') {
					if (!query[shh])
					{
						query[shh] = ++tot;
					}
					vec[query[shh]].push_back(i);
					shh = "";
				}
				else shh += c;
			}
			c = ' ';
		}
		if (!query[shh])
		{
			query[shh] = ++tot;
		}
		if (shh != "")
		{
			vec[query[shh]].push_back(i);
		}
		shh = "";
		fclose(fp);

	}
	//cout<<endl;
	fclose(fp);
}
char choice;

void show() {
	printf("����2��ѡ��\n");
	printf("1 �ҵ����к��ùؼ��ֵ����ģ��͸ùؼ��ֵĴ���\n");
	printf("2 �˳���ϵͳ\n");
	printf("������1������2\n");
	cin >> choice;
	if (choice != '1' && choice != '2')
	{
		printf("�����������������\n");
		choice = '0';
	}
}

void solveA() {
	printf("������ؼ���\n");
	cin >> key;
	int k = 0;
	int id = query[key];
	int siz = vec[id].size();
	int vis[maxn] = { 0 };
	printf("���ָùؼ��ֵ�������\n");
	for (int i = 0; i < siz; i++) {
		int keyid = vec[id][i];
		vis[keyid]++;
		if (vis[keyid] == 1) {
			cout << fil[keyid] << endl;
			k = 1;
		}
	}
	if (k == 0)
	{
		printf("û�����׳��ָùؼ���\n");
	}
	else
	{
		printf("�ֱ������\n");
		for (int i = 0; i < tops; i++) {
			if (vis[i])
			{
				printf("%d��\n", vis[i]);
			}
		}
	}

}
int  main() {
	ini();
	in();
	while (1) {
		printf("/****************************************************/\n");
		show();
		if (choice == '1')solveA();
		if (choice == '2')break;
		//	if(choice==3)solveC();
	}
	return 0;
}