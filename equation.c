#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
    while (1)
    {
        printf("\n");
        printf("\n");
       
        printf("[1] Phuong trinh bac 1\n");
        printf("[2] Phuong trinh bac 2\n");
        printf("[3] Phuong trinh bac 3\n");
        printf("[4] Phuong trinh trung phuong\n");
        printf("[5] Thoat\n");
        
        int chon_pt;
        float a, b, c, d, k, delta;
        printf("Chon: ");
        scanf("%d", &chon_pt);

        switch (chon_pt)
        {
        // Bac 1
        case 1:
            printf("[Ban da chon phuong trinh bac 1: ax + b = 0]\n");
            printf("Nhap a: ");
            scanf("%f", &a);
            printf("Nhap b: ");
            scanf("%f", &b);
            Bac_mot(&a, &b, &c);
            printf("\n");
            break;

        // Bac 2
        case 2:
            printf("[Ban da chon phuong trinh bac 2: ax^2 + bx + c = 0]\n");
            printf("Nhap a: ");
            scanf("%f", &a);
            printf("Nhap b: ");
            scanf("%f", &b);
            printf("Nhap c: ");
            scanf("%f", &c);
            Bac_hai(&a, &b, &c, &delta);
            printf("\n");
            break;

        // Bac 3
        case 3:
            printf("[Ban da chon phuong trinh bac 3: ax^3 + bx^2 + cx + d = 0]\n");
            printf("Nhap a: ");
            scanf("%f", &a);
            printf("Nhap b: ");
            scanf("%f", &b);
            printf("Nhap c: ");
            scanf("%f", &c);
            printf("Nhap d: ");
            scanf("%f", &d);
            Bac_ba(&a, &b, &c, &d, &k, &delta);
            printf("\n");
            break;

        // Bac 4
        case 4:
            printf("[Ban da chon phuong trinh trung phuong: ax^4 + bx^2 + c= 0]\n");
            printf("Nhap a: ");
            scanf("%f", &a);
            printf("Nhap b: ");
            scanf("%f", &b);
            printf("Nhap c: ");
            scanf("%f", &c);
            Bac_bon_trung_phuong(&a, &b, &c, &delta);
            printf("\n");
            break;
        case 5:
            printf("Nhan Enter de thoat!");
            exit(0);
        default:
            break;
        }
    }

    getch();
    return 0;
}
//________________________________________________________________________________________________________________________________________

// Phuong trinh bac 1
void Bac_mot(float *a, float *b, float *c)
{
    printf("ax + b = 0 <=> ");
    printf("%.1fx + %.1f = 0\n", *a, *b);
    if (*a == 0 && *b == 0)
    {
        printf("=> Phuong trinh co vo so nghiem ]\n");
    }
    else if (*a == 0 && *b != 0)
    {
        printf("=> Phuong trinh vo nghiem ]\n");
    }
    else
    {
        *c = -(*b) / (*a);
        printf("=> Phuong trinh co nghiem duy nhat: x = %.1f\n", *c);
    }
}
//______________________________________________________________________________________________________________________________

