#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class kupac
{
public:
	vector<int> t;

	kupac()
	{
		t.push_back(0);
	}
	~kupac()
	{
	}
	int size()
	{
		return t.size() - 1;
	}
	int peek()
	{
		return t[1];
	}
	void push(int e)
	{
		t.push_back(e);
		fellebegtet(size());
	}

	void repair(int e)
	{
		int i = keres(1, e);
		megigazit(i);
	}

	void diagnosztika()
	{
		for (int i = t.size() - 1; 0 <= i; i--)
		{
			int j = i;
			while (j != 0)
			{
				cout << "t[" << j << "] : " << t[j] << endl;
				j = szulo(j);
			}
			cout << "lanc vege\n";
		}
	}

	int pop()
	{
		int result = peek();
		csere(1, size());
		t.erase(t.end() - 1);

		sullyeszt(1);

		return result;
	}
private:
	int szulo(int n)
	{
		return n / 2;
	}
	int kisebbik_gyerek(int n)
	{
		int egyik = n * 2;
		int masik = egyik + 1;
		if (size() < egyik)
			return -1;
		if (size() < masik)
			return egyik;
		return t[egyik] < t[masik] ? egyik : masik;
	}
	int nagyobbik_gyerek(int n)
	{
		int egyik = n * 2;
		int masik = egyik + 1;
		if (size() < egyik)
			return -1;
		if (size() < masik)
			return egyik;
		return t[egyik] > t[masik] ? egyik : masik;
	}
	void fellebegtet(int n)
	{
		while (t[szulo(n)] > t[n])
		{
			csere(n, szulo(n));
			n = szulo(n);
		}
	}
	void sullyeszt(int n)
	{
		int kgy = kisebbik_gyerek(n);
		if (kgy == -1)
		{
			return;
		}
		if (t[kgy] < t[n])
		{
			csere(kgy, n);
			sullyeszt(kgy);
		}
	}
	void csere(int i, int j)
	{
		int i_elem = t[i];
		int j_elem = t[j];
		t[i] = j_elem;
		t[j] = i_elem;
	}
	void megigazit(int n)
	{
		sullyeszt(n);
		fellebegtet(n);
	}
	int keres(int hol, int elem)
	{
		if (t[hol] == elem)
			return hol;
		int egyik = 2 * hol;
		if (size() < egyik)
			return -1;
		int az_eredmeny = keres(egyik, elem);
		if (az_eredmeny != -1)
			return az_eredmeny;
		int masik = 2 * hol + 1;
		if (size() < masik)
			return -1;
		az_eredmeny = keres(masik, elem);
		if (az_eredmeny != -1)
			return az_eredmeny;
		return -1;
	}
};


/**/
vector<vector<int>> feldolgozas(kupac k, int rudhossz) {
	/** /
	cout << k.size() << endl;
	int summa = k.pop() + k.pop();
	cout << "a summa: " << summa << endl;
	rudhossz -= summa;
	cout << "a rudhossz: " << rudhossz << endl;
	cout << "----------" << endl;
	/**/
	vector<vector<int>> v;
	int summa = 0;
	while (k.size() > 0)
	{
		vector<int> t;
		int rud = 0;
		if (k.size() == 1 || summa != 0)
		{
			rud = k.pop();
			t.push_back(summa + rud);
			t.push_back(rud);
		}
		else {
			int a = k.pop();
			int b = k.pop();
			rud = a + b;
			t.push_back(summa + rud);
			t.push_back(a);
		}
		summa += rud;
		/*
		t.push_back(summa);
		t.push_back(rud);
		*/

		v.push_back(t);
		// cout << "a vagott rud: " << rud << endl;
		// cout << "a summa: " << summa << endl;
		rudhossz -= rud;
		// cout << "a rudhossz: " << rudhossz << endl;
		// cout << "-------------" << endl;
	}

	// cout << summa << endl;
	// cout << rudhossz << endl;

	return v;
}
/**/

/**/
void kiiras(vector<vector<int>> v, int summa) {
	cout << summa << endl;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		vector<int> j = v[i];
		cout << j[0] << " " << j[1] << endl;
	}
	/** /
	for (auto& i : v)
	{
		cout << i[0] << " " << i[1] << endl;
	}
	/**/
}
/**/

int main()
{
	/**/
	// BEOLVASÁS
	int N;
	cin >> N;
	int rudhossz = 0;
	kupac k;
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

	/**/
}

/*

5
2 5 2 7 10

*/