#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol235;

/*
   3
   / \
  9  20
    /  \
   15   7

[
  [3],
  [9,20],
  [15,7]
]
*/

tuple<Node *, vector<vector<int>>>
testFixture1()
{
  auto root = new Node(3);
  root->left = new Node(9);
  root->right = new Node(20);
  root->right->left = new Node(15);
  root->right->right = new Node(7);

  auto output = vector<vector<int>>{{3},
                                    {9, 20},
                                    {15, 7}};

  return {root, output};
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  cout << Util::toString(sol.levelOrder(get<0>(f))) << endl;
}

main()
{
  test1();
}