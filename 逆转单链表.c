/*
题目：要求逆置单链表
思路：利用上指针进行逆转
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)//reverse 逆转
{
	assert(head);
	struct ListNode *new_head = NULL, *cur;

	while (head)
	{
		cur = head->next;
		head->next = new_head;
		new_head = head;
		head = cur;
	}
	return new_head;
}

int main()
{
	 
	system("pause");
	return 0;
}
