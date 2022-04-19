import sys

def readFile(FileName):

    with open(FileName) as file:
        data = file.read()
    return data


def writeFile(FileName, text):

    with open(FileName,'w') as file:
        data = file.write(text)

def appendFile(FileName, text):

    with open(FileName,'a') as file:
        data = file.write(text)

def Encrypt(msg, key):
    result=""
    for i in range(len(msg)):
        ch = msg[i]
        if(ch >= 'a' and ch <= 'z'):
            ch = (ord(ch) - ord('a') + key) % 26 + ord('a')
            result += chr(ch)
        elif(ch >= 'A' and ch <= 'Z'):
            ch = (ord(ch) - ord('A') + key) % 26 + ord('A')
            result += chr(ch)

    return result


def Decrypt(msg, key):
    result=""
    for i in range(len(msg)):
        ch = msg[i]
        if(ch >= 'a' and ch <= 'z'):
            ch = (ord(ch) - ord('a') - key + 26) % 26 + ord('a')
            result += chr(ch)
        elif(ch >= 'A' and ch <= 'Z'):
            ch = (ord(ch) - ord('A') - key + 26) % 26 + ord('A')
            result += chr(ch)

    return result

def CryptAnalysis():
    PT=readFile("sample.txt")
    CT=readFile("encrypted.txt")

    for i in range(1,27):
        decrypted=Decrypt(CT,i)
        appendFile("BruteForce.txt",decrypted+"\t "+str(i)+"\n")
        if(decrypted==PT):
            print(f"Hacker will get message in {i} attempt")
            print(decrypted)
            break

def main():
    FileName = input("Enter File Name: ")
    msg = readFile(FileName)

    print("\nPlain Text is :", msg, end='\n')

    key = int(input("Enter the Key: "))

    print("\nEnter your choice \n0. Exit \n1. Encryption \n2. Decryption \n3. Crypt Analysis\n")
    choice = int(input("Enter your choice: "))

    if(choice == 1):
        encrypted = Encrypt(msg, key)
        print("\nEncrypted Message is: ", encrypted, end="\n")
        writeFile('encrypted.txt',encrypted)
    elif(choice == 2):
        msg = readFile("encrypted.txt")
        decrypted = Decrypt(msg, key)
        print("\nDecrypted Message is: ", decrypted, end="\n")
        writeFile('decrypted.txt',decrypted)
    elif(choice==3):
        CryptAnalysis()
    elif(choice==0):
        sys.exit()
    else:
        print("\nSelect Valid Option!")


if __name__ == '__main__':
    main()
