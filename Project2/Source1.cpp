////2331
//#include <iostream>
//#include <cmath> // pow 사용 
//#include <vector>
//
//using namespace std;
//
//int A, P;
//vector<int> num, D;
//
//void makeNumber(int A, int P)
//{
//	num.clear();
//	int tmp = A;
//	while (tmp > 0)
//	{
//		if (tmp > 999)
//		{
//			num.push_back(tmp / 1000);
//			tmp = tmp % 1000;
//		}
//		else if (tmp > 99)
//		{
//			num.push_back(tmp / 100);
//			tmp = tmp % 100;
//		}
//		else if (tmp > 9)
//		{
//			num.push_back(tmp / 10);
//			tmp = tmp % 10;
//		}
//		else
//		{
//			num.push_back(tmp);
//			break;
//		}
//	}
//	return;
//}
//
////while (a)
////{
////	sum = sum + pow(a % 10, P); // 뒷자리부터 쪼갬.
////	a = a / 10;
////}
//
//// 입력값 범위 벗어나면 예외처리. return -1
//// cnt[]에 그 수를 방문하면 ++로 방문 처리.
//// 37, 37+
//
//void multiply()
//{
//	int res(0);
//	for (int i = 0; i < num.size(); i++)
//	{
//		res += pow(num[i], P); // pow 시 0이 들어오면 domain error 발생. 
//	}
//	D.push_back(res);
//}
//
//int main()
//{
//	cin >> A >> P;
//	int pt(-1), tmp(A); //pt(0)으로 두었었으나, 0번쨰가 1번째와 같은 경우에는 while을 빠져나오지 못하므로 문제가 됨.
//	D.push_back(A);
//	while (pt == -1)
//	{
//		makeNumber(tmp, P); // 숫자 쪼개서 배열에 하나씩 저장, p 필요없음
//		if(P != 0) //0은 입력이 아님
//			multiply(); // 제곱해서 더한 값을 D배열에 저장. 마지막에 있을것임
//		tmp = D.back();
//		for (int i = 0; i < D.size()-1; i++) // 마지막은 tmp이므로. 제외하고 겹치는 자리 있나 확인.
//		{
//			//cout << D[i] << " "; //마지막 이전꺼까지 출력되고, tmp랑 같은 숫자가 생긴 경우에는 같은자리지 출력이 됨.
//			if (tmp == D[i])
//			{
//				pt = i; //수열이 시작되는 위치 찾기
//				break;
//			}
//		}
//	}
//
//	cout << pt << endl; //0부터 시작이니, 수열 시작지점이 결국 수열 아닌 남는 갯수.
//	/*if (pt != 0)
//	else cout << pt + 1 << endl;*/
//
//	return 0;
//}
//
////dfs로 풀어야겟다.

#include <iostream>
#include <cmath>

int cnt[1000000]; // 최대 6자리
using namespace std;

void DFS(int a, int p)
{
	int sum(0);

	while (a)
	{
		sum += pow(a % 10, p);
		a = a / 10;
	}

	if (cnt[sum] < 2)
	{
		cnt[sum]++;
		DFS(sum, p);
	}
	
}

int main()
{
	int A, P, result(0);
	cin >> A >> P;


	cnt[A]++;

	DFS(A, P);

	for (int i = 0; i < 1000000; i++)
	{
		if (cnt[i] == 1) result++;
		//if (cnt[i] > 1) break; // 수열이기 떄문에 작은 숫자인데, 2를 만났다고 해서 나가면 안됨. 수열은 작은 순서대로 배열되어있지 않기 때문.
	}

	cout << result << endl;

	return 0;

}