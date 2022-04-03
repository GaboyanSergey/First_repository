// ���������: �����������
// �����: ������ ������
// ��������: GPL v3
// ����������: ������������ �������� �������� �� ����� ������������, ����� ������ �����, ����� ���� �������� ����� ��������
// ��������: ���������(*),�������(/),��������(+),���������(-),���������� � �������(^),���������(!),������ � ���������(v)
// ��� ������ � ��������� ��������: ��������, ���������, ��������� ������������
#include <stdlib.h> // ����������� ���������
#include <stdio.h> // ����������� ���������
int main(int argc,char *argv[])
{
    // ����������� ������������
    // ������� ������������� � �������
    printf("������������!\n");
    printf("��� ������������ ��������� '�����������'\n");
    printf("��������� �������� �������� ��� ����� ���������� ���� �������(���������) � ������� ������������ �������� �� �����\n");
    printf("��������� ��������: ���������(*),�������(/),��������(+),���������(-),���������� � �������(^),���������(!),�������(v)\n");
    printf("��� ������������ ����� ������ ��������� �������� ������\n");
    // ����������
    double number1,number2; // 1 � 2 �����
    double result; // ��������� ���������� �������� ��� 1 � 2 ������
    char operation; // ��������
    char consent; // ��������/����� ������ �������� � ����������
    // ���������� ��� ������ � ���������
    double *A,*B; // ������ ������, ������ ������, ��������� ���������� �������� ��� ���������
    int size;
    char op; // �������� ��� ���������
    do // ���� ���� ������������ ������� ���������� ������ � ����������
    {
        // ��� ����������� ������
    	setvbuf(stdout, NULL, _IONBF, 0);
    	setvbuf(stderr, NULL, _IONBF, 0);
        // ����� ��������
        printf("\n�������� ��������(*, /, +, -, ^, !, v):");
        scanf(" %c",&operation);
        // ��������
        switch(operation)
        {
        // ������ � ���������
            case 'v':
            printf("������� ������ ��������: ");
            scanf("%i",&size);
            A = malloc(size*sizeof(int));
            B = malloc(size*sizeof(int));
            printf("������� ���������� ������� �������: ");
            for(int i=0;i<size;i++) scanf("%lf",&A[i]);
            printf("������� ���������� ������� �������: ");
            for(int i=0;i<size;i++) scanf("%lf",&B[i]);
            printf("�������� ��������(+,-,*): ");
            scanf(" %c",&op);
            if (op == '+')
            {
                printf("�������� ��������: ");
                for(int i=0;i<size;i++) printf("%lf ",A[i]+B[i]);
                printf("\n");
            }
            if (op == '-')
            {
                printf("��������� ��������: ");
                for(int i=0;i<size;i++) printf("%lf ",A[i]-B[i]);
                printf("\n");
            }
            if (op == '*')
            {
                printf("��������� ��������� ��������: ");
                for(int i=0;i<size;i++) printf("%lf ",A[i]*B[i]);
                printf("\n");
            }
            else printf("����������� ������� ��������!");
            free(A);
            free(B);
        break;
        // ��������� �����
            case '!':
            printf("\n������� �����:");
            scanf(" %lf",&number1);
            double h = 1;
            double b;
            b = number1;
            if (number1 > 0) for(h = 1; h < b; h++)
            {
                number1 = number1 * (b - h);
            }
            if (number1 == 0) printf("0! = 1");
            else if (number1 < 0) printf("��������� �������������� ����� �� �����������");
            else printf("\n%lf! = %lf",b,number1);
        break;
        // ��������
            case '+':
            printf("\n������� ������ �����:");
            scanf(" %lf",&number1);
            printf("\n������� ������ �����:");
            scanf(" %lf",&number2);
            result = number1 + number2;
            printf("\n%lf + %lf = %lf",number1,number2,result);
        break;
        // ���������
            case '-':
            printf("\n������� ������ �����:");
            scanf(" %lf",&number1);
            printf("\n������� ������ �����:");
            scanf(" %lf",&number2);
            result = number1 - number2;
            printf("\n%lf - %lf = %lf",number1,number2,result);
        break;
        // ���������
            case '*':
            printf("\n������� ������ �����:");
            scanf(" %lf",&number1);
            printf("\n������� ������ �����:");
            scanf(" %lf",&number2);
            result = number1 * number2;
            printf("\n%lf * %lf = %lf",number1,number2,result);
        break;
        // �������
            case '/':
            printf("\n������� ������ �����:");
            scanf(" %lf",&number1);
            printf("\n������� ������ �����:");
            scanf(" %lf",&number2);
            result = number1 / number2;
            if (number2 == 0) printf("������ �� ���� ������!");
            else printf("\n%lf / %lf = %lf",number1,number2,result);
        break;
        // ���������� � �������
            case '^':
            printf("\n������� ������ �����:");
            scanf(" %lf",&number1);
            printf("\n������� ������ �����(�������������):");
            scanf(" %lf",&number2);
            double a = 1;
            double copy = number1;
            for(a = 1; a < number2; a++)
            {
                number1 = number1 * copy;
                result = number1;
            }
            if (number2 < 0) printf("����������� ������� ������ ������������� �������!");
            else printf("\n%lf ^ %lf = %lf",copy,number2,result);
        break;
        // ��� ��������� �������� ��������
            default:
            printf("\n�� ����������� ������� ��������!");
        }
    // ��������/����� ������ �������� � ����������
    printf("\n������ �� �� ���������� ������ � ����������(y/n):");
    scanf(" %c",&consent);
    }while(consent == 'y'); // ������� ��� ������� ������ � ���������� �����������
    // ���� "n", �� ��������� �������� ������, ������������ � �������������
    if(consent == 'n') printf("\n������� �� ������!�� ��������!");
    // ��� ��������� �������� "consent"
    else printf("\n�� ������� ������ �� ����� ��������!");
    return 0;
}



