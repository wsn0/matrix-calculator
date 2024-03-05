//matrix calculator.c
#include <stdio.h>
#include <string.h>
#include <math.h>

void basicperf(int ,int );
void multy(int);
void transpose(int ,int );
void det(int ,int );
void inverse(int , int );

int main() {
	char greet[] = "Welcome to Matrix calculator";
	int len = strlen(greet);
	int i,j,k;
	
	int extra = len+6;
	
	for(i=0;i<extra;i++) {
		printf("*");
	}
	printf("\n");
	
	
	for(i=0;i<1;i++){
		for(j=0;j<extra;j++) {
			if(j==0 || j==(extra-2)) {
				printf("* ");
			} else printf(" ");
	}
		printf("\n");
	}
	printf("*  %s  *\n", greet);
	
	for(i=0;i<2;i++){
		for(j=0;j<extra;j++) {
			if(i==1) {
				printf("*");
			} else if (j==0 || j==(extra-2)) {
				printf("* ");
			} else printf(" ");
		}
		printf("\n");
	}
	
	printf("\n");
	printf("--- Menu ---\n");
	printf("Press 1 for Addition/Subtraction\n");
	printf("Press 2 for Multiplication\n");
	printf("Press 3 for Transpose\n");
	printf("Press 4 for Finding Determinant --> Maximum : 3x3\n");
	printf("Press 5 for Finding Inverse Matrix --> Maximum : 2x2\n");
	
	int row, col,num;
	printf("Enter number: "); scanf("%d", &num);
	printf("\n");
	if (num>5) {
		printf("Sorry, Our program can't perform this.\n");
	} else if(num != 2) {
		printf("Enter Row of your matrix: "); scanf("%d", &row);
		printf("Enter Column of your matrix: "); scanf("%d", &col);
	}
	
	switch (num) {
		case 1:
			basicperf(row,col);
			break;
		case 2:
			multy(num);
			break;
		case 3:
			transpose(row,col);
			break;
		case 4:
			det(row,col);
			break;
		case 5:
			inverse(row,col);
			break;
	}
}

void basicperf(int r,int c) {
	int m1[r][c], m2[r][c], result[r][c];
	int i,j,num;
	
	printf("Enter first matrix:\n");
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			scanf("%d", &m1[i][j]);
		}
	}
	
	printf("Enter second matrix:\n");
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			scanf("%d", &m2[i][j]);
		}
	}
	
	printf("\n");
	printf("Press 1 for Addition\n");
	printf("Press 2 for Subtraction\n");
	
	printf("Enter number: "); scanf("%d", &num);
	
	if(num == 1) {
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				result[i][j] = m1[i][j] + m2[i][j];
			}
		}
	}
	else if(num == 2) {
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				result[i][j] = m1[i][j] - m2[i][j];
			}
		}
	} else printf("Error.\n");
	
	printf("\n");
	printf("Result:\n");
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}

