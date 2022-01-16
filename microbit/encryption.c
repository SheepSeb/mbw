#include <math.h>
#include "./encryption.h"

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

char *encryptRot13(const char *message){
  char* encrypted = malloc(strlen(message));
  strcpy( encrypted, message );
  char* curr = encrypted;

  while(*curr != '\0'){
    // if((*curr >= 'a' && *curr <= 'z') || (*curr >= 'A' && *curr <= 'Z')){
    //   *curr += 13;
    //   if(*curr > 'z'){
    //     *curr -= 26;
    //   }
    //   if(*curr > 'Z'){
    //     *curr -= 26;
    //   }
    //   if((*curr >= '0' && *curr <='9')){
    //     *curr += 13;
    //   }
    // }
    *curr += 13;
    curr++;
  }
  // int n = 0;
  // while(message[n]){
  //   encrypted[n] = message[n] + 13;
  //   n++;
  // }
  // encrypted[n] = 0;
  printf("%s\n", encrypted);
  return encrypted;
  
}
