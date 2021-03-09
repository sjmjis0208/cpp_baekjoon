#include <iostream>
using namespace std;

int roomNum(int h, int w, int n){
    int floor = 1;
    int room = 1;
    int count = 1;
    for (int i = 1; i <= w; i++)
    {
        room = i;
        for (int j = 1; j <= h; j++)
        {
            floor = j;
            if(count == n){
                int result = floor * 100 + room;
                return result;
            }
            count++;

        }
    }
}

int main(){
    int t;
    int h, w, n;
    cin >> t;
    int *result = new int[t];
    for (int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;
        result[i] = roomNum(h, w, n);

    }
    for (int j = 0; j < t;j++){
        cout << result[j] << endl;
    }

        return 0;
}