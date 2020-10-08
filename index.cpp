//HEADER FILES
#include<iostream>
using namespace std;

// initial declarations
int grid[][3] = {{1,2,3},{4,5,6},{7,8,9}};
bool check[3][3];
char comp = 'O', player='X';
bool run = true;
bool playAgain = true;
struct Move
{
     int row, col;
};


// DECLARING FUNCTIONS
void changeGrid(int);
void Board();
int evaluate();
Move findBestMove();
int minimax(bool);
bool isTied();
void makeMove(int,int);
void whoWon();

// MAIN FUNCTION
int main(void)
{

    int mv;


    while(run)
    {

        cout<<"enter your move";
        cin>>mv;
        //cout<<"hello";
        //system("pause");
        system("cls");
        changeGrid(mv);
        //Board();
        //system("pause");
        Move ans = findBestMove();


        makeMove(ans.row, ans.col);
        whoWon();
        Board();
    }

    cout<<"Hey thanks for playing..";
    cout<<"see you again";


    return 0;
}

//makeMove
void makeMove(int row ,int col){
    grid[row][col] = comp;
    check[row][col] = true;
}
//MINIMAX FUNCTION
int minimax(bool isMax){
    int score = evaluate();
    if(score == 10)
        return score;
    if(score == -10)
        return score;
    if(isTied() == true)
        return 0;




    if (isMax)
    {
        int best = -1000;


        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {

                // Check if cell is empty
                if (!check[i][j])
                {

                    int initialVal = grid[i][j];
                    grid[i][j] = comp;
                     check[i][j] = true;

                    best = max( best,  minimax(!isMax) );


                    grid[i][j] = initialVal;
                     check[i][j] = false;
                }
            }
        }
        return best;
    }

    else
    {
        int best = 1000;


        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)

            {

                // Check if cell is empty
                if (!check[i][j])
                {

                    int initialVal = grid[i][j];
                    grid[i][j] = player;
                    check[i][j] = true;

                    best = min( best,  minimax(!isMax) );


                    grid[i][j] = initialVal;
                     check[i][j] = false;
                }
            }
        }
        return best;
    }


}
//FINDING THE BEST MOVE CALLING MINIMAX
Move findBestMove()
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {

            if (!check[i][j])
            {
                int initialVal = grid[i][j];

                grid[i][j] = comp;
                check[i][j] = true;

                int moveVal = minimax(false);


                grid[i][j] = initialVal;
                check[i][j] = false;


                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

// PRINT THE WHOLE BOARD (FUNCTION)
void Board()
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(grid[i][j]>10)
            {
                char c = grid[i][j];
                cout<<c<<"\t";
            }
            else cout<<grid[i][j]<<"\t";
        }

        cout<<endl;
    }
}

// MAKE THE MOVE ON THE BOARD
void changeGrid(int Mov)
{
    switch(Mov){
        case 1:
            {   if(check[0][0])
                    {
                        cout<< "Try again \n";

                        system("pause");
                        return;

                    }

                grid[0][0] = player;
                check[0][0] = true;
            }
        break;
        case 2:
        {
            if(check[0][1])
                    {
                        cout<< "Try again";

                        system("pause");
                        return;

                    }
            grid[0][1] = player;
            check[0][1] = true;
        }
        break;
        case 3:
        {
            if(check[0][2])
                    {
                        cout<< "Try again";

                        system("pause");
                        return;

                    }
            grid[0][2] = player;
            check[0][2] = true;
        }
        break;
        case 4:
        {
            if(check[1][0])
                    {
                        cout<< "Try again";

                        system("pause");
                        return;

                    }
            grid[1][0] = player;
            check[1][0] = true;
        }
        break;
        case 5:
        {
            if(check[1][1])
                    {
                        cout<< "Try again";

                        system("pause");
                        return;

                    }
            grid[1][1] = player;
            check[1][1] = true;
        }
        break;
        case 6:
        {
            if(check[1][2])
                    {
                        cout<< "Try again";

                        system("pause");
                        return;

                    }
            grid[1][2] = player;
            check[1][2] = true;
        }
        break;
        case 7:
        {
            if(check[2][0])
                    {
                        cout<< "Try again";

                        system("pause");
                        return;

                    }
            grid[2][0] = player;
            check[2][0] = true;
        }
        break;
        case 8:
        {
            if(check[2][1])
                    {
                        cout<< "Try again";

                        system("pause");
                        return;

                    }
            grid[2][1] = player;
            check[2][1] = true;
        }
        break;
        case 9:
        {
            if(check[2][2])
                    {
                        cout<< "Try again";

                        system("pause");
                        return;

                    }
            grid[2][2] = player;
            check[2][2] = true;
        }
        break;
        default:
         {
            cout<<"Try again"<<endl;

            cout<<Mov;
        }
    }
}

/*int evaluate()
{
    //rows checking
  for(int i = 0 ;i<3;i++){
      if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){
          if(grid[i][0] == player){
              return -10;
          }
          return 10;


      }
  }
    //columns checking
  for(int i = 0 ;i<3;i++){
      if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]){
          if(grid[0][i] == player){
              return -10;
          }
          return 10;


      }
  }
    //diagonals checking
     if(grid[0][0] == grid[1][1] && grid[2][2] == grid[1][1]){
          if(grid[0][0] == player){
              return -10;
          }
          return 10;


      }
     else if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
          if(grid[0][2] == player){
              return -10;
          }
          return 10;


      }
}
*/

int evaluate()
{
    {
	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++)
	{
		if (grid[row][0]==grid[row][1] &&
			grid[row][1]==grid[row][2])
		{
			if (grid[row][0]==comp)
				return +10;
			else if (grid[row][0]==player)
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++)
	{
		if (grid[0][col]==grid[1][col] &&
			grid[1][col]==grid[2][col])
		{
			if (grid[0][col]==comp)
				return +10;

			else if (grid[0][col]==player)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
	{
		if (grid[0][0]==comp)
			return +10;
		else if (grid[0][0]==player)
			return -10;
	}

	if (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
	{
		if (grid[0][2]==comp)
			return +10;
		else if (grid[0][2]==player)
			return -10;
	}

	// Else if none of them have won then return 0
	return 0;
}
}

//Check for tie
bool isTied(){
        bool filled = false;
        int point = 0;
         for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){

                if(check[i][j]){
                 point = point + 1;
                }
            }

        }
        if(point >= 9)
            return true;
        return filled;

    }

    // checking for winning condition:
    void whoWon()
{
    if(grid[0][0]==grid[0][1] && grid[0][1]==grid[0][2])
    {
        run =false;
    }

    else if(grid[1][0]==grid[1][1] && grid[1][1]==grid[1][2])
    {
        run = false;
    }
    else if(grid[2][0]==grid[2][1] && grid[2][1]==grid[2][2])
    {
        run = false;
    }
    else if(grid[0][0]==grid[1][0] && grid[1][0]==grid[2][0])
    {
        run = false;
    }
    else if(grid[0][1]==grid[1][1] && grid[1][1]==grid[2][1])
    {
        run = false;
    }
    else if(grid[0][2]==grid[1][2] && grid[1][2]==grid[2][2])
    {
        run = false;
    }

    else if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
    {
        run = false;
    }
    else if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
    {
        run = false;
    }
}

