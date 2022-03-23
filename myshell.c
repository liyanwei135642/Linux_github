#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/wait.h>
#define SIZE 200

//查看str中是否有'>' ">>" "|" 没有返回0； '>>'返回1 '>'返回2 "|"返回3 pp 存放'>''|''>>'之后的字符指针，没有返回NULL
int f1(char* str,char**pp)
{
  int re=0;
  *pp=NULL;
  if(str==NULL)
  {
    return re;
  }
  while(*str&&*(str+1))
  {
    if(str[0]==str[1]&&str[0]=='>')
    {
      *str=0;
      re=1;
      *pp=str+2;
      break;
    }
    if(str[0]=='>')
    {
      *str=0;
      re=2;
      *pp=str+1;
      break;
    }
    if(str[0]=='|')
    {
      *str=0;
      re=3;
      *pp=str+1;
      break;
    }
    str++;
  }
  return re;
}

// 把字符串按照空格的换行符分割 存到argv[]中
void f2(char* str,char**argv)
{
  argv[0]=strtok(str," \n");
  int i=0;
  while(argv[i])
  {
    argv[++i]=strtok(NULL," \n");
  }
}

//创建子进程执行str命令：

void f3(char* str)
{
  char* argv[50];
  pid_t id=fork();
  if(id==0)
  {
    char*pp=NULL;
    int n=f1(str,&pp);
    if(n==0)
    {
      f2(str,argv);
      execvp(argv[0],argv);
      exit(1);
    }
    if(n==1)
    {
      f2(str,argv);
      char*name=strtok(pp," \n");
      int fd=open(name,O_WRONLY|O_CREAT|O_APPEND,0664);
      dup2(fd,1);
      close(fd);
      execvp(argv[0],argv);
      exit(1);
    }
    if(n==2)
    {
      f2(str,argv);
      char*name=strtok(pp," \n");
      int fd=open(name,O_WRONLY|O_CREAT|O_TRUNC,0664);
      dup2(fd,1);
      close(fd);
      execvp(argv[0],argv);
      exit(1);   
    }
    if(n==3)
    {
      pid_t id=fork();
      if(id==0)
      {
        f2(str,argv);
        int fd=open("temp",O_WRONLY|O_CREAT|O_TRUNC,0664);
        dup2(fd,1);
        close(fd);
        execvp(argv[0],argv);
        exit(1);
      }
      int stat=0;
      waitpid(id,&stat,0);
      str=pp;
      char*name=" temp1 ";
      id=fork();
      if(id==0)
      {
        execlp("cp","cp","temp","temp1",NULL);
        exit(1);
      }
      waitpid(id,NULL,0);
      char arr[200]={0};
      int i=0;
      while(str[i])
      {
        arr[i]=str[i];
        i++;
      }
      n=f1(str,&pp);
      if(n==3)
      {
        i=0;
        while(str[i])
        {
          str[i]=str[i];
          i++;
        }
        while(*name)
        {
          arr[i]=*name;
          name++;
          i++;
        }
        arr[i++]='|';
        while(*pp)
        {
          arr[i++]=*pp;
          pp++;
        }
      }
      else 
      {
        i=strlen(arr);
        while(*name)
        {
          arr[i++]=*name;
          name++;
        }
      }
      f3(arr);
    }
  }
  int stat=0;
  waitpid(id,&stat,0);
}



int main()
{
  while(1)
  {
    char str[SIZE]={0}; 
    char*cmd1=getenv("USER");
    char*cmd2="@";
    char*cmd3=getenv("HOSTNAME");
    char*cmd4=getenv("PWD");
    char*cmd5="& ";
    printf("[%s%s%s%s]%s",cmd1,cmd2,cmd3,cmd4,cmd5);
    fgets(str,SIZE,stdin);
    f3(str);
    remove("temp");
    remove("temp1");
  }
  return 0;
}





