#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Union
union Is_active{
    char flag[6];
};

// Struct
struct Person{
    char Name[50];
    char Email[50];
    char Password[50];
    char Phone[50];
    union Is_active active;
};

struct Person persons[10];
int i = 0;

// Registeration
void Register(){
    struct Person Reg_person;

    printf("Enter Your Name: ");
    scanf("%s",Reg_person.Name);

    printf("Enter Your Email: ");
    scanf("%s",Reg_person.Email);

    printf("Enter Your Password: ");
    scanf("%s",Reg_person.Password);

    printf("Enter Your Phone: ");
    scanf("%s",Reg_person.Phone);
    do{
            printf("Active or Not: ");
            scanf("%s",Reg_person.active.flag);
            if(strcmp(Reg_person.active.flag,"true") == 0 || strcmp(Reg_person.active.flag,"1") == 0 ||
            strcmp(Reg_person.active.flag,"false") == 0 ||strcmp(Reg_person.active.flag,"0") == 0) {
                break;
            }
            printf("Wrong Value\ninsert:\ntrue or 1 for active\nfalse or 0 for not active\n");
        }while(1 == 1);

    persons[i++] = Reg_person;
    printf("**Register Successfully**\n");
}


// Login
int Login(){
    char _email[50],_password[50];

    printf("Enter Email: ");
    scanf("%s",_email);

    printf("Enter Password: ");
    scanf("%s",_password);

    //search for person
    int j;
    for(j=0;j<strlen(persons);j++){
        if(strcmp(_email,persons[j].Email) == 0 && strcmp(_password,persons[j].Password) == 0){
                if(strcmp(persons[j].active.flag,"true") == 0 || strcmp(persons[j].active.flag,"1") == 0){
                    return 1;
                }
        }
    }
    return 0;
}

int main()
{
    do{
        printf("Welcome To The System\n");
        printf("1- Register\n2- Login\n3-Exit\n---------------------\n");
        int t;
        scanf("%d",&t);
        if(t == 1){
                Register();
        }else if(t == 2){
            int res = Login();
            if(res == 1){
                printf("**Login Success**");
            }else{
                printf("**Login Failed**");
            }
        }else if(t == 3){
            return 0;
        }else{
            printf("**Wrong Value**");
        }
        printf("\n---------------------\n");
    }while(1 == 1);

    return 0;
}
