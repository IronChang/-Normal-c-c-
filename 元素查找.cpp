/*
����������
����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx��
�뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣
���������ֲ��� 
*/
class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        // write code here
        int left = 0;
        int right = n-1;
        while(left<=right)
        {
            int mid = (left + right)/2;
            
            if(A[mid] == x)
                return mid;
            
            //[left,mid] [mid,right]
            if(A[left] < A[mid])
            {
                if(A[left] <= x && x<A[mid])
                {
                    right = mid -1;
                }
                else
                {
                    left = mid +1;
                }
            }
            else
            {
                if(A[mid] < x && x<=A[right])
                {
                    left = mid +1;
                }
                else
                {
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};
