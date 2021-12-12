#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<sys/shm.h>

int main(){
    int shmID;
    char *shmptr,*temp;
    key_t key= 9876;
    char *text="Ho Ten: PHAM HOANG LONG, MSSV: 20182666, Class: ET-10 K63 \n";
    shmID = shmget(key,40,IPC_CREAT|8666);
    if(shmID<0){
        printf(" error\n");
        exit(0);
    }
    shmptr = shmat(shmID,NULL,0);
    if(shmptr == (char *)-1){

        printf("error");
    }

    temp =shmptr;
    int len =strlen(text);
    for(int i=0;i<len;i++){
        *temp =text[i];
        temp++;
    }
    *temp = '%' ;
    while(*shmptr != '#')
        sleep(1);
    shmdt(shmptr);
    shmctl(shmID,IPC_RMID,NULL);
    return 0;
}