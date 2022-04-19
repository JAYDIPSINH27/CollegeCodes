import sys


def readFile(FileName):

    with open(FileName) as file:
        data = file.read()
    return data


def writeFile(FileName, text):

    with open(FileName, 'w') as file:
        data = file.write(text)


def appendFile(FileName, text):

    with open(FileName, 'a') as file:
        data = file.write(text)


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def isPrime(a):
    i = 2
    k = int(a ** 0.5)

    while(i <= k):
        if(a % i == 0):
            return 0
        i += 1
    return 1


def modInverse(a, m):
    m0 = m
    y = 0
    x = 1

    if (m == 1):
        return 0

    while (a > 1):

        # q is quotient
        q = a // m

        t = m

        # m is remainder now, process
        # same as Euclid's algo
        m = a % m
        a = t
        t = y

        # Update x and y
        y = x - q * y
        x = t

    # Make x positive
    if (x < 0):
        x = x + m0

    return x


def Encrypt(msg, key , n):
    result= pow(msg,key) % n
    return result


def Decrypt(msg, key , n):
    result= pow(msg,key) % n
    return result


def CryptAnalysis():
    PT = readFile("sample.txt")
    CT = readFile("encrypted.txt")

    for i in range(1, 27):
        decrypted = Decrypt(CT, i)
        appendFile("BruteForce.txt", decrypted+"\t "+str(i)+"\n")
        if(decrypted == PT):
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
        writeFile('encrypted.txt', encrypted)
    elif(choice == 2):
        msg = readFile("encrypted.txt")
        decrypted = Decrypt(msg, key)
        print("\nDecrypted Message is: ", decrypted, end="\n")
        writeFile('decrypted.txt', decrypted)
    elif(choice == 3):
        CryptAnalysis()
    elif(choice == 0):
        sys.exit()
    else:
        print("\nSelect Valid Option!")


if __name__ == '__main__':
    main()
