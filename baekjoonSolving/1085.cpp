#include<iostream>
using namespace std;

int main(){
    pair<int, int> now_location;
    pair<int, int> a;
    cin >> now_location.first >> now_location.second >> a.first >> a.second;
    int x_dis = a.first - now_location.first;
    x_dis = min(x_dis, now_location.first);

    int y_dis = a.second - now_location.second;
    y_dis = min(y_dis, now_location.second);

    cout << min(x_dis, y_dis);
}