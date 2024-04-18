#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define FILENAME "contact.txt"
struct Contact{
char name[MAX_NAME_LENGTH];
char phone[MAX_PHONE_LENGTH];
};
struct Contact contacts[MAX_CONTACTS];
int num=0;
//fuction to load contact from the file
void load_contacts(){
FILE *file=fopen(FILENAME,"r");
if(file==NULL){
printf("error:unable to open file");
return;
}
while(fscanf(file,"%s%s",contacts[num].name,contacts[num].phone)!=EOF)
{
num++;
}
fclose(file);
}
//function to save contacts to file
void save_contacts()
{
int i;
FILE *file=fopen(FILENAME,"w");
if(file==NULL){
printf("error:unable save  contacts");
return;
}
for(i=0;i<num;i++){
fprintf(file,"%s %s\n",contacts[i].name,contacts[i].phone) ;
}
fclose(file);
}
//function to add a contact
void add_contacts(const char *name,const char *phone){
if(num>=MAX_CONTACTS)
{
printf("error:to many contacts are there");
return;
}
strncpy(contacts[num].name,name,MAX_NAME_LENGTH-1);
contacts[num].name[MAX_NAME_LENGTH-1]='\0';
strncpy(contacts[num].phone,phone,MAX_PHONE_LENGTH-1);
contacts[num].phone[MAX_PHONE_LENGTH-1]='\0';
num++;
printf("contact add successfully");
}
//function to search for contact
void search_contacts( const char *name){
int found=0;
int i;
printf("search results\n");
for(i=0;i<num;i++)
{
if(strstr(contacts[i].name,name)!=NULL)
{
printf("%s %s ",contacts[i].name,contacts[i].phone);
found=1;
}
}
if(!found){
printf("No contacts found that name\n");
}
}
//function to print all contacts
void print_contacts(){
int i;
printf("contacts:\n");
for(i=0;i<num;i++)
{
printf("%s %s\n",contacts[i].name,contacts[i].phone);
}
}
void delete_contact(const char *name){
int found=0,i,j;
for(i=0;i<num;i++){
if(strcmp(contacts[i].name,name)==0){
for(j=i;j<num-1;j++){
strcpy(contacts[j].name,contacts[j+1].name);
strcpy(contacts[j].phone,contacts[j+1].phone);
}
num--;
found=1;
printf("contact is deleted\n" );
break;
}
}
if(!found){
printf("no contact found with that name\n");
}
}

void main(){
int choice;
char name[MAX_NAME_LENGTH],phone[MAX_PHONE_LENGTH];
clrscr();
//load contacts from file upon startup
load_contacts();
while(1)
{
printf("\n1.add contacts\n2.search contacts\n3.print contacts\n4.delete contact\n5.exit\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice){
case 1:
       printf("enter contact name:");
       scanf("%s",name);
       printf("enter contact phone number:");
       scanf("%s",phone);
       add_contacts(name,phone);
       save_contacts();
       break;
case 2:
      printf("enter name to search:");
      scanf("%s",name);
      search_contacts(name);
      break;
case 3:
      print_contacts();
      break;
case 4:
       printf("enter name to delete:");
       scanf("%s",name);
       delete_contact(name);
       save_contacts();
       break;
case 5:
      printf("exit");
      exit(0);
default:
      printf("invalid choice\n");
      }
      }

      }
