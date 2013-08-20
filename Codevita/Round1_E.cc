#include<iostream.h> 
#include<stdio.h> 
#include<math.h> 

// Written by Ran 

// There have been enough comments to help the reader easily understand this program 

// Helpfulness of COMMENTS in this program and Pre-requisites:- 

// a. However it's assumed that the reader is familiar with the basics of C++ 
// b. It is also assumed that the reader knows the basic mathematics involving matrices. 
// c. Since this program focusses on how to find inverse of a matrix, the comments 
// in the program are sufficient for understanding this. 
// It is assumed that the reader is familiar with basics of matrices in C++ (like input, display, 
// addition,transpose,etc. of matrices) 
// The comments in this program aim to explain the reader how to find inverse 
// d. Hence through comments, the reader will also be taught how to find determinant, 
// adjoint, cofactor,etc. However as said in the previous lines, there won't be comments 
// for explaining basics like input,display,etc of a matrix using C++. 


// NOTES: 
// 1. float datatype has been used for matrix, determinant. 
// 2. To have consistency between mathematics and C++, this program considers a[1][1] as the first element 
// i.e row and column indices begin with 1 same as mathematics. 


// Define a structure matrix with a matrix (2D array of type float) and size n 
// Declare the objects of this structure used in this program 

struct matrix 
{ 
float a[25][25]; 
int n; 
}obj,c_obj,trans_obj,obj_cof,obj_adj,obj_inv; 

// Prototypes of the functions used in this program 

void input(matrix&); 
void display(matrix&); 
matrix reduced(matrix &, int ,int ); 
float determinant(matrix); 
float cofactor(matrix,int,int); 
matrix transpose(matrix); 
matrix adjoint(matrix); 
matrix inverse(matrix obj); 

// Begining of Main function 

int main() 
{ 
// Getting dimensions input by the user 
int r,c; 
again: 
cout<<"Enter the order of the matrix: "<<endl; 
cout<<"Enter Row dimension: "; 
cin>>r; 
cout<<"Enter Column dimension: "; 
cin>>c; 

// Check dimensions for square matrix so that inverse can be found 
// If user enters different dimensions for row and column, ask to re-enter or quit program 

// If it's a square matrix, proceed 

else if(r==c) 
{obj.n=r;} 

cout<<endl; 
input(obj); // call input function to input the matrix elements from the user 
display(obj); // display the matrix got as input now 

// Following lines were used to test parts/sections/segments of the code and hence commented 

/* char ans2; 
cout<<"do u want to check reduce matrix? Press y to check reduce matrix and press any char to skip this"<<endl; 
cin>>ans2; 
if(ans2=='y') 
{ 
int i,j; 
cout<<"Enter row i and col j to get reduced matrix"<<endl; 
cin>>i>>j; 
// i=i-1; 
// j=j-1; 
c_obj=reduced(obj,i,j); 
char ans1; 
cout<<"Do you want to display the reduced matrix? If yes, Press y "<<endl; 
cin>>ans1; 
if(ans1=='y') 
{ 
cout<<"Displaying reduced matrix..."<<endl; 
display(c_obj); 
} 
}*/ 


//Find Determinant 

cout<<"Finding determinant......"<<endl; 
cout<<"The determinant is"<<determinant(obj)<<endl; 

//Find Cofactor if user wishes to 
char ans3; 
cout<<"Do you want to find cofactor? Press y if yes"<<endl; 
cin>>ans3; 
while(ans3=='y') 
{ 
int i,j; 
cout<<"Finding cofactor. Enter row and column"<<endl; 
cin>>i>>j; 
cout<<"Cofactor of a["<<i<<"]["<<j<<"] is "<<cofactor(obj,i,j)<<endl; 
cout<<"want of find cofactor of another element? Press y for yes"<<endl; 
cin>>ans3; 
} 
// Following lines were to meant to test ONLY the transpose function and hence commented 

/* cout<<"Printing Transpose of the matrix "<<endl; 
matrix trans1; 
trans1=transpose(obj); 
display(trans1); 
*/ 

// Find Inverse 

cout<<"\n\n\n Finding Inverse. . .\n\n"; 
matrix obj_inv2; 
obj_inv2=inverse(obj); 
display(obj_inv2); // Display the matrix inverse 

getch(); 
return 0; 
} 
void input(matrix &obj) 
{ 
// This function gets elements of a matrix input by the user 
// Parameter is the structure object obj (used throughout the program) 
// Parameter is "passed by reference" so as to reflect the changes made by this function, to other functions that call it 

cout<<"Enter the matrix "<<endl; 
for (int i=1;i<=obj.n;i++) 
{ 
for (int j=1;j<=obj.n;j++) 
{ 
cout<<"Enter the element a["<<i<<"]["<<j<<"] : "; 
cout<<endl; 
cin>>obj.a[i][j]; 
} 
} 
} 
void display(matrix &obj) 
{ 
// This function displays elements of a matrix passed to it as a parameter 
// Parameter is the structure object obj (used throughout the program) 
// Parameter is "passed by reference" but may be "passed by value" also. 

if(obj.n==0) 
return; 
else{ 
cout<<"The matrix is: "<<endl; 
for (int i=1;i<=obj.n;i++) 
{ 
for (int j=1;j<=obj.n;j++) 
{ 

cout<<obj.a[i][j]<<" "; 
} 
cout<<endl; 
} 
}} 
matrix reduced(matrix &obj, int i,int j) 
{ 
// This function reduces the matrix passed as input to it 
// The 'reduction' requirement is like this: 
// Eliminate the row i and column j from the given matrix to get the reduced matrix 

// This is done by the following logic: 
// a is given matrix. c_obj is desired reduced matrix 
// i. Using two for loops (iterating with p and q here) as usual, we scan the given matrix. 
// row and col represent the current location pointer of row and column of the required reduced matrix. 
// ii. All elements from given matrix are copied to reduced matrix except for those corresponding to 
// row i and column j 
// iii. The reduced matrix has its dimensions one less than that of given matrix 

int row=1,col=1; 
for(int p=1;p<=obj.n;p++) // outer loop traverses through rows as usual 
{ 
for(int q=1;q<=obj.n;q++) // inner loop traverses through columns as usual 
{ 
if((p!=i)&&(q!=j)) // Skip the elements corresponding to row i OR column j of the given matrix 
{ 
c_obj.a[row][col]=obj.a[p][q]; 
col=col+1; 
} 
if(col>=obj.n) // When column 'col' of reduced matrix reaches (or exceeds n), reset it to 1 
{ // and increment 'row'. This means current row of reduced matrix got filled and 
// we need to begin filling a new row. 
col=1; 
row=row+1; 

if (row>=obj.n) //This represents the case when both 'col' and 'row of reduce matrix reach (or 
// exceed) n. This means the reduced matrix has been filled up.Break out of the loops. 
break; 
} 
} 

} 
c_obj.n=obj.n-1; // Fix the dimension of the reduced matrix one less than the given input matrix 

return c_obj; // Return the reduced matrix to the calling function. 
} 


