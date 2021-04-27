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

using namespace std;

struct GraphNode{
  int val;
vector<GraphNode*> neighbour;
  GraphNode(int x):val(x){}  
};

/**
 * @description: 
 * @param {vector<int>} nums
 * @return {*}
 */
GraphNode * makeGraph(vector<int> nums) {
    vector<GraphNode *> vec_graph(nums.size());
    for(int i=0;i<nums.size();i++) {
        vec_graph[i]=new Graph(nums[i]);
    }

    vec_graph[0]->neighbour.push_back(vec_graph[2]);
    vec_graph[0]->neighbour.push_back(vec_graph[4]);

    vec_graph[1]->neighbour.push_back(vec_graph[0]);
    vec_graph[1]->neighbour.push_back(vec_graph[2]);

    vec_graph[2]->neighbour.push_back(vec_graph[3]);
    vec_graph[3]->neighbour.push_back(vec_graph[4]);
    vec_graph[4]->neighbour.push_back(vec_grapj[3]);

    return vec_graph.front();
}
void dfs(GraphNode* graph) {
    
}

int main()
{

}