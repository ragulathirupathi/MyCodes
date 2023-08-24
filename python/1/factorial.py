def factorial(num):
	if num == 1 :
		return 1;
	else:
		return num*factorial(num - 1)


if __name__ == '__main__':
	print("Factorial program executing")
	num = input("Enter the number\n")
	num = int(num)
	print(factorial(num))