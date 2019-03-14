/****************用户注册*****************/
void registe(){
    user a[1];
    user userArray[MAX_USER];
    int userTotal;

    char passWord1[LENGTH_OF_PASSWPRD +1];
    int b=0;//b为0则重新注册。;

    userTotal = readUserFromFile(userArray,"user.dat");// 读取已注册用户个数。
    while(b==0){
    		a[0].role = 1;
        system("cls");    //清除屏幕
        printf("\n\n\n\n");
        printf("\t\t\t    姓名：");
        scanf("%s",a[0].name);
        printf("\n\n");
        while(1){
            printf("\t\t\t    账号：");
            scanf("%s",a[0].userId);
            if(userSearch(userArray,userTotal,a[0].userId) != -1){
                printf("\t\t\t该账号已注册!\n");
            }else{
                break;
            }
        }
        printf("\n\n");
        printf("\t\t\t    密码：");
        scanf("%s",passWord1);
        printf("\n\n");
        printf("\t\t\t确认密码：");
        scanf("%s",a[0].passWord);
        printf("\n\n");

        while(strcmp(a[0].passWord,passWord1)!=0){         //确认密码是否相等，不相等就重复循环。
            printf("\t\t\t输入密码与上一个不相等\n");
            printf("\t\t\t确认密码：");
            scanf("%s",a[0].passWord);
            printf("\n\n");
        }

        encryption(a[0].passWord);//密码加密

        printf("\t\t\t    电话：");
        scanf("%s",a[0].phone);
        printf("\n\n");
        printf("\t\t\t   Email：");
        scanf("%s",a[0].email);
        printf("\n\n");
        printf("\t\t\t    地址：");
        scanf("%s",a[0].addr);
        printf("\n\n");
        printf("\t\t\t    确认：[1]\n");
        printf("\t\t\t重新输入：[0]\n");
        printf("\t\t\t  请选择: [ ]\b\b");
        scanf("%d",&b);
   }
   writeUserAfterFile(a,"user.dat",1);
}
//函数名称 login
//登录界面
//入口参数 char ...
//函数功能 ： 用户身份信息验证，返回用户结构体，所以返回类型是 user。
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

  userTotal = readUserFromFile(userArray,f);//读取文件中已注册用户个数。
  while(1){
      printf("\t\t\t\t\t      小型销售系统-->用户登录\n");
      printf("\t\t\t\t\t==================================\n");
      printf("\t\t\t\t\t账号：  [          ]\b\b\b\b\b\b\b\b\b\b\b");
      scanf("%s",s[0].userId);
      printf("\n");

      printf("\t\t\t\t\t密码：  [      ]\b\b\b\b\b\b\b");
      scanf("%s",s[0].passWord);
      printf("\n");

      srand(time(0));
      yanZhengMa=(rand()%1000+1000)*5/3+1234;
      printf("\t\t\t\t\t验证码：[    ](%d)\b\b\b\b\b\b\b\b\b\b\b",yanZhengMa);
      scanf("%d",&yanZhengMa1);
      do{
        if(yanZhengMa!=yanZhengMa1){
            printf("验证码错误\n");
        }else{
            break;
        }
        yanZhengMa=(rand()%1000+1000)*5/3+1234;
        printf("\t\t\t\t\t验证码：[    ](%d)\b\b\b\b\b\b\b\b\b\b\b",yanZhengMa);
        scanf("%d",&yanZhengMa1);
      }while(yanZhengMa!=yanZhengMa1);

      index = userSearch(userArray,userTotal,s[0].userId);//获取该账号用户所在数组下标。
			decryption(userArray[index].passWord);//密码解密。
      if(index == -1){
        printf("\t\t\t\t用户不存在!\n");
      }else if(strcmp(userArray[index].passWord,s[0].passWord) != 0){
          printf("\t\t\t\t密码不正确!\n");
      }else{
          break;
      }
  }
  return userArray[index];
}

