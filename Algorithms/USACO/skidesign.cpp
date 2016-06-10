/*
ID: og192li1
ROG: skidesign
PROB: skidesign
LANG: C++
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int hills[1010];

int main(void)
{
    int sizeOfInput = 0;
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);    
    scanf("%d", &sizeOfInput);
    
    for(int i = 1; i <= sizeOfInput; i++)
    {
        scanf("%d", &hills[i]);
    }
    sort(hills + 1, hills + sizeOfInput + 1);
    vector<int> sortpos;
    vector<int> orignal(hills + 1, hills + sizeOfInput + 1);
    sortpos.push_back(-1);
    for(int i = 1; i < sizeOfInput + 1; ++i)
    {
        sortpos.push_back(i);
    }
    int diff = 0;
    int cost = 0;
    while((diff = hills[sortpos[sizeOfInput]] - hills[sortpos[1]]) > 17)
    {
        int curShouldMove = (diff -17) - (diff -17) / 2;
        hills[sortpos[sizeOfInput]] -= curShouldMove;
        hills[sortpos[1]] += curShouldMove;

        int tmp = sortpos[sizeOfInput];
        int curMax = hills[tmp];
        int i = sizeOfInput - 1;
        while(curMax < hills[sortpos[i]])
        {
            sortpos[i + 1] = sortpos[i];
            --i;
        }
        sortpos[i + 1] = tmp;

        tmp = sortpos[1];
        int curMin = hills[tmp];
        i = 2;
        while(curMin > hills[sortpos[i]])
        {
            sortpos[i - 1] = sortpos[i];
            ++i;
        }
        sortpos[i - 1] = tmp;
    }
    for(int i = 1; i <= sizeOfInput; ++i)
    {
        cost += (orignal[i - 1] - hills[i]) * (orignal[i - 1] - hills[i]);
    }
    cout << cost << endl;
}