/*************************************************************************
	> File Name: fd.c
	> Author: TianChang
	> Mail: 408662026@qq.com 
	> Created Time: 2019年10月19日 星期六 19时31分55秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
    //char buff[1024];
	//ssize_t s = read(0,buff,sizeof(buff));
	//close(0);
	close(2);
	int fd = open("hello.txt",O_RDONLY);
	if(fd < 0)
	{
		perror("open error:");
		close(fd);
		return -1;
	}
	printf("fd；%d\n",fd);
//	if(s > 0)
//	{
//		buff[s] = 0;
//		write(1,buff,strlen(buff));
//		write(1,buff,strlen(buff));
//	}
	close(fd);
	return 0;
}
