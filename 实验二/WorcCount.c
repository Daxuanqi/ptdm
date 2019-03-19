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
  	printf("文件打开失败\n");
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
 	printf("按英文字母顺序排列打印：\n");
 	printf("打印单词及单词频率：\n");
 	for(m=0;m<cc;m++){
 		if(wd[m].nn>0){
 			printf("%-20s出现%d次\n",wd[m].dc,wd[m].nn);
		 }
	 }
	 return menu();
 }
// void gpc(){
// 	int m,n,k;
// 	char t[20];
// 	printf("打印前10个高频词：\n");
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
//		printf("%s出现%d次\n",wd[m].dc,wd[m].nn);
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
	printf("              #                       词频统计                        #\n");
	printf("              #                                                       #\n");
	printf("              *********************************************************\n");
	printf("              #           1.显示单词总数、全部单词及频数              #\n");
//    printf("              #           2. 显示高频词及频数                         #\n");
	printf("              #                                                       #\n");
	printf("              #           3.退出系统                                  #\n");
	printf("              *********************************************************\n"); 
    printf("                     请选择您需要的操作序号(1-3)按回车确认:");
    scanf("%d",&ii);
    printf("\n");
    switch(ii)
  {
   	  case 1:dy();break;
//   	  case 2:gpc();break; 
      case 3: break;
      default:printf("请在1-3之间选择\n");break;
   }
}
int main()//主函数
{
  srwj();
  px();
  pv();
  menu(); 
}
