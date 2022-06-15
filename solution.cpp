#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace sol235;
using namespace std;

/*takeaways

*/

vector<vector<int>> Solution::levelOrder(Node *root)
{
  auto result = vector<vector<int>>();

  /* server as a queue mechanism */
  vector<Node *> curL, nextL;
  curL.push_back(root);
  while (!curL.empty())
  {
    result.push_back({});
    /* pick up node value and collect nodes from the next level */
    for (auto *n : curL)
    {
      result.back().push_back(n->val);
      if (n->left != nullptr)
        nextL.push_back(n->left);
      if (n->right != nullptr)
        nextL.push_back(n->right);
    }

    swap(curL, nextL);
    nextL.clear();
  }

  return result;
}