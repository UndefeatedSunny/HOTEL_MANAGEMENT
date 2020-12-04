#include <stdio.h>   // Adding Libraries
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ll long long int

                    // STRUCTURE

struct customer_info
{
    char room_no[20];
    char name[30];
    char address[50];
    char phone_no[15];
    char nationality[10];
    char email[20];
    char period[10];
    char arrival_date[15];
    char members_names[100];
};


struct request_user
{
    char details[100];
    char room_new[10];
    char room_old[10];
};


struct suggestion
{
    char room_no[10];
    char date[15];
    char suggest[100];
};



                        // FUNCTIONS
int password()
{
    char u_pass[15]={0};        // User Password
    char o_pass[15]={0};        // Original Password
    char ch;
    ll i=0,j=0;

    printf("\t\tPLEASE! ENTER THE PASSWORD\n\n");
    printf("\t\tONLY 3 CHANCES WILL BE GIVEN\n");

    for(i=0;i<3;i++)
    {
        j=0;
        printf("\n\n\nEnter the Password-> ");
        u_pass[0]=getch();

        while(u_pass[j]!='\r')
        {
            if(u_pass[j]=='\b')
            {
                --j;
                printf("\b");
                printf(" ");
                printf("\b");
                u_pass[j]=getch();
            }
            else
            {
                printf("*");
                ++j;
                u_pass[j]=getch();
            }
        }
        u_pass[j]='\0';
        FILE *fp;
        fp=fopen("password","r");
        if(fp==NULL)
        {
            printf("[FILE MISSING]");
            getch();
            return -1;
        }
        else
        {
            j=0;
            while(1)
            {
                ch=fgetc(fp);
                if(ch==EOF)
                {
                    o_pass[j]='\0';
                    break;
                }
                o_pass[j]=ch-5;
                ++j;
            }
        }
        if(strcmp(o_pass,u_pass)==0)
        {
            printf("\n\t\t\tACCESS GRANTED \n");
            return 1;
        }
        else
        {
            printf("\n\t\t\tWRONG PASSWORD \n");
        }
        fclose(fp);
    }
    printf("YOU ARE NOT ALLOWED TO ENTER");
    getch();
    return -1;
}


