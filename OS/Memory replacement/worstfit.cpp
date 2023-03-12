
#include <bits/stdc++.h>
using namespace std;

void NextFit(int blockSize[], int m, int processSize[], int n)
{
	
	int allocation[10], j = 0;

	
	memset(allocation, -1, sizeof(allocation));

	for (int i = 0; i < n; i++) {

		while (j < m) {

			if (blockSize[j] >= processSize[i]) {

				allocation[i] = j;

				blockSize[j] -= processSize[i];

				break;
			}

			j = (j + 1) % m;
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++) {
		cout << " " << i + 1 << "\t\t" << processSize[i]
			<< "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

int main()
{
	int blockSize[] = {  10, 20 ,30 };
	int processSize[] = { 10, 30 , 20 };
	int m = sizeof(blockSize) / sizeof(blockSize[0]);
	int n = sizeof(processSize) / sizeof(processSize[0]);

	NextFit(blockSize, m, processSize, n);

	return 0;
}
