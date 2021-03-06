#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t pid,w;
  int status;
  pid = fork();
  if(pid == -1)
  {
    perror("fork");
  }
  if(pid == 0)
  {
    printf(" Child PID is: %d\n",getpid());
    execlp("ls","ls",NULL);
  }
  w = waitpid(pid,&status, WUNTRACED | WCONTINUED);
  printf(" Wait ID: %d\n", &w);
  if(WIFEXITED(status)){printf("Child process se zaustavio normalno\n");}
  printf(" %d", WEXITSTATUS(status));
  
  return 0;
}