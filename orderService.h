/**************��ȡ�������***********************/
/*
����:������Ŀ������������Ŷ�ά����ָ�룬�û�id
����������
����һ����ά�ַ�ָ��oIdArray��Ϊ�������벢������ֵ��ֵ��ָ�룻
oIdArray[0]��Ϊ������ţ�
*/
char** getOrderID(int itemNum,char **oIdArray,char userId[]){
    int orderNum,i;
    char timeStr[13];
    char iStr[2];

    orderNum = (itemNum + 2) /3;


    oIdArray = (char**)malloc(orderNum*sizeof(char*));
    for(i = 0;i < orderNum;i++){
        oIdArray[i] = (char*)malloc(25*sizeof(char));
        getTimeStr(timeStr);
        //printf("%s\n",timeStr);
        itoa(i,iStr,10);
        strcpy(oIdArray[i],userId);
        //printf("%s\n",oIdArray[i]);;
        strcat(oIdArray[i],timeStr);
        strcat(oIdArray[i],iStr);;
    }

    return (char**)oIdArray;
}
/******************��ȡ�������е��û��˺�******************/
/*
ʹ��ǰuserId�����ʼ����
*/
void getUserIdFromOrderId( char orderId[] ,char userId[]){
    int length;



    length = strlen(orderId);
    //printf("%d\n",length);
    memset(userId,0,length - 13);
    userId[length - 13] = '\0';
    strncpy(userId,orderId,length - 13);


}
/******************��ҳ��ӡ����*********************/
void printOrder(order orderArray[],int orderTotal,char currentUserId[]){
    int i,j,k,x,c;
    int page = 0,totalPage;
    unsigned short ch;
    char userId[LENGTH_OF_USERID+1] = "";
    product productLoaded;
    char s1[15] = "δ֧��";
    char s2[15] = "��֧��δ����";
    char s3[15] = "������";
    char itemName1[30];
//    order searchedorder;

    if(orderTotal > 0){
        totalPage = (orderTotal + 9) / 10;//����ҳ��

        for(i = 0;i < orderTotal;){

            system("cls");
            page++;
            printf("%12s%24s%12s%12s%15s%15s%15s\n","�������","������","����״��","�ܼ�","��Ʒ��1","��Ʒ��2","��Ʒ��3");

            for(k = 0;k < 80;k++){
                putchar('-');
            }
            printf("\n");;
            for(j = 0;j < 10 && i < orderTotal;j++){
                userId[0] = '\0';
                getUserIdFromOrderId(orderArray[i].id,userId);
                if(strcmp(a.userId,userId) == 0){
                    printf("%-12d",orderArray[i].number);
                    printf("%24s",orderArray[i].id);

                    if(orderArray[i].status == 0){
                        printf("%15s",s1);
                    }else if(orderArray[i].status == 1){
                        printf("%15s",s2);
                    }else{
                        printf("%15s",s3);
                    }

                    printf("%12lf",orderArray[i].totalPrice);
                    for(c = 0;c < orderArray[i].itemNum;c++){
                        productLoaded = loadProductById(orderArray[i].items[c].id);

                        strcpy(itemName1,productLoaded.name);
                        printf("%15s",itemName1);
                    }
                    printf("\n");
                }

                i++;
            }
            printf("\n");
            for(k = 0;k < 80;k++){
                putchar('-');
            }
            printf("\n");
            printf("��%dҳ����%dҳ����һҳ(��),��һҳ(��),esc��������ʾ,����TAB�����ж�����ѡ�\n",page,totalPage);
            printf("\n��������%d������\n",orderTotal);
						ch = getch();
            if(9 == ch){
                printf("���붩���Ų鿴��Ʒ��ϸ��Ϣ\n");
                scanf("%d",&x);
	            system("cls");
//	            searchedorder=loadorderById(x);
//                orderDetail(searchedorder,currentUserId);

            }
            if(27 == ch)
                return;
            if(0 == ch || 0xe0 == ch)
                ch|=getch() << 8;
            if(0x48e0 == ch){
                i = i- j;
                if(i >10){
                    i = i - 10;
                    page -= 2;
                }else{
                    i = 0;
                    page = 0;
                }
            }
        }
    }
}

/******************����Ա��ҳ��ӡ����*********************/
void printAllOrder(order orderArray[],int orderTotal,char currentUserId[]){
    int i,j,k,x,c;
    int page = 0,totalPage;
    unsigned short ch;
    product productLoaded;
    char s1[15] = "δ֧��";
    char s2[15] = "��֧��δ����";
    char s3[15] = "������";
    char itemName1[30];
//    order searchedorder;

    if(orderTotal > 0){
        totalPage = (orderTotal + 9) / 10;//����ҳ��

        for(i = 0;i < orderTotal;){

            system("cls");
            page++;
            printf("%12s%24s%12s%12s%15s%15s%15s\n","�������","������","����״��","�ܼ�","��Ʒ��1","��Ʒ��2","��Ʒ��3");

            for(k = 0;k < 80;k++){
                putchar('-');
            }
            printf("\n");;
            for(j = 0;j < 10 && i < orderTotal;j++){
                if(1){
                    printf("%-12d",orderArray[i].number);
                    printf("%24s",orderArray[i].id);

                    if(orderArray[i].status == 0){
                        printf("%15s",s1);
                    }else if(orderArray[i].status == 1){
                        printf("%15s",s2);
                    }else{
                        printf("%15s",s3);
                    }

                    printf("%12lf",orderArray[i].totalPrice);
                    for(c = 0;c < orderArray[i].itemNum;c++){
                        productLoaded = loadProductById(orderArray[i].items[c].id);

                        strcpy(itemName1,productLoaded.name);
                        printf("%15s",itemName1);
                    }
                    printf("\n");
                }

                i++;
            }
            printf("\n");
            for(k = 0;k < 80;k++){
                putchar('-');
            }
            printf("\n");
            printf("��%dҳ����%dҳ����һҳ(��),��һҳ(��),esc��������ʾ,����TAB�����ж�����ѡ�\n",page,totalPage);
            printf("\n��������%d������\n",orderTotal);
						ch = getch();
            if(9 == ch){
                printf("���붩���Ų鿴��Ʒ��ϸ��Ϣ\n");
                scanf("%d",&x);
	            system("cls");
//	            searchedorder=loadorderById(x);
//                orderDetail(searchedorder,currentUserId);

            }
            if(27 == ch)
                return;
            if(0 == ch || 0xe0 == ch)
                ch|=getch() << 8;
            if(0x48e0 == ch){
                i = i- j;
                if(i >10){
                    i = i - 10;
                    page -= 2;
                }else{
                    i = 0;
                    page = 0;
                }
            }
        }
    }
}
