typedef struct Node {
	int val;
	struct Node *next;
}	Node;	// ����Ľ��

Node * pushFront(Node *head, int val) {
	// head ��ʾ����ĵ�һ����㣬����Ϊ NULL
	// 1. �Ȱ� val װ�������
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// 2. node Ӧ�ó��µĵ�һ����㣬����ԭ���ĵ�һ�����
	// Ӧ���� node ����һ�����
	node->next = head;
	// 3. ֪ͨ�����ĵ����ߣ�����ĵ�һ������Ѿ���������
	// ��ԭ���� head ����� node
	return node;
}

Node * pushBack(Node *head, int val) {
	// �Ȱ� val װ���
	Node * node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// ��Ϊ node ��Ȼ�����һ����㣬����������һ���� NULL
	node->next = NULL;
	// ����������������Ϊ��
	if (head != NULL) {
		// ���ҵ���ǰ�����һ�����
		Node *last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		// last ָ����������һ�����
		// �� node ��Ϊ���һ�����
		// Ҳ������ node ��Ϊ last ����һ�����
		last->next = node;
		// ����ĵ�һ�����û�б仯
		return head;
	}
	else {
		// ����Ϊ�յ������node �ǲ����������Ψһ�Ľ��
		// node Ҳ���ǵ�һ�����
		return node;
	}
}

// ��ת����
Node * reverseList(Node *head) {
	// ������ǰ��������ͷ�嵽��������
	Node *rHead = NULL;
	// ����
	Node *cur = head;
	while (cur != NULL) {
		// �ȼ�¼ԭ������һ�����
		Node *next = cur->next;
		// �� cur ͷ�嵽 rHead ��
		cur->next = rHead;
		rHead = cur;
		// �� cur �ߵ���һ�������
		cur = next;
	}

	return rHead;
}

// ��ɾ�����˵�һ�����������к� val �Ľ��
// ���ȥ�����һ�����
Node * removeAll(Node *head, int val) {
	if (head == NULL) {
		return NULL;
	}
	// ����� head ���������ˣ����Ա��뱣֤ head ��Ϊ NULL
	Node *cur = head->next;	// ����������ָ�룬�ж��Ƿ���� val
	Node *prev = head;	// ��Զָ�� cur ��ǰһ����㣬����ɾ�� cur ���

	while (cur != NULL) {
		if (cur->val == val) {
			// ��Ҫɾ�� cur ���
			prev->next = cur->next;
			// ���������ɾ����prev ����Ҫ�仯����Ϊ prev ���� �仯�� cur ��ǰ��
		}
		else {
			// ���û��ɾ��, prev �� cur һ��������
			prev = cur;
		}

		cur = cur->next;
	}

	if (head->val == val) {
		head = head->next;
	}

	return head;
}

// �ϲ�������������
// ����ȥ���������бȽϣ�ѡ���С�Ľ�㣬β�嵽��������
Node * mergeOrderedList(Node *head1, Node *head2) {
	if (head1 == NULL) {
		return head2;
	}

	if (head2 == NULL) {
		return head1;
	}

	Node *cur1 = head1;
	Node *cur2 = head2;

	Node *rHead = NULL;		// ������ĵ�һ�����
	Node *last = NULL;		// ����������һ�����

	// ��֤���������ж����н�㣬�űȽ�˭��˭С
	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->val <= cur2->val) {
			// �� cur1 β�嵽������
			Node *next = cur1->next;
			// cur1 ����β�嵽���������� cur1 ����һ��Ӧ���� NULL
			cur1->next = NULL;
			// β����Ҫ���������
			if (rHead == NULL) {
				rHead = cur1;
			}
			else {
				last->next = cur1;
			}
			// ��������������һ�����
			last = cur1;

			// �� cur1 ָ���һ���������һ�����
			cur1 = next;
		}
		else {
			// �� cur2 β�嵽������
			Node *next = cur2->next;
			cur2->next = NULL;
			// β����Ҫ���������
			if (rHead == NULL) {
				rHead = cur2;
			}
			else {
				last->next = cur2;
			}
			// ��������������һ�����
			last = cur2;

			// �� cur2 ָ��ڶ����������һ�����
			cur2 = next;
		}
	}

	if (cur1 != NULL) {
		last->next = cur1;
	}
	else {
		last->next = cur2;
	}

	return rHead;
}



