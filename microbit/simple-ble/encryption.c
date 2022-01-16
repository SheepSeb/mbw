#include <math.h>
#include "include/encryption.h"

void generateKeys(long int* publicKey, long int* privateKey){

}

char* encryptMessage(long int key, char* message){
  /*
  long int pt,ct,key=e[0],k,len;
    i=0;
    len=strlen(msg);
    while(i!=len)
    {
        pt=m[i];
        pt=pt-96;
        k=1;
        for(j=0;j<key;j++)
        {
            k=k*pt;
            k=k%n;
        }
        temp[i]=k;
        ct=k+96;
        en[i]=ct;
        i++;
    }
    en[i]=-1;
    return en[i]
    */
}


char* encryptRot13(char* message){
  char* encrypted
  int n = 0;
  while(message[n]){
    encrypted[n] = message[n] + 13;
    n++;
  }
  encrypted[n] = 0;
  return encrypted
  
}
