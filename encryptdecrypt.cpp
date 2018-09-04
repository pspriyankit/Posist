#include <iostream>
#include<cmath>
using namespace std;
//we can encrypt and decrypt the string in the same manner as integer by typecasting string to int
int encryptData(int data)//encrypts the data of the node and returns the key encoded value 
{
int k=log2(data);
int w=data-pow(2,k);
int j=w*10+k;
return j;
}

int decryptData(int data)//decrypts the data of the node 
{
int k=data%10;
int w=data/10;
int x=pow(2,k);
int j=w+x;
return j;
}

int main(int argc, char** argv) {
int data;
cout<<"Enter a data value: ";
cin>>data;	
int enc=encryptData(data);
cout<<"The encrypted data is: "<<enc<<endl;
int dec=decryptData(enc);
cout<<"The decrypted data is: "<<dec<<endl;
}
/*output
Enter a data value:45
The encrypted data is: 135
The decrypted data is: 45
*/
