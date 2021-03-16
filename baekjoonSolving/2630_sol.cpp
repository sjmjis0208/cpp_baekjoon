#include<iostream>
using namespace std;
int map[128][128];
int w =0, b =0;

void dcon(int x, int y, int size)
{
    int temp =0;
    for (int i = x; i < x+size; i++)
    {
        for (int j = y; j < y+size;j++){
            if(map[i][j]){
                temp++;
            }
        }
    }
    if(!temp)
        w++;
    else if(temp==size*size)
        b++;
    else{
        dcon(x, y, size / 2);
        dcon(x, y + size / 2, size / 2);
        dcon(x + size / 2, y, size / 2);
        dcon(x + size / 2, y + size / 2, size / 2);
    }
    
}

int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> map[i][j];
        }
    }
    dcon(0, 0, n);
    cout << w << endl;
    cout << b << endl;
    return 0;
}