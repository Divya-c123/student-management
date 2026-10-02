#include"project.h"
int flag=0;
int main()
{
	sll *headptr=0;
	char op;
	while(1)
	{
		printf("\033[32m/////////////////////////////////////////////////////////////////////////////////////////////\033[0m\n");
		printf("******************************STUDENT RECORD MENU***********************************\n");
		printf("\033[35ma/A:add new record\nd/D:delete a record\ns/S:show the list\nm/M:modify a record\nv/V:save\ne/E:exit\nt/T:sort the list\nl/L:deleteall the records\nr/R:reverse the list\033[0m\n");
		printf("Enter your choice:");
		scanf(" %c",&op);
		switch(op)
		{
			case 'a':
			case 'A':stud_add(&headptr);break;
			case 's':
			case 'S':stud_show(headptr);break;
			case 'e':
			case 'E':{
					 printf("s/S)save and exit\n e/E)exit\n");
					 char op;
					 scanf(" %c",&op);
					 switch(op)
					 {
						 case 'S':
						 case 's':save_file(headptr);
						 case 'e':
						 case 'E':exit(0);
					 }
				 }
				 break;
			case 'd':
			case 'D':stud_del(&headptr);break;
			case 'l':
			case 'L':stud_delall(&headptr);break;
			case 'm':
			case 'M':stud_mod(&headptr);break;
			case 't':
			case 'T':stud_sort(headptr);break;
			case 'r':
			case 'R':stud_rev(&headptr);break;
			default:printf("\033[33m enter wrong choice\033[0m\n");
		}
	}
}
void stud_add(sll **ptr)
{
	int c=count_node(*ptr),a,f;
	sll *p=*ptr;
	sll *new,*last,*t;
	int d=0;
	new=malloc(sizeof(sll));
	printf("enter name and percentage\n");
	scanf(" %s%f",new->name,&new->percentage);
	new->next=0;
	if(flag>=1)
	{ 
               if((c>1)&&(p->rollno!=1&&p->rollno>p->next->rollno))
	       {

		for(a=i,t=*ptr;a>=1&&t;a--,t=t->next)
		{
			if(a!=t->rollno)
				break;
		}
		new->rollno=a;
		}
		else
		{
		for(a=1,t=*ptr;a<c+1;a++,t=t->next)
		{
			if(a!=t->rollno)
				break;
		}
                new->rollno=a;
		}

		flag--;
	}
	else
	{
		i++;
		new->rollno=i;
	}
	if(*ptr==0)
		*ptr=new;
	else
	{
		if(p->rollno==1)
		{
			last=*ptr;
			while(last->next&&new->rollno>last->next->rollno)
				last=last->next;
				new->next=last->next;
				last->next=new;
		}
                else{
		new->next=*ptr;
		*ptr=new;
		d++;
		}
	
	}
	c=count_node(*ptr);
//	if(d==1)
        if((c>1)&&(p->rollno!=1&&p->rollno>p->next->rollno))
	{
	int i,j;
	sll *p1,*p2,temp;
	p1=*ptr;
			       for(i=0;i<c-1;i++)
			       {
				       p2=p1->next;
				       for(j=0;j<c-1-i;j++)
				       {
					       if(p1->rollno<p2->rollno)
					       {temp.rollno=p1->rollno;
					               p1->rollno=p2->rollno;
						       p2->rollno=temp.rollno;
						       strcpy(temp.name,p1->name);
						       temp.percentage=p1->percentage;
						       strcpy(p1->name,p2->name);
						       p1->percentage=p2->percentage;
						       strcpy(p2->name,temp.name);
						       p2->percentage=temp.percentage;
					       }
					       p2=p2->next;
				       }
				       p1=p1->next;
			       }
		       }

	}


