# f_write = open("py_test1.txt", "w")
# f_write.write("hello world")
# f_write.close()

# with open("py_test1.txt", "w") as f:
#     f.write("hello world2")

f_read = open("py_test1.txt", "r")
txt = f_read.read()
print(txt)
f_read.close()
