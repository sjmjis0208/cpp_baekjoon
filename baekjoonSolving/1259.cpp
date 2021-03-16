#include<iostream>
#include<vector>
using namespace std;

int main(){
    string temp;
    vector<string> a;
    int cnt = 0;
    while (true)
    {
        getline(cin, temp);
        if(temp =="0")
            break;
        a.push_back(temp);
        cnt++;
    }
    for (int i = 0; i < cnt;i++){
        
        cout << *(a[i].begin()+2)<<endl;
    }
        return 0;
}