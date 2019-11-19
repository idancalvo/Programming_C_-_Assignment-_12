#include <stdio.h>

#define N 11 /*size of matrix*/

enum boolean {FALSE=0,TRUE=1};
typedef int adjmat[N][N];


/*	FUNCTION PROTOTYPE	*/
enum boolean path (adjmat AdjacencyMatrix,int u, int v);
int whosMyFather (adjmat AdjacencyMatrix, int u);
void buildMatrix (adjmat AdjacencyMatrix);
void printMatrix (adjmat AdjacencyMatrix);


/*
 * First the variable N (the size of the matrix) must be defined at the top of the code!
 *  
 *  The program ask the user to enter the values of the matrix. (the function buildMatrix)
 *  
 *  then The program prints the entire matrix (the function printMatrix)
 *  
 *  The program will request 2 indexes from the user 
 *  And with the help of the recursive function (the function path),
 *  will return if there is a path between those indexes 
 *	
 *  the recursive function path Rises from the son to the root 
 *  and checks if the father is in the path.
 *	
 */
int main ()
{

	int u,v; /*Two index of nodes*/
	adjmat AdjacencyMatrix; /*Adjacency Matrix of the tree*/

	buildMatrix (AdjacencyMatrix); /*loading Matrix*/
	printMatrix (AdjacencyMatrix);/*print Matrix*/

	/*Receiving inputs from the user*/
	printf ("\nHi,\nplease enter 2 indexes of nodes that you want to check if they are ancestry:\n\n"); 

	while ( (scanf("%d %d",&u,&v)!=EOF) && !((u==-1)&&(v==-1)) )
	{
	enum boolean ans;
	ans = path (AdjacencyMatrix,u,v); 

	/*Print results*/
	printf ("You wanted to check if node %d is the ancestor of node %d\n",u,v); 

	if (ans == TRUE)
		printf ("and the answer is Yes!, %d is the ancestor of node %d\n",u,v);
	else
		printf ("and the answer is No!, %d isn't the ancestor of node %d\n",u,v);

	printf ("\nplease enter 2 indexes of nodes that you want to check if they are ancestry:\n\n");
	}
	return 0;
}



/*
 * The Recursive function returns whether v is an ancestor of u 
 *	input: adjmat, int u = father's index  , int v = son's index 
 *	output: boolean (FALSE or TRUE} = v is an ancestor of u
 */
enum boolean path (adjmat AdjacencyMatrix,int u, int v)
{
	int fathrV;
	if (u>=N || v>=N || u<0 || v<0) /*if there is a Deviation from array Or v is the root*/
		return FALSE;

	if ( (AdjacencyMatrix[u][v]=='1') || (u==v) ) /* u is the son of v or u and v is same node*/
		return TRUE;

	fathrV = whosMyFather (AdjacencyMatrix,v); /*who is the father of node 'v'*/

	return path (AdjacencyMatrix,u,fathrV);
}


/*
 * The function return who is the father of node 'v'
 *	input: adjmat , int = The node we want to check
 *	output: int = Father's index of v (-1 if v has no father)
 */
int whosMyFather (adjmat AdjacencyMatrix, int v)
{
	int i;	
	for (i=0; i<N ; i++)
	{
		if (AdjacencyMatrix[i][v]=='1')
		{
		return i;
		}
	}
	return -1;
}


/*
 * The function get Adjacency Matrix and initializes it according to the standard input
 *	input: adjmat
 *	output: -------- 
 */
void buildMatrix (adjmat AdjacencyMatrix)
{
	int i,j;
	char tempc;/*save the input temporarily*/

	printf ("\nThe size of the Adjacency Matrix is %dX%d\n",N,N); /*Explain to the user*/
	printf ("please enter the values 0/1 into the Adjacency Matrix, %d times\n",N*N);


	for (i=0;i<N;i++) /*Inserts input into the matrix*/
	{
		for (j=0;j<N;j++)
		{
			while ((tempc=getchar())==' '|| (tempc=='\t') || (tempc=='\n') );
			AdjacencyMatrix[i][j]=tempc;
		}
	}
}


/*
 * The function get Adjacency Matrix and print it on the standart output.
 *	input: adjmat 
 *	output: ---------
 */
void printMatrix (adjmat AdjacencyMatrix)
{
	int i,j;
 
	printf ("\n\nThis is your Adjacency Matrix\n\n     ");
	
	for (i=0;i<N;i++)/*index of column*/
		if (i<10)
			printf ("  %d ",i);
		else
			printf (" %d ",i);

	printf ("\n");

	for (i=0;i<N;i++){
		if (i<10) 
			printf ("\n %d   | ",i); /*index of Row*/
		else
			printf ("\n %d  | ",i); /*Fixing for two-digit line number*/
		
		for (j=0;j<N;j++){ 
			printf ("%c",AdjacencyMatrix[i][j]); /*The value of the matrix*/
			printf (" | ");
		}
	}
	printf ("\n");
}


