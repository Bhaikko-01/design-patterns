package questions.TicTacToe;

import java.util.List;

enum PieceType {
  X,
  O
}

// Creating Piece class that will act as Parent for all Pieces
// This way, any number of Piece classes can be created
class Piece {
  public PieceType pieceType;

  public Piece(PieceType pieceType) {
    this.pieceType = pieceType;
  }
}

class PieceX extends Piece {
  public PieceX() {
    super(PieceType.X);
  }
}

class PieceO extends Piece {
  public PieceO() {
    super(PieceType.O);
  }
}

class Board {
  int size;
  // Grid for placing pieces
  Piece pieces[][];

  public Board(int size) {
    this.size = size;
    this.pieces = new Piece[size][size];
  }
}

class Player {
  String name;
  PieceType playingPiece;

  public Player(String name, PieceType pieceType) {
    this.name = name;
    this.playingPiece = pieceType;
  }
}

class TicTacToeGame {
  List<Player> players;
  Board board;

  TicTacToeGame(List<Player> players, int size) {
    this.players = players;
    this.board = new Board(size);
  }

  public void startGame() {
    // Player turn can be managed using a queue
    // while we have no winner,
    // Player at front of queue will place piece
    // Check if winner found OR board is empty
    // return the player that won
    // If no player won, return null
  }

  private boolean addPiece(int row, int colum, PieceType piece) {
    // If Piece exists on that index, return false
    // else return true
    return true;
  }

  private boolean isGameWon(PieceType pieceType) {
    // Logic for game won by considering pieces of specific type
    return true;
  }
}
