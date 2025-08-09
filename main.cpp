#include <iostream>
#include <vector>


using std::vector;

vector<vector<int>> initSquare(int square_size) {
    vector<vector<int>> square(square_size, vector<int> (square_size, 0));
    return square;
}

int getSquareSize() {
    int square_size;
    std::cout << "Insert the size of the square:\n";
    std::cin >> square_size;
    return square_size;
}
int main() {
    int s_size;
    s_size = getSquareSize();
    initSquare(s_size);
    std::cout << "size of the square is: " << s_size << "\n";
    vector<vector<int>> square = initSquare(s_size);

    return 0;
}