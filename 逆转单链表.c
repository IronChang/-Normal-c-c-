/*
��Ŀ��Ҫ�����õ�����
˼·��������ָ�������ת
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)//reverse ��ת
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
