using System;
using System.Collections;

namespace ConsoleApp2
{
    class Program
    {

        static void inserir(Queue q, int valor)
        {
            q.Enqueue(valor);
        }

        static void imprimir(Queue q)
        {
            foreach (var e in q)
            {
                Console.WriteLine(e);
            }
        }

        static void remover(Queue q)
        {
            q.Dequeue();
        }


        static void Main(string[] args)
        {
            Queue q = new Queue();

            //Inserindo três elementos
            inserir(q, 1);
            inserir(q, 2);
            inserir(q, 3);
            inserir(q, 4);
            inserir(q, 5);
            inserir(q, 6);

            Console.WriteLine("Mostra todos os elementos \n");
            imprimir(q);

            Console.WriteLine("Remove 1 \n");
            remover(q);
            imprimir(q);

            Console.WriteLine("Remove 2 \n");
            remover(q);
            imprimir(q);
            
        }
    }
}
