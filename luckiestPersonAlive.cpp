/*
 * Kristina Kolibab
 */

#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int> v)
{
	for(auto x : v) cout << x << " ";
	cout << endl;
}

int luckiest_soldier_alive(int t)
{
	vector<int> soldiers;
	for(int i = 1; i <= t; i++) soldiers.push_back(i);
	vector<int> temp;
	displayVector(soldiers);
	while(soldiers.size() != 1)
	{
		temp = soldiers;
		vector<int>::iterator it = temp.begin();
		while(it != temp.end()) 
		{
			it = temp.erase(++it);
			displayVector(temp);	
			if(next(it) == temp.end()) 
			{
				temp.insert(temp.begin(), *it);
				temp.pop_back();
				break;
			}
		}
		soldiers = temp;
	}
	return soldiers[0];
}

int main()
{
	int t1 = 5, t2 = 10;
	cout << luckiest_soldier_alive(t2) << endl;

	return 0;
}
