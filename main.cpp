#include <iostream>
#include <vector>
#include <limits>

using std::vector;


constexpr int MIN_SIZE = 3;
constexpr int MAX_SIZE = 99;

vector<vector<int>> initSquare(const int square_size) {
    vector<vector<int>> square(square_size, vector<int> (square_size, 0));
    return square;
}

void createDoublyEvenSquare(vector<vector<int>> &sqr, const int size) {
    int num = 1;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            sqr[row][col] = num++;
        }
    }
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (!((row % 4 == col % 4) || (row % 4 + col % 4 ==3 ))) {
                sqr[row][col] = size * size - sqr[row][col] + 1;
            }
        }
    }
}

void createSinglyEvenSquare(vector<vector<int>> &sqr, const int size) {
    /* TODO: Implement the method for singly even squares
     *  1. Divide the square into four quadrants of size/2
     *  2. Fill the quadrants with odd squares using the Siamese method using different starting values
     *  3. Swap the necessary columns between the left quadrants and the right quadrants
     *     according to the algorithm for singly even magic squares
     *  4. Handle the middle column swap separately
     *
     */
}

void createOddSquare(vector<vector<int>> &sqr, const int size) {
    // Siamese method for odd squares
    int row = 0;
    int col = size / 2; // set the first number to the center column
    sqr[row][col] = 1;

    for (int num = 2; num <= size * size; num++) {
        const int last_row = row;
        const int last_col = col;
        row -= 1;
        col += 1;
        if  (row < 0) { row = size - 1; }
        if (col >= size) {col = 0; }
        if (sqr[row][col] != 0) {
            row = last_row + 1;
            if  (row < 0) { row = size - 1; }
            col = last_col;
        }
        sqr[row][col] = num;
    }

}

int getSquareSize() {
    /*  TODO: Check for extra digits
    *   1. Use std::getline to read input as string
    *   2. Check if all characters are digits
    *   3. If all characters are digits -> convert string to an integer
    */


    int square_size;

        std::cout << "Insert the size of the square (" << MIN_SIZE << "-" << MAX_SIZE << "):\n";
        std::cin >> square_size;

        while(std::cin.fail() || square_size < MIN_SIZE || square_size > MAX_SIZE) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<< "Invalid size.\n";
            std::cout << "Insert the size of the square (" << MIN_SIZE << "-" << MAX_SIZE << "):\n";
            std::cin >> square_size;
        }

    return square_size;
}

void drawSquare(const vector<vector<int>> &sqr, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << sqr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    const int s_size = getSquareSize();
    initSquare(s_size);
    std::cout << "size of the square is: " << s_size << "\n";
    vector<vector<int>> square = initSquare(s_size);
    if (s_size % 2 != 0) {
        createOddSquare(square, s_size);
    }
    if (s_size % 4 == 0) {
        createDoublyEvenSquare(square, s_size);
    }
    drawSquare(square, s_size);


    return 0;
}