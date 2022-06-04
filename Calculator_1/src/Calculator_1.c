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
    // ������������!
    // ��� ������������ ��������� "�����������"!
    // ��������� �������� �������� ��� ����� ���������� ���� �������(���������) � ������� ������������ �������� � �����.
    // ��������� ��������: ���������(*),�������(/),��������(+),���������(-),���������� � �������(^),���������(!),�������(v).
    // ��� ������ � ��������� ��������: ��������, ���������, ��������� ������������.
    // ��� ������������ ����� ������ ��������� �������� ������!

	// ������� ����� � ����(input.txt):
	// ��� ������ �������� ����� ������! ������(+ 1 2). � ���������� ��������: 1 + 2 = 3
	// ������� - (v, ������ ��������, �������� ������� �������, �������� ������� �������, ���� ��������)
	// �������� - (+, ������ �����, ������ �����)
	// ��������� - (-, ������ �����, ������ �����)
	// ��������� - (*, ������ �����, ������ �����)
	// ������� - (/, ������ �����, ������ �����)
	// ��������� - (!, �����)
	// ���������� � ������� - (^, ������ �����, ������ �����)

	// ����������
    double number1,number2; // 1 � 2 �����
    double result; // ��������� ���������� �������� ��� 1 � 2 ������
    char operation; // ��������
    char consent; // ��������/����� ������ �������� � ����������
    // ���������� ��� ������ � ���������
    double *A,*B; // ������ ������, ������ ������
    int size;
    char op; // �������� ��� ���������
    double res; // ��������� ���������� �������� ��� ���������

    do // ���� ���� ������������ ������� ���������� ������ � ����������
    {
    	// ��� ����������� ������
    	setvbuf(stdout, NULL, _IONBF, 0);
    	setvbuf(stderr, NULL, _IONBF, 0);
    	// �������� ���� - �����
    	FILE *input, *output;
    	char input_name[259], output_name[259];
    	//���������� ��� ������ ����� ������
    	printf("������� �������� ����� ������� '.txt', �� �������� � ���� ����� ������:");
    	scanf("%s", input_name);
    	printf("������� �������� ����� ������� '.txt', � ������� � ������ ����������:");
    	scanf("%s", output_name);
    	input = fopen(input_name,"r");
    	output = fopen(output_name,"w");
    	while(fscanf(input, " %c", &operation) != EOF){
        // ��������
        switch(operation)
        {
        // ������ � ���������
            case 'v':
            fscanf(input,"%i",&size); // ������� ������ ��������
            A = malloc(size*sizeof(double));
            B = malloc(size*sizeof(double));
            for(int i=0;i<size;i++) fscanf(input,"%lf",&A[i]); // ���������� ������� �������
            for(int i=0;i<size;i++) fscanf(input,"%lf",&B[i]); // ���������� ������� �������
            fscanf(input," %c",&op); // ����� ��������
            if (op == '+')
            {
                // �������� ��������
            	fprintf(output, "(");
            	for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]);
            	fprintf(output, ") + (");
                for(int i=0;i<size;i++) fprintf(output,"%lf ",B[i]);
            	fprintf(output, ") = (");
            	for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]+B[i]);
            	fprintf(output, ")\n");
            }
            if (op == '-')
            {
                // ��������� ��������
            	fprintf(output, "(");
            	for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]);
            	fprintf(output, ") - (");
            	for(int i=0;i<size;i++) fprintf(output,"%lf ",B[i]);
                fprintf(output, ") = (");
                for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]-B[i]);
            	fprintf(output, ")\n");
            }
            if (op == '*')
            {
                // ��������� ������������ ��������
            	for(int i=0;i<size;i++) res += A[i]*B[i];
            	fprintf(output, "(");
                for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]);
            	fprintf(output, ") * (");
                for(int i=0;i<size;i++) fprintf(output,"%lf ",B[i]);
            	fprintf(output, ") = ");
                fprintf(output,"%lf\n",res);
            }
            free(A);
            free(B);
        break;
        // ��������� �����
            case '!':
            fscanf(input," %lf",&number1); // ������� �����
            double h = 1;
            double b;
            b = number1;
            if (number1 > 0) for(h = 1; h < b; h++)
            {
                number1 = number1 * (b - h);
            }
            if (number1 == 0) fprintf(output,"0! = 1");
            else if (number1 < 0) fprintf(output,"��������� �������������� ����� �� �����������");
            else fprintf(output,"\n%lf! = %lf",b,number1);
        break;
        // ��������
            case '+':
            fscanf(input," %lf",&number1); // ������� ������ �����
            fscanf(input," %lf",&number2); // ������� ������ �����
            result = number1 + number2;
            fprintf(output,"\n%lf + %lf = %lf",number1,number2,result);
        break;
        // ���������
            case '-':
            fscanf(input," %lf",&number1); // ������� ������ �����
            fscanf(input," %lf",&number2); // ������� ������ �����
            result = number1 - number2;
            fprintf(output,"\n%lf - %lf = %lf",number1,number2,result);
        break;
        // ���������
            case '*':
            fscanf(input," %lf",&number1); // ������� ������ �����
            fscanf(input," %lf",&number2); // ������� ������ �����
            result = number1 * number2;
            fprintf(output,"\n%lf * %lf = %lf",number1,number2,result);
        break;
        // �������
            case '/':
            fscanf(input," %lf",&number1); // ������� ������ �����
            fscanf(input," %lf",&number2); // ������� ������ �����
            result = number1 / number2;
            if (number2 == 0) fprintf(output,"������ �� ���� ������!");
            else fprintf(output,"\n%lf / %lf = %lf",number1,number2,result);
        break;
        // ���������� � �������
            case '^':
            fscanf(input," %lf",&number1); // ������� ������ �����
            fscanf(input," %lf",&number2); // ������� ������ �����(�������������)
            double a = 1;
            double copy = number1;
            for(a = 1; a < number2; a++)
            {
                number1 = number1 * copy;
                result = number1;
            }
            if (number2 < 0) fprintf(output,"����������� ������� ������ ������������� �������!");
            else if (number2 == 0) fprintf(output,"����� ����� � ������� 0 ����� 1");
            else fprintf(output,"\n%lf ^ %lf = %lf",copy,number2,result);
        break;
        // ��� ��������� �������� ��������
        default:
        fprintf(output,"\n�� ����������� ������� ��������!");
        }
        fclose(input);
        fclose(output);
        // ��������/����� ������ �������� � ����������
        // ��� y - ������ ��������� �����������, ��� n - ��������� ��������� ������!
        printf("������ �� ���������� ������ � ����������(y/n)?: ");
        scanf(" %c",&consent);
        }
    }while(consent == 'y'); // ������� ��� ������� ������ � ���������� �����������
    printf("������� �� ������! �� ��������!");
    return 0;
}