void multy(int n) {
	int i,j,k;
	printf("Press 1 to Multiply with Scalar\n");
	printf("Press 2 to Multiply with Matrix\n");
	
	int num;
	printf("Enter number: "); scanf("%d", &num);
	
	if(num == 1) {
		int scalar;
		printf("Enter number(scalar): "); scanf("%d", &scalar);
		
		int r, c;
		printf("Enter Row of your matrix: "); scanf("%d", &r);
		printf("Enter Column of your matrix: "); scanf("%d", &c);
		int matrix[r][c], result[r][c];
		printf("\n");
		
		printf("Enter matrix:\n");
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				result[i][j] = scalar * matrix[i][j];
			}
		}
		
		printf("\n");
		printf("Result:\n");
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				printf("%d ", result[i][j]);
			}
			printf("\n");
		}
		
	}
	else if(num == 2) {
		int r1, c1, r2, c2;
		printf("Enter Row of your first Matrix:\n"); scanf("%d", &r1);
		printf("Enter Cloumn of your first Matrix:\n"); scanf("%d", &c1);
		
		printf("Enter Row of your second Matrix:\n"); scanf("%d", &r2);
		printf("Enter Cloumn of your second Matrix:\n"); scanf("%d", &c2);
		
		int check = 0;
		if(c1 == r2) {
			check = 1;
		} else check = 0;
		
		if(check) {
			int m1[r1][c1], m2[r2][c2], result[r1][c2];
			printf("Enter your first matrix:\n");
			for(i=0;i<r1;i++) {
				for(j=0;j<c1;j++) {
					scanf("%d", &m1[i][j]);
				}
			}
			
			printf("Enter your second matrix:\n");
			for(i=0;i<r2;i++) {
				for(j=0;j<c2;j++) {
					scanf("%d", &m2[i][j]);
				}
			}
			
			for(i=0;i<r1;i++) {
				for(j=0;j<c2;j++) {
					result[i][j] = 0;
					for(k=0;k<r2;k++) {
						result[i][j] += m1[i][k] * m2[k][j];
					}
				}
			}
			
			printf("\n");
			printf("Result:\n");
			for(i=0;i<r1;i++) {
				for(j=0;j<c2;j++) {
					printf("%d ", result[i][j]);
				}
				printf("\n");
			}
		} else printf("These matrices are unable to perform Multiplication.\n");
	} else printf("Error.\n");
}

void transpose(int r,int c) {
	int i,j;
	int matrix[r][c], t[c][r];
	
	printf("Enter your matrix:\n");
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for(i=0;i<c;i++) {
		for(j=0;j<r;j++) {
			t[i][j] = matrix[j][i];
		}
	}
	
	printf("\n");
	printf("Result:\n");
	for(i=0;i<c;i++) {
		for(j=0;j<r;j++) {
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}
}

void det(int r,int c) {
	int check = 0;
	if(r==c && r < 4 && c < 4) {
		check = 1;	
	} else check = 0;
	
	if(check) {
		int matrix[r][c], co[r-1][c-1];
		int i,j,k,t;
		int result = 0;
		
		printf("Enter your matrix:\n");
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		
		if(r==1) {
			result = matrix[0][0];
		}
		if(r==2) {
			result = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
		}	
		if(r==3) {
			for(i=0;i<r;i++) {
				int p=i;
				for(j=0;j<c;j++) {
					int q=j;
					for(k=0;k<r;k++){
						for(t=0;t<c;t++) {
							if(k!=p && t!=q) {
								co[k-(k>p)][t-(t>q)] = matrix[k][t];
							}
						}	
					}
					int dett = (co[0][0] * co[1][1]) - (co[0][1] * co[1][0]);
					result += (matrix[0][j] * pow(-1,(i+1)+(j+1))) * dett;	
				}
			}
		}
		
		printf("\nResult:");
		printf("\n%d", result);
	} else printf("Something is incorrect.\n");
				
}

void inverse(int r, int c) {
	int check = 0;
	if(r==c && r < 3 && c < 3) {
		check = 1;	
	} else check = 0;
	
	int i,j;
	float det = 0;
	if(check) {
		int matrix[r][c];
		float result[r][c];
		printf("Enter your matrix:\n");
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		
		if(r==1) {
			det = matrix[0][0];
			if(det != 0) {
				result[0][0] = 1.0/det;
			}
		}
		if(r==2) {
			det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
			int temp[r][c];
			if(det != 0) {
				temp[0][0] = matrix[1][1];
				temp[1][1] = matrix[0][0];
				temp[0][1] = (-1)*matrix[0][1];
				temp[1][0] = (-1)*matrix[1][0];
			}
			
			for(i=0;i<r;i++) {
				for(j=0;j<c;j++) {
					result[i][j] = (1.0/det) * temp[i][j];
					if(result[i][j] == 0.0) {
						result[i][j] *= -1;
					}
				}
			}	
		}
		
		printf("\nResult:\n");
		for(i=0;i<r;i++) {
			for(j=0;j<c;j++) {
				printf("%.2f  ", result[i][j]);
			}
			printf("\n");
		}
	} else printf("Something is incorrect.\n");	
}
