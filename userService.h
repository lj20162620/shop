/****************�û�ע��*****************/
void registe(){
    user a[1];
    user userArray[MAX_USER];
    int userTotal;

    char passWord1[LENGTH_OF_PASSWPRD +1];
    int b=0;//bΪ0������ע�ᡣ;

    userTotal = readUserFromFile(userArray,"user.dat");// ��ȡ��ע���û�������
    while(b==0){
    		a[0].role = 1;
        system("cls");    //�����Ļ
        printf("\n\n\n\n");
        printf("\t\t\t    ������");
        scanf("%s",a[0].name);
        printf("\n\n");
        while(1){
            printf("\t\t\t    �˺ţ�");
            scanf("%s",a[0].userId);
            if(userSearch(userArray,userTotal,a[0].userId) != -1){
                printf("\t\t\t���˺���ע��!\n");
            }else{
                break;
            }
        }
        printf("\n\n");
        printf("\t\t\t    ���룺");
        scanf("%s",passWord1);
        printf("\n\n");
        printf("\t\t\tȷ�����룺");
        scanf("%s",a[0].passWord);
        printf("\n\n");

        while(strcmp(a[0].passWord,passWord1)!=0){         //ȷ�������Ƿ���ȣ�����Ⱦ��ظ�ѭ����
            printf("\t\t\t������������һ�������\n");
            printf("\t\t\tȷ�����룺");
            scanf("%s",a[0].passWord);
            printf("\n\n");
        }

        encryption(a[0].passWord);//�������

        printf("\t\t\t    �绰��");
        scanf("%s",a[0].phone);
        printf("\n\n");
        printf("\t\t\t   Email��");
        scanf("%s",a[0].email);
        printf("\n\n");
        printf("\t\t\t    ��ַ��");
        scanf("%s",a[0].addr);
        printf("\n\n");
        printf("\t\t\t    ȷ�ϣ�[1]\n");
        printf("\t\t\t�������룺[0]\n");
        printf("\t\t\t  ��ѡ��: [ ]\b\b");
        scanf("%d",&b);
   }
   writeUserAfterFile(a,"user.dat",1);
}
//�������� login
//��¼����
//��ڲ��� char ...
//�������� �� �û�������Ϣ��֤�������û��ṹ�壬���Է��������� user��
user login(){
  system("cls");
  printf("\n\n\n\n\n\n");

  char* f = "user.dat";
  int yanZhengMa1;
  int yanZhengMa;
  user s[1];
  int userTotal;
  user userArray[100];
  int index;

  userTotal = readUserFromFile(userArray,f);//��ȡ�ļ�����ע���û�������
  while(1){
      printf("\t\t\t\t\t      С������ϵͳ-->�û���¼\n");
      printf("\t\t\t\t\t==================================\n");
      printf("\t\t\t\t\t�˺ţ�  [          ]\b\b\b\b\b\b\b\b\b\b\b");
      scanf("%s",s[0].userId);
      printf("\n");

      printf("\t\t\t\t\t���룺  [      ]\b\b\b\b\b\b\b");
      scanf("%s",s[0].passWord);
      printf("\n");

      srand(time(0));
      yanZhengMa=(rand()%1000+1000)*5/3+1234;
      printf("\t\t\t\t\t��֤�룺[    ](%d)\b\b\b\b\b\b\b\b\b\b\b",yanZhengMa);
      scanf("%d",&yanZhengMa1);
      do{
        if(yanZhengMa!=yanZhengMa1){
            printf("��֤�����\n");
        }else{
            break;
        }
        yanZhengMa=(rand()%1000+1000)*5/3+1234;
        printf("\t\t\t\t\t��֤�룺[    ](%d)\b\b\b\b\b\b\b\b\b\b\b",yanZhengMa);
        scanf("%d",&yanZhengMa1);
      }while(yanZhengMa!=yanZhengMa1);

      index = userSearch(userArray,userTotal,s[0].userId);//��ȡ���˺��û����������±ꡣ
			decryption(userArray[index].passWord);//������ܡ�
      if(index == -1){
        printf("\t\t\t\t�û�������!\n");
      }else if(strcmp(userArray[index].passWord,s[0].passWord) != 0){
          printf("\t\t\t\t���벻��ȷ!\n");
      }else{
          break;
      }
  }
  return userArray[index];
}

