//못풀었음 솔루션 검색

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
    if(a.size()!=b.size())
        return a.size() < b.size();
    else
        return a < b;
}

int main(){
    int n;
    cin >> n;
    vector<string> word;
    string a;
    for (int i = 0; i < n; i++){
        cin >> a;
        word.push_back(a);
    }
    string temp;

    sort(word.begin(), word.end(), compare);

    for (int i = 0; i < word.size(); i++){
        if(temp == word[i])
            continue;
        cout << word[i] << endl;
        temp = word[i];
    }

        return 0;
}