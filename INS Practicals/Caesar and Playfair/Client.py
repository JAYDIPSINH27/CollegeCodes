import socket
import Security_Ceasar as ceasar

def client_program():
    host = socket.gethostname()  # as both code is running on same pc
    port = 5000  # socket server port number

    client_socket = socket.socket()  # instantiate
    client_socket.connect((host, port))  # connect to the server
    key=-1
    key=int(client_socket.recv(1024).decode())
    if(key==-1):
        print("\nKey is not recieved!")
    else:
        print("\nKey is recieved!")
    # print("\n",key)

    FileName=input("\nEnter the file name which has Plain Text: ")
    data=ceasar.readFile(FileName)
    print(f"\n Your Plain Text from {FileName} is: {data} \n")
    encrypted=ceasar.Encrypt(data,key)
    ceasar.writeFile("encrypted.txt",encrypted)
    print("\nEncrypted Text is saved in encrypted.txt")

    client_socket.send(encrypted.encode())
    print("Encrypted Message has been sent!")
    # message = input(" -> ")  # take input

    # while message.lower().strip() != 'bye':
    #     client_socket.send(message.encode())  # send message
    #     data = client_socket.recv(1024).decode()  # receive response

    #     print('Received from server: ' + data)  # show in terminal

    #     message = input(" -> ")  # again take input
    reply=client_socket.recv(1024).decode()
    print(reply)
    client_socket.close()  # close the connection
    
    print("\nClient Off!\n")

if __name__ == '__main__':
    client_program()
