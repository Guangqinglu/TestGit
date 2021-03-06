﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace Socket_client
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                int port = 2000;
                string host = "127.0.0.1";
                ///创建终结点EndPoint
                IPAddress ip = IPAddress.Parse(host);
                //IPAddress ipp = new IPAddress("127.0.0.1");
                IPEndPoint ipe = new IPEndPoint(ip, port);
                ///创建socket并连接到服务器
                Socket c = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                Console.WriteLine("Conneting…");
                c.Connect(ipe);//连接到服务器

                ///向服务器发送信息
                string sendStr;
                byte[] bs;
                while (true)
                {
                    sendStr = Console.ReadLine();
                    bs = Encoding.ASCII.GetBytes(sendStr);//把字符串编码为字节
                    Console.WriteLine("Send Message");
                    c.Send(bs, bs.Length, 0);//发送信息
                    ///接受从服务器返回的信息
                    //string recvStr = "";
                    //byte[] recvBytes = new byte[1024];
                    //int bytes;
                    //bytes = c.Receive(recvBytes, recvBytes.Length, 0);//从服务器端接受返回信息
                    //recvStr += Encoding.ASCII.GetString(recvBytes, 0, bytes);
                }

                    
                   // Console.WriteLine("client get message:{0}", recvStr);//显示服务器返回信息
                    ///一定记着用完socket后要关闭
                    c.Close();                
 
            }
            catch (ArgumentNullException e)
            {
                Console.WriteLine("argumentNullException: {0}", e);
            }
            catch (SocketException e)
            {
                Console.WriteLine("SocketException:{0}", e);
            }
            Console.WriteLine("Press Enter to Exit");
            Console.ReadKey();
        }
    }
}
