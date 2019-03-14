
/*********查询product***************/
//product不存在返回-1，存在的话返回该product所在数组的下标
int productSearch(product productArray[],int productTatal,int id){
   int i;

    	for(i = 0;i < productTatal;i++){
    		if(id == productArray[i].id){
    			return i;
    		}
    	}

     return -1;
}
/**********管理员添加商品时商品信息输入模块********************/
void inputProduct(){
    int counter = 0;
    product account[1];
    product productArray[200];
    int productTotal;
    int order = 0;
    int order1 = 1;
    int endId;

    productTotal = readProductFromFile(productArray,"product.dat");
    if(productTotal != 0){
        endId = productArray[productTotal-1].id;
    }else{
        endId = productArray[productTotal-1].id = 0;
    }

    printf("\t\t\t\t\t      批量添加商品\n");
    printf("\t\t\t\t\t==================================\n");
    if(productTotal < PRODUCTID_MAX){

        while(order1 == 1){
            while(order == 0){
                system("cls");    //清除屏幕
                account[0].id = ++endId;
                printf("\n\n\n\n");
                printf("\t\t\t商品名:");
                scanf("%s",account[0].name);
                printf("\n");
                printf("\t\t\t商品描述:");
                scanf("%s",account[0].descr);
                printf("\n");
                printf("\t\t\t上架否？：");
                scanf("%d",&account[0].status);
                printf("\n");
                printf("\t\t\t原价：");
                scanf("%lf",&account[0].normalPrice);
                printf("\n");
                printf("\t\t\t折后价：");
                scanf("%lf",&account[0].memberPrice);
                printf("\n");
                printf("\t\t\t库存：");
                scanf("%d",&account[0].stock);
                printf("\n");
                account[0].sales = 0;
                printf("\t\t\t类名：");
                scanf("%s",account[0].ofCategory);
                printf("\n\t\t\t    确认：[1]\n");
                printf("\t\t\t重新输入：[0]\n");
                printf("\t\t\t请选择: [ ]\b\b");
                scanf("%d",&order);
          }
          order = 0;
          writeProductAfterFile(account,"product.dat",1);
          printf("成功创建一条商品");
          counter++;
          productTotal++;
          if(productTotal == PRODUCTID_MAX){
            break;
          }
          printf("\n\t\t\t继续：[1]\n");
          printf("\t\t\t结束添加：[0]\n");

          printf("\t\t\t : 选择[ ]\b\b");
          scanf("%d",&order1);
    }
    printf("成功创建%d条商品",counter);
  }
}

/***************删除商品******************/
int deleteProductFromFile(product productDeleteArray[],int n){
    product productArray[200];
    int productTotal;
    int i,j,k;

    productTotal = readProductFromFile(productArray,"product.dat");
    for(i = 0;i < n;i++){
        for(j = 0;j < productTotal;j++){
            if(productDeleteArray[i] .id == productArray[j].id){
                for(k = j + 1;k < productTotal;k++){
                    productArray[k - 1] = productArray[k];
                }
                productTotal--;
                break;
            }


        }
    }

    writeProductToFile(productArray,"product.dat",productTotal);
    return productTotal;

}
/*********************删除商品***************************/
int deleteProduct(){
    int i = 0;
    int t;
    product productArray[200];
    printf("输入要删除的id输入0结束:\n");
    while(t != 0){
        scanf("%d",&t);
        if(t != 0){
        	productArray [i] = loadProductById(t);
        	i++;
        }

    }
    deleteProductFromFile(productArray,i);
    return i;
}
/**************************修改商品*****************************/
int updateProduct(int id[],int n){
    product productArray[200];
    int i;
    int productTotal;
    int index;
    int order = 0;
    productTotal = readProductFromFile(productArray,"product.dat");

    for(i = 0;i < n;i++){
        index = productSearch(productArray,productTotal,id[i]);

        while(order == 0){
            system("cls");    //清除屏幕
            printf("\n\n\n\n");
            printf("\t\t\t修改第%d条:",i);
            printf("\n");
            printf("\t\t\t商品名:");
            scanf("%s",productArray[index].name);
            printf("\n");
            printf("\t\t\t商品描述:");
            scanf("%s",productArray[index].descr);
            printf("\n");
            printf("\t\t\t上架否？：");
            scanf("%d",&productArray[index].status);
            printf("\n");
            printf("\t\t\t原价：");
            scanf("%lf",&productArray[index].normalPrice);
            printf("\n");
            printf("\t\t\t折后价：");
            scanf("%lf",&productArray[index].memberPrice);
            printf("\n");
            printf("\t\t\t库存：");
            scanf("%d",&productArray[index].stock);
            printf("\n");
            printf("\t\t\t类名：");
            scanf("%s",productArray[index].ofCategory);
            printf("\n\t\t\t    确认：[1]\n");
            printf("\t\t\t重新输入：[0]\n");
            printf("\t\t\t请选择: [ ]\b\b");
            scanf("%d",&order);
       }
       order = 0;
       if(writeProductToFile(productArray,"product.dat",productTotal) != -1){
         printf("成功修改一条商品");
       }
    }
    printf("成功修改%d条商品",n);
    return n;
}


