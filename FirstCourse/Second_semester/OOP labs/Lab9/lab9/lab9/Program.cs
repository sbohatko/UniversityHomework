using System;
using System.Collections.Generic;

namespace lab9
{
    abstract class Persona{
        public abstract string LastName { get; set; }
        public abstract string Name { get; set; }
        public abstract int Age { get; set; }
        public abstract int Income { get; set; }

        public void WriteInfo()
        {
            Console.WriteLine("Write name: ");
            string Name = Convert.ToString(Console.ReadLine());
            Console.WriteLine("Enter last name: ");
            string LastName = Convert.ToString(Console.ReadLine());
            Console.WriteLine("Enter age: ");
            int Age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter income: ");
            int Income = Convert.ToInt32(Console.ReadLine());
        }
        public void GetInfo()
        {
            Console.WriteLine($"Name: {Name} LastName: {LastName} Age: {Age} Income: {Income}");
        }

    }

        class Worker : Persona
        {
        private string name;

        public override int Income { get; set; }
        public override int Age { get; set; }
        public override string LastName { get; set; }

        public override string Name
        {
            get { return "Worker " + name; }
            set { name = value; }
        }

        public void WriteInfo()
        {
            Console.WriteLine("Write name: ");
            string Name = Convert.ToString(Console.ReadLine());
            Console.WriteLine("Enter last name: ");
            string LastName = Convert.ToString(Console.ReadLine());
            Console.WriteLine("Enter age: ");
            int Age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter income: ");
            int Income = Convert.ToInt32(Console.ReadLine());
        }
        public void GetInfo()
        {
            Console.WriteLine($"Name: {Name} LastName: {LastName} Age: {Age} Income: {Income}");
        }
        public void AvgIncome()
        {

        }
        public void AvgAge()
        {

        }

    }


            class Engineer : Worker
            {
            private string name;

            public override int Income { get; set; }
            public override int Age { get; set; }
            public override string LastName { get; set; }

            public override string Name
                {
                    get { return "Engineer " + name; }
                    set { name = value; }
                }

            public void WriteInfo()
            {
                Console.WriteLine("Write name: ");
                string Name = Convert.ToString(Console.ReadLine());
                Console.WriteLine("Enter last name: ");
                string LastName = Convert.ToString(Console.ReadLine());
                Console.WriteLine("Enter age: ");
                int Age = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter income: ");
                int Income = Convert.ToInt32(Console.ReadLine());
            }

            public void GetInfo()
                {
                    Console.WriteLine($"Name: {Name} LastName: {LastName} Age: {Age} Income: {Income}");
                }
            public void AvgIncome()
            {

            }
            public void AvgAge()
            {

            }

    }
    


    class MainClass
    {
        public static void Main(string[] args)
        {
            List < Persona>  personas = new List<Persona>();
            personas.Add(new Persona())
            personas.Add(new Worker());
            personas.Add(new Engineer());
            Console.WriteLine(personas);
            
        }

    }

}