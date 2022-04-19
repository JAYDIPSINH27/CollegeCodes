import P6 
import socket,pickle

def server_program():
    # get the hostname
    host = socket.gethostname()
    port = 5000  # initiate port no above 1024

    server_socket = socket.socket()  # get instance
    # look closely. The bind() function takes tuple as argument
    server_socket.bind((host, port))  # bind host address and port together

    # configure how many client the server can listen simultaneously
    server_socket.listen(2)
    conn, address = server_socket.accept()  # accept new connection
    print("Connection from: " + str(address))

    # reckey=conn.recv(4096).decode()
    # key=pickle.loads(reckey)
    msg=conn.recv(1024).decode()
    print("Msg Recieved: ", msg,"\n\n")
    
    print("Sending Recieved Messege to verify \n\n")
    conn.send(msg.encode())

if __name__ == '__main__':
    server_program()