/******************��ҳ��ӡ�û�*********************/
void printUser(user userArray[],int userTotal){
    int i,j,k;
    int page = 0,totalPage;
    unsigned short ch;

    if(userTotal > 0){
        totalPage = (userTotal + 9) / 10;//����ҳ��

        for(i = 0;i < userTotal;){
            system("cls");
            page++;
            printf("%13s%8s%10s%13s%16s%14s%12s\n","�û��˺�","�û���","����","email","�绰","�û���ɫ","��ַ");

            for(k = 0;k < 80;k++){
                putchar('-');
            }
            printf("\n");
            for(j = 0;j < 10 && i < userTotal;j++){
                printf("%13s",userArray[i].userId);
                printf("%8s",userArray[i].name);
                decryption(userArray[i].passWord);
                printf("%12s",userArray[i].passWord);
                encryption(userArray[i].passWord);
                printf("%18s",userArray[i].email);
                printf("%13s",userArray[i].phone);
                printf("%5d",userArray[i].role);
                printf("%12s",userArray[i].addr);
                printf("\n");
                i++;
            }
            printf("\n");
            for(k = 0;k < 80;k++){
                putchar('-');
            }
            printf("\n");
            printf("��%dҳ����%dҳ����һҳ(��),��һҳ(��),esc��������ʾ\n",page,totalPage);
            ch = getch();
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

/**********����Ա�����û�ʱ�û���Ϣ����ģ��********************/
void inputUser(){
    int counter = 0;
    user account[1];
    user userArray[200];
    int userTotal;
    int order = 0;
    int order1 = 1;

    userTotal = readUserFromFile(userArray,"user.dat");

    printf("\t\t\t\t\t      ���������û�\n");
    printf("\t\t\t\t\t==================================\n");
    if(userTotal < MAX_USER){

        while(order1 == 1){
            while(order == 0){
                system("cls");    //�����Ļ
                printf("\t\t\t�û��˺�:");
                scanf("%s",account[0].userId);
                printf("\n\n\n\n");
                printf("\t\t\t�û���:");
                scanf("%s",account[0].name);
                printf("\n");
                printf("\t\t\t����:");
                scanf("%s",account[0].passWord);
                printf("\n");
                printf("\t\t\temail��");
                scanf("%s",account[0].email);
                printf("\n");
                printf("\t\t\t�绰��");
                scanf("%s",account[0].phone);
                printf("\n");
                printf("\t\t\t��ɫ��");
                scanf("%d",&account[0].role);
                printf("\n");
                printf("\t\t\t��ַ��");
                scanf("%s",account[0].addr);
                printf("\n");
                printf("\n\t\t\t    ȷ�ϣ�[1]\n");
                printf("\t\t\t�������룺[0]\n");
                printf("\t\t\t��ѡ��: [ ]\b\b");
                scanf("%d",&order);
          }
          order = 0;
          encryption(account[0].passWord);
          writeUserAfterFile(account,"user.dat",1);
          printf("�ɹ�����һ����Ʒ");
          counter++;
          userTotal++;
          if(userTotal == MAX_USER){
            break;
          }
          printf("\n\t\t\t������[1]\n");
          printf("\t\t\t�������ӣ�[0]\n");
          printf("\t\t\t : ѡ��[ ]\b\b");
          scanf("%d",&order1);
    }
    printf("�ɹ�����%d���û�",counter);
  }
}

/*****************����id����user**************************/
user loadUserById(char userId[]){
    user p;
    user userArray[100];
    int userTotal;
    int i;


    userTotal = readUserFromFile(userArray,"user.dat");
    for(i = 0;i < userTotal;i++){

        if(strcmp(userArray[i].userId,userId)==0){
            p = userArray[i];
            break;
        }
    }
    if(i == userTotal){
        printf("�Ҳ����˺�Ϊ%s����",userId);
        exit(-1);
    }
    return p;

}



/*********************ɾ���û�***************************/
int deleteUser(){
    int i = 0;
    char userId[11];
    userId[0]='1';
    user userArray[MAX_USER];

    printf("����Ҫɾ�����û��˺ţ�����0����:\n");
    while(userId[0] != '0'){
        scanf("%s",userId);
        if(userId[0] != '0'){
        	userArray [i] = loadUserById(userId);
        	i++;
        }
    }
    deleteUserFromFile(userArray,i);
    return i;
}

int menuAdminUser(){
    int c;

   printf("\n\n\n\n\n\n");
	 printf("\t\t\t\t\t             ����Աϵͳ\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t*           1 ��ҳ����û�         *\n");
                    printf("\t\t\t\t\t*           2 ���������û�         *\n");
                    printf("\t\t\t\t\t*           3 ����ɾ���û�         *\n");
                    printf("\t\t\t\t\t*           4 �����û�             *\n");
                    printf("\t\t\t\t\t*           5 ������һ��           *\n");
                    printf("\t\t\t\t\t*           6 �����û���Ϣ         *\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t������ѡ��[ ]\b\b");
                    scanf("%d",&c);
                    return c+10;
}
int menuAdminProduct(){
    int c;

	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t             ����Աϵͳ\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t*           1 ��ҳ��ʾ��Ʒ         *\n");
                    printf("\t\t\t\t\t*           2 ����������Ʒ         *\n");
                    printf("\t\t\t\t\t*           3 ����ɾ����Ʒ         *\n");
                    printf("\t\t\t\t\t*           4 ������Ʒ             *\n");
                    printf("\t\t\t\t\t*           5 ������һ��           *\n");
                    printf("\t\t\t\t\t*           6 ������Ʒ��Ϣ         *\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t������ѡ��[ ]\b\b");
                    scanf("%d",&c);
                    return c+20;
}

/*************��ʾ�û�ϸ��*****/
int userDetail(user searchedUser){
    int c;

    system("cls");    //�����Ļ
        printf("\n\n\n\n");
        printf("\t\t\t\t������%s",searchedUser.name);
        printf("\n\n");
        printf("\t\t\t\t�˺ţ�%s",searchedUser.userId);
        printf("\n\n");
        decryption(searchedUser.passWord);//�������
        printf("\t\t\t\t���룺%s",searchedUser.passWord);
        printf("\n\n");
        encryption(searchedUser.passWord);//�������
        printf("\t\t\t\t�绰��%s",searchedUser.phone);
        printf("\n\n");
        printf("\t\t\t\tEmail��%s",searchedUser.email);
        printf("\n\n");
        if(searchedUser.role==1)
            printf("\t\t\t\t��ɫ����ͨ�û�");
        else
            printf("\t\t\t\t��ɫ������Ա");
        printf("\n\n");
        printf("\t\t\t\t��ַ��%s",searchedUser.addr);
        printf("\n\n");
        printf("\t\t\t\t�޸ĸ��û���Ϣ��[1]\n");
        printf("\t\t\t\tɾ�����û���[2]\n");
        printf("\t\t\t\t���أ�[0]\n");
        printf("\t\t\t\t  ��ѡ��: [ ]\b\b");
        scanf("%d",&c);
        return c;
}
/*************************�����û�*************/
void search_user(){
    user searchedUser[1];
    char userId[11];
    int c;

    printf("\n\n\n\t\t\t����Ҫ�������û��˺�:\n\t\t\t");
    scanf("%s",userId);
    searchedUser[0]=loadUserById(userId);
    c=userDetail(searchedUser[0]);
    switch(c){
				  case 1: deleteUserFromFile(searchedUser,1);registe();break;//�޸��û���Ϣ
				  case 2: deleteUserFromFile(searchedUser,1);//ɾ�����û�
				  case 0: break;//������һ��
			 }
}
//*************��ʾ��ͨ�û���ɫ���ܲ˵�**************
   int menuUser(){
        int c;

        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t              �û�ϵͳ\n");
        printf("\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t*           1 �����Ʒ             *\n");
        printf("\t\t\t\t\t*           2 ������Ʒ             *\n");
        printf("\t\t\t\t\t*           3 ���ﳵ               *\n");
        printf("\t\t\t\t\t*           4 �޸ĸ�����Ϣ         *\n");
        printf("\t\t\t\t\t*           5 �޸ĵ�¼����         *\n");
        printf("\t\t\t\t\t*           6 �˳�ϵͳ             *\n");
        printf("\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t������ѡ��[ ]\b\b");
        scanf("%d",&c);
        return c;
   }

//****************��ʾ����Ա��ɫ���ܲ˵�*******************
int menuAdmin(){
        int c;


        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t             ����Աϵͳ\n");
        printf("\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t*           1 �û�����             *\n");
        printf("\t\t\t\t\t*           2 ��Ʒ����             *\n");
        printf("\t\t\t\t\t*           3 �޸ĵ�¼����         *\n");
        printf("\t\t\t\t\t*           4 �鿴���ж���         *\n");
        printf("\t\t\t\t\t*           5 �˳�ϵͳ             *\n");
        printf("\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t������ѡ��[ ]\b\b");
        scanf("%d",&c);
        system("cls");
        printf("\n\n\n\n\n\n");
        switch(c){
            case 1: printf("\t\t\t\t\t             ����Աϵͳ\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t*           1 ��ҳ����û�         *\n");
                    printf("\t\t\t\t\t*           2 ���������û�         *\n");
                    printf("\t\t\t\t\t*           3 ����ɾ���û�         *\n");
                    printf("\t\t\t\t\t*           4 �����û�             *\n");
                    printf("\t\t\t\t\t*           5 ������һ��           *\n");
                    printf("\t\t\t\t\t*           6 �����û���Ϣ         *\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t������ѡ��[ ]\b\b");
                    scanf("%d",&c);
                    return c+10;

            case 2: printf("\t\t\t\t\t             ����Աϵͳ\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t*           1 ��ҳ��ʾ��Ʒ         *\n");
                    printf("\t\t\t\t\t*           2 ����������Ʒ         *\n");
                    printf("\t\t\t\t\t*           3 ����ɾ����Ʒ         *\n");
                    printf("\t\t\t\t\t*           4 ������Ʒ             *\n");
                    printf("\t\t\t\t\t*           5 ������һ��           *\n");
                    printf("\t\t\t\t\t*           6 ������Ʒ��Ϣ         *\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t������ѡ��[ ]\b\b");
                    scanf("%d",&c);
                    return c+20;
            case 4:return c+40;
            case 3:return c;
            default:return 5;

        }
        return c;
   }

/*****************�޸ĵ�¼����**********/
void passwordChange(char currentUserId[]){
    system("cls");
    displayTopic("�޸ĵ�¼�������");
    user currentuser[1];
    char passWord1[LENGTH_OF_PASSWPRD+1];

    currentuser[0]=loadUserById(currentUserId);

    printf("����ԭ���룺");
    scanf("%s",passWord1);
    decryption(currentuser[0].passWord);
     while(strcmp(currentuser[0].passWord,passWord1)!=0){         //ȷ�������Ƿ���ȣ�����Ⱦ��ظ�ѭ����
            printf("����������ԭ���벻���\n");
            printf("����ԭ���룺");
            scanf("%s",passWord1);
            printf("\n\n");
        }
     deleteUserFromFile(currentuser,1);//�������
     printf("���������룺");
     scanf("%s",currentuser[0].passWord);
     encryption(currentuser[0].passWord);//�������
     writeUserAfterFile(currentuser,"user.dat",1);
}

//����Աģ��
void adminSystem(char currentUserId[]){
    int c,loop=0,loop1=2;
    user userArray[MAX_USER];
    int userTotal;
    int index;
    int productTotal;
    int tag;
    product productArray[PRODUCTID_MAX];
    order orderArray[1000];
    int orderTotal;
    while(loop1 == 2){
    	system("cls");
			c=menuAdmin();  //��ʾ����Ա��ɫ���ܲ˵����档
		//	if(c == 5){
          //      return;
			//}
			tag = 0;
		while(loop==0){
              userTotal = readUserFromFile(userArray,"user.dat");//��ȡ�ļ�����ע���û�������
			  index = userSearch(userArray,userTotal,currentUserId);//��ȡ���˺��û����������±ꡣ
			  productTotal = readProductFromFile(productArray,"product.dat");
			  orderTotal = readOrderFromFile(orderArray,"order.dat");
			system("cls");
			printf("\n\n");
			printf("\t%s",userArray[index].name);//��ʾ��ǰ�û�������
			showTime(0);    //��ʾ��ӭ���档
			if(tag != 0){
				if(c / 10 == 1){
					c = menuAdminUser(c);
				}else if(c / 10 == 2){
					c = menuAdminProduct(c);
				}else{
				    c=menuAdmin();
				}
			}
			if(c == 15 || c == 25){
				break;
			}

			switch(c){
				  case 11: printUser(userArray,userTotal);break;//��ҳ����û�
				  case 12: inputUser();break;//���������û�
				  case 13: deleteUser();break;//����ɾ���û�
				  case 14: search_user();break;//�����û�
				  case 21: printProduct(productArray,productTotal,currentUserId);break;//��ҳ��ʾ��Ʒ
				  case 22: inputProduct();break;//����������Ʒ
				  case 23: deleteProduct();break;//����ɾ����Ʒ
				  case 24: search_product(currentUserId);break;//������Ʒ
				  case 44: printAllOrder(orderArray,orderTotal,a.userId);break;
				  case 3:  passwordChange(currentUserId);break;//�޸ĵ�¼����
				  case 16: backupUser(userArray,userTotal);break;//�����û���Ϣ
                  case 26: backupProduct(productArray,productTotal,orderArray,orderTotal);break;//������Ʒ��Ϣ

				  case 5: return;//�˳�ϵͳ


			}
			tag = 1;
		}
	}
    return ;
}

//�û�ģ��
void userSystem(char currentUserId[]){
    int c,loop=2;
    user userArray[MAX_USER];
    int userTotal,productTotal;
    int index;
    product productArray[PRODUCTID_MAX];
    user currentuser[1];
    order orderArray[1000];
    int orderTotal;

    productTotal = readProductFromFile(productArray,"product.dat");
    userTotal = readUserFromFile(userArray,"user.dat");//��ȡ�ļ�����ע���û�������
    index = userSearch(userArray,userTotal,currentUserId);//��ȡ���˺��û����������±ꡣ
    currentuser[0]=userArray[index];

    while(loop==2){
        productTotal = readProductFromFile(productArray,"product.dat");
        userTotal = readUserFromFile(userArray,"user.dat");//��ȡ�ļ�����ע���û�������
        orderTotal = readOrderFromFile(orderArray,"order.dat");
        index = userSearch(userArray,userTotal,currentUserId);//��ȡ���˺��û����������±ꡣ
        currentuser[0]=userArray[index];
        system("cls");
        printf("\n\n");
        printf("\t%s",userArray[index].name);//��ʾ��ǰ�û�������
        showTime(0);    //��ʾ��ӭ���档
        c=menuUser();  //��ʾ�û���ɫ���ܲ˵����档
        switch(c){
              case 1: printProduct(productArray,productTotal,currentUserId);break;//��ҳ�����Ʒ
              case 2: search_product(currentUserId);break;//������Ʒ
              case 3: printOrder(orderArray,orderTotal,currentUserId);break;//���ﳵ
              case 4: deleteUserFromFile(currentuser,1);registe();break;//�޸ĸ�����Ϣ
              case 5: passwordChange(currentUserId);break;//�޸ĵ�¼����
              case 6: //���Ѽ�¼
              case 7:  return;//�˳�ϵͳ
        }
    }
    return ;
}

//�����û���ɫ��ͬ���벻ͬ�Ĺ�����ϵͳ
void enterSystem(int c,char currentUserId[]){
    switch(c){
        case 0:  adminSystem(currentUserId);break;
        case 1:  userSystem(currentUserId);break;

    }
}
