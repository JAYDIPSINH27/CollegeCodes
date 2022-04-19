import socket
import random
import Security_Ceasar as ceasar

def Key_Gen():
    return random.randint(1,26)


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

    key=Key_Gen()
    conn.send(str(key).encode())
    print("\nKey has been generated and sent!")

    ceasar.writeFile("key.txt",str(key))
    # while True:
    #     # receive data stream. it won't accept data packet greater than 1024 bytes
    #     conn.send(str(key).encode())
    #     data = conn.recv(1024).decode()
    #     if not data:
    #         # if data is not received break
    #         break
    #     print("from connected user: " + str(data))
    #     data = input(' -> ')
    #     conn.send(data.encode())  # send data to the client

    data = conn.recv(1024).decode()
    print(f"\nEncrypted Data recieved: {data}\n")
    decrypted=ceasar.Decrypt(data,key)
    print(f"\nEncrypted Data has been Decrypted: {decrypted}\n ")
    

    ceasar.writeFile("decrypted.txt",decrypted)
    print("\nDecrypted Text is saved in decrypted.txt")

    response="Message has been Recieved"
    conn.send(response.encode())
    conn.close()  # close the connection
    print("Server Ended")
if __name__ == '__main__':
    server_program()