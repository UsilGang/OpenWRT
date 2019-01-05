/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*****************************************************************************
cat /etc/passwd 
root:x:0:0:root:/root:/bin/ash
daemon:*:1:1:daemon:/var:/bin/false
ftp:*:55:55:ftp:/home/ftp:/bin/false
network:*:101:101:network:/var:/bin/false
nobody:*:65534:65534:nobody:/var:/bin/false
dnsmasq:x:453:453:dnsmasq:/var/run/dnsmasq:/bin/false
//file '/etc/passwd' convert to hex string
char *passwd_hex="726f6f743a783a303a303a726f6f743a2f726f6f743a2f62696e2f6173680d0a6461656d6f6e3a2a3a313a313a6461656d6f6e3a2f7661723a2f62696e2f66616c73650d0a6674703a2a3a35353a35353a6674703a2f686f6d652f6674703a2f62696e2f66616c73650d0a6e6574776f726b3a2a3a3130313a3130313a6e6574776f726b3a2f7661723a2f62696e2f66616c73650d0a6e6f626f64793a2a3a36353533343a36353533343a6e6f626f64793a2f7661723a2f62696e2f66616c73650d0a646e736d6173713a783a3435333a3435333a646e736d6173713a2f7661722f72756e2f646e736d6173713a2f62696e2f66616c7365";

cat /etc/shadow
root::0:0:99999:7:::
daemon:*:0:0:99999:7:::
ftp:*:0:0:99999:7:::
network:*:0:0:99999:7:::
nobody:*:0:0:99999:7:::
dnsmasq:x:0:0:99999:7:::
//file '/etc/shadow' convert to hex string
char *shadow_hex="726f6f743a3a303a303a39393939393a373a3a3a0d0a6461656d6f6e3a2a3a303a303a39393939393a373a3a3a0d0a6674703a2a3a303a303a39393939393a373a3a3a0d0a6e6574776f726b3a2a3a303a303a39393939393a373a3a3a0d0a6e6f626f64793a2a3a303a303a39393939393a373a3a3a0d0a646e736d6173713a783a303a303a39393939393a373a3a3a";
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getHexVal(char c)
{
  if(c >= '0' && c<= '9')
    return c - '0';
  else if(c >= 'a' && c<= 'f')
    return c - 'a' + 10;
  else if(c >= 'A' && c<= 'F')
    return c - 'A' + 10;
  else
    return -1;//error
}

char* hexToAscii(char* hexStr)
{
int hexLen = strlen(hexStr);

char* asciiStr = malloc(hexLen/2 + 1);//new char(hexLen/2 + 1)

for(int i = 0; i < hexLen; i +=2)
{
  asciiStr[i/2] = (getHexVal(hexStr[i])*16 + getHexVal(hexStr[i+1]));
}

return asciiStr;
}

int to_file(char *name, char *str){
 //int fd=open(name,"w+");
 int fd=open(name,O_CREAT|O_RDWR);
 if(fd) {
    write(fd,str,strlen(str));
    close(fd);
 }
 return(0);
}

int main()
{
  char *passwd_hex="726f6f743a783a303a303a726f6f743a2f726f6f743a2f62696e2f6173680d0a6461656d6f6e3a2a3a313a313a6461656d6f6e3a2f7661723a2f62696e2f66616c73650d0a6674703a2a3a35353a35353a6674703a2f686f6d652f6674703a2f62696e2f66616c73650d0a6e6574776f726b3a2a3a3130313a3130313a6e6574776f726b3a2f7661723a2f62696e2f66616c73650d0a6e6f626f64793a2a3a36353533343a36353533343a6e6f626f64793a2f7661723a2f62696e2f66616c73650d0a646e736d6173713a783a3435333a3435333a646e736d6173713a2f7661722f72756e2f646e736d6173713a2f62696e2f66616c7365";
  char *shadow_hex="726f6f743a3a303a303a39393939393a373a3a3a0d0a6461656d6f6e3a2a3a303a303a39393939393a373a3a3a0d0a6674703a2a3a303a303a39393939393a373a3a3a0d0a6e6574776f726b3a2a3a303a303a39393939393a373a3a3a0d0a6e6f626f64793a2a3a303a303a39393939393a373a3a3a0d0a646e736d6173713a783a303a303a39393939393a373a3a3a";
  //
  char *passwd_str = hexToAscii(passwd_hex);
  printf(passwd_str);
  to_file("/etc/passwd_new",passwd_str);
  //
  char *shadow_str = hexToAscii(shadow_hex);
  printf(shadow_str);
  to_file("/etc/shadow_new",shadow_str);
 return(0);
}
