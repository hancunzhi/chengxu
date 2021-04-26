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
int tree[maxn][30];//tree[i][j]表示节点i的第j个儿子的节点编号
bool flagg[maxn];//表示以该节点结尾是一个单词
int tot;//总节点数
string fil[maxn];
int tops = 0;
char s[100][maxn];
int top;
map <string, int > query;

vector<int>vec[maxn];

string key;
void ini() {

	printf("请输入要查找的论文数量\n");
	int n;
	scanf("%d", &n);
	printf("请依次输入它们的名称以回车为分开\n");
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
		char temp[maxn];// cout<<1<<endl;      /// 存储文本信息
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
	printf("您有2种选择\n");
	printf("1 找到所有含该关键字的论文，和该关键字的次数\n");
	printf("2 退出该系统\n");
	printf("请输入1或者是2\n");
	cin >> choice;
	if (choice != '1' && choice != '2')
	{
		printf("输入错误请重新输入\n");
		choice = '0';
	}
}

void solveA() {
	printf("请输入关键字\n");
	cin >> key;
	int k = 0;
	int id = query[key];
	int siz = vec[id].size();
	int vis[maxn] = { 0 };
	printf("出现该关键字的文献有\n");
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
		printf("没有文献出现该关键词\n");
	}
	else
	{
		printf("分别出现了\n");
		for (int i = 0; i < tops; i++) {
			if (vis[i])
			{
				printf("%d次\n", vis[i]);
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