/*#################全局变量#########################*/
/*****************用户区全局变量***********************/
#define MAX_USER 1000//最多用户100个
#define LENGTH_OF_USERID 10//用户名长度
#define LENGTH_OF_PASSWPRD 6//密码长度

/************产品区全局变量********************/
#define PRODUCTID_MAX 200//200钟商品
/*#######################################*/



/****************用户节点**********************/
struct usernode {
    char userId[LENGTH_OF_USERID+1];
    char name[9];
    char passWord[LENGTH_OF_PASSWPRD+1];
    char email[16];
    char phone[12];
    int role;
    char addr[80];
    char addr1[80];
    char addr2[80];
};
typedef struct usernode user;

/**************产品节点******************/
struct productnode{
	  int id;//自动增长，从0开始
	  char name[30];
	  char descr[100];//商品描述
	  int status;//是否上架
	  double normalPrice;//原价
	  double memberPrice;//折后价
	  int stock;//库存
	  int sales;//销量
	  char ofCategory[15];//所属类的id
};
typedef struct productnode product;

/*
比如：17年10月23号账号为1234567890的用户在时间分别为01:01:01, 02:02:02, 03:03:03,
下单了商品；在第一个时间下了4种商品，超过了3，前3个打包一个订单；第四个为第
二个定单，前者订单号为12345678901710230101010，多出来的第四个为第二个订单为12345678901710230101011；
第二个时间两个商品，订单号为12345678901710230101012，
第三个时间两个商品，订单号为12345678901710230101013；
订单1总价 = (item1.count)*(item1.price) + (item2.count)*(item2.price) +
(item3.count)*item3.price)
*/
/**************订单内一个商品项*********************/
struct itemNode{
    int number;//序号
    int id;//商品id比如黑人牙膏的id38
    int counts;//商品项数量
    double price;//下单单价
};
typedef struct itemNode item;

/***************订单******************/
struct orderNode{
    int number;
    char id[24];//账号+下单时间(yymmddhhmmss)+下单顺序
    int status ;//1或0
    int itemNum;
    item items[3];//超过3生成新订单
    double totalPrice;
    char addr[81];
};

typedef struct orderNode order;
