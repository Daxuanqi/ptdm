#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cc;
struct words{
	char dc[20];
	int nn;
}wd[1000000];
 
 void srwj(){
 	FILE *fp;
 	int m;
 	char temp[20];
  if((fp=fopen("test.txt","r"))==NULL){
  	printf("�ļ���ʧ��\n");
  	exit(0);
  }
  while(!feof(fp)){
  	for(m=0;m<20;m++){
  		temp[m]=fgetc(fp);
  		if(temp[m]==' '||temp[m]==','||temp[m]=='.'||temp[m]=='!'||temp[m]=='?'){
  			temp[m]='\0';
  		    strcpy(wd[cc].dc,temp);
  		    cc++;
  		    break;
		  }
	  }
  }
  fclose(fp);
 }
 void pv(){
 	int m,n,flag=1;
 	for(m=0;m<cc;m++){
 		for(n=0;n<m;n++){
 			if(strcmp(wd[n].dc,wd[m].dc)==0){
 				flag=0;
 				break;
			 }
			 else flag=1;
		 }
		 while(flag){
		 	for(n=m;n<cc;n++){
		 		if(strcmp(wd[n].dc,wd[m].dc)==0){
		 			wd[m].nn++;
				 }
				 flag=0;
			 }
		 }
	 }
 }
 void px(){
 	int m,n,k;
 	char temp[20];
 	for(m=0;m<cc-1;m++){
 		k=m;
 		for(n=m+1;n<cc;n++){
 			if(strcmp(wd[k].dc,wd[n].dc)>0){
 				k=n;
			 }
			 if(k!=m){
//			 	temp=wd[m].dc;
//			 	wd[m].dc=wd[k].dc;
//			 	wd[k].dc=temp;
                strcpy(temp,wd[m].dc);
                strcpy(wd[m].dc,wd[k].dc);
                strcpy(wd[k].dc,temp);
			 }
		 }
	 }
 }
 void dy(){
 	int m;
 	printf("��Ӣ����ĸ˳�����д�ӡ��\n");
 	printf("��ӡ���ʼ�����Ƶ�ʣ�\n");
 	for(m=0;m<cc;m++){
 		if(wd[m].nn>0){
 			printf("%-20s����%d��\n",wd[m].dc,wd[m].nn);
		 }
	 }
	 return menu();
 }
// void gpc(){
// 	int m,n,k;
// 	char t[20];
// 	printf("��ӡǰ10����Ƶ�ʣ�\n");
// for(m=0;m<cc-1;m++){
// 		k=m;
// 		for(n=m+1;n<cc;n++){
// 			if(wd[k].nn>wd[n].nn){
// 			   strcpy(t,wd[k].dc);
//			   strcpy(wd[k].dc,wd[n].dc);
//			   strcpy(wd[n].dc,t);
//			   k=n;
//			 }
//			}
//	}
//	for(m=cc-1;m>=cc-10;m--){
//		if(wd[m].nn>0){
//		printf("%s����%d��\n",wd[m].dc,wd[m].nn);
//    	}
//	}
//	return menu();
// }

 int menu()
{
	int ii;
	printf("\n");
	printf("              *********************************************************\n");
	printf("              #                                                       #\n");
	printf("              #                       ��Ƶͳ��                        #\n");
	printf("              #                                                       #\n");
	printf("              *********************************************************\n");
	printf("              #           1.��ʾ����������ȫ�����ʼ�Ƶ��              #\n");
//    printf("              #           2. ��ʾ��Ƶ�ʼ�Ƶ��                         #\n");
	printf("              #                                                       #\n");
	printf("              #           3.�˳�ϵͳ                                  #\n");
	printf("              *********************************************************\n"); 
    printf("                     ��ѡ������Ҫ�Ĳ������(1-3)���س�ȷ��:");
    scanf("%d",&ii);
    printf("\n");
    switch(ii)
  {
   	  case 1:dy();break;
//   	  case 2:gpc();break; 
      case 3: break;
      default:printf("����1-3֮��ѡ��\n");break;
   }
}
int main()//������
{
  srwj();
  px();
  pv();
  menu(); 
}
