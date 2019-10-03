void list_modifiers_4()
{
	//  resize/swap/clear��ϰ
	int arr[] = { 1, 2, 3 };
	list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(l1);

	//��l1��Ԫ�����ӵ�10�������Ԫ����Ĭ��ֵ���
	// (ע�⣺���list�з��õ����������ͣ�Ĭ��ֵΪ0, ���list�з����Զ�������Ԫ�أ�����ȱʡ���캯��)
	l1.resize(10);
	Print(l1);

	//��l1�е�Ԫ�����ӵ�20���������Ԫ����4�����
	l1.resize(20, 4);
	Print(l1);

	//��l1�е�Ԫ�ؼ��ٵ��������Ϊresize���Ըı�list���������б���vector�е�resize
	l1.resize(5, 100);//��ʼֵû����
	Print(l1);


	//�������е�Ԫ������ʼ������list
	vector<int> v{ 4, 5, 6 };
	list<int> l2(v.begin(), v.end());//��������ʼ��
	Print(l2);

	//��l2�е�Ԫ�����
	l2.clear();
	cout << l2.size() << endl;
}

void iterator_questions()
{
	//��Ϊlist�ĵײ�ԭ���Ǵ�ͷ˫��ѭ�����������ڲ���ʱ�ǲ��ᵼ��list�ĵ�����ʧЧ�ģ�ֻ����ɾ��ʱ�Ż�ʧЧ������ʧЧ��ֻ��ָ��ɾ���ڵ��������ָ�������ڵ�ĵ�������������ʧЧ��
	//������ʧЧ��������ָ��Ľڵ���Ч����ɾ����

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = L.begin();
	while (it != L.end())
	{
		//L.erase(it);
		//++it;//��ʱ�ᱨ����Ϊ�Ѿ�ɾ����it��ָ����ĸ��ڵ㣬��ʱit�Ѿ���Ч��������¸�ֵ���Ľ�����
		//it = L.begin();

		//L.erase(it++);
		//erase()y��Ϊ������ ɾ��һ���ڵ����ǰһ���ڵ�ͺ�ҡ���ڵ��������������ر�ɾ���ڵ�ĺ�һ���ڵ�ĵ�ַ������
		it = L.erase(it);
	}
}
