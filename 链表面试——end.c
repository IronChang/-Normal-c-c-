/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

Node* BuyNode(int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->random = NULL;
    
    return node;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        // 1.拷贝插入节点
        while(cur)
        {
            Node* next = cur->next;
            Node* cpnode = BuyNode(cur->val);
            
            cur->next = cpnode;
            cpnode->next = next;
            
            // 迭代
            cur = next;
        }
        
        // 2.置random
        cur = head;
        while(cur)
        {
            Node* cpnode = cur->next;
            
            // 置random
            if(cur->random)
                cpnode->random = cur->random->next;
            
            // 迭代
            cur = cur->next->next;
        }
        
        // 3.拆解-重新链接
        Node* cphead = BuyNode(0);
        Node* cptail = cphead;
        
        cur = head;
        while(cur)
        {
            Node* cpnode = cur->next;
            Node* next = cur->next->next;
            
            // 拆解
            cur->next = next;
            
            // 链接
            cptail->next = cpnode;
            cptail = cpnode;
            
            // 迭代
            cur = next;
        }
        
        Node* cplist =  cphead->next;
        free(cphead);
        
        return cplist;
    }
};

