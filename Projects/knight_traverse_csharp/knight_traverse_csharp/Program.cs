using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace knight_traverse_csharp
{
    class CommData
    {
        public const int MAX_WIDTH = 30;
        public const int MAX_DIR = 8;
    }
    class Knight
    {
        public Knight(int d)
        {
            width =d;
            init_direction();
        }
        public void print()
        {
            int x, y;
            Console.Write(" +");
            for (x = 0; x < width; x++)
                Console.Write("----+");
            Console.Write('\n');
            for (x = 0; x < width; x++)
            {
                Console.Write(" |");
                for (y = 0; y < width; y++)
                    Console.Write(chessboard[x, y].ToString().PadLeft(3) + " |");
                Console.Write("\n +");
                for (y = 0; y < width; y++)
                    Console.Write("----+");
                Console.Write('\n');
            }
        }

        public bool tourist(int start_x, int start_y)
        {
            init_chessboard();
            set_start(start_x, start_y);
            do
            {
                if (select_direction())
                    forward();
                else backward();
            } while (!is_end() && !back_to_start());
            if (back_to_start())
                return false;
            else
            {
                print();
                return true;
            }
        }

        protected int[] var_x = new int[CommData.MAX_DIR];
        protected int[] var_y = new int[CommData.MAX_DIR];
        protected int [,]chessboard = new int[CommData.MAX_WIDTH,CommData.MAX_WIDTH];
        protected int[,] direction = new int[CommData.MAX_WIDTH, CommData.MAX_WIDTH];
        protected int width, step, last_direction, curr_x, curr_y;

        protected void init_chessboard()
        {
            int x, y;
            for (x = 0; x < width; x++)
                for (y = 0; y < width; y++)
                    chessboard[x, y] = 0;
        }

        protected void init_direction()
        {
            var_x[0] = 2; var_y[0] = 1;
            var_x[1] = 1; var_y[1] = 2;
            var_x[2] = -1; var_y[2] = 2;
            var_x[3] = -2; var_y[3] = 1;
            var_x[4] = -2; var_y[4] = -1;
            var_x[5] = -1; var_y[5] = -2;
            var_x[6] = 1; var_y[6] = -2;
            var_x[7] = 2; var_y[7] = -1;
        }

        protected bool is_legal(int x, int y)
        {
            if (x < 0 || x >= width)
                return false;
            if (y < 0 || y >= width)
                return false;
            if(chessboard[x,y]>0)
                return false;
            return true;
        }

        protected bool back_to_start()
        {
            if (1 == step)
                return true;
            else return false;
        }

        protected bool is_end()
        {
            if (step > width * width)
                return true;
            else return false;
        }

        protected void set_start(int x, int y)
        {
            curr_x = x;
            curr_y = y;
            step = 2;
            chessboard[x, y] = 1;
            direction[x, y] = CommData.MAX_DIR;
            last_direction = CommData.MAX_DIR;
        }

        protected bool select_direction()
        {
            int try_x, try_y;
            if (CommData.MAX_DIR == last_direction)
                last_direction = 0;
            else last_direction++;
            while (last_direction < CommData.MAX_DIR)
            {
                try_x = curr_x + var_x[last_direction];
                try_y = curr_y + var_y[last_direction];
                if (is_legal(try_x, try_y)) break;
                last_direction++;
            }
            if (CommData.MAX_DIR == last_direction) return false;
            else return true;
        }

        protected void backward()
        {
            step--;
            chessboard[curr_x, curr_y] = 0;
            last_direction = direction[curr_x, curr_y];
            curr_x -= var_x[last_direction];
            curr_y -= var_y[last_direction];
        }

        protected void forward()
        {
            curr_x += var_x[last_direction];
            curr_y += var_y[last_direction];
            chessboard[curr_x, curr_y] = step;
            step++;
            direction[curr_x, curr_y] = last_direction;
            last_direction = CommData.MAX_DIR;
        }

    }
    
    class Program
    {
        static void Main(string[] args)
        {
            Knight k_test = new Knight(8);
            k_test.tourist(0,0);
            //Console.WriteLine("Hello World!"+my[1,1].ToString());
            Console.ReadKey();
        }
    }
}
