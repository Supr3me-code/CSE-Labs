with open("file1.txt","r") as file_in:

data_in = file_in.read()

data_out = data_in[::-1]

file_out = open("file2.txt","w")

file_out.write(data_out)

file_out.close()