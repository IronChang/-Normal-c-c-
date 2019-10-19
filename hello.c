/*************************************************************************
	> File Name: hello.c
	> Author: TianChang
	> Mail: 408662026@qq.com 
	> Created Time: 2019年10月19日 星期六 19时02分28秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
   //int fp = open("hello.txt",O_WRONLY | O_CREAT,0644);
   ////以只写的方式打开，并且如果文件不存在则创建文件
	int fp = open("hello.txt",O_RDONLY);
	if(fp < 0)
	{
		perror("open error:");
		return -1;
	}

	//int count = 5;
	const char *msg = "hello ufe!\n";
	char buff[1024];
	int len = strlen(msg);
	
	//while(count--)
	//{
		//write(fp,msg,len);
	//}
	while(1)
	{
		ssize_t s = read(fp,buff,len);
		if(s > 0)
		{
			printf("%s",buff);
		}
		else if(s < 0)
		{
			perror("read error:");
			close(fp);
			return -1;
		}
		else
		{
			printf("读取到文件末尾：%d\n",s);
			close(fp);
			return ;
		}
	}

	close(fp);
	return 0;
}

