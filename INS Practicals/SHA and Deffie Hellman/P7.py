import hashlib

# prime no
q = 23
# p is primitive root of q, p < q
p = 9

private_key_alice = 4
public_key_alice = int(pow(p,private_key_alice,q))

private_key_bob = 3
public_key_bob = int(pow(p,private_key_bob,q))

print("--------------------Deffie Hellman Data--------------------")
print("Prime No q            | ", q)
print("Premitive Root Of Q, p| ", p)
print("Private Key Of Alice  | ", private_key_alice)
print("Public Key Of Alice   | ", public_key_alice)
print("Private Key Of Bob    | ", private_key_bob)
print("Public Key Of Bob     | ", public_key_bob, "\n")
print("------------------Deffie Hellman Data End------------------\n\n")


secret_key_alice = int(pow(public_key_bob, private_key_alice,q))
original_msg = "hello world"
prpared_msg_to_hash = str(original_msg) + "," + str(secret_key_alice)
hashed_msg = hashlib.sha256(prpared_msg_to_hash.encode("utf-8")).hexdigest()
msg_to_send = str(original_msg) +","+ hashed_msg

print("----------------Alice Is Preparing To Send------------------")
print("Secret Key For Alice | ", secret_key_alice)
print("Original Msg         | ", original_msg)
print("Prepared Msg To Hash | ", prpared_msg_to_hash)
print("Hashed Msg           | ", hashed_msg)
print("Msg To Send          | ", msg_to_send)
print("-------------------Alice Sended The Msg---------------------\n\n")

msg_recieved = msg_to_send
msg_recieved = msg_recieved.split(",")
secret_key_bob = int(pow(public_key_alice, private_key_bob,q))
msg_recieved_with_s = msg_recieved[0] + "," +str(secret_key_bob)
hashed_recieved_msg = hashlib.sha256(msg_recieved_with_s.encode("utf-8")).hexdigest()

print("---------------------Bob Recieved Msg-----------------------")
print("Secret Key For Bob   | ", secret_key_bob)
print("Msg Recieved         | ", msg_to_send)
print("Original Msg         | ", msg_recieved[0])
print("Msg Bob's Secret Key | ", msg_recieved_with_s)
print("Hash Of Recieved Msg | ", hashed_recieved_msg)
print("------------------------------------------------------------\n\n")

print("-----------Validating Hashed Msg With Recieved Hash-----------")
if(hashed_recieved_msg == msg_recieved[1]):
    print("Msg Is Non Compromized")
else:
    print("Msg Is Compromized")

