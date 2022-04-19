from matplotlib import pyplot as plt
from PIL import Image


I = Image.open("E:\\Sem 6\\DIP\\sample\\e6.png")
I1 = Image.open("E:\\Sem 6\\DIP\\sample\\e6.png")
K = I.load()

n, m = I.size

# returns true if the selected pixel is of yellow

def IsYellow(r, g, b):
    if(r > 200 and g > 174 and b < 128):
        return True
    return False

# returns true if the selected pixel is of blue

def IsBlue(r, g, b):
    if(r < 95 and g < 189 and b > 146):
        return True
    return False


for i in range(n):
    for j in range(m):
        r, g, b, a = K[i, j]

        if IsBlue(r, g, b):
            K[i, j] = (225, 255, 0, a)

        if IsYellow(r, g, b):
            K[i, j] = (0, 0, 255, a)

# I.show()
w = 10
h = 10
fig = plt.figure(figsize=(8, 8))

columns = 2
rows = 1
# for i in range(1, columns*rows +1):
# img = np.random.randint(10, size=(h,w))
fig.add_subplot(rows, columns, 1)
plt.imshow(I1)
plt.axis('off')
plt.title('Input Image')
fig.add_subplot(rows, columns, 2)
plt.imshow(I)
plt.axis('off')
plt.title('Output Image')

plt.show()
