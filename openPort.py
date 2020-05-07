import socket

host = '192.168.40.135'                                                                                                                            
port = int(input('Enter the port: '))                   

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  
s.bind((host, port))                                                    
s.listen(5)   
