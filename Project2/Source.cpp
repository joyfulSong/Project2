//1260
#include <iostream>
#include <array>
#include <queue>

using namespace std;

int N, M, V;  //minN(1000);
int map[1001][1001], check1[1001], check2[1001]; //res;
queue<int> Q[1001]; // local로 둘 수 있다. 

void DFS(int n)
{
	//if (n == N) // 바로 마지막 노드 순번에 도달해버리면 끝나버림.
	//{
	//	return;
	//}

	/*else
	{*/
		//for (int i = minN; i < N + 1; i++) //현재 노드를 기점으로 넘어갈 수 있는 모든 노드에 대해, 단 작은 노드부터.
			//어차피 검사하면 되니깐 최솟값 구하는 함수 통과할 필요 없다.
		for (int i = 1; i < N + 1; i++)
		{
			//cout << map[n][i] << " " << check1[i] << std::endl;
			if (map[n][i] == 1 && check1[i] == 0)
			{
				check1[i] = 1;
				//res.push_back(i); //도착했을 때 출력해버리면 됨.
				cout << i << " ";
				DFS(i);
				//check[n][i] = 0; // 최단거리를 구할 때, 스택을 푸는게 필요한거라면 지금은 필요 없겠다. 지금은 마지막 노드까지 계속 쌓기만 함
			}
		}
	//}
}

void BFS()
{
	int cnt(1);
	while (!Q->empty())// || cnt != N)
	{
		int a = Q->front();
		Q->pop();

		//for (int i = minN; i < N + 1; i++)
		for (int i = 1; i < N + 1; i++)
		{
			if (map[a][i] == 1 && check2[i] == 0) //check[i]로만 둬도 되는구나. 어디에서 어디로 갔냐 가 아니라, 그 노드에 갔냐. 
			{
				check2[i] = 1;
				//res.push_back(i);
				cout << i << " ";
				cnt++;
				if (cnt == N) break;
				Q->push(i);
			}
		}
	}
	return;
}

//int Min(int a, int b, int min)
//{
//	int tmp1, tmp2;
//	if (a > b) tmp1 = b;
//	else tmp1 = a;
//	if (tmp1 > min) tmp2 = min;
//	else tmp2 = tmp1;
//	return tmp2;
//}

int main()
{
	cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
		//minN = Min(a, b, minN);
	}

	//res.push_back(V);
	cout << V << " ";
	check1[V] = 1;
	DFS(V);
	cout << std::endl;
	/*for (int i = minN; i < N + 1; i++)
	{
		cout << res[i] << " " << endl;
	}
	res.clear();*/

	//res.push_back(V);
	cout << V << " ";
	check2[V] = 1;
	Q->push(V);
	BFS();
	/*for (int i = minN; i < N + 1; i++)
	{
		cout << res[i] << " " << endl;
	}
	res.clear();*/
	return 0;
}