#include<iostream>
#include<stack>
using namespace std;

stack<int> A, B, C;

void print_sequense(stack<int>& from, stack<int>& to) {
	int f, t;
	if (from == A) { f = 1; }
	else if (from == B) f = 2;
	else f = 3;

	if (to == A) t = 1;
	else if (to == B)t = 2;
	else t = 3;
	cout << f << " " << t << "\n";
}

void hanoi(stack<int>& from, stack<int>& to, stack<int>& other, int n, int count) {
	if (n == 1) {
		to.push(from.top());
		from.pop();
		
		//cout << count << '\n';
		//if (from.empty() && other.empty())cout << count << '\n';
		print_sequense(from, to);
		return;
	}
	else {
		hanoi(from, other, to, n - 1, ++count);
		if (!from.empty()) {
			to.push(from.top());
			from.pop();
			print_sequense(from, to);
			hanoi(other, to, from, n - 1, ++count);
			
		}
		}
	
}
	
	

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		A.push(num - i);
	}
	//cout << C.top();

	hanoi(A, C, B, num, 1);
}