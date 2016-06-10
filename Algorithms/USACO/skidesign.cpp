/*
ID: og192li1
ROG: skidesign
PROB: skidesign
LANG: C
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
    //freopen("skidesign.out", "w", stdout);    
    scanf("%d", &sizeOfInput);
    
    for(int i = 1; i <= sizeOfInput; i++)
    {
        scanf("%d", &hills[i]);
    }
    sort(hills + 1, hills + sizeOfInput + 1);
    int diff = 0;
    int cost = 0;
    int shouldMove = 0;
    while((diff = hills[sizeOfInput] - hills[1]) > 17)
    {
        shouldMove += (diff -17) - (diff -17) / 2;
        int curShouldMove = (diff -17) - (diff -17) / 2;
        hills[sizeOfInput] -= curShouldMove;
        hills[1] += curShouldMove;
        
        sort(hills + 1, hills + sizeOfInput + 1);
    }
    cout << cost << endl;
}