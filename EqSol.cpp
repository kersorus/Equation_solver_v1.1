 #include <stdio.h>
 #include <math.h>
 #include <assert.h>


 const int infinity = -1;
 const double infelicity = 1E-6;


//-----------------------------------------------------------------------------

/*!

     \brief ��������� �����.
     \param[in] A, B - ������������ �����.
     \return -1 - � ������ �, 0 - � � � �����, 1 - � ������ �.

     ������ ������� ��������� �������� ��� �����.
*/

 int comparer(double A, double B)
     {
     if ( fabs ( A - B ) < infelicity)
     return 0;

     if              ( A < B )
     return -1;

     if              ( A > B )
     return 1;
     }


//-----------------------------------------------------------------------------

/*!

     \brief ���������� � scanf().
     \param[in] a, b, c - �������� ���������.

     ��� ������� ������������� ������ ����������������� �����.
*/

 void checker (double* a, double* b, double* c)
     {
     assert (a != NULL);
     assert (b != NULL);
     assert (c != NULL);

     int check = scanf ("%lg, %lg, %lg", a, b, c);

     while (check != 3)
         {
         printf ("# Sorry, try to input CORRECT information\n\n"
                 "# Enter your a, b, c: ");

         fflush (stdin);

         check = scanf ("%lg, %lg, %lg", a, b, c);
         }
     }


//-----------------------------------------------------------------------------

/*!

     \param[in] a, b, c - ������������ ����������� ���������.
     \return 0 - ��������� �� ����� ������, 1 - ��������� ����� ���� ������, 2 - ��������� ����� ��� �����.

     ������, �������� ���������� ��������� ���� a*x^2 + b*x + c = 0

*/

 int Square(double a, double b, double c, double* root1, double* root2)
     {
     assert (root1 != NULL);
     assert (root2 != NULL);

     double discr = b*b-4*a*c;
     double  zero = 0;

     int res = comparer(discr, zero);

     switch (res)
        {
        case -1:
        return 0;

        case 0:
        *root1 = -b/2/a;

        return 1;

        case 1:
        *root1 = (-b+sqrt(discr))/2/a;
        *root2 = (-b-sqrt(discr))/2/a;

        return 2;
        }
     }


//-----------------------------------------------------------------------------

/*!

     \param[in] b, c - ������������ ��������� ���������.
     \return 0 - ��������� �� ����� ������, 1 - ��������� ����� ���� ������, -1 - ��������� ����� ����������� ���-�� ������.

     ������, �������� �������� ��������� ���� b*x + c = 0

*/

 int Linear(double b, double c, double* root1)
     {
     assert (root1 != NULL);

     if     (b == 0)
     return (c == 0)? infinity : 0;

     *root1 = -c/b;

     return 1;
     }


//-----------------------------------------------------------------------------

/*!

     \brief �������, �������� ���������.
     \param[in] a, b, c - ������������ ���������.
     \return �������� ��������� ������� Linear() - ���� �������� �������� ���������, Square() - ���� ����������.

      �������� ������� Square() ��� Linear() � ����������� �� ����, ����� ��������� ������ (���������� ��� ��������).
*/

 int solver (double a, double b, double c, double* root1, double* root2)
     {
     assert (root1 != NULL);
     assert (root2 != NULL);

     if (a == 0)
     return Linear (b, c, root1);

     return Square (a, b, c, root1, root2);
     }


//-----------------------------------------------------------------------------

/*!

     ������� �������, �������� ����� ���� ���������.

*/

 int main()
     {
     printf ("# Equation solver (square (a*x^2 + b*x + c = 0) version)\n"
            "# (c) Ferrum, 2020\n\n");

     printf ("# Enter your a, b, c: ");

     double a = 0, b = 0, c = 0;

     checker ( &a, &b, &c);

     double x1 = 0, x2 = 0;
     int n_of_roots = 0;

     n_of_roots = solver(a, b, c, &x1, &x2);

     printf ("Answer: ");

     switch (n_of_roots)
         {
         case 0:
         printf ("no roots.\n");
         break;

         case 1:
         printf ("one root x1 = %lg.\n", x1);
         break;

         case 2:
         printf ("two roots x1 = %lg, x2 = %lg.\n", x1, x2);
         break;

         case infinity:
         printf ("any number.\n");
         break;

         default:
         printf ("main(): ERROR: roots = %d.\n",
                          n_of_roots);
         return 1;
         }
    }
