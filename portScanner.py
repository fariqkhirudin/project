import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.settimeout(5)

server = '192.168.40.135'


def pscan(port):
	if s.connect((server, port)):
		return True
	else:
		return False

pscan(port)

for x in range (1,9092):
	if pscan(x):
		print('Port', x, ': Open')
	else:
		print('Port', x, ': Close')	

