void getTimeStr(char timeStr[]){
    time_t rawtime;
    char str[9];

    int timeOfY;
    int timeOfM;
    int timeOfD;
    int timeOfH;
    int timeOfMi;
    int timeOfS;
    char strY[3];;
    char strM[3];
    char strD[3];
    char strH[3];
    char strMi[3];
    char strS[3];
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    timeOfY = 1900 + timeinfo->tm_year;
    timeOfY = timeOfY % 100;
    timeOfM = timeinfo->tm_mon + 1;
    timeOfD = timeinfo->tm_mday;
    timeOfH = timeinfo->tm_hour;
    timeOfMi = timeinfo->tm_min;
    timeOfS = timeinfo->tm_sec;
    //printf("%2d",timeOfS);
//printf("%d%d%d%d%d%d\n",timeOfY,timeOfM,timeOfD,timeOfH,timeOfMi,timeOfS);

    itoa(timeOfY,strY,10);
    itoa(timeOfM,strM,10);
    itoa(timeOfD,strD,10);
    itoa(timeOfH,strH,10);
    itoa(timeOfMi,strMi,10);
    itoa(timeOfS,strS,10);


    if(timeOfM < 10){
        strcat(strM,"0");
    }
    if(timeOfD < 10){
        strcat(strD,"0");
    }
/*    if(timeOfH == 0){
        strcat(strH,"00");
    }else if(timeOfH >0 && timeOfH <10){
        strcat(strH,"0");
    }
    */
    if(timeOfH < 10){
        strcat(strH,"0");
    }
    if(timeOfMi < 10){
        strcat(strMi,"0");
    }
    if(timeOfS < 10){
        strcat(strS,"0");
    }
    strcpy(str,strY);
    strcat(str,strM);
    strcat(str,strD);
    strcat(str,strH);
    strcat(str,strMi);
    strcat(str,strS);

    strcpy(timeStr,str);

}

/**************密码加密*******************/
void encryption(char password[]){
    int i = 0;
    while(password[i] != '\0'){
        password[i] = password[i]^0xba;
        i++;
    }
}

/***************密码解密***************************/
void decryption(char password[]){
    int i = 0;
    while(password[i] != '\0'){
        password[i] = password[i]^0xba;
        i++;
    }
}
/*******************kmp算next*******************/
//模糊搜索
void makeNext(char p[],int next[]){
    int q,k;
    next[0] = 0;
    int m = strlen(p);
    for(q = 1,k = 0;q < m;++q){
        while(k > 0 && p[q] != p[k])
            k = next[k - 1];
        if(p[q] == p[k]){
            k++;
        }
        next[q] = k;
    }

}
/********************kmp算法*****************/
//模糊搜索
int kmpSearch(char s[],char p[],int next[]){
    int n,m;
    int i,q;
    n = strlen(s);
    m = strlen(p);
    makeNext(p,next);
    for (i = 0,q = 0; i < n; ++i)
     {
         while(q > 0 && p[q] != s[i])
             q = next[q-1];
         if(p[q] == s[i]){
            q++;
         }
         if (q == m)
        {
            return i - m + 1;
        }
     }
     return -1;
}

//函数名称 mainMenu
//主菜单界面
//出口参数 int c
//函数功能： 选则登陆或退出
int mainMenu(){
    int c;
//  gotox(6);
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t            小型销售系统\n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t*           1 登陆系统             *\n");
    printf("\t\t\t\t\t*           0 新用户注册系统       *\n");
    printf("\t\t\t\t\t*          -1 退出系统             *\n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t请输入选项[ ]\b\b");
    scanf("%d",&c);
    return c;
}



//函数名称 tuiChu
//退出提醒界面
//入口参数 。。。
//
//函数功能 ：退出或者返回上一界面。
int tuiChu(){
   int a;
   system("cls");
   printf("\n\n\n\n");
   printf("\t\t\t\t\t再按一次退出键确认退出销售系统\n");
   printf("\t\t\t\t\t否则按1键返回上一页");
   scanf("%d",&a);
   if(a==-1){
    //退出整个系统
    return -1;
   }
   else{
    //返回上一界面
    return 0;
   }
   printf("\n\n\n\n");
}

//显示时间与欢迎界面
void showTime(int k){
    time_t nowtime;
    struct tm *t;
    time(&nowtime);
    t=localtime(&nowtime);
    if(t->tm_hour>=5 && t->tm_hour<9)
        printf("  早上好！\n");
    else if(t->tm_hour>=9 && t->tm_hour<12)
              printf("  上午好！\n");
          else if(t->tm_hour>=12 && t->tm_hour<18)
                     printf("  下午好！\n");
                else
                    printf("  晚上好！\n");

    switch(k){
        case 0: printf("\n\t欢迎使用物联网2班不知名小组的销售系统！");
                break;
        case 1: printf("谢谢使用物联网2班不知名小组的销售系统！\n");
                printf("\t当前时间：%s",ctime(&nowtime));
                break;
    }
    return ;
}