float determinant(matrix obj) 
{ 
// This function is called recursively until we get dimension = 1 where the only element in the matrix gets returned. 

float det=0; 
if(obj.n==1) 
{return obj.a[1][1]; 
} 
else 
{ 
for(int scan=1;scan<=obj.n;scan++)//Fix the first row and vary the column in this row using for loop iteration variable 'scan' 
{ 

det=det+obj.a[1][scan]*int(pow(-1,(1+scan)))*determinant(reduced(obj,1,scan)); 
// det is calculated to be the sum of the following 
// i. prev value stored in det. 
// ii. current element in the first row (i.e. a[1][scan]) MULTIPLIED by -1^(i+j) [i is 1 for 1st row and j is nothing but scan here MULTIPLIED by the reduced matrix corresponding to this i (1) and j (scan) 

// PLEASE UNDERSTAND BY COMPARING THIS WITH THE MATHEMATICAL WAY OF CALCULATING DETERMINANT 
// - It's computed in a similar way here. 

} 
return det; 
} 
} 

float cofactor(matrix obj,int i,int j) 
{ 

// The computation done here is like this: 
// If the matrix (passed as paramenter) has dimension = 1, return the only element as cofactor 
// Else, return determinant of the reduced matrix corresponding to i and j passed with a 
// multiplication factor -1^(i+j) 

float cofact; 
if(obj.n==1) 
{ 
return obj.a[1][1]; 
} 
else 
{ 
cofact=int(pow(-1,(i+j)))*determinant(reduced(obj,i,j)); 
} 
return cofact; 

} 
matrix transpose(matrix obj) 
{ 
// Transpose matrix is the given matrix with its rows and columns interchanged. 

// Just invert the elements during storing when scanning through the for loops 
// trans_obj is the transposed matrix, returned by the function. 
// obj is the input matrix passed to this function. 

trans_obj.n=obj.n; 
for(int i=1;i<=obj.n;i++) 
{ 
for(int j=1;j<=obj.n;j++) 
{ 
trans_obj.a[i][j]=obj.a[j][i]; 
} 
} 
return trans_obj; 
} 

matrix adjoint(matrix obj) 
{ 
// obj_adj is adjoint matrix and obj_cof is cofactor matrix 
// both have dimensions n 

// Cofactor matrix of a given matrix is a matrix whose elements are the cofactors of the respective 
// elements of the given matrix 


// Adjoint matrix is transpose of cofactor matrix. Return this 

obj_adj.n=obj.n; 
obj_cof.n=obj.n; 



for(int i=1;i<=obj.n;i++) 
{ 
for(int j=1;j<=obj.n;j++) 
{ 
obj_cof.a[i][j]=cofactor(obj,i,j); 
} 
} 

obj_adj=transpose(obj_cof); 
return obj_adj; 
} 

matrix inverse(matrix obj) 
{ 
// Formula : Inverse of a matrix is = adj(matrix)/its determinant 

float d=determinant(obj); // First find determinant of the given matrix 

matrix obj_null; 
obj_null.n=0; 
// Display error message if determinant is 0 

if(d==0) 
{ 
cout<<"Inverse can be found only if the determninant of the matrix is non-zero"<<endl; 
return obj_null; 
} 

// Determinant is non-zero - Proceed finding inverse using the above formula 
else 
{ 
matrix obj_adj1=adjoint(obj); 
obj_adj1.n=obj.n; 
obj_inv.n=obj.n; 
for(int i=1;i<=obj.n;i++) 
{ 
for(int j=1;j<=obj.n;j++) 
{ 
obj_inv.a[i][j]=(obj_adj1.a[i][j])/d; 
} 
} 

return obj_inv; 
} 
}


