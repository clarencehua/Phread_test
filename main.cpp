#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>
#include<string.h>
#include<string>
/* 声明结构体 */
struct member
{
    int num;
    char *name;
};

/* 定义线程pthread */
static void * pthread(void *arg)
{
    struct member *temp;

    /* 线程pthread开始运行 */
    printf("pthread start!\n");

    /* 令主线程继续执行 */
    sleep(2);

    /* 打印传入参数 */
    temp = (struct member *)arg;
    printf("member->num:%d\n",temp->num);
    printf("member->name:%s\n",temp->name);

    return NULL;
}

/* main函数 */
int main()
{
    pthread_t tidp;
    struct member *b;

    /* 为结构体变量b赋值 */
    b = (struct member *)malloc(sizeof(struct member));
    b->num=1;

    b->name=new char[10];
    b->name="abcd";

    /* 创建线程pthread */
    if ((pthread_create(&tidp, NULL, pthread, (void*)b)) == -1)
    {
        printf("create error!\n");
        return 1;
    }

    /* 令线程pthread先运行 */
    sleep(1);

    /* 线程pthread睡眠2s，此时main可以先执行 */
    printf("mian continue!\n");

    /* 等待线程pthread释放 */
    if (pthread_join(tidp, NULL))
    {
        printf("thread is not exit...\n");
        return -2;
    }

    return 0;
}
