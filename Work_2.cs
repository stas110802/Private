using System;

namespace Ulearn
{
    class Program
    {
        static void Main(string[] args)
        {
            int size = 0;
            size =  Convert.ToInt32(Console.ReadLine());
            Arr a = new Arr(size);

            a.Print(size);
            
            a.InitArrive(size);
            
            a.Print(size);
        }
    }

    class Arr
    {
        public int[] mass;

        public Arr(int size)
        {
            mass = new int[size];
            for (int i = 0; i < size; i++)
            {
                mass[i] = 0;
            }
        }

        public void InitArrive(int size)
        {
            for (int i = 0; i < size; i++)
            {
                if(mass[i] == 0)
                {
                    Console.WriteLine("mass" +"[" + i + "]" + " = ");
                    mass[i] = Convert.ToInt32(Console.ReadLine());
                }
            }
            Console.WriteLine("");
        }

        public void Print(int size)
        {
            for (int i = 0; i < size; i++)
            {
                Console.WriteLine("mass" + "[" + i + "]" + " = " + mass[i]);
            }
            Console.WriteLine("");
        }
    }
}
