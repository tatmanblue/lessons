using System;

namespace suduko
{
    class Program
    {
        public static void Main(string[] args)
        {
            Program p = new Program();
            int[,] data = new int[,]
                    {
                        {1,2,3,  4,5,6,  7,8,9},
                        {4,5,6,  7,8,9,  1,2,3},
                        {7,8,9,  1,2,3,  4,5,6},

                        {2,3,4,  5,6,7,  8,9,1},
                        {5,6,7,  8,9,1,  2,3,4},
                        {8,9,1,  2,3,4,  5,6,7},

                        {3,4,5,  6,7,8,  9,1,2},
                        {6,7,8,  9,1,2,  3,4,5},
                        {9,1,2,  3,4,5,  6,7,8},
                    };
            p.Print(data);

            Console.WriteLine($"Data is {p.Validate(data)}");

        }

        public void Print(int[,] game)
        {
            Console.WriteLine("\r\n     |------+------+-----|");
            for (int row = 0; row < 9; row++)
            {
                Console.Write($"     ");
                for (int col = 0; col < 9; col++)
                {
                    if ((col % 3) == 0)
                        Console.Write($"|");

                    string spot = " ";
                    if (0 < game[row, col])
                        spot = game[row, col].ToString();

                    Console.Write($"{spot} ");
                }

                if ((row % 3) == 2)
                    Console.WriteLine("\r\n     |------+------+-----|");
                else
                    Console.WriteLine("");

            }
        }

        public bool Validate(int[,] game)
        {
            const int rightValue = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
            for (int row = 0; row < 9; row++)
            {
                int rowValue = 0;
                for (int col = 0; col < 9; col++)
                {
                    rowValue += game[row, col];
                }

                if (rowValue != rightValue)
                    return false;
            }

            for (int col = 0; col < 9; col ++)
            {
                int colValue = 0;
                for (int row = 0; row < 9; row ++)
                {
                    colValue += game[row, col];
                }
                if (colValue != rightValue)
                    return false;
            }

            return true;
        }

    }
}
