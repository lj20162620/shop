/*#################ȫ�ֱ���#########################*/
/*****************�û���ȫ�ֱ���***********************/
#define MAX_USER 1000//����û�100��
#define LENGTH_OF_USERID 10//�û�������
#define LENGTH_OF_PASSWPRD 6//���볤��

/************��Ʒ��ȫ�ֱ���********************/
#define PRODUCTID_MAX 200//200����Ʒ
/*#######################################*/



/****************�û��ڵ�**********************/
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

/**************��Ʒ�ڵ�******************/
struct productnode{
	  int id;//�Զ���������0��ʼ
	  char name[30];
	  char descr[100];//��Ʒ����
	  int status;//�Ƿ��ϼ�
	  double normalPrice;//ԭ��
	  double memberPrice;//�ۺ��
	  int stock;//���
	  int sales;//����
	  char ofCategory[15];//�������id
};
typedef struct productnode product;

/*
���磺17��10��23���˺�Ϊ1234567890���û���ʱ��ֱ�Ϊ01:01:01, 02:02:02, 03:03:03,
�µ�����Ʒ���ڵ�һ��ʱ������4����Ʒ��������3��ǰ3�����һ�����������ĸ�Ϊ��
����������ǰ�߶�����Ϊ12345678901710230101010��������ĵ��ĸ�Ϊ�ڶ�������Ϊ12345678901710230101011��
�ڶ���ʱ��������Ʒ��������Ϊ12345678901710230101012��
������ʱ��������Ʒ��������Ϊ12345678901710230101013��
����1�ܼ� = (item1.count)*(item1.price) + (item2.count)*(item2.price) +
(item3.count)*item3.price)
*/
/**************������һ����Ʒ��*********************/
struct itemNode{
    int number;//���
    int id;//��Ʒid������������id38
    int counts;//��Ʒ������
    double price;//�µ�����
};
typedef struct itemNode item;

/***************����******************/
struct orderNode{
    int number;
    char id[24];//�˺�+�µ�ʱ��(yymmddhhmmss)+�µ�˳��
    int status ;//1��0
    int itemNum;
    item items[3];//����3�����¶���
    double totalPrice;
    char addr[81];
};

typedef struct orderNode order;
