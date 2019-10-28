
public class main {

	public static void main(String[] args) 
	{
	     array A = new array();
		A.push_front(0);
		A.push_front(1);
		A.push_front(2);
		A.push_front(3);
		A.push_front(4);		
		A.show();
		A.top();
		A.pop();
		A.show();
		System.out.println("栈的空间大小:"+A.getcapacity());
	}

}
