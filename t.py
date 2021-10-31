def simulate():
	global score_max, p, n, k, all_stack
	i_x = 0
	i_y = 0
	selected_count = 0
	score = 0
	while i_y < n:
		get_max_value(selected_count, score, i_x, i_y)
		i_y += 1

def get_max_value(selected_count, score, i_x, i_y):
	global score_max, p, n, k, all_stack
	score += all_stack[i_y][i_x]
	selected_count += 1

	if selected_count == p:
		if score_max < score:
			score_max = score
		return

	new_x = i_x
	new_y = i_y
	if i_x + 1 <  k:
		new_x+= 1
		get_max_value(selected_count, score, new_x, new_y)
	while new_y + 1 < n:
		new_y += 1
		new_x = 0
		get_max_value(selected_count, score, new_x, new_y)
	
	
	
	

		
t = int(input())
for i in range(1, t + 1):
	score_max = -1
	n, k, p = map(int, input().split())
	all_stack = []
	for _ in range(n):
		stack = list(map(int, input().split()))
		all_stack.append(stack)
	# get_max_value(0, 0, 0, 0)
	simulate()
	if score_max == -1:
		score_max = 0
	print('Case #{}: {}\n'.format(i, score_max))
