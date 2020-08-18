class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        if board is None:
            return
        self.solution(board)

    def solution(self, board):
        for row in range(len(board)):
            for column in range(len(board[0])):
                if board[row][column] == '.':
                    for va in range(1, 10):
                        if self.is_valid(board, row, column, str(va)):
                            board[row][column] = str(va)
                            if self.solution(board):
                                return True
                            else:
                                board[row][column] = '.'
                    return False
        return True

    def is_valid(self, board, row, column, va):
        for i in range(9):
            if board[row][i] == va or board[i][column] == va:
                return False
            if board[3 * (row // 3) + (i // 3)][3 * (column // 3) + (i % 3)] == va:
                return False
        return True