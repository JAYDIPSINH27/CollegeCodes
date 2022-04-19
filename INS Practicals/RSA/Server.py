import socket
import random
import Security_RSA as rsa

# def Key_Gen():
#     return random.randint(1,26)

def private_keyGen(e,phi):
    d=rsa.modInverse(e,phi)
    return d

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


    p=int(rsa.readFile('p.txt'))
    q=int(rsa.readFile('q.txt'))
    print("P: ",p)
    print("Q: ",q)

    n=p*q
    phi=(p-1)*(q-1)

    public_key=int(conn.recv(1024).decode())
    print("Public Key is: ",public_key)

    private_key=private_keyGen(public_key,phi)
    print("Generated Private Key is: ",private_key)

    private_key1=str(private_key) + " "+ str(n)  
    rsa.writeFile('private_key.txt',private_key1)

    # message=int(conn.recv(1024).decode())
    data = int(conn.recv(1024).decode())
    print(f"\nEncrypted Data recieved: {data}\n")
    decrypted=rsa.Decrypt(data,private_key,n)
    print(f"\nEncrypted Data has been Decrypted: {decrypted}\n ")
    

    rsa.writeFile("decrypted.txt",str(decrypted))
    print("\nDecrypted Text is saved in decrypted.txt")

    response="Message has been Recieved"
    conn.send(response.encode())
    conn.close()  # close the connection
    print("Server Ended")
if __name__ == '__main__':
    server_program()