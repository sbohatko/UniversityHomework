using Microsoft.Win32.SafeHandles;
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ServerTCP
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
            Socket tcpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp); //створення сокета
            tcpSocket.Bind(tcpEndPoint);
            tcpSocket.Listen(5);
            Socket listener;
            while (true)
            {
                listener = tcpSocket.Accept(); 
                Console.WriteLine("New connection");
                byte[] buf = new byte[256];
                int size = 0;
                string data;
                while (true)
                {
                    do
                    {
                        size = listener.Receive(buf);
                        data = Encoding.UTF8.GetString(buf, 0, size);
                    } while (listener.Available > 0);
                    if (data == "0")
                        break;
                    Console.WriteLine(data);

                    listener.Send(Encoding.UTF8.GetBytes("Message received successfully"));

                }
                listener.Shutdown(SocketShutdown.Both);
                Console.WriteLine("Client was disconnected.");
            }
        }
    }
}
