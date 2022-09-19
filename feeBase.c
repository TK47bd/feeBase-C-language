#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


static int l=11;


struct fees
{
    int sm;
    int reg;
    int mid;
    int fnal;
};

typedef struct fees fee;



struct profile
{
    int srl;
    char id[20];
    char name[30];
    char pass[20];

    int c_s;
    int paid;
    int pay;

    struct profile *next;

}*start=NULL,*stop=NULL;

typedef struct profile user;



fee fixed[12] = {
                  {1,35100,20400,20400},
                  {2,13500,25400,25400},
                  {3,13500,27800,27800},
                  {4,13500,26600,26600},
                  {5,13500,21800,21800},
                  {6,13500,26500,26500},
                  {7,13500,21800,21800},
                  {8,13500,25300,25300},
                  {9,13500,23700,23700},
                  {10,13500,25500,25500},
                  {11,13500,25300,25300},
                  {12,13500,16800,16800}
                };


void data(); //call inside main(on starting)when changing the data inside the 'fixed' array given above{delete database file before calling!}//
void modify();
void waiver();
void cost();
void display_all();
void profile();
void login();
void delt(user *idn);
void s_semester();
void pr_data(user *tmp);
char mygetch();


COORD coord = {0,0};

void gotoxy (int x, int y)
{
coord.X = x;
coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



char fname[] = {"Database//DB.tk"};
char tname[] = {"Database//temp_folder.tk"};
char usr[]   = {"Database//User//UserDB.tk"};



int main()
{

    /* data(); */

    system("COLOR 1E");

    int m_key;



    while(1)
    {
        system("cls");


        gotoxy(0,0);
        for(int j=0;j<80;j++)
         {
           Sleep(12);
           printf("*");
         }

        char intr[]= {"==================\xB2* Payable Fees Database Management System *\xB2================="};
        for(int i=0;i<strlen(intr);i++)
        {
           Sleep(10);
           printf("%c",intr[i]);
        }
        printf("\n\n");

        printf("\t\t\t  1. Create a Profile\n\n");
        printf("\t\t\t  2. Login with a Profile\n\n");
        printf("\t\t\t  3. Update the main fees list\n\n");
        printf("\t\t\t  4. Search for any semester cost\n\n");
        printf("\t\t\t  5. Waiver calculation in semester cost\n\n");
        printf("\t\t\t  6. Calculate Improvement cost\n\n");
        printf("\t\t\t  7. Semester Fees\n\n");
        printf("\t\t\t  0. Exit from the program\n\n");

        printf("\n================================================================================");
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

        printf("\nPlease Select any Option from Menu: ");
        scanf("%d",&m_key);

        switch(m_key)
        {

        case 1:
             profile();
            break;

        case 2:
             login();
            break;

        case 3:
             modify();
            break;

        case 4:
            s_semester();
            break;

        case 5:
            waiver();
            break;

        case 6:
            cost();
            break;

        case 7:
            display_all();
            break;

        case 0:

            printf("\n\n\n\n\t\t\t---------------------------------- \n");
            printf("\t\t\t Thanks for using feeBase...! :-D");
            printf("\n\t\t\t---------------------------------- \n\n\n");

            char intr[]= {"   !!Designed and Developed for Lab Project purpose by group 'The NextSTEP'!!"};
            char intr1[]= {"\t\t\t    [Tasin,Arnob,Sabbir & Ritu]"};
            char intr2[]= {"\t\t\t       (c) The NextSTEP.[Tm]"};

              for(int i=0;i<strlen(intr);i++)
                {
                  Sleep(10);
                  printf("%c",intr[i]);
                }
                printf("\n\n");

                for(int i=0;i<strlen(intr1);i++)
                {
                  Sleep(9);
                  printf("%c",intr1[i]);
                }
                printf("\n\n");

                for(int i=0;i<strlen(intr2);i++)
                {
                  Sleep(7);
                  printf("%c",intr2[i]);
                }
                printf("\n\n\n\n\n");

                getchar();
                printf("\n\nPress Any Key to continue.....");
                getchar();

            exit(0);

            system("cls");



        default:

            printf("\n\n\t\tWrong Input!\n");
            break;

        }



        printf("\n\nPress Any Key to continue.....");


        mygetch();

    }


    return 0;
}




void profile()
{
    user *nw,*cur;
    char pass2[20];



    nw = (user*)malloc(sizeof(user));

    nw->srl=l;
    l++;

    printf("\n\n\t\tWelcome Sir!\n\t\tTo create new profile, please\n\n");

printf("\nEnter ID: ");
scanf("%s",&nw->id);

  cur=start;
  while(cur!=NULL)
  {

if(start==NULL)
 {
    goto okay;
 }

else
 {
    if(strcmp(cur->id,nw->id)==0)
    {
    printf("\n\n\t\tID matched with a previous account!\n\t\tPlease enter New ID or just Login!!\n");
    return;
    }
 }
 cur = cur->next;
  }


okay:


printf("\nEnter Your Surname: ");
scanf("%s",&nw->name);
printf("\nEnter New Password: ");
scanf("%s",&nw->pass);



check:

printf("\nEnter the Password Again: ");
scanf("%s",pass2);


if(strcmp(pass2,nw->pass)==0)

    {
    printf("\n\n\tCongratulation Sir!\n\tProfile Successfully Created!!\n");
    }

else

    {
     printf("\n\n\t\tPassword Didn't matched!\n\t\tPlease enter same password again!!\n\n");
     goto check;
    }



       pr_data(nw);


       if(start == NULL)
          {
              start = nw;
              stop = nw;
              nw -> next = NULL;
          }

        else
          {
              stop -> next = nw;
              stop = nw;
              nw -> next = NULL;
          }



printf("\n\n\n\t\t\t%d) Your ID: ",nw->srl);
printf("%s",nw->id);

printf("\n\t\t\tYour Name: ");
printf("%s\n\n",nw->name);


printf("\n\n\n\t\t\tCost you have paid till Now:");
printf("\n\n\t\t\tTill [%d] semester(s): %d Taka!",nw->c_s,nw->paid);

printf("\n\n\n\n\t\t\tCost you have to pay:");
printf("\n\n\t\t\tFrom [%d] to [%d] semester(s): %d Taka!",(nw->c_s)+1,12,nw->pay);


printf("\n\n\n\nSo, your total cost is/will be: %d Taka\n\n\n",(nw->paid + nw->pay));


}




void pr_data(user *tmp)
{


    FILE *fp;

    int i,x,r_t=0,m_t=0,f_t=0;



     fp=fopen(fname,"rb");



     printf("\n\n\t\tPlease enter your current semester: ");
     scanf("%d",&tmp->c_s);


    while(1)
    {
        fread(&fixed,sizeof(fixed),1,fp);

        if(feof(fp))
        {
            break;
        }

        x = tmp->c_s;

      for(i=0;i<x;i++)
        {
          r_t=r_t+fixed[i].reg;
          m_t=m_t+fixed[i].mid;
          f_t=f_t+fixed[i].fnal;
        }

        tmp -> paid = r_t+m_t+f_t;


        r_t = 0;
        m_t = 0;
        f_t = 0;


        for(i=x;i<12;i++)
        {
          r_t=r_t+fixed[i].reg;
          m_t=m_t+fixed[i].mid;
          f_t=f_t+fixed[i].fnal;
        }

        tmp -> pay = r_t+m_t+f_t;


              fclose(fp);
              break;
       }


}




void login()
{
    user *nw;
    char id_n[20],pas[20],pass2[20];
    int f=0,x,i,k;


	printf("\n\nEnter your ID to Login: ");
	scanf("%s",id_n);

	c_p:

	printf("\n\nEnter your Password: ");
	scanf("%s",pas);


	if(start == NULL)
	{
		printf("\n\tNo Record has been created !!\n");
	}

	else
	{
	    nw = start;
		while(nw!=NULL)
		{
			if(strcmp(id_n,nw->id)==0)
			{
			    if(strcmp(pas,nw->pass)==0)
                {

                system("cls");

                menu:


                printf("\n\n\n\t\t  Choose any option from the sub menu: ");
                printf("\n\t\t  ------------------------------------\n\n");

                printf("\n\t\t1. View Profile");
                printf("\n\t\t2. Update Profile");
                printf("\n\t\t3. Remove Profile");
                printf("\n\t\t0. LOG OUT!");


                printf("\n\n\nChoose any option from the menu: ");
                scanf("%d",&k);

                printf("\n\n");


               switch(k)
                {

                case 1:
                    goto view;

                case 2:
                    {

                     printf("\nEnter Your New Surname: ");
                     scanf("%s",&nw->name);

                     printf("\nEnter a New Password: ");
                     scanf("%s",&nw->pass);



                     check:

                     printf("\nEnter the Password Again: ");
                     scanf("%s",pass2);


                     if(strcmp(pass2,nw->pass)==0)

                       {
                        printf("\n\n\tCongratulation Sir!\n\tProfile Successfully Updated!!\n");
                       }

                      else

                      {
                       printf("\n\n\t\tPassword Didn't matched!\n\t\tPlease enter same password again!!\n\n");
                       goto check;
                      }



                      pr_data(nw);


                      return;

                    }

                case 3:

                   delt(nw);
                   return;

                case 0:

                   return;

                default:
                    printf("\n\tWrong Input!");
                    getchar();
                    getchar();
                    system("cls");
                    goto menu;

                }



                view:


                    x = nw -> c_s;

				printf("\n\t\t\t\t !!Record Found!!");
				printf("\n\t\t\t\t ----------------\n");

				printf("\n\t\tSerial: | %d |",nw->srl);
				printf("\n\t\tStudent ID: %s",nw->id);
				printf("\n\t\tStudent Name: %s",nw->name);

				printf("\n\n\t\tCost you have paid till Now:");
                printf("\n\t\tTill [%d] semester(s): %d Taka!",x,nw->paid);

                printf("\n\n\t\tCost you have to pay:");
                printf("\n\t\tFrom [%d] to [%d] semester(s): %d Taka!",x+1,12,nw->pay);

                printf("\n\n\nSo, your total cost is/will be: %d Taka\n\n\n",(nw->paid + nw->pay));

				f = 1;
				break;
                }

                  else
                      {
                        printf("\n\n\tWrong Password!!!");
                        goto c_p;
				      }
			}
			nw = nw -> next;
		}

	}

	if(f==0)
    {
        printf("\n\n\tRecord was not found !!\n");
        return;
    }

    getchar();
    printf("\n\nPress Any key to continue....");
    getchar();
    system("cls");

    goto menu;

}




void delt(user *idn)
{

    user *t,*t1,*c;
    int found=0,count=0,pos=0,i=1,l;


    jump:

    printf("\nAre you sure to remove the profile[ 1 for yes/ 0 for no!]: ");
    scanf("%d",&l);

    if(l==0)
    {
        return;
    }


    if(l<0 || l>1)
    {
        printf("\n\n\t\tWrong Input!\n");
        goto jump;
    }


    if(start==NULL)
    {
        printf("\n\n\t\tNo Data inserted on the DataBase!\n");
        return;
    }

    while(1)
    {
    t1=start;
    while(t1!=NULL)
    {
        count++;
        if(t1->id==idn->id)
        {
            pos=count;
            found=1;
            break;
        }
        t1=t1->next;
    }

        if(found==0)
        {
          printf("\n\n\t\tPROFILE NOT FOUND!\n\n");
          getchar();
          system("cls");
          break;
        }

    t=start;
    while(i<=pos-2)
    {
       t=t->next;
       i++;
    }

    if(start==t1)
    {
        start=t1->next;
    }

    else if(t1->next==NULL)
    {
        t->next=NULL;
    }

    else
    {
        t->next=t1->next;
    }

    printf("\n\n\t\tProfile Successfully Removed!\n");

    getchar();
    getchar();



    c=start;
    while(c->next!=NULL)
    {
        c = c -> next;
    }

    if(start!=NULL)
    {
       stop = c -> next;
    }

    else if(start==NULL)
        {
          printf("\n\n\t\tNo Profile left!");
        }


    break;

   }
}




void s_semester()
{
    FILE *fp;
    fee t1;
    int sem,found=0,count=0;

    fp=fopen(fname,"rb");

    printf("\n\nEnter the semester no. you want to see the cost of: ");
    scanf("%d",&sem);

    while(1)
    {
        fread(&fixed,sizeof(fixed),1,fp);

        if(feof(fp))
        {
            break;
        }

        for(int i=0;i<12;i++)
        {
            if(fixed[i].sm==sem)
            {
            found=1;

            printf("\n================================================================================\n\n");
            printf("\t\t\t   %d no. semester will cost you:\n\n",fixed[i].sm);
            printf("================================================================================\n\n");

    printf("       Semester\t           Reg.\t           Mid\t         Final\n\n");
    printf("       --------\t          ------\t  -----\t         -----\n\n");

        printf("          %d\t",fixed[i].sm);
        printf("          %d\t",fixed[i].reg);
        printf("          %d\t",fixed[i].mid);
        printf("         %d\t\n\n",fixed[i].fnal);

            printf("================================================================================\n\n");

            }
        }
    }

    fclose(fp);

    if(found==0)
    {
        printf("\n\n\t\aInvalid Entry!!\n\n");
    }


}





void modify()
{
    FILE *fp,*fp1;
    fee t1;
    int sem,found=0,count=0;

    fp=fopen(fname,"rb");
    fp1=fopen(tname,"wb");

    printf("\n\nEnter the semester no. you want to Modify: ");
    scanf("%d",&sem);

    while(1)
    {
        fread(&fixed,sizeof(fixed),1,fp);

        if(feof(fp))
        {
            break;
        }

        for(int i=0;i<12;i++)
        {
            if(fixed[i].sm==sem)
            {
            found=1;

            printf("\nEnter the New Reg. fee: ");
            scanf("%d",&fixed[i].reg);

            fflush(stdin);
            printf("\nEnter the new Mid fee: ");
            scanf("%d",&fixed[i].mid);
            printf("\nEnter the new Final fee: ");
            scanf("%d",&fixed[i].fnal);

            fwrite(&fixed,sizeof(fixed),1,fp1);

            }
        }
    }

    fclose(fp);
    fclose(fp1);

    if(found==0)
    {
        printf("\n\n\t\aInvalid Entry!!\n\n");
    }

    else
    {
        fp=fopen(fname,"wb");
        fp1=fopen(tname,"rb");

        while(1)
        {
            fread(&fixed,sizeof(fixed),1,fp1);

            if(feof(fp1))
            {
                break;
            }
            fwrite(&fixed,sizeof(fixed),1,fp);
        }

    }
    fclose(fp);
    fclose(fp1);
}




void waiver()
{
    FILE *fp;
    int i,wv,sem,found=0;
    char per = '%';

    fp=fopen(fname,"rb");

    printf("\nEnter the Semester no.: ");
    scanf("%d",&sem);

    while(1)
    {
        fread(&fixed,sizeof(fixed),1,fp);

        if(feof(fp))
        {
            break;
        }

        for(i=0;i<12;i++)
        {
             if(fixed[i].sm==sem)
        {
            printf("\nEnter the '%c' of your waiver to calculate{effects on mid and Final only!}: ",per);
            scanf("%d",&wv);

            printf("\n================================================================================\n\n");
            printf("\t\t %d%c Waiver on %d no. semester will cost you:\n\n",wv,per,fixed[i].sm);
            printf("================================================================================\n\n");

    printf("       Semester\t           Reg.\t           Mid\t         Final\n\n");
    printf("       --------\t          ------\t  -----\t         -----\n\n");

        printf("          %d\t",fixed[i].sm);
        printf("          %d\t",fixed[i].reg);
        printf("          %d\t",((fixed[i].mid)-(((fixed[i].mid)*wv))/100));
        printf("         %d\t\n\n",((fixed[i].fnal)-(((fixed[i].fnal)*wv))/100));

            printf("================================================================================\n\n");

            found=1;
            break;

        }

        else
        {
            found=0;
        }

    }

    }
    if(found==0)
    {
        printf("\n\n\t\aInvalid Entry!!\n\n");
    }
    fclose(fp);
}






void cost()
{
    int n,c;


    jump:

    printf("\nHow many credits per hour [1 for lab/3 for class]: ");

    scanf("%d",&n);

    if(n!=1 && n!=3)

    {
        printf("\nWRONG CREDIT INFORMATION!\n");
        goto jump;
    }

    c = n*4000;



            printf("\n================================================================================\n\n");
            printf("\t\t       %d Credits per hour will cost you:\n\n",n);
            printf("\t\t     -------------------------------------\n\n");
            printf("================================================================================\n\n");

    printf("          \t           Mid\t           Final\t      \n\n");
    printf("                          -----\t           -----\t         \n\n");

        if(n==1)
        {
           printf("                          <null>");
        }
        else{

            printf("                          %d\t",((c*40)/100));
        }

        printf("           %d\t\n\n",((c*60)/100));



            printf("================================================================================\n\n");




}





void display_all()
{
    int i,r_t=0,m_t=0,f_t=0;
    FILE *fp;


    system("cls");

    fp=fopen(fname,"rb");

    printf("\n================================================================================\n\n");
    printf("\t\t\t Total semester fees Details\n");
    printf("\t\t\t-----------------------------\n\n");
    printf("\n================================================================================\n\n");

    printf("       Semester\t           Reg.\t           Mid\t         Final\n\n");
    printf("       --------\t          ------\t  -----\t         -----\n\n");

    while(1)
    {
        fread(&fixed,sizeof(fixed),1,fp);

        if(feof(fp))
        {
            break;
        }

        for(i=0;i<12;i++)
        {
        printf("          %d\t",fixed[i].sm);
        printf("          %d\t",fixed[i].reg);
        printf("          %d\t",fixed[i].mid);
        printf("         %d\t\n\n",fixed[i].fnal);
        }

      printf("\n      ------------------------------------------------------------\n\n");


      for(i=0;i<12;i++)
        {
          r_t=r_t+fixed[i].reg;
          m_t=m_t+fixed[i].mid;
          f_t=f_t+fixed[i].fnal;
        }

        printf(" cost:");

        printf("    12\t");
        printf("         %d\t",r_t);
        printf("         %d\t",m_t);
        printf("         %d\t",f_t);
        printf("\n ----\n\n");
        printf("\n\n Total cost of 12 semester: %d Taka!",r_t+m_t+f_t);
        printf("\n -------------------------\n\n");


    }
    printf("\n================================================================================\n\n");

    fclose(fp);
}


void data()
{
    int i;
    FILE *fp;

    fp=fopen(fname,"wb");

    for(i=0;i<12;i++)
    {
        fwrite(&fixed[i],sizeof(fixed[i]),1,fp);
    }

    fclose(fp);
}


char mygetch()
{
    char val;
    char rel;

    scanf("%c",&val);
    scanf("%c",&rel);
    return (val);
}

