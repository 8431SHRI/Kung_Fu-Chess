// #include "Board.hpp"
// #include "RuleEngine.hpp"
// #include "RealTimeArbiter.hpp"
// #include "GameEngine.hpp"
// #include "Renderer.hpp"
// #include "Img.hpp"
// #include "GameSnapshot.hpp"
// #include "window.hpp"
// #include "ResourceManager.hpp"
// #include "SelectionModel.hpp"
// #include <iostream>
// #include <filesystem>
// #include <vector>

// int main()
// {
//     try
//     {
//         std::cout << "Starting game engine..." << std::endl;
//         Board board(8, 8);
//         SelectionModel selection;
//         Window window(800, 800, "Kung Fu Chess");
//         // מערך סדר הכלים בשורה הראשונה
//         PieceType backRow[] = {
//             PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
//             PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK};

//         // סידור הכלים על הלוח
//         for (int col = 0; col < 8; ++col)
//         {
//             // שורה 0: כלים שחורים
//             board.setPieceAt(0, col, std::make_shared<Piece>(1, Side::BLACK, backRow[col], Position(0, col)));
//             // שורה 1: רגלים שחורים
//             board.setPieceAt(1, col, std::make_shared<Piece>(2, Side::BLACK, PieceType::PAWN, Position(1, col)));
//             // שורה 6: רגלים לבנים
//             board.setPieceAt(6, col, std::make_shared<Piece>(3, Side::WHITE, PieceType::PAWN, Position(6, col)));
//             // שורה 7: כלים לבנים
//             board.setPieceAt(7, col, std::make_shared<Piece>(4, Side::WHITE, backRow[col], Position(7, col)));
//         }

//         RuleEngine ruleEngine;
//         RealTimeArbiter arbiter(board);
//         GameEngine engine(board, ruleEngine, arbiter);

//         ResourceManager resources("assets");
//         Renderer renderer(resources, "assets/board.png");

//         Img canvas;
//         canvas.read("assets/board.png", {800, 800}, false);

//         if (canvas.get_mat().channels() == 3)
//         {
//             cv::cvtColor(canvas.get_mat(), canvas.get_mat(), cv::COLOR_BGR2BGRA);
//         }
//         while (true)
//         {
//             GameSnapshot snapshot = engine.snapshot();

//             window.render(snapshot);
//             window.show();

//             if (cv::waitKey(16) == 27)
//                 break;
//         }

//         return 0;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Error: " << e.what() << std::endl;
//         std::cout << "Press Enter to exit...";
//         std::cin.get(); // זה ישאיר את החלון פתוח כדי שתוכלי לקרוא את השגיאה
//         return 1;
//     }
// }
#include "Board.hpp"
#include "RuleEngine.hpp"
#include "RealTimeArbiter.hpp"
#include "GameEngine.hpp"
#include "GameController.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include "ResourceManager.hpp"
#include "SelectionModel.hpp"

#include <opencv2/highgui.hpp>
#include <iostream>

int main()
{
    try
    {
        std::cout << "Starting Kung Fu Chess..." << std::endl;

        // =========================
        // יצירת הלוח
        // =========================
        Board board(8, 8);

        PieceType backRow[] =
            {
                PieceType::ROOK,
                PieceType::KNIGHT,
                PieceType::BISHOP,
                PieceType::QUEEN,
                PieceType::KING,
                PieceType::BISHOP,
                PieceType::KNIGHT,
                PieceType::ROOK};

        for (int col = 0; col < 8; ++col)
        {
            // שחורים
            board.setPieceAt(
                0, col,
                std::make_shared<Piece>(
                    100 + col,
                    Side::BLACK,
                    backRow[col],
                    Position(0, col)));

            board.setPieceAt(
                1, col,
                std::make_shared<Piece>(
                    200 + col,
                    Side::BLACK,
                    PieceType::PAWN,
                    Position(1, col)));

            // לבנים
            board.setPieceAt(
                6, col,
                std::make_shared<Piece>(
                    300 + col,
                    Side::WHITE,
                    PieceType::PAWN,
                    Position(6, col)));

            board.setPieceAt(
                7, col,
                std::make_shared<Piece>(
                    400 + col,
                    Side::WHITE,
                    backRow[col],
                    Position(7, col)));
        }

        // =========================
        // מנוע המשחק
        // =========================
        RuleEngine ruleEngine;
        RealTimeArbiter arbiter(board);
        GameEngine engine(board, ruleEngine, arbiter);

        // =========================
        // בחירה + קלט
        // =========================
        SelectionModel selection;
        GameController controller(
            board,
            engine,
            selection);

        // =========================
        // ציור
        // =========================
        ResourceManager resources("assets");
        Renderer renderer(resources, "assets/board.png");

        Window window(
            renderer,
            controller,
            selection);

        // =========================
        // לולאת המשחק
        // =========================
        while (true)
        {
            engine.wait(16);
            GameSnapshot snapshot = engine.snapshot();

            window.render(snapshot);
            window.show();

            // ESC לסיום
            if (cv::waitKey(16) == 27)
                break;
        }

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}