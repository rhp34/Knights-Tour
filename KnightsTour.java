class Main {
    static int knightsMoves = 8;
    static int[] possibleMovesX = {-1, -1, -2, -2, 1, 1, 2, 2};
    static int[] possibleMovesY = {2, -2, 1, -1, 2, -2, -1, 1};
 
    static boolean isMovePossible(int x, int y, int chessboard[][]) {
    
        return (x >= 0 && x < knightsMoves && y >= 0 && y < knightsMoves && chessboard[x][y] == -1);
    }
 
    
    static void solution(int chessboard[][]) {
    
        for (int x = 0; x < knightsMoves; x++) {
            for (int y = 0; y < knightsMoves; y++)
                System.out.print(chessboard[x][y] + " ");
            System.out.println();
        }
    }
 

 
    static boolean solve(int x, int y, int move, int chessboard[][], int[] possibleMovesX, int[] possibleMovesY) {
    
        int i, nextX, nextY;
        if (move == knightsMoves * knightsMoves)
            return true;
 

        for (i = 0; i < 8; i++) {
            nextX = x + possibleMovesX[i];
            nextY = y + possibleMovesY[i];
            if (isMovePossible(nextX, nextY, chessboard)) {
                chessboard[nextX][nextY] = move;
                if (solve(nextX, nextY, move + 1, chessboard, possibleMovesX, possibleMovesY))
                    return true;
                else
                    chessboard[nextX][nextY] = -1;
            }
        }
 
        return false;
    }
 
    public static void main(String args[]) {
   
        int chessboard[][] = new int[8][8];
        
        for(int x = 0; x < knightsMoves; x++) {
        	for(int y = 0; y < knightsMoves; y++) {
        		chessboard[x][y] = -1;
        		
        	}
        }
        chessboard[0][0] = 0;
        
        if(!solve(0, 0, 1, chessboard, possibleMovesX, possibleMovesY)) {
        	System.out.println("Solution does not exist");

        } else {solution(chessboard);}

    }
}