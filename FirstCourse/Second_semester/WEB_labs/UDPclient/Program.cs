using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ClientUDP
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.Unicode;
            Console.InputEncoding = System.Text.Encoding.Unicode;
            const string IP = "your ip";  //localhost
            Random rnd = new Random();
            int port = rnd.Next(1001, 9999);

            IPEndPoint udpEndPoint = new IPEndPoint(IPAddress.Parse(IP), port);
            Socket udpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp); 
            udpSocket.Bind(udpEndPoint);

            while (true)
            {
                Console.Write("Enter message (0, to disconnect) -> ");
                string message = Console.ReadLine();
                EndPoint serverEndPoint = new IPEndPoint(IPAddress.Parse(IP), 8081);
                if (message == "0")
                {
                    udpSocket.SendTo(Encoding.UTF8.GetBytes(message), serverEndPoint);
                    break;
                }
                udpSocket.SendTo(Encoding.UTF8.GetBytes(message), serverEndPoint);

                byte[] buf = new byte[256];
                int size = 0;
                string data;

                do
                {
                    size = udpSocket.ReceiveFrom(buf, ref serverEndPoint);
                    data = Encoding.UTF8.GetString(buf, 0, size);
                } while (udpSocket.Available > 0);

                Console.WriteLine(data);
            }
            udpSocket.Shutdown(SocketShutdown.Both);
            udpSocket.Close();

            Console.WriteLine("You are connected");
            Console.ReadKey();
        }
    }
}
