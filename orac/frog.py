import sys

stdin = sys.stdin
stdout = sys.stdout

inp = []

out = ""

for line in stdin.readlines():
	line = line.strip()
	print(line)
	if (line == "exit"):
		exit(0)
	inp.append([int(x) for x in line.split(" ")])
	out += line

out = str(out)

stdout.write(out)