void edit_password()
{
    system("cls");

    char pass1[15]={0};
    char pass2[15]={0};
    char ch;
    ll i=0,j=0,match,choice;

    printf("\n\n");
    FILE *fp;
    fp=fopen("password","rb");
    if(fp==NULL)
    {
        fp=fopen("password","wb");
        if(fp==NULL)
        {
            printf("SYSTEM ISSUE -_-");
            getch();
            return ;
        }
        fclose(fp);
        printf("\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }
    fclose(fp);

    match=password();

    if(match==-1)
    {
        return;
    }
    do
    {
        if(match==1)
        {
            printf("\nEnter the NEW password -> ");
            fflush(stdin);
            pass1[0]=getch();
            while(pass1[j]!='\r')
            {
                if(pass1[j]=='\b')
                {
                    --j;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    pass1[j]=getch();
                }
                else
                {
                    printf("*");
                    ++j;
                    pass1[j]=getch();
                }
            }
            pass1[j]='\0';
            i=0;
            printf("\nConfirm Password -> ");
            pass2[0]=getch();
            while(pass2[i]!='\r')
            {
                if(pass2[i]=='\b')
                {
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    pass2[i]=getch();
                }
                else
                {
                    printf("*");
                    i++;
                    pass2[i]=getch();
                }
            }
            pass2[i]='\0';
            if(strcmp(pass1,pass2)==0)
            {
                fp=fopen("password","wb");
                 if(fp==NULL)
                 {
                    printf("SYSTEM ERROR -_-");
                    getch();
                    return;
                 }
                i=0;
                while(pass1[i]!='\0')
                {
                    ch=pass1[i];
                    fputc(ch+5,fp);
                    i++;
                }
                fputc(EOF,fp);
                fclose(fp);
            }
            else
            {
                printf("\nWRONG PASSWORD");
                choice=1;
            }
        }
    }while(choice==1);
    printf("\n\n\t\tPassword Changed (-_-)");
    getch();
}


void edit()
{
    system("cls");
    printf("\n\n\t\t\t***********************\n");
    printf("\t\t\t* WELCOME TO EDIT MENU*");
    printf("\n\t\t\t***********************\n\n");

    struct customer_info guest;

    FILE *fp;
    FILE *fptemp;

    fp=fopen("book.txt","r");
    fptemp=fopen("Temp.txt","w");

    if(fp==NULL)
    {
        return;
    }
    if(fptemp==NULL)
    {
        return;
    }
    char room_no[10];
    int check=0;

	printf("Enter Room number of the customer to edit:\n\n");
    fflush(stdin);
	gets(room_no);

    int comp = atoi(room_no);
    if(comp<0 || comp>100)
    {
        printf("\n\t\tROOM DOESN'T EXISTS");
        getch();
        return;
    }

    while(fread(&guest,sizeof(guest),1,fp)==1)
    {
        if(strcmp(room_no,guest.room_no)==0)
        {
            check=1;
            strcpy(guest.room_no,room_no);
            printf("\n\t\tEnter the Name: ");
            fflush(stdin);
            gets(guest.name);
            printf("\n\t\tEnter the Address: ");
            fflush(stdin);
            gets(guest.address);
            printf("\n\t\tEnter the Phone No. : ");
            fflush(stdin);
            gets(guest.phone_no);
            printf("\n\t\tEnter the Nationality: ");
            fflush(stdin);
            gets(guest.nationality);
            printf("\n\t\tEnter the Email: ");
            fflush(stdin);
            gets(guest.email);
            printf("\n\t\tEnter the Time Period to Stay : ");
            fflush(stdin);
            gets(guest.period);
            printf("\n\t\tEnter the Arrival Date : ");
            fflush(stdin);
            gets(guest.arrival_date);
            printf("\n\t\tEnter all the Members Details (If Any)");
            fflush(stdin);
            gets(guest.members_names);
            fwrite(&guest, sizeof(guest),1,fptemp);
            continue;
        }
        else
        {
            fwrite(&guest, sizeof(guest),1,fptemp);
        }
    }
    fclose(fp);
    fclose(fptemp);
    if(check==0)
    {
        printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
        getch();
    }
    else
    {
        remove("book.txt");
        rename("Temp.txt","book.txt");
        printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
        getch();
    }
}


void delete()
{
    printf("\n\n\t\t\t*************************\n");
    printf("\t\t\t* WELCOME TO DELETE MENU*");
    printf("\n\t\t\t*************************\n\n");

    FILE *fp;
    FILE *fptemp;
    char room_no[10];
    int check=0;
    struct customer_info removee;

    fp = fopen("book.txt","r");
    if(fp==NULL)
    {
        return;
    }
    fptemp = fopen("Temp.txt","w");
    if(fptemp==NULL)
    {
        return;
    }
    printf("Enter the Room Number of the hotel to be deleted from the database: \n");
    fflush(stdin);
    gets(room_no);
    fflush(stdin);

    int comp = atoi(room_no);
    if(comp<0 || comp>100)
    {
        printf("\n\t\tROOM DOESN'T EXISTS");
        getch();
        return;
    }

    while(fread(&removee,sizeof(removee),1,fp)==1)
    {
        if(strcmp(removee.room_no,room_no)==0)
        {
            check=1;
            continue;
        }
        else
        {
            fwrite(&removee,sizeof(removee),1,fptemp);
        }
    }
    if(check==0)
    {
        fclose(fp);
        fclose(fptemp);
        printf("\n\n Records of Customer in this  Room number is not found!!");
        getch();
        return;
    }
    fclose(fp);
    fclose(fptemp);
    remove("book.txt");
    rename("Temp.txt","book.txt");
    printf("\n\nThe Customer is successfully removed....");
    getch();
}


void book()
{
    system("cls");
    printf("\n\n\t\t\t****************************************\n");
    printf("\t\t\t* WELCOME TO ADD CUSTOMER DETAILS MENU *");
    printf("\n\t\t\t****************************************\n\n");

    struct customer_info guest;
    char enter='Y';
    int exist;

    FILE *fp;
    fp=fopen("book.txt","a+");
    if(fp==NULL)
    {
        fp=fopen("book.txt","w+");
        if(fp==NULL)
        {
            printf("[SYSTEM ERROR -_-]");
            printf("\nEnter any KEY to exit");
            getch();
            return;
        }
        fclose(fp);
    }
    while(enter=='y'||enter=='Y')
    {
        exist=1;
        char room_no[10];
        printf("\n\t\tEnter the Room Number => ");
        fflush(stdin);
        gets(room_no);
        fflush(stdin);

        int comp = atoi(room_no);
        if(comp<0 || comp>100)
        {
            printf("\n\t\tROOM DOESN'T EXISTS");
            getch();
            return;
        }
        rewind(fp);
        while(fread(&guest,sizeof(guest),1,fp)==1)
        {
            if(strcmp(room_no,guest.room_no)==0)
            {
                printf("\n\t\tAlready Exists\n");
                exist=0;
                break;
            }
        }
        char phone_verif[15];

        if(exist==1)
        {
            system("cls");
            strcpy(guest.room_no,room_no);
            printf("\n\t\tEnter the Name: ");
            fflush(stdin);
            gets(guest.name);
            printf("\n\t\tEnter the Address: ");
            fflush(stdin);
            gets(guest.address);

            while(1)
            {
                printf("\n\t\tEnter the Phone No. : ");
                fflush(stdin);
                gets(phone_verif);
                ll plength = atoi(phone_verif);

                if(strlen(phone_verif)==10 && plength>999999999 && plength<=9999999999)
                {
                    strcpy(guest.phone_no,phone_verif);
                    break;
                }
                else
                {
                    printf("\n\t\tWRONG PHONE NO. ENTERED\n\n\t\tPLEASE TRY AGAIN !!");
                }
            }

            printf("\n\t\tEnter the Nationality: ");
            fflush(stdin);
            gets(guest.nationality);
            printf("\n\t\tEnter the Email: ");
            fflush(stdin);
            gets(guest.email);
            printf("\n\t\tEnter the Time Period to Stay : ");
            fflush(stdin);
            gets(guest.period);
            printf("\n\t\tEnter the Arrival Time : ");
            fflush(stdin);
            gets(guest.arrival_date);
            printf("\n\t\tEnter all the Members Details (If Any) : ");
            fflush(stdin);
            gets(guest.members_names);
            fwrite(&guest, sizeof(guest),1,fp);
            printf("\n\t\tYOUR RECORD IS ADDED...\n");
        }
        if(exist==0)
        {
            printf("\n\t\tCHECK another ROOM .... (Y/N) ");
            fflush(stdin);
            enter=getch();
        }
        else
        {
            printf("\n\t\tDO YOU WANT TO ADD ANOTHER ROOM .... (Y/N) ");
            fflush(stdin);
            enter=getch();
        }
    }
    fclose(fp);
    printf("\n\t\tEnter any KEY to Exit");
    getch();

}


void view()
{
    system("cls");
    if(password()==-1)
    {
        return;
    }
    system("cls");
    struct customer_info info;

    printf("\n\n\t\t*******************************\n");
    printf("\t\t* HERE IS THE VIEWING MENU *");
    printf("\n\t\t*******************************\n\n");

    FILE *fp;
    fp=fopen("book.txt","r");
    if(fp==NULL)
    {
        return;
    }
    while(fread(&info,sizeof(info),1,fp)==1)
    {
        printf("Room Number => %s\n",info.room_no);
        printf("Name => %s\n",info.name);
        printf("Address => %s\n",info.address);
        printf("Phone Number => %s\n",info.phone_no);
        printf("Nationality => %s\n",info.nationality);
        printf("Email => %s\n",info.email);
        printf("Stay Time Period  => %s\n",info.period);
        printf("Arrival Date  => %s\n",info.arrival_date);
        printf("Members Details => %s\n",info.members_names);
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    }
    fclose(fp);
    getch();
}
void message()
{
    system("cls");
    printf("\n\n\t\t*******************************\n");
    printf("\t\t* HERE IS THE MESSAGE MENU *");
    printf("\n\t\t*******************************\n\n");

    FILE *fp;
    fp=fopen("REQUEST.txt","r+");

    struct request_user msg;

    if(fp==NULL)
    {
        printf("\n\n\t\t\tNO MESSAGES YET");
        getch();
        return;
    }

    while(fread(&msg,sizeof(msg),1,fp)==1)
    {
        printf("\t\tOLD ROOM NO. => %s\n\n",msg.room_old);
        printf("\t\tNEW ROOM NO. WANTED=> %s\n\n",msg.room_new);
        printf("\t\tPROBLEM => %s\n",msg.details);
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    }
    rewind(fp);
    printf("\n\t\tDo you want to Delete any Entry\n\n\t\tPRESS 1 for YES\n\n\t\tPRESS 2 for NO\n\n\t\tPRESS any KEY For ACCEPTING USER Request. \n\n\t\t");
    char option;
    scanf("%c",&option);

    if(option=='1')
    {
        printf("\n\t\tEnter the no of Entry you want to DELETE\n\n\t\t");
        int entry;
        scanf("%d",&entry);

        struct request_user del;

        FILE *fptemp;
        fptemp = fopen("Temp.txt","w+");
        if(fptemp==NULL)
        {
            return;
        }
        int count=0;
        while(fread(&del,sizeof(del),1,fp)==1)
        {
            count++;
            if(entry==count)
            {
                continue;
            }
            else
            {
                fwrite(&del,sizeof(del),1,fptemp);
            }
        }
        fclose(fp);
        fclose(fptemp);
        remove("REQUEST.txt");
        rename("Temp.txt","REQUEST.txt");
        printf("\n\n\t\t\tThe ENTRY is successfully DELETED....");
    }
    else if(option=='2')
    {
        fclose(fp);
        return;
    }
    else
    {
        getch();
        int approv;
        printf("\n\n\t\t\tEnter the Qwery No. which you want to APPROVED => ");
        scanf("%d",&approv);

        struct customer_info info;
        struct request_user req;
        int c=0;

        FILE *fp1;
        fp1=fopen("REQUEST.txt","r+");
        if(fp1==NULL)
        {
            return;
        }
        FILE *fp2;
        fp2 = fopen("book.txt","r");
        if(fp2==NULL)
        {
            return;
        }
        FILE *fptemp;
        fptemp = fopen("Temp.txt","w");
        if(fptemp==NULL)
        {
            return;
        }

        while(fread(&req,sizeof(req),1,fp1)==1)
        {
            c++;
            fread(&info,sizeof(info),1,fp2);
            if(approv==c)
            {
                strcpy(info.room_no , req.room_new);
                fwrite(&info,sizeof(info),1,fptemp);
            }
            else
            {
                fwrite(&info,sizeof(info),1,fptemp);
            }
        }
        fclose(fp1);
        fclose(fp2);
        fclose(fptemp);
        remove("book.txt");
        rename("Temp.txt","book.txt");
        printf("\n\n\t\t\tDETAILS UPDATED....");
        getch();
    }
    fclose(fp);
    getch();
}


void review()
{
    system("cls");
    printf("\n\n\t\t**********************************\n");
    printf("\t\t* HERE IS THE SUGGESTION MENU *");
    printf("\n\t\t**********************************\n\n");

    FILE *fp;
    fp = fopen("SUGGEST.txt","r+");

    if(fp==NULL)
    {
        return;
    }

    struct suggestion print;

    while(fread(&print,sizeof(print),1,fp)==1)
    {
        printf("\t\t\tROOM NO    => %s\n\n",print.room_no);
        printf("\t\t\tDATE       => %s\n\n",print.date);
        printf("\t\t\tSUGGESTION => %s\n",print.room_no);
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    }
    getch();
}

void stay()
{
    system("cls");
    printf("\n\n\t\t\t*************************\n");
    printf("\t\t\t* WELCOME TO PRICE CHANGE MENU*");
    printf("\n\t\t\t*************************\n\n");
    FILE *fp;
    int num1;

    fp = fopen("price.txt","w");

    if(fp==NULL)
    {
        printf("\nError: Cannot open File (-_-)");
        return;
    }
    printf("\n\n\t\tEnter the NEW Price of Accommodation : ");
    scanf("%d",&num1);

    putw(num1,fp);                           // Write only Integer Value value
    fclose(fp);

    printf("\n\n\t\tNEW PRICE APPLIED SUCCESSFULLY\n\n\t\t (-_-)");
    getch();
}

void admin()
{
    system("cls");
    if(password()==-1)
    {
        return;
    }
    while(1)
    {
        system("cls");
        printf("\n\n\n");
        printf("                            #######    ####      ###     ###   ##    ###     ##          \n");
        printf("                            ##   ##    ##  ##    ## ## ## ##   ##    ## ##   ##          \n");
        printf("                            #######    ##   ##   ##  ##   ##   ##    ##  ##  ##          \n");
        printf("                            ##   ##    ##   ##   ##       ##   ##    ##   ## ##          \n");
        printf("                            ##   ##    #####     ##       ##   ##    ##     ###          \n");
        int option;

        printf("\n\n\n\t\t\t\t{ MAIN MENU }\t    { OPTIONS }");
        printf("\n\n\t\t\tBOOK A ROOM\t\t\t\t[1]");
        printf("\n\t\t\tVIEW CUSTOMER RECORD\t\t\t[2]");
        printf("\n\t\t\tDELETE CUSTOMER RECORD\t\t\t[3]");
        printf("\n\t\t\tEDIT CUSTOMER RECORD\t\t\t[4]");
        printf("\n\t\t\tGUESTS REQUESTS\t\t\t\t[5]");
        printf("\n\t\t\tGUESTS SUGGESTIONS\t\t\t[6]");
        printf("\n\t\t\tCHANGE STAY PRICES\t\t\t[7]");
        printf("\n\t\t\tEXIT\t\t\t\t\t[8]");
        printf("\n\n\t\t\tPlease! Enter the Option: ");

        scanf("%d",&option);

        switch(option)
        {
            case 1:
                book();
                break;
            case 2:
                view();
                break;
            case 3:
                delete();
                break;
            case 4:
                edit();
                break;
            case 5:
                message();
                break;
            case 6:
                review();
                break;
            case 7:
                stay();
                break;
            case 8:
                return;
        }
        system("cls");
    }
}



void price()
{
    int price=0;
    int days=0;
    int total=0;
    printf("\n\t\t\tEnter the No. of Days you want to Stay ");
    scanf("%d",&days);

    FILE *fp;

    fp = fopen("price.txt","r");

    price = getw(fp);                         // Read only Integer Value value

    fclose(fp);

    total=(price*days);
    printf("\n\t\t\tTOTAL AMOUNT FOR %d DAYS ==> %d",days,total);
    getch();
}


void record()
{
    system("cls");
    printf("\n\n\t\t\t*************************\n");
    printf("\t\t\t* WELCOME TO RECORD MENU*");
    printf("\n\t\t\t*************************\n\n");
    printf("\t\t\tOCCUPATION\tPHONE NO.\n\n");
    printf("\t\t\tGUARD\t\t9953691354\n\n");
    printf("\t\t\tGARDNER\t\t7083691354\n\n");
    printf("\t\t\tMANAGER\t\t7071231354\n\n");
    printf("\t\t\tMEDICAL\t\t8871231214\n\n");
    printf("\t\t\tSWEEPER\t\t9953691354\n\n");
    getch();
    return;
}


void availability()
{
    system("cls");
    printf("\n\n\t\t\t********************************\n");
    printf("\t\t\t* WELCOME TO AVAILABILITY MENU *");
    printf("\n\t\t\t********************************\n\n");

    FILE *fp;
    char room_no[10];
    int check=0;
    struct customer_info avail;

    fp = fopen("book.txt","r");
    if(fp==NULL)
    {
        return;
    }

    printf("\t\t\tEnter the Room Number of the hotel to be SEARCHED from the database: ");
    fflush(stdin);
    gets(room_no);
    fflush(stdin);

    int comp = atoi(room_no);
    if(comp<0 || comp>100)
    {
        printf("\n\t\tROOM DOESN'T EXISTS");
        getch();
        return;
    }

    while(fread(&avail,sizeof(avail),1,fp)==1)
    {
        if(strcmp(room_no,avail.room_no)==0 && (strlen(room_no)==strlen(avail.room_no)))
        {
            check=1;
            break;
        }
    }
    fclose(fp);
    if(check==0)
    {
        printf("\n\n\t\t\t AVAILABLE");
        getch();
        return;
    }
    else
    {
        printf("\n\n\t\t\t NOT AVAILABLE [-_-]");
        getch();
        return;
    }
}


void room_change()
{
    system("cls");
    printf("\n\n\t\t\t***************************\n");
    printf("\t\t\t* WELCOME TO REQUEST MENU *");
    printf("\n\t\t\t***************************\n\n");

    char room_o[10];
    printf("\t\t\tEnter the OLD Room No.\n\t\t\t");
    fflush(stdin);
    gets(room_o);
    int comp = atoi(room_o);
    if(comp<0 || comp>100)
    {
        printf("\n\t\tROOM DOESN'T EXISTS");
        getch();
        return;
    }

    char user_name[30];
    printf("\t\t\tPlease Enter your Name for Verification Purpose \n\t\t\t");
    fflush(stdin);
    gets(user_name);

    FILE *fc;
    int c=0;
    struct customer_info check1;

    fc = fopen("book.txt","r");
    if(fc==NULL)
    {
        return;
    }

    while(fread(&check1,sizeof(check1),1,fc)==1) // Security Purpose Only.
    {
        if(strcmp(room_o,check1.room_no)==0 && (strlen(room_o)==strlen(check1.room_no)) && (strcmp(check1.name,user_name))==0 && (strlen(user_name)==strlen(check1.name)))
        {
            c=1;
            break;
        }
    }
    fclose(fc);

    if(c==0)
    {
        printf("\n\n\t\t\tWrong ROOM NO. entered, Please Verify That");
        getch();
        return;
    }


    char room_n[10];
    printf("\t\t\tEnter the Room No. from which you want to exchange ");
    fflush(stdin);
    gets(room_n);
    comp = atoi(room_n);
    if(comp<0 || comp>100)
    {
        printf("\n\t\tROOM DOESN'T EXISTS");
        getch();
        return;
    }

    fflush(stdin);
    printf("\n\t\t\tChecking the Availability ........");


    FILE *fp;
    struct customer_info req;

    int check = 0;
    fp = fopen("book.txt","r");

    if(fp==NULL)
    {
        return;
    }

    while(fread(&req,sizeof(req),1,fp))
    {
        if(strcmp(room_n,req.room_no)==0)
        {
            check=1;
            break;
        }
    }
    fclose(fp);

    if(check==0)
    {
        FILE *fr;
        struct request_user input;

        printf("\n\n\t\t\tYes Sir, Room is Available");
        fr = fopen("REQUEST.txt","a+");
        if(fr==NULL)
        {
            printf("a+");
            fr = fopen("REQUEST.txt","w+");
            {
                if(fr==NULL)
                {
                    printf("[SYSTEM ERROR -_-]");
                    printf("\nEnter any KEY to exit");
                    getch();
                    return;
                }
            }
            fclose(fr);
        }
        strcpy(input.room_new,room_n);
        strcpy(input.room_old,room_o);
        printf("\n\n\t\t\tPlease Enter the Problem why you want to Change Room \n\n\t\t\t");
        fflush(stdin);
        gets(input.details);
        fwrite(&input,sizeof(input),1,fr);
        printf("\n\n\t\t\tRequest Placed Successfully ....");
        fclose(fr);
        getch();
    }
    else
    {
        printf("\n\n\t\t\tNo Sir, Room is not Available");
        getch();
        return;
    }
}

void suggests()
{
    system("cls");
    printf("\n\n\t\t\t******************************\n");
    printf("\t\t\t* WELCOME TO SUGGESTION MENU *");
    printf("\n\t\t\t******************************\n\n");

    char room[10];
    printf("\t\t\tEnter the Room No.\n\t\t\t");
    fflush(stdin);
    gets(room);
    int comp = atoi(room);
    if(comp<0 || comp>100)
    {
        printf("\n\t\tROOM DOESN'T EXISTS");
        getch();
        return;
    }

    char user_name[30];
    printf("\t\t\tPlease Enter your Name for Verification Purpose \n\t\t\t");
    fflush(stdin);
    gets(user_name);


    FILE *fc;
    int c=0;
    struct customer_info check1;

    fc = fopen("book.txt","r");
    if(fc==NULL)
    {
        return;
    }

    while(fread(&check1,sizeof(check1),1,fc)==1)
    {
        if(strcmp(room,check1.room_no)==0 && (strlen(room)==strlen(check1.room_no) && (strcmp(check1.name,user_name))==0 && (strlen(user_name)==strlen(check1.name))))
        {
            c=1;
            break;
        }
    }
    fclose(fc);

    if(c==0)
    {
        printf("\n\n\t\t\tWrong ROOM NO. entered, Please Verify That");
        getch();
        return;
    }

    struct suggestion s;


    FILE *fp;

    fp = fopen("SUGGEST.txt","a+");
    if(fp==NULL)
    {
        printf("a+");

        fp = fopen("REQUEST.txt","w+");
        {
            if(fp==NULL)
            {
                printf("[SYSTEM ERROR -_-]");
                printf("\nEnter any KEY to exit");
                getch();
                return;
            }
            fclose(fp);
        }
    }
    strcpy(s.room_no,room);

    printf("\n\n\t\t\tPlease! Enter the DATE\n\n\t\t\t");
    fflush(stdin);
    gets(s.date);
    printf("\n\n\t\t\tPlease Type the Suggestion Ma'am/Sir \n\n\t\t\t");
    fflush(stdin);
    gets(s.suggest);

    fwrite(&s,sizeof(s),1,fp);

    printf("\n\n\t\t\tTHANK YOU FOR SUGGESTION (-_-) ....");
    getch();

    fclose(fp);
}

void request()
{
    while(1)
    {
        system("cls");
        printf("\n\n\n\t\t\t\t{ MAIN MENU }\t\t    { OPTIONS }");
        printf("\n\n\t\t\tREQUEST FOR ROOM CHANGE\t\t\t[1]");
        printf("\n\t\t\tSUGGESTIONS \t\t\t\t[2]");
        printf("\n\t\t\tEXIT\t\t\t\t\t[3]");

        int option;
        printf("\n\n\t\t\tPlease! Enter the Option: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                room_change();
                break;
            case 2:
                suggests();
                break;
            case 3:
                return;
        }
        system("cls");
    }
}

void user()
{
    while(1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t                       ##  ##    #######    #######   ######                   \n           ");
        printf("                            ##  ##    ##         ##        ##  ##                   \n           ");
        printf("                            ##  ##    #######    #######   ######                   \n           ");
        printf("                            ##  ##         ##    ##        ##   ##                  \n           ");
        printf("                            ######    #######    #######   ##    ###                \n           ");
        int option;

        printf("\n\n\t\t\tNOTE => ROOM EXISTS FROM [1-100] ONLY\n\n");

        printf("\n\n\n\t\t\t\t{ MAIN MENU }\t\t    { OPTIONS }");
        printf("\n\n\t\t\tSTAY PRICE\t\t\t\t[1]");
        printf("\n\t\t\tCHECK AVAILABILITY OF ROOM \t\t[2]");
        printf("\n\t\t\tEMPLOYEES RECORDS\t\t\t[3]");
        printf("\n\t\t\tREQUEST OR SUGGESTIONS\t\t\t[4]");
        printf("\n\t\t\tEXIT\t\t\t\t\t[5]");
        printf("\n\n\t\t\tPlease! Enter the Option: ");

        scanf("%d",&option);

        switch(option)
        {
            case 1:
                price();
                break;
            case 2:
                availability();
                break;
            case 3:
                record();
                break;
            case 4:
                request();
                break;
            case 5:
                return;
        }
        system("cls");
    }
}


int main()
{
    while(1)
    {
        system("COLOR 0A");
        int option;
        printf("\n\n\n");
        printf("\t\t                       ##  ##    #######    #########    ########    ## \n           ");
        printf("                            ##  ##    ##   ##       ##        ##          ## \n           ");
        printf("                            ######    ##   ##       ##        ########    ## \n           ");
        printf("                            ##  ##    ##   ##       ##        ##          ## \n           ");
        printf("                            ##  ##    #######       ##        ########    ###### \n       ");

        printf("\n\n\n");
        printf("                            ###     ###    #######    ####    ##   #######    #######     ######    ###     ###   ######   ####    ##   #########      \n");
        printf("                            ## ## ## ##    ##   ##    ## ##   ##   ##   ##    ##          ##        ## ## ## ##   ##       ## ##   ##      ##          \n");
        printf("                            ##  ##   ##    #######    ##  ##  ##   #######    ##  ###     ######    ##  ##   ##   ######   ##  ##  ##      ##          \n");
        printf("                            ##       ##    ##   ##    ##   ## ##   ##   ##    ##   ##     ##        ##       ##   ##       ##   ## ##      ##          \n");
        printf("                            ##       ##    ##   ##    ##    ####   ##   ##    #######     ######    ##       ##   ######   ##    ####      ##          \n");

        printf("\n\n\n\t\t\t\t{ MAIN MENU }\t    { OPTIONS }");
        printf("\n\n\t\t\tADMIN\t\t\t[1]");
        printf("\n\t\t\tUSER\t\t\t[2]");
        printf("\n\t\t\tEDIT PASSWORD\t\t[3]");
        printf("\n\t\t\tEXIT\t\t\t[4]");
        printf("\n\n\t\t\tPlease! Enter the Option: ");

        scanf("%d",&option);

        switch(option)
        {
            case 1:
                admin();
                break;
            case 2:
                user();
                break;
            case 3:
                edit_password();
                break;
            case 4:
                printf("\n\t\t\tTHANK YOU\t [-_-]\n");
                getch();
                return 0;
                break;
        }
        system("cls");
    }
    return 0;
}