/******************分页打印用户*********************/
void printUser(user userArray[],int userTotal){
    int i,j,k;
    int page = 0,totalPage;
    unsigned short ch;

    if(userTotal > 0){
        totalPage = (userTotal + 9) / 10;//计算页数

        for(i = 0;i < userTotal;){
            system("cls");
            page++;
            printf("%13s%8s%10s%13s%16s%14s%12s\n","用户账号","用户名","密码","email","电话","用户角色","地址");

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
            printf("第%d页，共%d页，上一页(↑),下一页(↓),esc键结束显示\n",page,totalPage);
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

/**********管理员添加用户时用户信息输入模块********************/
void inputUser(){
    int counter = 0;
    user account[1];
    user userArray[200];
    int userTotal;
    int order = 0;
    int order1 = 1;

    userTotal = readUserFromFile(userArray,"user.dat");

    printf("\t\t\t\t\t      批量添加用户\n");
    printf("\t\t\t\t\t==================================\n");
    if(userTotal < MAX_USER){

        while(order1 == 1){
            while(order == 0){
                system("cls");    //清除屏幕
                printf("\t\t\t用户账号:");
                scanf("%s",account[0].userId);
                printf("\n\n\n\n");
                printf("\t\t\t用户名:");
                scanf("%s",account[0].name);
                printf("\n");
                printf("\t\t\t密码:");
                scanf("%s",account[0].passWord);
                printf("\n");
                printf("\t\t\temail：");
                scanf("%s",account[0].email);
                printf("\n");
                printf("\t\t\t电话：");
                scanf("%s",account[0].phone);
                printf("\n");
                printf("\t\t\t角色：");
                scanf("%d",&account[0].role);
                printf("\n");
                printf("\t\t\t地址：");
                scanf("%s",account[0].addr);
                printf("\n");
                printf("\n\t\t\t    确认：[1]\n");
                printf("\t\t\t重新输入：[0]\n");
                printf("\t\t\t请选择: [ ]\b\b");
                scanf("%d",&order);
          }
          order = 0;
          encryption(account[0].passWord);
          writeUserAfterFile(account,"user.dat",1);
          printf("成功创建一条商品");
          counter++;
          userTotal++;
          if(userTotal == MAX_USER){
            break;
          }
          printf("\n\t\t\t继续：[1]\n");
          printf("\t\t\t结束添加：[0]\n");
          printf("\t\t\t : 选择[ ]\b\b");
          scanf("%d",&order1);
    }
    printf("成功创建%d个用户",counter);
  }
}

/*****************根据id加载user**************************/
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
        printf("找不到账号为%s的数",userId);
        exit(-1);
    }
    return p;

}



/*********************删除用户***************************/
int deleteUser(){
    int i = 0;
    char userId[11];
    userId[0]='1';
    user userArray[MAX_USER];

    printf("输入要删除的用户账号，输入0结束:\n");
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
	 printf("\t\t\t\t\t             管理员系统\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t*           1 分页浏览用户         *\n");
                    printf("\t\t\t\t\t*           2 批量添加用户         *\n");
                    printf("\t\t\t\t\t*           3 批量删除用户         *\n");
                    printf("\t\t\t\t\t*           4 搜索用户             *\n");
                    printf("\t\t\t\t\t*           5 返回上一级           *\n");
                    printf("\t\t\t\t\t*           6 备份用户信息         *\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t请输入选项[ ]\b\b");
                    scanf("%d",&c);
                    return c+10;
}
int menuAdminProduct(){
    int c;

	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t             管理员系统\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t*           1 分页显示商品         *\n");
                    printf("\t\t\t\t\t*           2 批量添加商品         *\n");
                    printf("\t\t\t\t\t*           3 批量删除商品         *\n");
                    printf("\t\t\t\t\t*           4 搜索商品             *\n");
                    printf("\t\t\t\t\t*           5 返回上一级           *\n");
                    printf("\t\t\t\t\t*           6 备份商品信息         *\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t请输入选项[ ]\b\b");
                    scanf("%d",&c);
                    return c+20;
}

/*************显示用户细节*****/
int userDetail(user searchedUser){
    int c;

    system("cls");    //清除屏幕
        printf("\n\n\n\n");
        printf("\t\t\t\t姓名：%s",searchedUser.name);
        printf("\n\n");
        printf("\t\t\t\t账号：%s",searchedUser.userId);
        printf("\n\n");
        decryption(searchedUser.passWord);//密码解密
        printf("\t\t\t\t密码：%s",searchedUser.passWord);
        printf("\n\n");
        encryption(searchedUser.passWord);//密码加密
        printf("\t\t\t\t电话：%s",searchedUser.phone);
        printf("\n\n");
        printf("\t\t\t\tEmail：%s",searchedUser.email);
        printf("\n\n");
        if(searchedUser.role==1)
            printf("\t\t\t\t角色：普通用户");
        else
            printf("\t\t\t\t角色：管理员");
        printf("\n\n");
        printf("\t\t\t\t地址：%s",searchedUser.addr);
        printf("\n\n");
        printf("\t\t\t\t修改该用户信息：[1]\n");
        printf("\t\t\t\t删除该用户：[2]\n");
        printf("\t\t\t\t返回：[0]\n");
        printf("\t\t\t\t  请选择: [ ]\b\b");
        scanf("%d",&c);
        return c;
}
/*************************搜索用户*************/
void search_user(){
    user searchedUser[1];
    char userId[11];
    int c;

    printf("\n\n\n\t\t\t输入要搜索的用户账号:\n\t\t\t");
    scanf("%s",userId);
    searchedUser[0]=loadUserById(userId);
    c=userDetail(searchedUser[0]);
    switch(c){
				  case 1: deleteUserFromFile(searchedUser,1);registe();break;//修改用户信息
				  case 2: deleteUserFromFile(searchedUser,1);//删除该用户
				  case 0: break;//返回上一级
			 }
}
//*************显示普通用户角色功能菜单**************
   int menuUser(){
        int c;

        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t              用户系统\n");
        printf("\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t*           1 浏览商品             *\n");
        printf("\t\t\t\t\t*           2 搜索商品             *\n");
        printf("\t\t\t\t\t*           3 购物车               *\n");
        printf("\t\t\t\t\t*           4 修改个人信息         *\n");
        printf("\t\t\t\t\t*           5 修改登录密码         *\n");
        printf("\t\t\t\t\t*           6 退出系统             *\n");
        printf("\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t请输入选项[ ]\b\b");
        scanf("%d",&c);
        return c;
   }

//****************显示管理员角色功能菜单*******************
int menuAdmin(){
        int c;


        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t             管理员系统\n");
        printf("\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t*           1 用户管理             *\n");
        printf("\t\t\t\t\t*           2 商品管理             *\n");
        printf("\t\t\t\t\t*           3 修改登录密码         *\n");
        printf("\t\t\t\t\t*           4 查看所有订单         *\n");
        printf("\t\t\t\t\t*           5 退出系统             *\n");
        printf("\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t请输入选项[ ]\b\b");
        scanf("%d",&c);
        system("cls");
        printf("\n\n\n\n\n\n");
        switch(c){
            case 1: printf("\t\t\t\t\t             管理员系统\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t*           1 分页浏览用户         *\n");
                    printf("\t\t\t\t\t*           2 批量添加用户         *\n");
                    printf("\t\t\t\t\t*           3 批量删除用户         *\n");
                    printf("\t\t\t\t\t*           4 搜索用户             *\n");
                    printf("\t\t\t\t\t*           5 返回上一级           *\n");
                    printf("\t\t\t\t\t*           6 备份用户信息         *\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t请输入选项[ ]\b\b");
                    scanf("%d",&c);
                    return c+10;

            case 2: printf("\t\t\t\t\t             管理员系统\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t*           1 分页显示商品         *\n");
                    printf("\t\t\t\t\t*           2 批量添加商品         *\n");
                    printf("\t\t\t\t\t*           3 批量删除商品         *\n");
                    printf("\t\t\t\t\t*           4 搜索商品             *\n");
                    printf("\t\t\t\t\t*           5 返回上一级           *\n");
                    printf("\t\t\t\t\t*           6 备份商品信息         *\n");
                    printf("\t\t\t\t\t====================================\n");
                    printf("\t\t\t\t\t请输入选项[ ]\b\b");
                    scanf("%d",&c);
                    return c+20;
            case 4:return c+40;
            case 3:return c;
            default:return 5;

        }
        return c;
   }

/*****************修改登录密码**********/
void passwordChange(char currentUserId[]){
    system("cls");
    displayTopic("修改登录密码界面");
    user currentuser[1];
    char passWord1[LENGTH_OF_PASSWPRD+1];

    currentuser[0]=loadUserById(currentUserId);

    printf("输入原密码：");
    scanf("%s",passWord1);
    decryption(currentuser[0].passWord);
     while(strcmp(currentuser[0].passWord,passWord1)!=0){         //确认密码是否相等，不相等就重复循环。
            printf("输入密码与原密码不相等\n");
            printf("输入原密码：");
            scanf("%s",passWord1);
            printf("\n\n");
        }
     deleteUserFromFile(currentuser,1);//密码解密
     printf("输入新密码：");
     scanf("%s",currentuser[0].passWord);
     encryption(currentuser[0].passWord);//密码加密
     writeUserAfterFile(currentuser,"user.dat",1);
}

//管理员模块
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
			c=menuAdmin();  //显示管理员角色功能菜单界面。
		//	if(c == 5){
          //      return;
			//}
			tag = 0;
		while(loop==0){
              userTotal = readUserFromFile(userArray,"user.dat");//读取文件中已注册用户个数。
			  index = userSearch(userArray,userTotal,currentUserId);//获取该账号用户所在数组下标。
			  productTotal = readProductFromFile(productArray,"product.dat");
			  orderTotal = readOrderFromFile(orderArray,"order.dat");
			system("cls");
			printf("\n\n");
			printf("\t%s",userArray[index].name);//显示当前用户姓名。
			showTime(0);    //显示欢迎界面。
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
				  case 11: printUser(userArray,userTotal);break;//分页浏览用户
				  case 12: inputUser();break;//批量添加用户
				  case 13: deleteUser();break;//批量删除用户
				  case 14: search_user();break;//搜索用户
				  case 21: printProduct(productArray,productTotal,currentUserId);break;//分页显示商品
				  case 22: inputProduct();break;//批量添加商品
				  case 23: deleteProduct();break;//批量删除商品
				  case 24: search_product(currentUserId);break;//搜索商品
				  case 44: printAllOrder(orderArray,orderTotal,a.userId);break;
				  case 3:  passwordChange(currentUserId);break;//修改登录密码
				  case 16: backupUser(userArray,userTotal);break;//备份用户信息
                  case 26: backupProduct(productArray,productTotal,orderArray,orderTotal);break;//备份商品信息

				  case 5: return;//退出系统


			}
			tag = 1;
		}
	}
    return ;
}

