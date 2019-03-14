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

/**************�������*******************/
void encryption(char password[]){
    int i = 0;
    while(password[i] != '\0'){
        password[i] = password[i]^0xba;
        i++;
    }
}

/***************�������***************************/
void decryption(char password[]){
    int i = 0;
    while(password[i] != '\0'){
        password[i] = password[i]^0xba;
        i++;
    }
}
/*******************kmp��next*******************/
//ģ������
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
/********************kmp�㷨*****************/
//ģ������
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

//�������� mainMenu
//���˵�����
//���ڲ��� int c
//�������ܣ� ѡ���½���˳�
int mainMenu(){
    int c;
//  gotox(6);
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t            С������ϵͳ\n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t*           1 ��½ϵͳ             *\n");
    printf("\t\t\t\t\t*           0 ���û�ע��ϵͳ       *\n");
    printf("\t\t\t\t\t*          -1 �˳�ϵͳ             *\n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t������ѡ��[ ]\b\b");
    scanf("%d",&c);
    return c;
}



//�������� tuiChu
//�˳����ѽ���
//��ڲ��� ������
//
//�������� ���˳����߷�����һ���档
int tuiChu(){
   int a;
   system("cls");
   printf("\n\n\n\n");
   printf("\t\t\t\t\t�ٰ�һ���˳���ȷ���˳�����ϵͳ\n");
   printf("\t\t\t\t\t����1��������һҳ");
   scanf("%d",&a);
   if(a==-1){
    //�˳�����ϵͳ
    return -1;
   }
   else{
    //������һ����
    return 0;
   }
   printf("\n\n\n\n");
}

//��ʾʱ���뻶ӭ����
void showTime(int k){
    time_t nowtime;
    struct tm *t;
    time(&nowtime);
    t=localtime(&nowtime);
    if(t->tm_hour>=5 && t->tm_hour<9)
        printf("  ���Ϻã�\n");
    else if(t->tm_hour>=9 && t->tm_hour<12)
              printf("  ����ã�\n");
          else if(t->tm_hour>=12 && t->tm_hour<18)
                     printf("  ����ã�\n");
                else
                    printf("  ���Ϻã�\n");

    switch(k){
        case 0: printf("\n\t��ӭʹ��������2�಻֪��С�������ϵͳ��");
                break;
        case 1: printf("ллʹ��������2�಻֪��С�������ϵͳ��\n");
                printf("\t��ǰʱ�䣺%s",ctime(&nowtime));
                break;
    }
    return ;
}

void displayTopic(char *c){
    printf("%s\n",c);
    printf("--------------------------\n");
}

/*************������֤��***********/
void getVerificationCode(char verificationCode[],int n){
    char str[]="23456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++){
        verificationCode[i]=str[rand()%62];
    }
    verificationCode[n]='\0';
}
/**************�ļ�β��д���û�*******************/
int writeUserAfterFile(user s[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(s,sizeof(user),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}
/***************��user.dat��ȡ�û���Ϣ********************/
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
        return counter;//���ض�ȡ����
    }else{
        printf("�ļ���ȡʧ��!");
        return 0;
    }
    return -1;
}

/**************����д���û�*******************/
int writeUserToFile(user userArray[],char *f,int n){
    int k;

    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(userArray,sizeof(user),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}


//�����û���Ϣ
void backupUser(user userArray[],int userTotal){
    char filename[30]="user_.dat";
//   time_t t;
 //   time(&t);
 //   strcat(filename,ctime(&t));
 //  strcpy(filename+strlen(filename)-15,".dat");
    printf("�û����ݱ�������user_.dat");
    writeUserToFile(userArray,filename,userTotal);
}

/*********��ѯ�û�***************/
int userSearch(user userArray[],int userTotal,char id[]){
    	int i;

    	for(i = 0;i < userTotal;i++){
    		if(strcmp(id,userArray[i].userId) == 0){
    			return i;
    		}
    	}

     return -1;
}
/***************���ļ���ɾ���û�******************/
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
/**************����д����Ʒ*******************/
int writeProductToFile(product productArray[],char *f,int n){
    int k;
    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(productArray,sizeof(product),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}
/**************�ļ�β��д����Ʒ*******************/
int writeProductAfterFile(product productArray[],char *f,int n){
    int k;
    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(productArray,sizeof(product),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}

/***************��product.bat��ȡ��Ʒ��Ϣ********************/
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
        return counter;//���ض�ȡ����
    }else{
        printf("�ļ���ȡʧ��!");
        return 0;
    }
    return -1;
}



/*****************����id����product**************************/
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
        printf("�Ҳ���idΪ%d����",id);
        exit(-1);
    }
    return p;

}
/******************������д���ļ�************************/
int writeOrderToFile(order orderArray[],char *f,int n){
    int k;
    FILE *fp=fopen(f,"wb");
    if(fp!=NULL){
        k = fwrite(orderArray,sizeof(order),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}
/**************��order���ļ���ȡ����***************************/
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
        return counter;//���ض�ȡ����
    }else{
        printf("�ļ���ȡʧ��!");
        return 0;
    }
    return -1;
}
/**************�ļ�β��д����Ʒ*******************/
int writeOrderAfterFile(order orderArray[],char *f,int n){
    int k;
    FILE *fp=fopen(f,"ab+");
    if(fp!=NULL){
        k = fwrite(orderArray,sizeof(order),n,fp);
        fclose(fp);
        return k;
    }
    else{
        printf("�ļ�����ʧ�ܣ�\n");
        return -1;
    }
}

//������Ʒ��Ϣ
void backupProduct(product productArray[],int productTotal,order orderArray[],int n){
    char filename[30]="product_.dat";
//   time_t t;
 //   time(&t);
 //   strcat(filename,ctime(&t));
 //  strcpy(filename+strlen(filename)-15,".dat");
    printf("��Ʒ���ݱ�������product_.dat");
    writeProductToFile(productArray,filename,productTotal);
     writeOrderToFile(orderArray,"order_.dat",n);
}
