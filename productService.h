
/*********��ѯproduct***************/
//product�����ڷ���-1�����ڵĻ����ظ�product����������±�
int productSearch(product productArray[],int productTatal,int id){
   int i;

    	for(i = 0;i < productTatal;i++){
    		if(id == productArray[i].id){
    			return i;
    		}
    	}

     return -1;
}
/**********����Ա�����Ʒʱ��Ʒ��Ϣ����ģ��********************/
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

    printf("\t\t\t\t\t      ���������Ʒ\n");
    printf("\t\t\t\t\t==================================\n");
    if(productTotal < PRODUCTID_MAX){

        while(order1 == 1){
            while(order == 0){
                system("cls");    //�����Ļ
                account[0].id = ++endId;
                printf("\n\n\n\n");
                printf("\t\t\t��Ʒ��:");
                scanf("%s",account[0].name);
                printf("\n");
                printf("\t\t\t��Ʒ����:");
                scanf("%s",account[0].descr);
                printf("\n");
                printf("\t\t\t�ϼܷ񣿣�");
                scanf("%d",&account[0].status);
                printf("\n");
                printf("\t\t\tԭ�ۣ�");
                scanf("%lf",&account[0].normalPrice);
                printf("\n");
                printf("\t\t\t�ۺ�ۣ�");
                scanf("%lf",&account[0].memberPrice);
                printf("\n");
                printf("\t\t\t��棺");
                scanf("%d",&account[0].stock);
                printf("\n");
                account[0].sales = 0;
                printf("\t\t\t������");
                scanf("%s",account[0].ofCategory);
                printf("\n\t\t\t    ȷ�ϣ�[1]\n");
                printf("\t\t\t�������룺[0]\n");
                printf("\t\t\t��ѡ��: [ ]\b\b");
                scanf("%d",&order);
          }
          order = 0;
          writeProductAfterFile(account,"product.dat",1);
          printf("�ɹ�����һ����Ʒ");
          counter++;
          productTotal++;
          if(productTotal == PRODUCTID_MAX){
            break;
          }
          printf("\n\t\t\t������[1]\n");
          printf("\t\t\t������ӣ�[0]\n");

          printf("\t\t\t : ѡ��[ ]\b\b");
          scanf("%d",&order1);
    }
    printf("�ɹ�����%d����Ʒ",counter);
  }
}

/***************ɾ����Ʒ******************/
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
/*********************ɾ����Ʒ***************************/
int deleteProduct(){
    int i = 0;
    int t;
    product productArray[200];
    printf("����Ҫɾ����id����0����:\n");
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
/**************************�޸���Ʒ*****************************/
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
            system("cls");    //�����Ļ
            printf("\n\n\n\n");
            printf("\t\t\t�޸ĵ�%d��:",i);
            printf("\n");
            printf("\t\t\t��Ʒ��:");
            scanf("%s",productArray[index].name);
            printf("\n");
            printf("\t\t\t��Ʒ����:");
            scanf("%s",productArray[index].descr);
            printf("\n");
            printf("\t\t\t�ϼܷ񣿣�");
            scanf("%d",&productArray[index].status);
            printf("\n");
            printf("\t\t\tԭ�ۣ�");
            scanf("%lf",&productArray[index].normalPrice);
            printf("\n");
            printf("\t\t\t�ۺ�ۣ�");
            scanf("%lf",&productArray[index].memberPrice);
            printf("\n");
            printf("\t\t\t��棺");
            scanf("%d",&productArray[index].stock);
            printf("\n");
            printf("\t\t\t������");
            scanf("%s",productArray[index].ofCategory);
            printf("\n\t\t\t    ȷ�ϣ�[1]\n");
            printf("\t\t\t�������룺[0]\n");
            printf("\t\t\t��ѡ��: [ ]\b\b");
            scanf("%d",&order);
       }
       order = 0;
       if(writeProductToFile(productArray,"product.dat",productTotal) != -1){
         printf("�ɹ��޸�һ����Ʒ");
       }
    }
    printf("�ɹ��޸�%d����Ʒ",n);
    return n;
}


