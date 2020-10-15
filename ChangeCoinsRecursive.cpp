#include <bits/stdc++.h>

using namespace std;

bool ready[1000];
int value[1000];
vector<int> coins;

int solve(int x) {
  if (x < 0) return 999;
  if (x == 0) return 0;
  if (ready[x]) return value[x];
  int best = 999;
  for (auto c : coins) {
    best = min(best, solve(x-c) + 1);
  }
  ready[x] = true;
  value[x] = best;
  return best;
}

int main(void) {

  int n = 12;
  coins.resize(3);
  coins[0] = 1;
  coins[1] = 3;
  coins[2] = 4;
  for (int i = 0; i <= 10; ++i)
    cout << solve(i) << "\n";

  return 0;
}
