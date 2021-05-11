/*
 * @Author: your name
 * @Date: 2021-04-27 20:38:40
 * @LastEditTime: 2021-04-27 20:45:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Editu
 * @FilePath: /wenjx/c-/graph/graph.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct GraphNode
{
  int val;
  vector<GraphNode *> neighbour;
  GraphNode(int x) : val(x) {}
};

//最终需要一个顶点-下标的映射,通过这样找到具体下标
void dfs_graph(GraphNode *graph, vector<bool> &isvisit)
{
  isvisit[graph->val] = true;
  cout << graph->val << " ";
  for (int i = 0; i < graph->neighbour.size(); i++)
  {
    if (!isvisit[graph->neighbour[i]->val])
    {
      dfs_graph(graph->neighbour[i], isvisit);
    }
  }
}

//图的 宽搜
void bfs_graph(GraphNode *node, vector<bool> &isvisit)
{
  queue<GraphNode *> graphQue;
  graphQue.push(node);
  isvisit[node->val]=true;

  while (!graphQue.empty()) {
    auto node = graphQue.front();
    graphQue.pop();
    cout<<node->val<<" ";
    for(int i=0;i<node->neighbour.size();++i) {
      if (!isvisit[node->neighbour[i]->val]) {
              graphQue.push(node->neighbour[i]);
              isvisit[node->neighbour[i]->val]=true;
      }
        
    }
  }
}

//图的dfs
void test01()
{
  vector<int> nums{0, 1, 2, 3, 4};
  vector<GraphNode *> vec_graph(nums.size());
  for (int i = 0; i < nums.size(); i++)
  {
    vec_graph[i] = new GraphNode(nums[i]);
  }

  vec_graph[0]->neighbour.push_back(vec_graph[2]);
  vec_graph[0]->neighbour.push_back(vec_graph[4]);

  vec_graph[1]->neighbour.push_back(vec_graph[0]);
  vec_graph[1]->neighbour.push_back(vec_graph[2]);

  vec_graph[2]->neighbour.push_back(vec_graph[3]);
  vec_graph[3]->neighbour.push_back(vec_graph[4]);
  vec_graph[4]->neighbour.push_back(vec_graph[3]);

  vector<bool> isvisit(5, false);
  for (int i = 0; i < 5; i++)
  {
    if (!isvisit[i])
    {
      cout << vec_graph[i]->val << ":";
      dfs_graph(vec_graph[i], isvisit);
      cout << endl;
    }
  }
}

void test02()
{
  vector<int> nums{0, 1, 2, 3, 4};
  vector<GraphNode *> vec_graph(nums.size());
  for (int i = 0; i < nums.size(); i++)
  {
    vec_graph[i] = new GraphNode(nums[i]);
  }

  vec_graph[0]->neighbour.push_back(vec_graph[2]);
  vec_graph[0]->neighbour.push_back(vec_graph[4]);

  vec_graph[1]->neighbour.push_back(vec_graph[0]);
  vec_graph[1]->neighbour.push_back(vec_graph[2]);

  vec_graph[2]->neighbour.push_back(vec_graph[3]);
  vec_graph[3]->neighbour.push_back(vec_graph[4]);
  vec_graph[4]->neighbour.push_back(vec_graph[3]);

  vector<bool> isvisit(5, false);

  for (int i = 0; i < 5; i++)
  {
    if (!isvisit[i])
    {
      cout << "from "<<vec_graph[i]->val << ":";
      bfs_graph(vec_graph[i], isvisit);
      cout << endl;
    }
  }
}

int main()
{
  //test01();

  test02();
}