from copyreg import pickle
import P6
import socket,pickle

def client_program():
    host = socket.gethostname()  # as both code is running on same pc
    port = 5000  # socket server port number

    client_socket = socket.socket()  # instantiate
    client_socket.connect((host, port))  # connect to the server

    key=P6.generate_key()
    # sendkey=pickle.dump(key)
    # client_socket.send(sendkey.encode())
    print("Enter Msg To Be Sent : ")
    msg=input()

    print("Msg To Be Sent : ", msg)
    msg_sended = P6.get_msg_to_be_sent(msg, key).decode()
    print("Msg Sended: ", msg_sended,"\n\n")
    client_socket.send(msg_sended.encode())
    print("\n\n")
    msg_verify=client_socket.recv(1024).decode()
    P6.verify_msg(msg_verify.encode(), key)

if __name__ == '__main__':
    client_program()