/*********立即购该商品***********/
void buyPoduct(product searchedProduct,user currentUser){
    int index;
    product productArray[PRODUCTID_MAX];
    int productTotal;
    char **oIdArray = NULL;
    order quickOrder[1];
    item item1;
    int counts;
    int totalOrder;
    order orderArray[1000];
    totalOrder = readOrderFromFile(orderArray,"order.dat");

    printf("\n请输入要购买的数量:");
    scanf("%d",&counts);
    productTotal = readProductFromFile(productArray,"product.dat");//读取文件中商品信息
    index=productSearch(productArray,productTotal,searchedProduct.id);//得到当前商品下标
    if(index==-1)
        return;
    else{

        deleteProductFromFile(productArray,productTotal);//先删除文件中的商品数据
        productArray[index].stock=productArray[index].stock-counts;//库存-1
        productArray[index].sales=productArray[index].sales+counts;//销量+1
        writeProductToFile(productArray,"product.dat",productTotal);//重新写入数据
        oIdArray = getOrderID(1,oIdArray,currentUser.userId);//获得订单编号

        item1.number = 1;
        item1.id = searchedProduct.id;
        item1.counts =counts;
        item1.price = searchedProduct.memberPrice;

        quickOrder[0].number = totalOrder + 1;
        strcpy(quickOrder[0].id,oIdArray[0]);
        quickOrder[0].status = 0;
        quickOrder[0].items[0] = item1;
        quickOrder[0].itemNum = 1;
        quickOrder[0].totalPrice = item1.price *item1.counts;
        strcpy(quickOrder[0].addr,currentUser.addr1);

        writeOrderAfterFile(quickOrder,"order.dat",1);

    }
    return ;
}

/*************显示商品细节*****/
void  productDetail(product searchedProduct,char currentUserId[]){
    int c;
    system("cls");    //清除屏幕
        printf("\n\n\n\n");
        printf("\t\t\t\t商品编号：%d",searchedProduct.id);
        printf("\n\n");
        printf("\t\t\t\t商品名称：%s",searchedProduct.name);
        printf("\n\n");
        printf("\t\t\t\t商品描述：%s",searchedProduct.descr);
        printf("\n\n");

        if(searchedProduct.status==1)
            printf("\t\t\t\t是否上架：是");
        else
            printf("\t\t\t\t是否上架：否");
        printf("\n\n");
        printf("\t\t\t\t原价：%lf",searchedProduct.normalPrice);
        printf("\n\n");
        printf("\t\t\t\t折后价：%lf",searchedProduct.memberPrice);
        printf("\n\n");
        printf("\t\t\t\t库存：%d",searchedProduct.stock);
        printf("\n\n");
        printf("\t\t\t\t销量：%d",searchedProduct.sales);
        printf("\n\n");
        printf("\t\t\t\t商品类别：%s",searchedProduct.ofCategory);
        printf("\n\n");
        printf("\t\t\t\t立即购买该商品：[1]\n");
        printf("\t\t\t\t加入购物车：[2]\n");
        printf("\t\t\t\t返回：[0]\n");
        printf("\t\t\t\t  请选择: [ ]\b\b");
        scanf("%d",&c);
        switch(c){
              case 1: buyPoduct(searchedProduct,a);break;//立即购该商品
              case 2: //加入购物车
              case 0: break;//返回
        }
        return ;
}

/******************分页打印商品*********************/
void printProduct(product productArray[],int productTotal,char currentUserId[]){
    int i,j,k,x;
    int page = 0,totalPage;
    unsigned short ch;
    product searchedProduct;
    int pTotal;
    product pA[200];

    pTotal = readProductFromFile(pA,"product.dat");
    if(productTotal > 0){
        totalPage = (productTotal + 9) / 10;//计算页数

        for(i = 0;i < productTotal;){
            if(productTotal == pTotal){
                readProductFromFile(productArray,"product.dat");
            }

            system("cls");
            page++;
            printf("%12s%15s%12s%12s%12s%12s%12s%12s\n","商品编号","商品名","是否上架","原价","折后价","库存","销量","类名");

            for(k = 0;k < 80;k++){
                putchar('-');
            }
            printf("\n");
            for(j = 0;j < 10 && i < productTotal;j++){
                printf("%12d",productArray[i].id);
                printf("%15s",productArray[i].name);
                printf("%12d",productArray[i].status);
                printf("%12lf",productArray[i].normalPrice);
                printf("%12lf",productArray[i].memberPrice);
                printf("%12d",productArray[i].stock);
                printf("%12d",productArray[i].sales);
                printf("%15s",productArray[i].ofCategory);
                printf("\n");
                i++;
            }
            printf("\n");
            for(k = 0;k < 80;k++){
                putchar('-');
            }
            printf("\n");
            printf("第%d页，共%d页，上一页(↑),下一页(↓),esc键结束显示,输入TAB键进行商品选项。\n",page,totalPage);
            printf("\n共搜索到%d个产品\n",productTotal);
            ch = getch();
            if(9 == ch){
                printf("输入商品编号查看商品详细信息\n");
                scanf("%d",&x);
	            system("cls");
	            searchedProduct=loadProductById(x);
                productDetail(searchedProduct,currentUserId);
                i = i- j;
                if(i >10){
                    i = i - 10;
                    page -= 2;
                }else{
                    i = 0;
                    page = 0;
                }

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


/***********产品搜索函数**************/
int productSearchKmp(product productSearchedArray[],char p[]){
    product productArray[PRODUCTID_MAX];
    int productTotal;
    int index = 0;
    int i;
    int *next;
    int length;

    productTotal = readProductFromFile(productArray,"product.dat");
    length = strlen(p);
    next = (int *)(malloc(length*sizeof(int)));
    makeNext(p,next);
    for(i = 0;i < productTotal;i++){
        if(kmpSearch(productArray[i].name,p,next) != -1){
            productSearchedArray[index++] = productArray[i];
        }
    }

    return index;
}
/**************产品搜索模块*************/
void search_product(char currentUserId[]){
    product productSearchedArray[200];
    char p[20];
    int sCount;

    printf("\n\n\n\t\t\t输入要搜索的产品名:\n\t\t\t");
    scanf("%s",p);
    sCount = productSearchKmp(productSearchedArray,p);
    printProduct(productSearchedArray,sCount,currentUserId);

}

