/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*,Node*>& vis){
        if(node == nullptr){
            return nullptr;
        }

        if(vis.find(node) != vis.end()){
            return vis[node];
        }

        //create clone node
        Node* clone_node = new Node(node->val);

        vis[node] = clone_node;
        for(auto neigh: node->neighbors){
            Node* clone_neighbor = dfs(neigh, vis);
            clone_node->neighbors.push_back(clone_neighbor);
        }
        return clone_node;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> f;
        return dfs(node, f);
    }
};