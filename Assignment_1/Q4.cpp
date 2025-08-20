// Q4

#include <iostream>
using namespace std;

int mat[10][10];
int r1 = 0, c1 = 0;

void createMatrix()
{
    cout << "Enter rows and columns: ";
    cin >> r1 >> c1;
    cout << "Enter elements:\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void displayMatrix()
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices()
{
    int r2, c2, B[10][10], result[10][10] = {0};

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    if (c1 != r2)
    {
        cout << "Matrix multiplication not possible. Columns of first must equal rows of second.\n";
        return;
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += mat[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}

void transposeMatrix()
{
    int transpose[10][10];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            transpose[j][i] = mat[i][j];

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < c1; i++)
    {
        for (int j = 0; j < r1; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE Matrix\n";
        cout << "2. DISPLAY Matrix\n";
        cout << "3. REVERSE Matrix\n";
        cout << "4. MATRIX MULTIPLICATION\n";
        cout << "5. MATRIX TRANSPOSE\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createMatrix();
            break;
        case 2:
            displayMatrix();
            break;
        case 3:
            multiplyMatrices();
            break;
        case 4:
            transposeMatrix();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
