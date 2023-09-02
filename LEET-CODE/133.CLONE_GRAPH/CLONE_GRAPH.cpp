class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> m;
        queue<Node*> q;
        q.push(node);
        Node* FirstNode = new Node(node->val);
        m[node]=FirstNode;
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            for(auto i:curr->neighbors){
                if(m.find(i)==m.end()){
                    Node* temp=new Node(i->val);
                    m[i]=temp;
                    q.push(i);
                }
                m[curr]->neighbors.push_back(m[i]);
            }
        }
        return FirstNode;
        
        
    }
};