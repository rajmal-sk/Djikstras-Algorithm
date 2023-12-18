#ifndef _MY_DIJKSTRA_H_
#define _MY_DIJKSTRA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

typedef unsigned int NodeType;
typedef unsigned int WeightType;
typedef std::vector<std::vector<std::pair<NodeType, WeightType>>> GraphType; // graph as adjacent list

/*------------------------------------------------------------------------------
 ShortestPath_Dijkstra
  Find and print the shortest path from source to end using the Dijkstra's algorithm

 Vairables:
   - graph: the input graph
   - source: the source node
   - end: the target node
   - path_len: the the summation of weights of all edges in the shortest path
   - path: the shortest path represented as a list of nodes

------------------------------------------------------------------------------*/
void ShortestPath_Dijkstra(
    const GraphType &graph,
    const NodeType &source,
    const NodeType &end,
    WeightType &path_len,
    std::vector<NodeType> &path)
{
  if (source == end)
  {
    path_len = 0;
    path.push_back(source);
    return;
  }
  std::priority_queue<std::pair<WeightType, NodeType>, std::vector<std::pair<WeightType, NodeType>>, std::greater<std::pair<WeightType, NodeType>>> pq;
  int graph_size = graph.size();
  std::vector<WeightType> dist(graph_size, 1e9);
  std::vector<NodeType> parent(graph_size);
  for (int i = 0; i < graph_size; i++)
  {
    parent[i] = i;
  }

  dist[source] = 0;
  pq.push({dist[source], source});

  while (!pq.empty())
  {
    std::pair<WeightType, NodeType> top_element = pq.top();
    WeightType dist_from_src = top_element.first;
    NodeType current_node = top_element.second;
    pq.pop();

    for (auto itr : graph[current_node])
    {
      NodeType adj_node = itr.first;
      WeightType edge_weight = itr.second;

      if ((dist_from_src + edge_weight) < dist[adj_node])
      {
        dist[adj_node] = dist_from_src + edge_weight;
        pq.push({dist[adj_node], adj_node});
        parent[adj_node] = current_node;
      }
    }
  }

  // No path to the destination node
  if (dist[end] == 1e9)
  {
    return;
  }

  NodeType node = end;
  path_len = dist[end];

  // Retrieve the path traversed
  while (parent[node] != node)
  {
    path.push_back(node);
    node = parent[node];
  }
  path.push_back(node);

  std::reverse(path.begin(), path.end());
}

#endif
