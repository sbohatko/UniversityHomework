using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ClientTCP
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.Unicode;
            Console.InputEncoding = System.Text.Encoding.Unicode;
            const string IP = "your ip";  //localhost
            const int port = 5780;

            IPEndPoint tcpEndPoint = new IPEndPoint(IPAddress.Parse(IP), port);
            Socket tcpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            tcpSocket.Connect(tcpEndPoint);
            while (true)
            {
                Console.Write("New connection (send 0, to disconnect) -> ");
                string message = Console.ReadLine();
                if (message == "0")
                {
                    tcpSocket.Send(Encoding.UTF8.GetBytes(message));
                    break;
                }
                byte[] data = Encoding.UTF8.GetBytes(message);

                tcpSocket.Send(data);

                byte[] buf = new byte[256];
                int size = 0;
                string answer;

                do
                {
                    size = tcpSocket.Receive(buf);
                    answer = Encoding.UTF8.GetString(buf, 0, size);
                } while (tcpSocket.Available > 0);

                Console.WriteLine(answer.ToString());
            }
            tcpSocket.Shutdown(SocketShutdown.Both);
            tcpSocket.Close();

            Console.ReadKey();
        }
    }
}
