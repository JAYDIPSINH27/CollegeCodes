import hashlib
from cryptography.fernet import Fernet

def hash(msg: str):
    return hashlib.sha256(msg.encode('utf-8')).hexdigest()

def prepare_msg_string(msg: str):
    prepared_msg_to_encrypt = str(hash(msg))+ "," + str(msg)
    print("Prpared Msg To Encrypt: ", prepared_msg_to_encrypt, "\n")
    return prepared_msg_to_encrypt

def encrypt_msg(msg: str, key):
    return key.encrypt(bytes(msg, 'utf-8'))

def decrypt_msg(msg: str, key):
    return key.decrypt(msg)

def get_msg_to_be_sent(msg: str, encryption_key):
    hashed_msg = hash(msg)
    msg_string = prepare_msg_string(msg)
    encrypted_msg_string = encrypt_msg(msg_string, encryption_key)
    return encrypted_msg_string
    
def verify_msg(msg: str, key):
    msg = decrypt_msg(msg, key).decode()
    print("Decrypted Msg: ", msg)
    msg = msg.split(",")
    hash_of_original_msg = hashlib.sha256(msg[1].encode('utf-8')).hexdigest()
    if(msg[0] == hash_of_original_msg):
        print("Original Msg: ", msg[1])
        print("Msg Is Non-Compromised")
    else:
        print("Hash Varyfication Failed Msg Is Compromised")

def generate_key():
    key = Fernet.generate_key()
    key = Fernet(key)
    return key

def main():
    key=generate_key()
    print(key)
    print("Enter Msg To Be Sent : ")
    msg=input()

    print("Msg To Be Sent : ", msg)
    msg_sended = get_msg_to_be_sent(msg, key).decode()
    print("Msg Sended: ", msg_sended,"\n\n")

    msg_received = msg_sended
    print("Msg Recieved: ", msg_received, "\n\n")
    verify_msg(msg_received.encode(), key)

if __name__ == '__main__':
    main()