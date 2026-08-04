#include "../include/board.h"
#include "../include/moves.h"
#include <cstdio>
#include <vector>


// --------------------------------------------------
// Setup the board with pawns in their initial positions
// --------------------------------------------------

board_t* setupPawns() {
    board_t* board = new board_t();

    board->black_pawns   = static_cast<std::uint64_t>(0b11111111) << 48;
    board->black_knights = static_cast<std::uint64_t>(0b01000010) << 56;
    board->black_kings   = static_cast<std::uint64_t>(0b00001000) << 56;
    board->black_queens  = static_cast<std::uint64_t>(0b00010000) << 56;
    board->black_bishops = static_cast<std::uint64_t>(0b00100100) << 56;
    board->black_rooks   = static_cast<std::uint64_t>(0b10000001) << 56;
    
    board->white_pawns   = static_cast<std::uint64_t>(0b11111111) << 8;
    board->white_knights = static_cast<std::uint64_t>(0b01000010);
    board->white_kings   = static_cast<std::uint64_t>(0b00001000);
    board->white_queens  = static_cast<std::uint64_t>(0b00010000);
    board->white_bishops = static_cast<std::uint64_t>(0b00100100);
    board->white_rooks   = static_cast<std::uint64_t>(0b10000001);

    return board;
}

void print_bits(std::uint64_t val) {
    std::bitset<64> bits(val);

    for (int i = 63; i >= 0; --i) {
        std::cout << bits[i];

        if (i % 8 == 0)
            std::cout << ' ';
    }

    std::cout << "\n";
}

// --------------------------------------------------
// Get the piece at a given position on the board
// --------------------------------------------------

piece_type_t getPieceAt(int x, int y, board_t* board) {
    std::uint64_t mask = static_cast<std::uint64_t>(1) << (y * 8 + x);

    if (board->black_pawns   & mask) return BLACK_PAWN;
    if (board->black_knights & mask) return BLACK_KNIGHT;
    if (board->black_bishops & mask) return BLACK_BISHOP;
    if (board->black_rooks   & mask) return BLACK_ROOK;
    if (board->black_queens  & mask) return BLACK_QUEEN;
    if (board->black_kings   & mask) return BLACK_KING;

    if (board->white_pawns   & mask) return WHITE_PAWN;
    if (board->white_knights & mask) return WHITE_KNIGHT;
    if (board->white_bishops & mask) return WHITE_BISHOP;
    if (board->white_rooks   & mask) return WHITE_ROOK;
    if (board->white_queens  & mask) return WHITE_QUEEN;
    if (board->white_kings   & mask) return WHITE_KING;

    return PIECE_NONE;
}

// --------------------------------------------------
// handle mouse button pressed event
// --------------------------------------------------

static Square mousePositionToSquare(Vector2 mouse_position) {
    int screen_x = static_cast<int>(mouse_position.x) / cell_width;
    int screen_y = static_cast<int>(mouse_position.y) / cell_width;
    int board_x = screen_x;
    int board_y = board_cells - 1 - screen_y;

    return compressCoordinates(board_x, board_y);
}

void handleMouseButtonPressed(game_state_t *game_state) {
    Square final_position;

    if (!game_state->is_piece_selected) {
        auto pI = GetMousePosition();
        
        game_state->selected_square = mousePositionToSquare(pI);
        
        game_state->selected_piece = getPieceAt(game_state->selected_square % 8, game_state->selected_square / 8, game_state->board);
        

        if   (game_state->selected_piece != PIECE_NONE) game_state->is_piece_selected = true;
        else                                            game_state->is_piece_selected = false;

        std::printf("initial screen coordinates: %f, %f\n", pI.x, pI.y);
        std::printf("initial board coordinates: %d, %d\n", game_state->selected_square % 8, game_state->selected_square / 8);
        std::fflush(stdout);
    }

    else {
        game_state->is_piece_selected = false;
        auto pF = GetMousePosition();
        final_position = mousePositionToSquare(pF);

        std::printf("final screen coordinates: %f, %f\n", pF.x, pF.y);
        std::printf("final board coordinates: %d, %d\n", final_position % 8, final_position / 8);
        std::fflush(stdout);
        
        std::vector<move_t> possible_moves = getPossibleMoves(game_state->board, game_state->selected_square % 8, game_state->selected_square / 8, game_state->selected_piece, game_state->is_white_turn);

        for (auto move : possible_moves) {
            printf("from: %d, to: %d", move.from, move.to);
        }
        makeMove(game_state, possible_moves, final_position);
    }

    
    std::printf("piece is slected?: %b, white_turn?: %b\n", game_state->is_piece_selected, game_state->is_white_turn);
    std::fflush(stdout);
}
