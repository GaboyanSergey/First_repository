// ���������: �����������
// �����: ������ ������
// ��������: GPL v3
// ����������: ������������ �������� �������� �� ����� ������������, ����� ������ �����, ����� ���� �������� ����� ��������
// ��������: ���������(*),�������(/),��������(+),���������(-),���������� � �������(^),���������(!)
#include <stdio.h>
int main(int argc,char *argv[])
{
    // ����������� ������������
    // ������� ������������� � �������
    printf("������������!\n");
    printf("��� ������������ ��������� '�����������'\n");
    printf("��������� �������� �������� ��� ����� ���������� ���� ������� � ������� ������������ �������� �� �����\n");
    printf("��������� ��������: ���������(*),�������(/),��������(+),���������(-),���������� � �������(^),���������(!)\n");
    printf("��� ������������ ����� ������ ��������� �������� ������\n");
    // ����������
    double number1,number2; // 1 � 2 �����
    double result; // ��������� ���������� �������� ��� 1 � 2 ������
    char operation; // ��������
    char consent; // ��������/����� ������ �������� � ����������
    do // ���� ���� ������������ ������� ���������� ������ � ����������
    {
    	setvbuf(stdout, NULL, _IONBF, 0);
    	setvbuf(stderr, NULL, _IONBF, 0);
        // ����� ��������
        printf("\n�������� ��������(*, /, +, -, ^, !):");
        scanf(" %c",&operation);
        // ��������
        switch(operation)
        {
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
