#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <sys/time.h>

/*
    ֱ�ӵ����򷵻�0, ��siglongjmp���÷����򷵻ط�0ֵ.
    sigsetjmp(sigjmp_buf env, int savesigs)
*/

sigjmp_buf jmp_env;

static void connect_alarm(int)
{
    siglongjmp(jmp_env, 1);
}

int main()
{
    // ����ʱʱ��sec_timeoutС�ڵ�������ʱ��run_timeʱ������printf("running...\n");
    int sec_timeout = 4;
    int run_time = 1;

    printf("timeout = %d, run time = %d\n", sec_timeout, run_time);
    if (sec_timeout)
    {
        // ������alarm�������õ�ʱ��ʱ�������źţ�����connect_alarm����
        signal(SIGALRM, connect_alarm);
        alarm(sec_timeout);
        printf("set timeout\n");
        if (sigsetjmp(jmp_env, 1))
        {
            printf("timeout\n");
            goto out;
        }
    }

    sleep(run_time);
    printf("running...\n");

out:
    if (sec_timeout)
    {
        // ȡ����ǰ���õ�����
        alarm(0);
        printf("cancel timeout\n");
    }

    return 0;
}

