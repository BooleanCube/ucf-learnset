tc = 1

while 1:
    a,b = input(), input()
    if a=="END" and b=="END": break
    print(f"Case {tc}:", "same" if sorted(a) == sorted(b) else "different")
    tc += 1
