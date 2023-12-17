#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> feldolgozas(priority_queue<int, vector<int>, greater<int>> k, int rudhossz) {
	
	vector<vector<int>> v;
	int summa = 0;

	while (k.size() > 1)
	{
		vector<int> t;
		int rud = 0;

		int a = k.top();
		k.pop();
		int b = k.top();
		k.pop();
		rud = a + b;
		t.push_back(rud);
		t.push_back(a);
		t.push_back(b);

		k.push(rud);

		summa += rud;

		v.push_back(t);
		rudhossz -= rud;
	}


	return v;
}

void kiiras(vector<vector<int>> v, int summa) {
	cout << summa << endl;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		vector<int> j = v[i];
		cout << j[0] << " " << j[1] << endl;
	}
}


int main()
{
	// BEOLVASÁS
	int N;
	cin >> N;
	int rudhossz = 0;
	priority_queue<int, vector<int>, greater<int>> k;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		k.push(temp);
		rudhossz += temp;
	}

	// FELDOLGOZÁS
	vector<vector<int>> v = feldolgozas(k, rudhossz);

	int summa = 0;
	for (auto& i : v)
	{
		summa += i[0];
	}

	kiiras(v, summa);
}

/*

5
2 5 2 7 10

*/