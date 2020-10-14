def pigeonhole_sort(a):  
	my_min = min(a) 
	my_max = max(a) 
	size = my_max - my_min + 1

	holes = [0] * size 

	for x in a: 
		assert type(x) is int, "integers only please"
		holes[x - my_min] += 1
	i = 0
	for count in range(size): 
		while holes[count] > 0: 
			holes[count] -= 1
			a[i] = count + my_min 
			i += 1
a = [9, 5, 1, 7, 4, 8, 9] 
print("Sorted order is : ", end = ' ') 

pigeonhole_sort(a) 
		
for i in range(0, len(a)): 
	print(a[i], end = ' ') 
	
# OUTPUT: Sorted order is : 1 5 4 7 8 9 9 
