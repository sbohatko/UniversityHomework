using  System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
namespace L10
{
    class Variant
    {
       
        public List<int> level1 = new List<int>();
        public List<int> level2 = new List<int>();
        public List<int> level3 = new List<int>();
        Random rand = new Random();

        public Variant(int lev1, int lev2, int lev3)
        {
            for (int i = 0; i < 8; i++)
            {
                int temp = rand.Next(1, lev1 + 1);
                while (level1.Count(c => c == temp) > 0)
                    temp = rand.Next(1, lev1 + 1);
                level1.Add(temp);
            }
            for (int i = 0; i < 8; i++)
            {
                int temp = rand.Next(lev1, lev1 + lev2 + 1);
                while (level2.Count(c => c == temp) > 0)
                    temp = rand.Next(lev1, lev1 + lev2 + 1);
                level2.Add(temp);
            }
            for (int i = 0; i < 4; i++)
            {
                int temp = rand.Next(lev1 + lev2, lev1 + lev2 + lev3 + 1);
                while (level3.Count(c => c == temp) > 0)
                    temp = rand.Next(lev1 + lev2, lev1 + lev2 + lev3 + 1);
                level3.Add(temp);
            }
        }
    }
    class Discipline
    {
        public int NumberVars { get; set; }
        List<Variant> variant = new List<Variant>();
        public string NameT { get; set; }
        public string NameD { get; set; }
        public string Date { get; set; }
        public int Level1 { get; set; }
        public int Level2 { get; set; }
        public int Level3 { get; set; }
        StreamWriter file = new StreamWriter("variants.txt");

        public Discipline(string nd, string tn, string date, int nvar, int lev1, int lev2, int lev3)
        {
            this.NumberVars = nvar;
            this.NameT = tn;
            this.NameD = nd;
            this.Date = date;
            this.Level1 = lev1;
            this.Level2 = lev2;
            this.Level3 = lev3;
        }

        public void FillVariants()
        {
            for(int i = 0; i < NumberVars; ++i)
                variant.Add(new Variant(Level1, Level2, Level3 ));
        }

        public void PrintConsole()
        {
            for (int i = 0; i < NumberVars; ++i)
            {
                Console.WriteLine("Discipline: " + this.NameD);
                Console.WriteLine("Teacher: " + this.NameT);
                Console.WriteLine("Date: " + this.Date);
                Console.WriteLine("Variant: " + (i + 1).ToString());
                Console.Write("Level 1: ");
                for (int j = 0; j < 8; j++)
                {
                    if (j == 7)
                    {
                        Console.WriteLine(variant[i].level1[j].ToString());
                    }
                    else
                    Console.Write(variant[i].level1[j].ToString() + ", ");
                }
                Console.Write("Level 2: ");
                for (int j = 0; j < 8; j++)
                {
                    if (j == 7)
                    {
                        Console.WriteLine(variant[i].level2[j].ToString());
                    }
                    else
                    Console.Write(variant[i].level2[j].ToString() + ", ");
                }
                Console.Write("Level 3: ");
                for (int j = 0; j < 4; j++)
                {
                    if (j == 3)
                    {
                        Console.WriteLine(variant[i].level3[j].ToString());
                    }
                    else
                    Console.Write(variant[i].level3[j].ToString() + ", ");
                }
                Console.WriteLine("-------------------------------------------------------------------------------------------------");
            }
        }
        public void PrintFile()
        {
            for (int i = 0; i < NumberVars; ++i)
            {
                file.WriteLine("Discipline: " + this.NameD);
                file.WriteLine("Teacher: " + this.NameT);
                file.WriteLine("Date: " + this.Date);
                file.WriteLine("Variant: " + (i + 1).ToString());
                file.Write("Level 1: ");
                for (int j = 0; j < 8; j++)
                {
                    if (j == 7)
                    {
                        file.WriteLine(variant[i].level1[j].ToString());
                    }
                    else
                        file.Write(variant[i].level1[j].ToString() + ", ");
                }
                file.Write("Level 2: ");
                for (int j = 0; j < 8; j++)
                {
                    if (j == 7)
                    {
                        file.WriteLine(variant[i].level2[j].ToString());
                    }
                    else
                        file.Write(variant[i].level2[j].ToString() + ", ");
                }
                file.Write("Level 3: ");
                for (int j = 0; j < 4; j++)
                {
                    if (j == 3)
                    {
                        file.WriteLine(variant[i].level3[j].ToString());
                    }
                    else
                        file.Write(variant[i].level3[j].ToString() + ", ");
                }
                file.WriteLine("-------------------------------------------------------------------------------------------------");
            }
            file.Close();
        }
    } 
    internal class Program
    {
        /*
         * NameDisc
         * Teacher
         * Number of var
         * max min for levels
         * 
         */
        public static void Main(string[] args)
        {
            int lev1 = 50, lev2 = 50, lev3 = 30;
            Console.Write("Enter name of Discipline: ");
            string disc = Console.ReadLine();
            Console.Write("Enter name of Teacher: ");
            string tn = Console.ReadLine();
            Console.Write("Enter Date of test: ");
            string date = Console.ReadLine();
            Console.Write("Enter number of variants: "); 
            int nvar = Int32.Parse(Console.ReadLine());
            while (lev1 > 40 || lev1 < 10)
            {
                Console.Write("Enter number of tasks for level 1(40 or less to 10): ");
                lev1 = Int32.Parse(Console.ReadLine());
            }
            while (lev2 > 40 || lev2 < 10)
            {
                Console.Write("Enter number of tasks for level 2(40 or less to 10): ");
                lev2 = Int32.Parse(Console.ReadLine());
            }
            while (lev3 > 20 || lev3 < 5)
            {
                Console.Write("Enter number of tasks for level 3(20 or less to 5): ");
                lev3 = Int32.Parse(Console.ReadLine());
            }
            Discipline d = new Discipline(disc, tn, date, nvar, lev1, lev2, lev3);
            d.FillVariants();
            d.PrintConsole();
            d.PrintFile();
           

        }
    }
}