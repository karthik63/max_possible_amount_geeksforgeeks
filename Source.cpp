#include<iostream>
#include<algorithm>

using namespace std;

pair<int,int> findwin(int coins[101], int front, int back, int player, pair<int,int> dp[101][101])
{
	if (front > back)
		return make_pair(0,0);

	if (front == back)
		return make_pair(coins[front], 0);

	if (dp[front][back] != make_pair(-1, -1))
		return dp[front][back];

	pair<int, int> ans1, ans2, ans3, ans4;

	ans1 = findwin(coins, front + 1, back, abs(player - 1), dp);

	ans2 = findwin(coins, front, back - 1, abs(player - 1), dp);

	if (coins[front] + ans1.second > coins[back] + ans2.second)
	{
		dp[front][back] = make_pair(coins[front] + ans1.second, ans1.first);
		return make_pair(coins[front] + ans1.second, ans1.first);
	}
	else
	{
		dp[front][back] = make_pair(coins[back] + ans2.second, ans2.first);
		return make_pair(coins[back] + ans2.second, ans2.first);
	}
}

int main()
{
	register int t;
	cin >> t;
	while (t--)
	{
		int n; pair<int, int> ans;
		register int i, j;

		pair<int, int> dp[101][101];

		for (i = 0; i < 101; i++)
			for (j = 0; j < 101; j++)
				dp[i][j] = { -1,-1 };

		cin >> n; int coins[101];

		for (i = 0; i < n; i++)
			cin >> coins[i];

		ans = findwin(coins, 0, n - 1, 1, dp);

		cout << ans.first << endl;
	}
}