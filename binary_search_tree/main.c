#include <stdio.h>
#include <stdlib.h>

typedef struct ikili_agac
{
    int no;
    char ad[25];
    struct agac *right;
    struct agac *left;
} agac;


agac *new_data(int sayi2)
{

    agac *temp = malloc(sizeof(agac));
    if (temp == NULL)
    {
        printf("Hafiza dolu!");
        return NULL;
    }
    temp->no=sayi2;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

agac *insert(agac *root, agac *temp)
{
    if (root == NULL)
    {
        printf("adi giriniz: ");
        scanf("%s",temp->ad);
        return temp;
    }

    if (temp->no < root->no)
    {
        root->left = insert(root->left, temp);

    }
    else
    {
        root->right = insert(root->right, temp);

    }

    return root;
}


agac *search(int temp,agac *root)
{
    if (root == NULL)
    {
        printf("Bu numarada kimse bulunmamaktadir.\n");
        return NULL;
    }

    if(temp < root->no)
    {
        return search(temp,root->left);
    }
    else if(temp > root->no)
    {
        return search(temp,root->right);
    }
    else
    {
        if(temp ==root->no)
        {

            return root;
        }
    }
}

agac *inorder_list(agac *root)
{
    if(root != NULL)
    {
        inorder_list(root->right);
        printf("%d-%s\n",root->no,root->ad);
        inorder_list(root->left);
        return root;

    }
}

agac *ortalama(agac *root)
{
    int toplam=0,sayac=0;

    if(root != NULL)
    {
        toplam= toplam + root->no;
        sayac ++; //toplam eleman sayisini olcmek icin
        toplam= ortalama(root->left);
        toplam=ortalama(root->right);
    }
    if (sayac != 0)
    {
        int ort = toplam / sayac;
        printf("\nGirilen numaralarin ortalamasi:%d ",ort);
    }
    else
    {
        printf("\nAgac bos.\n");
    }

}

agac *delete_tree(int temp,agac *root)
{

    /*search(temp,root);
    free(root);*/

}


int main()
{
    agac *root =NULL;
    agac *temp;
    int sayi,numara,sayi3;


    while(1)
    {
        printf("\n\n\n1)Ekleme\n2)Listeleme\n3)Silme\n4)Agacin yuksekligi\n5)Numaralarin ortalamasi\n6)Bulmak istediginiz isim\n7)Cikis\n\n\n");
        scanf("%d",&numara);
        switch (numara)
        {
        case 1:

            printf("kac sayi gireceksiniz: ");
            scanf("%d",&sayi);

            for(int i=0; i<sayi; i++)
            {
                int sayi2;
                printf("sayi giriniz: ");
                scanf("%d",&sayi2);
                temp=new_data(sayi2);//yeni eleman olusturuldu
                root=insert(root,temp);//agaca eklendi

            }
            break;

        case 2:

            inorder_list(root);
            break;

        case 3:
            printf("Silmek istediginiz sayiyi girin: ");
            scanf("%d",&sayi3);
            search(sayi3,root);//eger silinmek istenen agacta yoksa diye once onu kontrol ediyor,bulunmazsa uyariyi verecek
            delete_tree(sayi3,root);//simdi silme islemi
            break;

        case 4:

            break;

        case 5:

        {

            ortalama(root);

        }
        break;


        case 6:

            printf("Bulmak istediginiz kisinin numarasi: ");
            scanf("%d",&sayi3);
            search(sayi3,root);//arama fonskiyonu
            printf("%d numarali kisi :%s",sayi3,root->ad);
            break;

        case 7:
            return 0;
        default:
            printf("gecersiz sayi!");
            break;
        }
    }




    return 0;
}
