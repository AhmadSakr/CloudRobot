import time, socket
import RPi.GPIO as GPIO
import board
import serial
import busio
import adafruit_am2320
import re
import socket, sys
import threading
#sudo rfcomm bind rfcomm0 FC:A8:9A:00:6E:81
class CreateClientThread(threading.Thread):

    def init(self):
            threading.Thread.init(self)

    def run(self):
        try:            
            print("\nWelcome to Chat Room\n")
            print("Initialising....\n")
            time.sleep(1)

            s = socket.socket()
            host = "192.168.43.36"
            ip = socket.gethostbyname(host)
            port = 1235
            s.bind((host, port))
            print(host, "(", ip, ")\n")
            name = "Robot 1"
                       
            s.listen(5)
            print("\nWaiting for incoming connections...\n")
            conn, addr = s.accept()
            print("Received connection from ", addr[0], "(", addr[1], ")\n")

            s_name = conn.recv(1024)
            s_name = s_name.decode()
            print(s_name, "has connected to the chat room\nEnter [e] to exit chat room\n")
            conn.send(name.encode())

            while True:
                message = conn.recv(1024)
                message = message.decode()
                print(s_name, ":", message)
                
            

        except Exception as e:
            print(e)
            

ser = serial.Serial(
port='/dev/rfcomm0',
baudrate=115200,
parity=serial.PARITY_ODD,
stopbits=serial.STOPBITS_TWO,
bytesize=serial.SEVENBITS)
ser.isOpen()

GPIO.setmode(GPIO.BCM)
# create the I2C shared bus
i2c = busio.I2C(board.SCL, board.SDA)
am = adafruit_am2320.AM2320(i2c)
print("\nWelcome to Chat Room\n")
print("Initialising....\n")
time.sleep(1)
s = socket.socket()
host = "192.168.43.140"
ip = socket.gethostbyname(host)
port = 1234
print(host, "(", ip, ")\n")
name = "Robot1"
print("\nTrying to connect to ", host, "(", port, ")\n")
time.sleep(1)
s.connect((host, port))
print("Connected...\n")
s.send(name.encode())
s_name = s.recv(1024)
s_name = s_name.decode()
print(s_name, "has joined the chat room\nEnter [e] to exit chat room\n")

print('Enter your message below.\r\nInsert "exit" to leave the application.')
CreateClientThread().start()
while True:
        user_input = "t"
        ser.write(user_input.encode())
        recv = ''
        tic = time.time()
        while time.time() - tic < 15 and ser.inWaiting() == 0: 
                time.sleep(1)

        if ser.inWaiting() > 0:
               recv = ser.readline()
                    
        user_input = "g"
        ser.write(user_input.encode())
        recv2 = ''
        tic = time.time()
        while time.time() - tic < 15 and ser.inWaiting() == 0: 
            time.sleep(1)

        if ser.inWaiting() > 0:
           recv2 = ser.readline()
        if(recv!=''):
            print("Server Response >> " + str(recv, 'utf-8'))
            valueN = re.findall(r"-?\d+.\d+|-?\d+", str(recv))

        if(recv2!=''):
            print("Server Response >> " + str(recv2, 'utf-8'))
            valueN2 = re.findall(r"-?\d+.\d+|-?\d+", str(recv2))

        messagt ="1temp:"+str(am.temperature)
        s.send(messagt.encode())
        time.sleep(2)
        messageh ="1hum:"+str(am.relative_humidity)
        s.send(messageh.encode())
        time.sleep(2)
        messagt2 ="2temp:"+(valueN[0])
        s.send(messagt2.encode())
        messagg ="2gas:"+(valueN2[0])
        s.send(messagg.encode())
        time.sleep(2)