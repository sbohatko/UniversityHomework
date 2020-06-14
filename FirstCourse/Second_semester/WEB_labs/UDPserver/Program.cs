using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ServerUDP
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.Unicode;
            Console.InputEncoding = System.Text.Encoding.Unicode;
            const string IP = "your ip";  //localhost
            const int port = 8081;

            IPEndPoint udpEndPoint = new IPEndPoint(IPAddress.Parse(IP), port);
            Socket udpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp); 

            udpSocket.Bind(udpEndPoint);

            while (true)
            {
                byte[] buf = new byte[256];
                int size = 0;
                string data;
                EndPoint senderEndPoint = new IPEndPoint(IPAddress.Any, 0); //адреса клієнта
                
                do
                {
                    size = udpSocket.ReceiveFrom(buf, ref senderEndPoint);
                    data = Encoding.UTF8.GetString(buf, 0, size);
                } while (udpSocket.Available > 0);
                if (data == "0")
                    continue;
                udpSocket.SendTo(Encoding.UTF8.GetBytes("Received successfully!"), senderEndPoint);
                Console.WriteLine(data);
            }
        }
    }
}