/*********����������Ʒ***********/
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

    printf("\n������Ҫ���������:");
    scanf("%d",&counts);
    productTotal = readProductFromFile(productArray,"product.dat");//��ȡ�ļ�����Ʒ��Ϣ
    index=productSearch(productArray,productTotal,searchedProduct.id);//�õ���ǰ��Ʒ�±�
    if(index==-1)
        return;
    else{

        deleteProductFromFile(productArray,productTotal);//��ɾ���ļ��е���Ʒ����
        productArray[index].stock=productArray[index].stock-counts;//���-1
        productArray[index].sales=productArray[index].sales+counts;//����+1
        writeProductToFile(productArray,"product.dat",productTotal);//����д������
        oIdArray = getOrderID(1,oIdArray,currentUser.userId);//��ö������

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

/*************��ʾ��Ʒϸ��*****/
void  productDetail(product searchedProduct,char currentUserId[]){
    int c;
    system("cls");    //�����Ļ
        printf("\n\n\n\n");
        printf("\t\t\t\t��Ʒ��ţ�%d",searchedProduct.id);
        printf("\n\n");
        printf("\t\t\t\t��Ʒ���ƣ�%s",searchedProduct.name);
        printf("\n\n");
        printf("\t\t\t\t��Ʒ������%s",searchedProduct.descr);
        printf("\n\n");

        if(searchedProduct.status==1)
            printf("\t\t\t\t�Ƿ��ϼܣ���");
        else
            printf("\t\t\t\t�Ƿ��ϼܣ���");
        printf("\n\n");
        printf("\t\t\t\tԭ�ۣ�%lf",searchedProduct.normalPrice);
        printf("\n\n");
        printf("\t\t\t\t�ۺ�ۣ�%lf",searchedProduct.memberPrice);
        printf("\n\n");
        printf("\t\t\t\t��棺%d",searchedProduct.stock);
        printf("\n\n");
        printf("\t\t\t\t������%d",searchedProduct.sales);
        printf("\n\n");
        printf("\t\t\t\t��Ʒ���%s",searchedProduct.ofCategory);
        printf("\n\n");
        printf("\t\t\t\t�����������Ʒ��[1]\n");
        printf("\t\t\t\t���빺�ﳵ��[2]\n");
        printf("\t\t\t\t���أ�[0]\n");
        printf("\t\t\t\t  ��ѡ��: [ ]\b\b");
        scanf("%d",&c);
        switch(c){
              case 1: buyPoduct(searchedProduct,a);break;//����������Ʒ
              case 2: //���빺�ﳵ
              case 0: break;//����
        }
        return ;
}

/******************��ҳ��ӡ��Ʒ*********************/
void printProduct(product productArray[],int productTotal,char currentUserId[]){
    int i,j,k,x;
    int page = 0,totalPage;
    unsigned short ch;
    product searchedProduct;
    int pTotal;
    product pA[200];

    pTotal = readProductFromFile(pA,"product.dat");
    if(productTotal > 0){
        totalPage = (productTotal + 9) / 10;//����ҳ��

        for(i = 0;i < productTotal;){
            if(productTotal == pTotal){
                readProductFromFile(productArray,"product.dat");
            }

            system("cls");
            page++;
            printf("%12s%15s%12s%12s%12s%12s%12s%12s\n","��Ʒ���","��Ʒ��","�Ƿ��ϼ�","ԭ��","�ۺ��","���","����","����");

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
            printf("��%dҳ����%dҳ����һҳ(��),��һҳ(��),esc��������ʾ,����TAB��������Ʒѡ�\n",page,totalPage);
            printf("\n��������%d����Ʒ\n",productTotal);
            ch = getch();
            if(9 == ch){
                printf("������Ʒ��Ų鿴��Ʒ��ϸ��Ϣ\n");
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


/***********��Ʒ��������**************/
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
/**************��Ʒ����ģ��*************/
void search_product(char currentUserId[]){
    product productSearchedArray[200];
    char p[20];
    int sCount;

    printf("\n\n\n\t\t\t����Ҫ�����Ĳ�Ʒ��:\n\t\t\t");
    scanf("%s",p);
    sCount = productSearchKmp(productSearchedArray,p);
    printProduct(productSearchedArray,sCount,currentUserId);

}

