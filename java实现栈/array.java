
public class array {
	private int[] data;
	private int size;
	
	//@SuppressWarnings("unchecked")
	public array(int capacity)//构造函数
	{
		data = new int[capacity];
		size = 0;
	}
	
	public array()
	{
		data = new int[10];
		size = 0;
	}
	
	public int getcapacity()
	{
		return data.length;
	}
	
	public void add(int index,int e)//头部插入
	{
		if(index < 0 || index > size)
		{
			
		}
		
		if(size == data.length)
		{
			resize(2*data.length);
		}
		
		for(int i = size-1;i>=index;i--)
		{
			data[i+1] = data[i];
		}
		
		data[index]=e;
		size++;	
	}
	
	public void push_front(int e)
	{
		add(0,e);
	}
	
	public void resize(int newcapacity)
	{
		int newdata[] = new int[newcapacity];
		for(int i=0;i<size;i++) {
			newdata[i]=data[i];
			data = newdata;
		}
	}
	
	public void show()
	{
		System.out.print("当前栈中元素:");
		for(int i = 0;i<size;i++)
		{
			System.out.print(data[i] + " ");
		}
		System.out.print("\n");
	}
	
	public void top()
	{
		System.out.print("当前栈顶元素为:");
		System.out.println(data[0]);
	}
	
	public void pop()
	{
		for(int i = 0;i<size;i++)
		{
			data[i] = data[i+1];
		}
		--size;
	}
	
	
}





