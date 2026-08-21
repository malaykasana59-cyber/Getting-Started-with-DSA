#include <iostream>
using namespace std;

// brute o(m*n*(m+n)) o(1)

// using 2d array

// void markrow(int **arr, int row, int columns){
//     for (int j{} ; j<columns ; ++j){
//         if (arr[row][j] != 0) arr[row][j]=-1;
//     }
// }
//
// void markcolumn(int **arr, int column, int rows){
//     for (int i{} ; i<rows ; ++i){
//         if (arr[i][column] != 0) arr[i][column]=-1;
//     }
// }
//
// void set0s(int **arr, int n, int m){
//     for (int i{} ; i<n ; ++i){
//         for (int j{} ; j<m ; ++j){
//             if (arr[i][j]==0){
//                 markrow(arr,i,m);
//                 markcolumn(arr,j,n);
//             }
//         }
//     }
//     for (int i{} ; i<n ; ++i){
//         for (int j{} ; j<m ; ++j){
//             if (arr[i][j]==-1) arr[i][j]=0;
//         }
//     }
// }

// using arr[][] neither arr* nor arr** but still contigous memory allocation

// void markrow(int arr[][3], int row, int columns){
//     for (int j{} ; j<columns ; ++j){
//         if (arr[row][j] != 0) arr[row][j]=-1;
//     }
// }
//
// void markcolumn(int arr[][3], int column, int rows){
//     for (int i{} ; i<rows ; ++i){
//         if (arr[i][column] != 0) arr[i][column]=-1;
//     }
// }
//
// void set0s(int arr[][3], int n, int m){
//     for (int i{} ; i<n ; ++i){
//         for (int j{} ; j<m ; ++j){
//             if (arr[i][j]==0){
//                 markrow(arr,i,m);
//                 markcolumn(arr,j,n);
//             }
//         }
//     }
//     for (int i{} ; i<n ; ++i){
//         for (int j{} ; j<m ; ++j){
//             if (arr[i][j]==-1) arr[i][j]=0;
//         }
//     }
// }

// using flat 1d array (best to understand and write)
/*
void markrow(int arr[], int row, int rows, int columns){
    for (int j{} ; j<columns ; ++j){
        if (arr[row*rows+j] != 0) arr[row*rows+j]=-1;
    }
}

void markcolumn(int arr[], int column, int rows, int columns){
    for (int i{} ; i<rows ; ++i){
        if (arr[rows*i+column] != 0) arr[rows*i+column]=-1;
    }
}

void set0s(int arr[], int n, int m){
    for (int i{} ; i<n ; ++i){
        for (int j{} ; j<m ; ++j){
            if (arr[i*n+j]==0){
                markrow(arr,i,n,m);
                markcolumn(arr,j,n,m);
            }
        }
    }
    for (int i{} ; i<n ; ++i){
        for (int j{} ; j<m ; ++j){
            if (arr[i*n+j]==-1) arr[i*n+j]=0;
        }
    }
}

int main() {
    int row=3; // rows
    int column=3; // columns
    // int** arr = new int*[row]{};
    // for (int i{} ; i<row ; ++i){
    //     arr[i]= new int[column]{};
    // }
    // for (int i{} ; i<row ; ++i){
    //     for (int j{} ; j<column ; ++j){
    //         int x{};
    //         cin>>x;
    //         arr[i][j]=x;
    //     }
    // }
    // set0s(arr,row,column);
    // for (int i{} ; i<row ; ++i){
    //     for (int j{} ; j<column ; ++j){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for (int i{} ; i<row ; ++i){
    //     delete[] arr[i];
    // }
    // delete[] arr;

    // this is same as arr[][] method as it also allocates contigous memory
    int arr[row*column]{1,1,1,1,0,1,1,1,1};
    set0s(arr,row,column);
    for (int i{} ; i<row ; ++i){
        for (int j{row*i} ; j<row*i+column ; ++j){
            cout << arr[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
    
    // this is same as contigous memory i.e. above method
    // const int column=3;
    // const int row=3;
    // int arr[row][column]{
    //     {1,1,1},
    //     {1,0,1},
    //     {1,1,1},
    // };
    // set0s(arr,row,column);
    // for (int i{} ; i<row ; ++i){
    //     for (int j{} ; j<column ; ++j){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // return 0;
}
*/

// better o(m*n), o(m+n) using 2 arrays to mark rows and columns to be marked as 0
/*
void mrkrw(int arr[], int row, int rows, int columns){
    for (int j{} ; j<columns ; ++j){
        arr[row*columns+j]=0;
    }
}

void mrkclm(int arr[], int column, int rows, int columns){
    for (int i{} ; i<rows ; ++i){
        arr[i*columns+column]=0;
    }
}

int main(){
    int row=3; // rows
    int column=3; // columns
    int arr[row*column]{1,1,1,1,0,1,1,1,1};
    int markrow[row]{};
    int markcolumn[column]{};
    for (int i{} ; i<row ; ++i){
        for (int j{} ; j<column ; ++j){
            if (arr[i*column+j]==0){
                markrow[i]=1;
                markcolumn[j]=1;
            }
        }
    }
    for (int i{} ; i<row ; ++i){
        if (markrow[i]==1){
            mrkrw(arr,i,row,column);
        }
    }
    for (int j{} ; j<column ; ++j){
        if (markcolumn[j]==1){
            mrkclm(arr,j,row,column);
        }
    }
    for (int i{} ; i<row ; ++i){
        for (int j{} ; j<column ; ++j){
            cout << arr[i*column+j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
*/

// optimal o(m*n), o(1) using first row and column to mark rows and columns to be marked as 0


int main(){
    int row=3; // rows
    int column=3; // columns
    int* arr = new int [row*column]{1,1,1,1,0,1,1,1,1};
    int firstcolumn{arr[0]};
    for (int i{} ; i<row ; ++i){
        for (int j{} ; j<column ; ++j){
            if (arr[i*column+j]==0){
                if (j==0) firstcolumn=0;
                else arr[j]=0;
                arr[i*column]=0;
            }
        }
    }
    for (int i{1} ; i<row ; ++i){
        for (int j{1} ; j<column ; ++j){
            if (arr[i*column]==0 || arr[j]==0){
                arr[i*column+j]=0;
            }
        }
    }
    if (arr[0]==0){
        for (int j{} ; j<column ; ++j){
            arr[j]=0;
        }
    }
    if (firstcolumn==0){
        for (int i{} ; i<row ; ++i){
            arr[i*column]=0;
        }
    }
    for (int i{} ; i<row ; ++i){
        for (int j{} ; j<column ; ++j){
            cout << arr[i*column+j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