void displayTopic(char *c){
    printf("%s\n",c);
    printf("--------------------------\n");
}

/*************产生验证码***********/
void getVerificationCode(char verificationCode[],int n){
    char str[]="23456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++){
        verificationCode[i]=str[rand()%62];
    }
    verificationCode[n]='\0';
}
/**************文件尾部写入用户*******************/
int writeUserAfterFile(user s[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(s,sizeof(user),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}
/***************从user.dat读取用户信息********************/
int readUserFromFile(user userArray[], char *f){
    FILE *fp;
    int counter=0,k;

    fp = fopen(f,"rb");
    if(fp !=NULL){
        while(1){
            k = fread(userArray + counter,sizeof(user),1,fp);
            if(k == 1){
                counter++;
            }else{
                 break;
           }
        }
        fclose(fp);
        return counter;//返回读取个数
    }else{
        printf("文件读取失败!");
        return 0;
    }
    return -1;
}

/**************重新写入用户*******************/
int writeUserToFile(user userArray[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(userArray,sizeof(user),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}


//备份用户信息
void backupUser(user userArray[],int userTotal){
    char filename[30]="user_.dat";
//   time_t t;
 //   time(&t);
 //   strcat(filename,ctime(&t));
 //  strcpy(filename+strlen(filename)-15,".dat");
    printf("用户数据备份至：user_.dat");
    writeUserToFile(userArray,filename,userTotal);
}

/*********查询用户***************/
int userSearch(user userArray[],int userTotal,char id[]){
    	int i;

    	for(i = 0;i < userTotal;i++){
    		if(strcmp(id,userArray[i].userId) == 0){
    			return i;
    		}
    	}

     return -1;
}
/***************从文件中删除用户******************/
int deleteUserFromFile(user userDeleteArray[],int n){
    user userArray[100];
    int userTotal;
    int i,j,k;

    userTotal = readUserFromFile(userArray,"user.dat");
    for(i = 0;i < n;i++){
        for(j = 0;j < userTotal;j++){
            if(strcmp(userDeleteArray[i].userId,userArray[j].userId)==0){
                for(k = j + 1;k < userTotal;k++){
                    userArray[k - 1] = userArray[k];
                }
                userTotal--;
                break;
            }
        }
    }
    writeUserToFile(userArray,"user.dat",userTotal);
    return userTotal;
}
/**************重新写入商品*******************/
int writeProductToFile(product productArray[],char *f,int n){
    int k;
    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(productArray,sizeof(product),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}
/**************文件尾部写入商品*******************/
int writeProductAfterFile(product productArray[],char *f,int n){
    int k;
    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(productArray,sizeof(product),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}

/***************从product.bat读取商品信息********************/
int readProductFromFile(product productArray[], char *f){
    FILE *fp;
    int counter=0,k;

    fp = fopen(f,"rb");
    if(fp !=NULL){
        while(1){
            k = fread(productArray + counter,sizeof(product),1,fp);
            if(k == 1){
                counter++;
            }else{
                 break;
           }
        }
        fclose(fp);
        return counter;//返回读取个数
    }else{
        printf("文件读取失败!");
        return 0;
    }
    return -1;
}



/*****************根据id加载product**************************/
product loadProductById(int id){
    product p;
    product productArray[200];
    int productTotal;
    int i;


    productTotal = readProductFromFile(productArray,"product.dat");
    for(i = 0;i < productTotal;i++){
        if(productArray[i].id == id){
            p = productArray[i];
            break;
        }
    }
    if(i == productTotal){
        printf("找不到id为%d的数",id);
        exit(-1);
    }
    return p;

}
/******************将订单写入文件************************/
int writeOrderToFile(order orderArray[],char *f,int n){
    int k;
    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(orderArray,sizeof(order),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}
/**************将order从文件读取出来***************************/
int readOrderFromFile(order orderArray[],char *f){
    FILE *fp;
    int counter=0,k;

    fp = fopen(f,"rb");
    if(fp !=NULL){
        while(1){
            k = fread(orderArray + counter,sizeof(order),1,fp);
            if(k == 1){
                counter++;
            }else{
                 break;
           }
        }
        fclose(fp);
        return counter;//返回读取个数
    }else{
        printf("文件读取失败!");
        return 0;
    }
    return -1;
}
/**************文件尾部写入商品*******************/
int writeOrderAfterFile(order orderArray[],char *f,int n){
    int k;
    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(orderArray,sizeof(order),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("文件保存失败！\n");
        return -1;
    }
}

//备份商品信息
void backupProduct(product productArray[],int productTotal,order orderArray[],int n){
    char filename[30]="product_.dat";
//   time_t t;
 //   time(&t);
 //   strcat(filename,ctime(&t));
 //  strcpy(filename+strlen(filename)-15,".dat");
    printf("商品数据备份至：product_.dat");
    writeProductToFile(productArray,filename,productTotal);
     writeOrderToFile(orderArray,"order_.dat",n);
}
