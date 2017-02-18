init
	// get args, declare variables

	first:string = args[1]
	second:string = args[2]
	common:bool = false
	first_pos:int = 0
	second_pos:int = 0

	first_length:long = first.length - 1
	second_length:long = second.length - 1

	var first_list = new array of char[first_length]
	var second_list = new array of char[second_length]

	for var i = 0 to first_length
		first_list[i] = (first[i])

	for var i = 0 to second_length
		second_list[i] = (second[i])

	// compare the words (gets the very first instance of the same char)

	for var i = 0 to first_length
		if common
			break
		second_pos = 0
		first_pos++

		for var j = 0 to second_length
			second_pos++
			if first_list[i] == second_list[j]
				common = true
				break

	// print values
	if common
		var first_final = (string)first_list
		var second_final = (string)second_list

		print first_final.substring(0, first_pos) + second_final.substring(second_pos) + "-" + second_final.substring(0, second_pos) + first_final.substring(first_pos)
	else
		print first + "-" + second