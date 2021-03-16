#include<stdio.h>
#include<algorithm>
using namespace std;
int narr[100000];
int s[100000];
/*  재귀 시간 초과
int bsearch(int key, int mid,int low, int high){
    if(low>high)
        return 0;
    else if(narr[mid]==s[key])
        return 1;
    else if(narr[mid]<s[key]){
        low = mid + 1;
        mid = (high + low) / 2;
        return bsearch(key, mid, low, high);
    }else {
        high = mid - 1;
        mid = (high + low) / 2;
        return bsearch(key, mid, low, high);
    }
}*/

/*
cin, cout, endl을 썼을 때 시간 초과 떴는데
scanf, printf \0으로 바꾸니 통과했다. 
*/
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &narr[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&s[i]);
    }
    sort(narr, narr + n);


    for (int i = 0; i < m;i++){
        int low = 0, high = n - 1, mid;
        while (1)
        {
            if (low > high)
            {
                printf("0\n");
                break;
            }else{
                mid = (high + low) / 2;

                if(narr[mid]==s[i]){
                    printf("1\n");
                    break;
                }
                else if(narr[mid]<s[i]){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
    }
    return 0;
}