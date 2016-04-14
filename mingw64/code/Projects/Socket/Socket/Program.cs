using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace Socket_server
{
    
    class Program
    {
        static void Main(string[] args)
        {
            int port = 2000;
            string host = "127.0.0.1";
            IPAddress ip = IPAddress.Parse(host);
            IPEndPoint ipe = new IPEndPoint(ip, port);
            Socket s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            s.Bind(ipe);
            s.Listen(0);//开始监听
            Console.WriteLine("等待客户端连接");
            Socket temp = s.Accept();
            Console.WriteLine("建立连接");
            while (true)
            {                
                string recvStr = "";
                byte[] recvBytes = new byte[1024];
                int bytes;
                bytes = temp.Receive(recvBytes, recvBytes.Length, 0);
                recvStr = Encoding.ASCII.GetString(recvBytes, 0, bytes);
                //给client端返回信息
                Console.WriteLine("server get message:{0}", recvStr);
                //string sendStr = "OK!Client send message successful!";
                //byte[] bs = Encoding.ASCII.GetBytes(sendStr);
                //temp.Send(bs, bs.Length, 0);
               // Console.ReadKey();
                
            }
            temp.Close();
            s.Close();
            Console.ReadKey();

        }
    }
}
