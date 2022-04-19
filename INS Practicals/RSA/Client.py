import socket
import Security_RSA as rsa
import random

def public_keyGen(phi,p,q):
    while True:
        e=random.randrange(2,phi-1,1)
        #and (e != p and e!= q)
        if(rsa.gcd(phi,e) == 1 and rsa.isPrime(e)):
            return e
    


def client_program():
    host = socket.gethostname()  # as both code is running on same pc
    port = 5000  # socket server port number

    client_socket = socket.socket()  # instantiate
    client_socket.connect((host, port))  # connect to the server


    p=int(rsa.readFile('p.txt'))
    q=int(rsa.readFile('q.txt'))
    print("P: ",p)
    print("Q: ",q)

    n=p*q
    phi=(p-1)*(q-1)

    e=public_keyGen(phi,p,q)
    public_key=str(e) + " "+ str(n)  
    rsa.writeFile('public_key.txt',public_key)
    # e=7
    # d=3
    print("Generated E: ",e)

    public_key=e
    client_socket.send(str(public_key).encode())


    FileName=input("\nEnter the file name which has Plain Text: ")
    data=int(rsa.readFile(FileName))
    print(f"\n Your Plain Text from {FileName} is: {data} \n")
    encrypted=rsa.Encrypt(data,public_key,n)
    rsa.writeFile("encrypted.txt",str(encrypted))
    print("\nEncrypted Text is saved in encrypted.txt")

    client_socket.send(str(encrypted).encode())
    print("Encrypted Message has been sent!")
    reply=client_socket.recv(1024).decode()
    print(reply)
    client_socket.close()  # close the connection
    
    print("\nClient Off!\n")

if __name__ == '__main__':
    client_program()
