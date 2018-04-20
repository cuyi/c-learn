/*
 * BearerPriorityAlgoSimulatorFor5GC00602.cpp
 *
 *  Created on: 2017/4/18
 *      Author: simon li
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include <time.h>       /* time */
#include <unistd.h>
#include <fcntl.h>

char Centers[3][20];
char Power_Fowards[3][20];
char Fowards[3][20];
char Guards[3][20];

char Centers_Default[3][20]={"QiSuyun",  "DaTang", "BiKun"};
char Power_Fowards_Default[3][20]={"ZhongHai",  "TongYi", "XieYi"};;
char Fowards_Default[3][20] = {"ZhangJun",  "WangHaiHui", "ZhuMing"};
char Guards_Default[3][20] = {"FangBiao",  "FaGe", "Simon"};

char PlayerList[12][20] = {"QiSuyun",  "DaTang", "BiKun", "ZhongHai",  "TongYi", "XieYi","ZhangJun",  "WangHaiHui", "ZhuMing", "FangBiao",  "FaGe", "Simon"};

char Team_SanJiaoMao[4][20];
char Team_BuLaoFu[4][20];
char Team_RuanShizi[4][20];

void dosomething()
{
    srand ((unsigned)time(NULL));

    int  temp = rand();

    strcpy(Team_SanJiaoMao[0], Centers_Default[temp%3]);

    int  teamIndex = rand();

    teamIndex = (teamIndex)%2;
    if(teamIndex % 2 == 0)
    {
        strcpy(Team_BuLaoFu[0], Centers_Default[(temp+1)%3]);
        strcpy(Team_RuanShizi[0], Centers_Default[(temp+2)%3]);
    }
    else
    {
        strcpy(Team_BuLaoFu[0], Centers_Default[(temp+2)%3]);
        strcpy(Team_RuanShizi[0], Centers_Default[(temp+1)%3]);
    }
    
    temp = rand();
    strcpy(Team_SanJiaoMao[1], Power_Fowards_Default[temp%3]);
    teamIndex = rand();
    teamIndex = (teamIndex)%2;
    if(teamIndex % 2 == 0)
    {
        strcpy(Team_BuLaoFu[1], Power_Fowards_Default[(temp+1)%3]);
        strcpy(Team_RuanShizi[1], Power_Fowards_Default[(temp+2)%3]);
    }
    else
    {
        strcpy(Team_BuLaoFu[1], Power_Fowards_Default[(temp+2)%3]);
        strcpy(Team_RuanShizi[1], Power_Fowards_Default[(temp+1)%3]);
    }
    
    temp = rand();
    strcpy(Team_SanJiaoMao[2], Fowards_Default[temp%3]);
    teamIndex = rand();
    teamIndex = (teamIndex)%2;
    if(teamIndex % 2 == 0)
    {
        strcpy(Team_BuLaoFu[2], Fowards_Default[(temp+1)%3]);
        strcpy(Team_RuanShizi[2], Fowards_Default[(temp+2)%3]);
    }
    else
    {
        strcpy(Team_BuLaoFu[2], Fowards_Default[(temp+2)%3]);
        strcpy(Team_RuanShizi[2], Fowards_Default[(temp+1)%3]);
    }
    
    temp = rand();
    strcpy(Team_SanJiaoMao[3], Guards_Default[temp%3]);
    teamIndex = rand();
    teamIndex = (teamIndex)%2;
    if(teamIndex % 2 == 0)
    {
        strcpy(Team_BuLaoFu[3], Guards_Default[(temp+1)%3]);
        strcpy(Team_RuanShizi[3], Guards_Default[(temp+2)%3]);
    }
    else
    {
        strcpy(Team_BuLaoFu[3], Guards_Default[(temp+2)%3]);
        strcpy(Team_RuanShizi[3], Guards_Default[(temp+1)%3]);
    }
    
    int fd;
    fd = open("/home/tongy/basketballTeam.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if(fd == -1)
    {
        perror("open error\n");
    }
    write(fd, "SanJiaoMao Team:\n", strlen("SanJiaoMao Team:\n"));

    //printf("\nSanJiaoMao Team:\n");
    for(int i= 0 ;i< 4;i++)
    {
        //printf(" %s, ", Team_SanJiaoMao[i]);
        write(fd, " ", 1);
        write(fd, Team_SanJiaoMao[i], strlen(Team_SanJiaoMao[i]));
        write(fd, ",", 1);
    }

    write(fd, "\nBuLaoFu Team:\n", strlen("\nBuLaoFu Team:\n"));
    //printf("\n\nBuLaoFu Team:\n");
    for(int i= 0 ;i< 4;i++)
    {
        //printf(" %s, ",Team_BuLaoFu[i]);
        write(fd, " ", 1);
        write(fd, Team_BuLaoFu[i], strlen(Team_BuLaoFu[i]));
        write(fd, ",", 1);
    }

    write(fd, "\nRuanShizi Team:\n", strlen("\nRuanShizi Team:\n"));
    //printf("\n\nRuanShizi Team:\n");
    for(int i= 0 ;i< 4;i++)
    {
        //printf(" %s, ", Team_RuanShizi[i]);
        write(fd, " ", 1);
        write(fd, Team_RuanShizi[i], strlen(Team_RuanShizi[i]));
        write(fd, ",", 1);
    }

    write(fd, "\n\n", 3);
    close(fd);
    //printf("\n\n\n");
}

