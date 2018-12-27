#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>
#include<string.h>
#include<string>
/* �����ṹ�� */
struct member
{
    int num;
    char *name;
};

/* �����߳�pthread */
static void * pthread(void *arg)
{
    struct member *temp;

    /* �߳�pthread��ʼ���� */
    printf("pthread start!\n");

    /* �����̼߳���ִ�� */
    sleep(2);

    /* ��ӡ������� */
    temp = (struct member *)arg;
    printf("member->num:%d\n",temp->num);
    printf("member->name:%s\n",temp->name);

    return NULL;
}

/* main���� */
int main()
{
    pthread_t tidp;
    struct member *b;

    /* Ϊ�ṹ�����b��ֵ */
    b = (struct member *)malloc(sizeof(struct member));
    b->num=1;

    b->name=new char[10];
    b->name="abcd";

    /* �����߳�pthread */
    if ((pthread_create(&tidp, NULL, pthread, (void*)b)) == -1)
    {
        printf("create error!\n");
        return 1;
    }

    /* ���߳�pthread������ */
    sleep(1);

    /* �߳�pthread˯��2s����ʱmain������ִ�� */
    printf("mian continue!\n");

    /* �ȴ��߳�pthread�ͷ� */
    if (pthread_join(tidp, NULL))
    {
        printf("thread is not exit...\n");
        return -2;
    }

    return 0;
}