// Phuong trinh bac 2
void Bac_hai(float *a, float *b, float *c, float *delta)
{
    // ax^2 + bx + c = 0
    printf("ax^2 + bx + c = 0 <=> ");
    printf("%.1fx^2 + %.1fx + %.1f = 0 <=> ", *a, *b, *c);
    *delta = pow((*b), 2) - (4 * ((*a) * (*c)));
    printf("Delta: %.2f\n", *delta);
    if (*delta < 0)
    {
        printf("=> Phuong trinh vo nghiem\n");
    }
    else if (*delta == 0)
    {
        float x = (-*b) / (2 * (*a));
        printf("=> Phuong trinh co nghiem kep: x1 = x2 = -b/2a = %.1f\n", x);
    }
    else
    {
        float x1 = (-*b + sqrt(*delta)) / (2 * (*a));
        float x2 = (-*b - sqrt(*delta)) / (2 * (*a));
        printf("=> Phuong trinh co hai nghiem: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }

    // gia tri lon nhat, gia tri nho nhat
    float gt_x, gt_y;
    gt_x = (-*b) / (2 * (*a));
    gt_y = (-*delta) / (4 * (*a));

    if (*a > 0)
    {
        printf("gia tri lon nhat y= %f tai x=%f ", gt_y, gt_x);
    }
    else
    {
        printf("gia tri nho nhat y= %f tai x=%f ", gt_y, gt_x);
    }
}

//____________________________________________________________________________________________________________________________________________________

// Phuong trinh bac 3
void Bac_ba(float *a, float *b, float *c, float *d, float *k, float *delta)
{
    // ax^3 + bx^2 + cx + d = 0
    printf("ax^3 + bx^2 + cx + d = 0 <=> ");
    printf("%.1fx^3 + %.1fx^2 + %.1fx + %.1f  = 0\n", *a, *b, *c, *d);
    *delta = pow(*b, 2) - 3 * (*a) * (*c);
    float deltaphay = pow(*b, 2) - 3 * (*a) * (*c);
    if (*delta == 0)
    {
        *k = 0;
    }
    else
    {
        *k = (9 * (*a) * (*b) * (*c) - (2 * pow(*b, 3)) - (27 * pow(*a, 2) * (*d))) / (2 * sqrt(pow(fabs(*delta), 3)));
    }
    printf("k = %.2f; ", *k);
    printf("Delta = %.2f\n", *delta);
    if (*delta > 0)
    {
        if (fabs(*k) <= 1)
        {
            float x1 = (2 * sqrt(*delta) * cos(acos(*k) / 3) - *b) / (3 * (*a));
            float x2 = (2 * sqrt(*delta) * cos(acos(*k) / 3 - (2 * 3.14) / 3) - *b) / (3 * (*a));
            float x3 = (2 * sqrt(*delta) * cos(acos(*k) / 3 + (2 * 3.14) / 3) - *b) / (3 * (*a));
            printf("=> Phuong trinh co 3 nghiem: ");
            printf("x1 = %.2f; x2 = %.2f; x3 = %.2f\n", x1, x2, x3);
        }
        else if (fabs(*k) > 1)
        {
            float x = ((sqrt(*delta) * fabs(*k)) / (3 * (*a) * (*k)) * ((cbrt(fabs(*k) + sqrt(pow(*k, 2) - 1))) + (cbrt(fabs(*k) - sqrt(pow(*k, 2) - 1))))) - (*b / (3 * (*a)));
            printf("=> Phuong trinh co 1 nghiem duy nhat: ");
            printf("x = %.2f\n", x);
        }
    }
    else if (*delta == 0)
    {
        float x = ((-*b) + (cbrt((pow(*b, 3) - (27 * pow(*a, 2) * (*d)))))) / (3 * (*a));
        printf("=> Phuong trinh co nghiem: ");
        printf("x = %.2f\n", x);
    }
    else if (*delta < 0)
    {
        float x = (((sqrt(fabs(*delta))) / (3 * (*a))) * ((cbrt(*k + sqrt(pow(*k, 2) + 1))) + (cbrt(*k - sqrt(pow(*k, 2) + 1))))) - ((*b) / (3 * (*a)));
        printf("=> Phuong trinh co 1 nghiem duy nhat: ");
        printf("x = %.2f\n", x);
    }

    //-----------cuc dai cuc tieu cua ham so bac 3-------------

    float a1 = (-(*b) + sqrt(pow(*b, 2) - (3 * (*a) * (*c)))) / (3 * (*a));
    float a2 = (-(*b) - sqrt(pow(*b, 2) - (3 * (*a) * (*c)))) / (3 * (*a));
    //   sap xep lai thu tu x tang dan
    if (a2 <= a1)
    {
        float tm = a2;
        a2 = a1;
        a1 = tm;
    }

    float b1 = (*a) * pow(a1, 3) + (*b) * pow(a1, 2) + (*c) * a1 + (*d);
    float b2 = (*a) * pow(a2, 3) + (*b) * pow(a2, 2) + (*c) * a2 + (*d);

    if (deltaphay <= 0)
    {
        printf("  => phuong trinh khong co cuc tri");
    }
    else if (deltaphay > 0)
    {

        if (*a > 0)
        {
            printf(" cuc dai x= %f\n", a1);
            printf(" cuc dai y= %f\n", b1);
            printf("----------------------\n");
            printf(" cuc tieu x= %f\n", a2);
            printf(" cuc tieu y= %f\n", b2);
        }
        else
        {
            printf(" cuc tieu x= %f\n", a1);
            printf(" cuc tieu y= %f\n", b1);
            printf("----------------------\n");
            printf(" cuc dai x= %f\n", a2);
            printf(" cuc dai y= %f\n", b2);
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________

// Phuong trinh bac 4 trung phuong
void Bac_bon_trung_phuong(float *a, float *b, float *c, float *delta)
{
    float t, t1, t2;
    *delta = (*b * (*b)) - (4 * ((*a) * (*c)));
    if (*delta < 0)
    {
        printf("=> Phuong trinh nay vo nghiem\n");
    }
    else if (*delta == 0)
    {
        t = -(*b) / 2 * (*a);
        if (t >= 0)
        {
            printf("=> Phuong trinh co 2 nghiem: \n");
            printf("x1 = %.2f; x2 = %.2f\n", sqrt(t), -sqrt(t));
        }
        else
        {
            printf("=> Phuong trinh nay vo nghiem\n");
        }
    }
    else
    {
        t1 = (-(*b) + sqrt(*delta)) / (2 * (*a));
        t2 = (-(*b) - sqrt(*delta)) / (2 * (*a));
        if (t1 < 0 && t2 >= 0)
        {
            printf("=> Phuong trinh co 2 nghiem: ");
            printf("x1 = %.2f; x2 = %.2f\n", sqrt(t2), -sqrt(t2));
        }
        else if (t2 < 0 && t1 >= 0)
        {
            printf("=> Phuong trinh co 2 nghiem: ");
            printf("x1 = %.2f; x2 = %.2f\n", sqrt(t1), -sqrt(t1));
        }
        else if (t1 >= 0 && t2 >= 0)
        {
            printf("=> Phuong trinh co 4 nghiem: ");
            printf("x1 = %.2f; x2 = %.2f; x3 = %.2f; x4 = %.2f\n", sqrt(t1), -sqrt(t1), sqrt(t2), -sqrt(t2));
        }
        else
        {
            printf("=> Phuong trinh nay vo nghiem\n");
        }
    }

    //_________________________cuc tri pt trung phuong_______________________

    float a1 = +sqrt(-(*b) / (2 * (*a)));
    float a2 = -sqrt(-(*b) / (2 * (*a)));
    float b1 = (*a) * pow(a1, 4) + (*b) * pow(a1, 2) + (*c);
    float b2 = (*a) * pow(a2, 4) + (*b) * pow(a2, 2) + (*c);
    float gt = (*c);
    if ((*a) * (*b) >= 0)
    {
        printf("phuong trinh co 1 cuc tri x =0\n\n");
        printf("gia tri cuc dai la y= %f", gt);
    }
    else
    {
        if (*a < 0)
        {
            printf("cuc tieu cua ham so x= 0\n");
            printf("gia tri cuc tieu la y= %f", gt);
            printf("cuc dai cua ham so x1= %f\n                   x2= %f\n", a1, a2);
            printf(" gia tri cuc dai y1= %f\n", b1);
            printf(" gia tri cuc dai y2= %f\n", b2);
        }
        else
        {
            printf("cuc dai cua ham so x= 0\n");
            printf("gia tri cuc dai la y= %f", gt);
            printf("cuc tieu cua ham so x= %f\n                   x= %f\n", a1, a2);
            printf(" gia tri cuc tieu y1= %f\n", b1);
            printf(" gia tri cuc tieu y2= %f\n", b2);
        }
    }
}
