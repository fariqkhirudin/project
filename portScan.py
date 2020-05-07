

import socket



s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.settimeout(5)



host = input("Please enter the IP you want to scan: ")

port = 0





def portScanner(port):
	s.connect((host,port))
for x in range(9080,9096):
			if portScanner(x):
				print('Port', x, ': Open')
			else:
				print('')

portScanner(port)
