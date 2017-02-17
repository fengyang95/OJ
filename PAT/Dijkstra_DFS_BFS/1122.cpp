/*1122. Hamiltonian Cycle (25)*/
#include <iostream>
#include <vector>
using namespace std;

int v[201][201] = { 0 };

int main(){
	int n,m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i){
		cin >> a >> b;

		v[a][b] = v[b][a] = 1;
	}

	int num_query;
	cin >> num_query;
	vector<int> ret(num_query,1);
	for (int i = 0; i < num_query; ++i){
		int k;
		cin >> k;
		vector<int> t(k);
		vector<bool> visit(n+1, false);
		for (int j = 0; j < k; ++j){
			cin >> t[j];
		}

		for (int j = 0; j < k - 1; ++j){
			visit[t[j]] = true;
			if (v[t[j]][t[j + 1]] != 1){
				ret[i] = 0;
				break;
			}
		}

		for (int j = 1; j <= n; ++j){
			if (!visit[j]){
				ret[i] = 0;
				break;
			}
		}
		if (k != n + 1 || t.front() != t.back())
			ret[i] = 0;
	}

	for (int i = 0; i < num_query; ++i){
		if (ret[i] == 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}