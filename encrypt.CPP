//Program for encryption & decryption.

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

void encrypt();
void decrypt();
void f();
void show();
int main()
{
char choice;
system("cls");
	do
	{
	show();
	cout<<"\n                                 MENU";
	cout<<"\n                    1.To Encrypt the message.";
	cout<<"\n                    2.To Decrypt the message.";
	cout<<"\n                    3.To Quit.";
	cout<<"\n\n                    Enter your choice.";
	f();
	cin>>choice;
	switch(choice)
		{
		case '1':
		encrypt();
		break;

		case '2':
		decrypt();
		break;

		case '3':
		show();
		f();
		cout<<"      Thank You.Run me again!!!";
		break;

		default:
		f();
		cout<<"Wrong Choice";
		getch();
		}
	}
	while(choice!='3');
getch();
}

//put on every time cout...
void f()
{
cout<<endl<<"                    ";
}


//for main heading
void show()
{
	system("cls");
	cout<<"\n                    Program for Encryption And Decryption"<<endl;
}


//Function for encryption
void encrypt()
{
char message[1000],encryptmessage[1000];
int x,y,key,keymat[2][2],messagemat[2][1000],encryptmat[2][1000],length;
show();
f();
cout<<"Write your message to be encrypted.";
f();
gets(message);

back:
f();
cout<<"Enter the key (4 digit number).";
f();
cin>>key;

//making key matrix
keymat[1][1]=key%10;
keymat[0][1]=key%100-keymat[1][1];
keymat[1][0]=key%1000-keymat[0][1];
keymat[0][0]=key-keymat[1][0];

keymat[0][1]/=10;
keymat[1][0]/=100;
keymat[0][0]/=1000;

x=keymat[0][0]*keymat[1][1];
y=keymat[0][1]*keymat[1][0];
int z=1/(x-y);
if (z==0)
{
f();
cout<<"The key you entered cant work";
f();
goto back;
}

//making message matrix
int k=0,i,j;
length=strlen(message);
for(j=0;j<=length/2;j++)
	{
	for(i=0;i<2;i++)
		{
				if ((int)message[k]>=97)
				messagemat[i][j]=(int)message[k++]-96;
				else
				messagemat[i][j]=(int)message[k++]-64;

		}
	}


//multiplying key matrix and message matrix
	for(j=0;j<=length/2;j++)
		encryptmat[0][j]=keymat[0][0]*messagemat[0][j]+keymat[0][1]*messagemat[1][j];
	for(j=0;j<=length/2;j++)
		encryptmat[1][j]=keymat[1][0]*messagemat[0][j]+keymat[1][1]*messagemat[1][j];

//mod of 26
for(j=0;j<=length/2;j++)
	{
	for(i=0;i<2;i++)
		{
		if(encryptmat[i][j]!=26)
		encryptmat[i][j]%=26;
		}
	}

//printing the encrypted message
k=0;
for(j=0;j<=length/2;j++)
	{
	for(i=0;i<2;i++)
		{

				encryptmessage[k++]=(char)(encryptmat[i][j]+64);
	       }
	}
f();
cout<<"The encrypted message is ...";
f();
cout<<encryptmessage;
getch();
}


//Function to Decrypt the message

void decrypt()
{
char message[1000],decryptmessage[1000];
int x,y,key,keymat_1[2][2],messagemat[2][1000],decryptmat[2][1000],length;
show();
f();
cout<<"Write your message to be decrypted.";
f();
gets(message);
f();
cout<<"Enter the key (4 digit number).";
f();
cin>>key;

//making key inverse matrix
keymat_1[1][1]=key%10;
keymat_1[0][1]=key%100-keymat_1[1][1];
keymat_1[1][0]=key%1000-keymat_1[0][1];
keymat_1[0][0]=key-keymat_1[1][0];

keymat_1[0][1]/=10;
keymat_1[1][0]/=100;
keymat_1[0][0]/=1000;

x=keymat_1[0][0]*keymat_1[1][1];
y=keymat_1[0][1]*keymat_1[1][0];
int z=1/(x-y);

//for exchanging values of keymat_1[0][0] & 1 resp
keymat_1[0][0]+=keymat_1[1][1];
keymat_1[1][1]=keymat_1[0][0]-keymat_1[1][1];
keymat_1[0][0]-=keymat_1[1][1];
keymat_1[0][1]=-keymat_1[0][1];
keymat_1[1][0]=-keymat_1[1][0];

// making key inverse finish//
for(int i=0;i<2;i++)
{
keymat_1[!i][!i]*=z;
keymat_1[!i][i]*=z;
}


//making message matrix
int k=0,j;
length=strlen(message);
for(j=0;j<=length/2;j++)
	{
	for(int i=0;i<2;i++)
		{
				if ((int)message[k]>=97)
				messagemat[i][j]=(int)message[k++]-96;
				else
				messagemat[i][j]=(int)message[k++]-64;

		}
	}


//checking number of alphabets
if(length%2 != 0)
messagemat[1][j]=0;

//multiplying key matrix and message matrix
	for(j=0;j<=length/2;j++)
		decryptmat[0][j]=keymat_1[0][0]*messagemat[0][j]+keymat_1[0][1]*messagemat[1][j];
	for(j=0;j<=length/2;j++)
		decryptmat[1][j]=keymat_1[1][0]*messagemat[0][j]+keymat_1[1][1]*messagemat[1][j];

//mod of 26
for(j=0;j<=length/2;j++)
	{
	for(int i=0;i<2;i++)
		{
			if(decryptmat[i][j]!=26)
			{
			decryptmat[i][j]%=26;
			while(decryptmat[i][j]<0)
			decryptmat[i][j]+=26;
			}

		}
	}

//printing the encrypted message
k=0;
for(j=0;j<=length/2;j++)
	{
	for(int i=0;i<2;i++)
		{

				decryptmessage[k++]=(char)(decryptmat[i][j]+64);
	       }
	}
f();
cout<<"The decrypted message is ...";
f();
cout<<decryptmessage;
getch();

}