///////////////////////////////////////////////////////////////////////////////////////////////////////
void stud_show(sll *ptr)
{
	printf("*******************************************************************************************\n");
	if(ptr==0)
	{
		printf("no records found\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void stud_del(sll**ptr)
{
	int c=0,d=0;
	char op,s[50];
	printf("r/R:enter roll to del\nn/N:enter name to del\n");
	scanf(" %c",&op);
	switch(op)
	{
		case 'r':
		case 'R':if(*ptr==0)
			 {
				 printf("no record found\n");
				 return;
			 }
			 int num;
			 printf("enter the rollno:\n");
			 scanf("%d",&num);
			 sll *del=*ptr,*prev;
			 while(del)
			 {
				 if(num==del->rollno)
				 {
					 if(del==*ptr)
					 {
						 *ptr=del->next;
					 }
					 else
						 prev->next=del->next;
					 free(del);
					 flag++;
				 }
				 prev=del;
				 del=del->next;
			 }
			 break;
		case 'n':
		case 'N':if(*ptr==0)
			 {
				 printf("no record found\n");
				 return;
			 }
			 char name[50];
			 printf("enter the name to del:\n");
			 scanf("%s",name);
			 sll *del1=*ptr;
			 while(del1)
			 {
				 if(strcmp(name,del1->name)==0)
				 {
					 c++;
				 }
				 del1=del1->next;
			 }
			 printf("c=%d\n",c);
			 if(c>1)
			 {
				 sll *p=*ptr;
				 while(p)
				 {
					 if(strcmp(name,p->name)==0)
						 printf("%d %s %f\n",p->rollno,p->name,p->percentage);
					 p=p->next;
				 }
				 printf("identical names are present delete according to rollno \n");
				 int rollno;
				 scanf("%d",&rollno);
				 sll *del=*ptr,*prev;
				 while(del)
				 {
					 if(rollno==del->rollno)
					 {
						 if(strcmp(name,del->name)==0)
						 {
							 if(del==*ptr)
							 {
								 *ptr=del->next;
							 }
							 else
								 prev->next=del->next;
							 free(del);
					 		 flag++;
						 }
						 else
						 {
							 printf("passing wrong rollno\n");
							 break;
						 }
					 }
					 prev=del;
					 del=del->next;
				 }
			 }
			 if(c==1)
			 {
				 sll *del1=*ptr,*prev1;
				 while(del1)
				 {
					 if(strcmp(name,del1->name)==0)
					 {
						 if(del1==*ptr)
							 *ptr=del1->next;
						 else
							 prev1->next=del1->next;
						 free(del1);
					 	 flag++;
					 }
					 prev1=del1;
					 del1=del1->next;
				 }
				 strcpy(s,name);
			 }
			 break;
		default:printf("enter wrong choice\n");
			break;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void stud_delall(sll **ptr)
{
	if(*ptr==0)
	{
		printf("no record found\n");
		return;
	}
	sll *del=*ptr;
	int c=1;
	while(del)
	{
		*ptr=del->next;
		free(del);
		sleep(1);
		printf("deleted nodes:%d\n",c++);
		del=*ptr;
	}
	printf("delete all the nodes\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void stud_mod(sll**ptr)
{
	if(*ptr==0)
	{
		printf("no record found\n");
		return ;
	}
	printf("enter which record to search for modification\n");
	printf("r/R: to search a rollno\nn/N: to search a name\np/P: mark based\n");
	char op;
	int c=0;
	sll *p=*ptr;
	scanf(" %c",&op);
	switch(op)
	{
		case 'r':
		case 'R':roll_num(ptr);
			 break;
		case 'n':
		case 'N':{
				 char s[20];
				 printf("enter name to search\n");
				 scanf("%s",s);
				 int flag=0;
				 sll *t1=*ptr;
				 while(t1)
				 {
					 if(strcmp(s,t1->name)==0)
						 c++;
					 t1=t1->next;
				 }
				 if(c>1)
				 {
					 sll *t1=*ptr;
					 while(t1)
					 {
						 if(strcmp(s,t1->name)==0)
							 printf("%d %s %f\n",t1->rollno,t1->name,t1->percentage);
						 t1=t1->next;
					 }
					 printf("indentical names are present modify according to rollno\n");
					 roll_num(&*ptr);
				 }
				 if(c==1)
				 {
					 sll *t2=*ptr;
					 while(t2)
					 {
						 if(strcmp(s,t2->name)==0)
						 {
							 printf("%d %s %f\n",t2->rollno,t2->name,t2->percentage);
							 printf("\033[32m enter modification is done according to name or marks\033[0m\n");
							 printf("enter 1)for name\n2)for marks\n");
							 int op;
							 scanf("%d",&op);
							 switch(op)
							 {
								 case 1:{
										char s[50];
										scanf("%s",s);
										strcpy(t2->name,s);
									}
									break;
								 case 2:{
										float f;
										scanf("%f",&f);
										t2->percentage=f;
									}
									break;

							 }
							 flag=1;
						 }
						 t2=t2->next;
					 }
					 if(flag==0)
						 printf("name not found\n");
				 }
			 }
			 break;
		case 'P':
		case 'p':{
				 float percentage;
				 printf("enter marks to search\n");
				 scanf("%f",&percentage);
				 int flag=0;
				 sll *t1=*ptr;
				 while(t1)
				 {
					 if(percentage==t1->percentage)
						 c++;
					 t1=t1->next;
				 }
				 if(c>1)
				 {
					 t1=*ptr;
					 while(t1)
					 {
						 if(percentage==t1->percentage)
							 printf("%d %s %f\n",t1->rollno,t1->name,t1->percentage);
						 t1=t1->next;
					 }
					 printf("indentical names are present modify according to rollno\n");
					 printf("again use mode and choice option rollno\n");
					 roll_num(&*ptr);
				 }
				 if(c==1)
				 {
					 sll *t2=*ptr;
					 while(t2)
					 {
						 if(t2->percentage==percentage)
						 {
							 printf("%d %s %f\n",t2->rollno,t2->name,t2->percentage);
							 printf("enter modification is done according to name or marks\n");
							 printf("enter 1)for name\n2)for marks\n");
							 int op;
							 scanf("%d",&op);
							 switch(op)
							 {
								 case 1:{
										char s[50];
										scanf("%s",s);
										strcpy(t2->name,s);
									}
									break;
								 case 2:{
										float f;
										scanf("%f",&f);
										t2->percentage=f;
									}
									break;

							 }
							 flag=1;
						 }
						 t2=t2->next;
					 }
					 if(flag==0)
						 printf("name not found\n");
				 }
			 }
			 break;
		default:printf("wrong option\n");
			break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void stud_sort(sll*ptr)
{
	if(ptr==0)
	{
		printf("no records found\n");
		return;
	}
	printf("enter choice for sorting\n");
	printf("1)sort with name\n2)sort with percentage\n");
	printf("enter op\n");
	int op;
	sll *p1=ptr,*p2,temp;
	int i,j,c1=count_node(ptr);
	scanf("%d",&op);
	switch(op)
	{
		case 1:{
			       for(i=0;i<c1-1;i++)
			       {
				       p2=p1->next;
				       for(j=0;j<c1-i-1;j++)
				       {
					       if(strcmp(p1->name,p2->name)>0)
					       {
						       strcpy(temp.name,p1->name);
						       temp.percentage=p1->percentage;
						       strcpy(p1->name,p2->name);
						       p1->percentage=p2->percentage;
						       strcpy(p2->name,temp.name);
						       p2->percentage=temp.percentage;
					       }
					       p2=p2->next;
				       }
				       p1=p1->next;
			       }
		       }
		       break;
		case 2:{
			       for(i=0;i<c1-1;i++)
			       {
				       p2=p1->next;
				       for(j=0;j<c1-1-i;j++)
				       {
					       if(p1->percentage>p2->percentage)
					       {
						       strcpy(temp.name,p1->name);
						       temp.percentage=p1->percentage;
						       strcpy(p1->name,p2->name);
						       p1->percentage=p2->percentage;
						       strcpy(p2->name,temp.name);
						       p2->percentage=temp.percentage;
					       }
					       p2=p2->next;
				       }
				       p1=p1->next;
			       }
		       }
		       break;
		default:printf("wrong choice\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////
int count_node(sll*ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}
//////////////////////////////////////////////////////////////////////////////////////////////
void save_file(sll*ptr)
{
	if(ptr==0)
	{
		printf("no records\n");
		return;
	}
	FILE *fp;
	fp=fopen("student.dat","w");
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}
	fclose(fp);
	printf("data saved in afile\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void stud_rev(sll**ptr)
{
	if(*ptr==0)
	{
		printf("no records found\n");
		return ;
	}
	int c=count_node(*ptr);
	sll **p,*temp=*ptr;
	if(c>1)
	{
		p=malloc(sizeof(sll*)*c);
		int i=0;
		while(temp)
		{
			p[i++]=temp;
			temp=temp->next;
		}
		for(i=1;i<c;i++)
			p[i]->next=p[i-1];
		p[0]->next=0;
		*ptr=p[c-1];
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////iv/
void roll_num(sll **ptr)
{
	int rollno;
	printf("enter rollno to search\n");
	scanf("%d",&rollno);
	int flag=0;
	sll *t=*ptr;
	while(t)
	{
		if(rollno==t->rollno)
		{
			printf("%d %s %f\n",t->rollno,t->name,t->percentage);
			printf("enter modification is done according to name or marks\n");
			printf("enter 1 for name\n 2 for marks\n");
			int op;
			scanf("%d",&op);
			switch(op)
			{
				case 1:{
					       char s[10];
					       scanf("%s",s);
					       strcpy(t->name,s);
				       }
				       break;
				case 2:{
					       float f;
					       scanf("%f",&f);
					       t->percentage=f;
				       }
				       break;
			}

			flag=1;
		}
		t=t->next;
	}
	if(flag==0)
		printf("rollno not found\n");
}
