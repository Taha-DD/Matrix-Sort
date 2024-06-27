#include<stdio.h>
void swap ( int *a, int *b )
{
    int s = *a;
    *a = *b;
    *b = s;
}
void insertion ( int matrix [][10], int r, int c )
{
    for (int i = 0; i < r; i++)
        for ( int j = 0; j < c; j++ )
        {
            int save = matrix [i][j];
            int q = j, p = i;
            
            while ( p >= 0 && matrix [p][q-1] > save )
            {
                matrix [p][q] = matrix [p][q-1];
                q--;
                if ( q == 0 ){
                    p--;
                    q = c;
                }    
            }
            matrix [p][q] = save;
        }
} 

void selection ( int matrix [][10], int r, int c )
{
    for ( int i = 0; i < r; i++ )
        for ( int j = 0; j < c; j++ )
        {
            int minr = i, minc = j;
            
            for ( int l = i; l < r; l++ )
            {
                int f = 0;
                if (l == i)
                    f = j;
                for (; f < c; f++ )
                    if ( matrix [minr][minc] > matrix [l][f] )
                    {
                        minr = l;
                        minc = f;
                    }
            }        
            swap ( &matrix [minr][minc], &matrix [i][j] );
        }
}

void bubble ( int matrix [][10], int r, int c )
{
    for ( int i = 0; i < r; i++ )
        for ( int j = 0; j < c; j++ )
            for ( int l = 0; l < r; l++ )
                for ( int f = 0; f < c; f++ )
                    if ( matrix [l][f] > matrix [l][f + 1] )
                        swap ( &matrix [l][f], &matrix [l][f + 1] );
}

void shell (int matrix[][10], int r, int c) {
    for (int gap = r * c / 2; gap > 0; gap /= 2) {
        for (int i = 0; i < r * c; ++i) {
            for (int j = i + gap; j < r * c; j += gap) {
                int save = matrix[j / c][j % c];
                int k = j;

                while (k >= gap && matrix[(k - gap) / c][(k - gap) % c] > save) {
                    matrix[k / c][k % c] = matrix[(k - gap) / c][(k - gap) % c];
                    k -= gap;
                }

                matrix[k / c][k % c] = save;
            }
        }
    }
}
int main()
{
    int matrix [3][10] = { { 1, 7, 2, 2, -12, 365, 928, 25, 21, 36 } , { 10, 87, 2, 0, 3, 1, 98, 42, 12, 33 } , { 1, 7, 23, 222, 911, 711, 9, 11, 124, 5 } };
    
    puts ("unsorted:");
    
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 10; j++)
            printf("matrix [%d][%d] = %d\n", i, j, matrix [i] [j] );
    
    insertion ( matrix, 3, 10 ); // choose a sorting method as you like 
    selection ( matrix, 3, 10 );
    bubble ( matrix, 3, 10 );
    shell ( matrix, 3, 10 );

    puts ("sorted:");
    
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 10; j++)
            printf("matrix [%d][%d] = %d\n", i, j, matrix [i] [j] );
            
    return 0;
}
