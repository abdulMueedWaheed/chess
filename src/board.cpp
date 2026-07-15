#include "../include/board.h"
#include "../include/move_logic.h"


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
// Convert screen coordinates to board coordinates
// --------------------------------------------------

Vector2 screenToBoard(int x, int y, int board_size, int cell_width) {
    if (x < 0 || y < 0 || x >= board_size * cell_width || y >= board_size * cell_width) {
        return {0.0f, 0.0f};
    }

    int boardX = x / cell_width;
    int boardY = board_size - 1 - (y / cell_width);

    return Vector2({static_cast<float>(boardX), static_cast<float>(boardY)});
}

// --------------------------------------------------
// handle mouse button pressed event
// --------------------------------------------------

void handleMouseButtonPressed(game_state_t *game_state) {
    
    if (!game_state->piece_selected) {
        auto p = GetMousePosition();
        
        game_state->initial_position = screenToBoard(p.x, p.y, board_cells, cell_width);
        
        piece_type_t piece = getPieceAt(game_state->initial_position.x, game_state->initial_position.y, game_state->board);
        
        if (piece != PIECE_NONE) {
            game_state->piece_selected = true;
            // std::printf("initial: %f, %f\n", game_state->initial_position.x, game_state->initial_position.y);
            // std::fflush(stdout);
            
        }

        else {
            game_state->piece_selected = false;
        }
    }

    else {
        game_state->piece_selected = false;
        auto p = GetMousePosition();
        game_state->final_position = screenToBoard(p.x, p.y, board_cells, cell_width);

        // std::printf("final: %f, %f\n", game_state->final_position.x, game_state->final_position.y);
        // std::fflush(stdout);
        
        makeMove(game_state);
    }

}