//用户模块
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
    userTotal = readUserFromFile(userArray,"user.dat");//读取文件中已注册用户个数。
    index = userSearch(userArray,userTotal,currentUserId);//获取该账号用户所在数组下标。
    currentuser[0]=userArray[index];

    while(loop==2){
        productTotal = readProductFromFile(productArray,"product.dat");
        userTotal = readUserFromFile(userArray,"user.dat");//读取文件中已注册用户个数。
        orderTotal = readOrderFromFile(orderArray,"order.dat");
        index = userSearch(userArray,userTotal,currentUserId);//获取该账号用户所在数组下标。
        currentuser[0]=userArray[index];
        system("cls");
        printf("\n\n");
        printf("\t%s",userArray[index].name);//显示当前用户姓名。
        showTime(0);    //显示欢迎界面。
        c=menuUser();  //显示用户角色功能菜单界面。
        switch(c){
              case 1: printProduct(productArray,productTotal,currentUserId);break;//分页浏览商品
              case 2: search_product(currentUserId);break;//搜索商品
              case 3: printOrder(orderArray,orderTotal,currentUserId);break;//购物车
              case 4: deleteUserFromFile(currentuser,1);registe();break;//修改个人信息
              case 5: passwordChange(currentUserId);break;//修改登录密码
              case 6: //消费记录
              case 7:  return;//退出系统
        }
    }
    return ;
}

//根据用户角色不同进入不同的管理子系统
void enterSystem(int c,char currentUserId[]){
    switch(c){
        case 0:  adminSystem(currentUserId);break;
        case 1:  userSystem(currentUserId);break;

    }
}

