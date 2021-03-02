#include <iostream>
using namespace std;
string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"};
string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"};

string board[50];

int count(int a, int b){
    int cnt_1 = 0;
    int cnt_2 = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++){
            if(BW[i][j] != board[i+a][j+b])
                cnt_1++;
            if (WB[i][j] != board[i + a][j + b])
                cnt_2++;
        }
    }
    //return min(cnt_1, cnt_2);
    return (cnt_1 <= cnt_2) ? cnt_1 : cnt_2;
}

int main()
{
    int cnt;
    pair<int, int> p1;
    int min_val = 99999;
    int temp;
    cin >> p1.first >> p1.second;
    for (int i = 0; i < p1.first;i++){
        cin >> board[i];
    }
    for (int x = 0; x+8 <= p1.first;x++){
        for (int y = 0; y+8 <= p1.second;y++){
            temp = count(x, y);
            min_val = (min_val <= temp) ? min_val : temp;
        }
    }
    cout << min_val<<endl;
}