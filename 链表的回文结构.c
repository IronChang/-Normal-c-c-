struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
	ListNode *new_head = NULL, *next;
	while (head)
	{
		next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
	}
	return new_head;
}

bool chkPalindrome(ListNode* A)
{
	ListNode *slow = A,*fast = A;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	} 
	
	ListNode* leftList = A;
	ListNode* rightList = slow->next;
	slow->next = NULL;
	
	//逆置右半段链表
	rightList =  reverseList(rightList);
	
	//进行比较 
	while(rightList != NULL)
	{
		if(leftList->val != rightList->val)
		{
			return false;
		}
		else
		{
			leftList = leftList->next;
			rightList = rightList->next; 
		}
		
		return true;
	}
} 