Node * partition(Node *head, int x) {
	// ���� head �������������ÿ������ֵ�� x ���бȽ�
	// ���С�� x��β�嵽һ��С�� x ��������
	// ������ڵ��� x��β�嵽һ�����ڵ��� x ��������

	// �ȶ����������������� С�� x �� ���ڵ��� x ������
	Node * small = NULL;	// С�� x ������
	Node * smallLast = NULL;	// С�� x ����������һ�����
	Node * big = NULL;		// ���ڵ��� x ������
	Node * bigLast = NULL;		// ���ڵ��� x ����������һ�����

	// ͨ�� cur ������ԭ�����ÿ�����
	Node * cur = head;
	while (cur != NULL) {
		if (cur->val < x) {
			// �� cur β�嵽 small ��

			/*
			�� cur ����һ����Ϊ NULL
			cur->next = NULL;
			���������
			��� small ���ڵ������ǿ�����			
			if (small == NULL)			
				��ʵҲ���ǰ� cur ͷ�嵽 small ��������
				�� small ָ�� cur ��ǰָ��Ľ��			
				small = cur;		
			��� small ���ڵ������ǿ�����
				���ҵ� small �����е����һ�����
				1���ӵ�һ��������һֱ�ҵ����ȥ
				2����Ϊ֮ǰ�����һ����������ǲ���ģ��������Ǽ�¼һ�¼���	��ѡ��
					smallLast		
				�� smallLast ����һ������� cur
				smallLast->next = cur;
			��¼�µ����һ�������˭���ղ�����β����Ǹ���� cur
				smallLast = cur;
			����µ����һ�������˭��֮ǰ���һ��������һ�����
				smallLast = smallLast->next;
			�� cur ָ��ԭ�������һ�����
			cur = cur->next;
			Node *next = cur->next;
			β��
			cur = next;
			*/

			Node *next = cur->next;

			cur->next = NULL;
			if (small == NULL) {
				small = cur;
			}
			else {
				smallLast->next = cur;
			}
			smallLast = cur;

			cur = next;

		}
		else {
			// �� cur β�嵽 big ��



			Node *next = cur->next;

			cur->next = NULL;
			if (big == NULL) {
				big = cur;
			}
			else {
				bigLast->next = cur;
			}
			bigLast = cur;

			cur = next;
		}
	}

	// ע�⣺һ��Ҫ��֤������������һ��������һ���� NULL

	// ���û�� < x ��������ô�죿
	if (small == NULL) {
		return big;
	}
	else {
		smallLast->next = big;
		return small;
	}
}

Node * findKthToTail(Node *head, int k) {
	int count = 0;
	for (Node *cur = head; cur != NULL; cur = cur->next) {
		count++;
	}

	if (count < k) {
		return NULL;
	}

	Node *p = head;
	for (int i = 0; i < count - k; i++) {
		p = p->next;
	}

	return p;
}

struct ListNode* middleNode(struct ListNode* head){
	int count = 0;
	for (struct ListNode *cur = head; cur != NULL; cur = cur->next) {
		count++;
	}

	struct ListNode * p = head;
	for (int i = 0; i < count / 2; i++) {
		p = p->next;
	}

	return p;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode *front = pListHead;
	ListNode *back = pListHead;

	//
	for (int i = 0; i < k; i++) {
		if (front == NULL) {
			return NULL;
		}
		front = front->next;
	}

	// front == NULL ��ʾ�����Ⱦ��� k ��
	while (front != NULL) {
		front = front->next;
		back = back->next;
	}

	return back;
}

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}
	ListNode * node = (ListNode *)malloc(sizeof(ListNode));
	node->next = pHead;

	ListNode *prev = node;		// ǰ��
	ListNode *p1 = pHead;		// ��ɫ
	ListNode *p2 = pHead->next;	// ��ɫ
	// ��Զ�Ƚϵ� p1 �� p2 �� val

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else {
			// ֱ�� p2 �ߵ�β ���� �����
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}

			// ɾ�� [p1, p2) �����н��
			prev->next = p2;

			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;
			}
		}
	}

	return node->next;
}


ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *prev = NULL;		// ǰ��
	ListNode *p1 = pHead;		// ��ɫ
	ListNode *p2 = pHead->next;	// ��ɫ
	// ��Զ�Ƚϵ� p1 �� p2 �� val
	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else {
			// ֱ�� p2 �ߵ�β ���� �����
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			// ɾ�� [p1, p2) �����н��
			if (prev != NULL) {
				prev->next = p2;
			}
			else {
				pHead = p2;
			}
			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;
			}
		}
	}

	return pHead;
}