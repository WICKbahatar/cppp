#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<iostream>
using namespace std;

#define FIFO_NAME1 "/tmp/myfifo1"
#define FIFO_NAME2 "/tmp/myfifo2"

int main(){
    char s[999];
    char endSequence[10] = "bye";
    int fd1, fd2, readResullt;
    pid_t pid = fork();

    if(pid == -1){
        cout<<"fork: child creation fail";
    }
    else if(pid){
        cout<<"Parent\n";

        if(mkfifo(FIFO_NAME1, 0666) == -1){
            perror("mkfifo fail");
        }

        cout<<"Fifo create successful\nWaiting for write fifo open\n";
        int fd1 = open(FIFO_NAME1, O_WRONLY);
        cout<<"Write fifo open successfully";

        while(true){
            if(waitpid(pid, NULL, WNOHANG) != 0){
                close(fd1);
                close(fd2);
                kill(pid);
                break;
            }

            fgets(s, 999, stdin);
            cout<<"Client 1:"<<endl;
            write(fd1, s, strlen(s));

            if(strcmp(s,end) == 0){
            close(fd1);
            close(fd2);
            kill(pid);
            break;
            }
        }

        
    }
    else{
        cout<<"Child "<<getpid()<<"\n";

        if(mkfifo(FIFO_NAME2, 0666) == -1){
            perror("mkfifo fail");
        }

        cout<<"Fifo create successful\nWaiting for read fifo open\n";
        int fd2 = open(FIFO_NAME2, O_RDONLY);
        cout<<"read fifo open successfully";

        while(true){
            readResult = read(fd2, s, 999);
            s[readResullt] = '\0'
            cout<<"Client 2:"<<s<<"\n";

            if(strcmp(s,end) == 0){
            close(fd1);
            close(fd2);
            break;
            }

            exit();
        }
    }
    return 0;
}