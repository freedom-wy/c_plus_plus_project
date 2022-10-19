def swap(num1, num2):
    tmp = num1
    num1 = num2
    num2 = tmp
    print("交换后的num1和num2的值为: {}-{}".format(num1, num2))

def main():
    a = 1
    b = 2
    swap(a, b)
    print("交换后的a和b的值为: {}-{}".format(a, b))

main()