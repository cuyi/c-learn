#include <unistd.h> 
#include <signal.h> 
#include <fcntl.h>
#include <sys/syslog.h>
#include <sys/param.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int init_daemon(void)
{ 
	int pid; 
	int i;
	
	// 1������һЩ�����ն˲������ź�
	signal(SIGTTOU,SIG_IGN); 
	signal(SIGTTIN,SIG_IGN); 
	signal(SIGTSTP,SIG_IGN); 
	signal(SIGHUP ,SIG_IGN);
 
	// 2���ں�̨����
    if( pid=fork() ){ // ������
        exit(0); //���������̣��ӽ��̼���
	}else if(pid< 0){ // ����
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	// 3����������նˡ���¼�Ự�ͽ�����
	setsid();  
	
	// 4����ֹ�������´򿪿����ն�
	if( pid=fork() ){ // ������
		exit(0);      // ������һ�ӽ��̣��ڶ��ӽ��̼������ڶ��ӽ��̲����ǻỰ�鳤�� 
	}else if(pid< 0){ // ����
		perror("fork");
		exit(EXIT_FAILURE);
	}  
	
	// 5���رմ򿪵��ļ�������
	// NOFILE Ϊ <sys/param.h> �ĺ궨��
	// NOFILE Ϊ�ļ�����������������ͬϵͳ�в�ͬ����
	for(i=0; i< NOFILE; ++i){
		close(i);
	}
	
	// 6���ı䵱ǰ����Ŀ¼
	chdir("/tmp"); 
	
	// 7�������ļ�������ģ
	umask(0);  
	
	// 8������ SIGCHLD �ź�
	signal(SIGCHLD,SIG_IGN);
	
	return 0; 
} 

int main(int argc, char *argv[]) 
{
	init_daemon();
	
	while(1);

	return 0;
}

