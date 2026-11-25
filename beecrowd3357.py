import math

N_L_Q = input().split()
N = int(N_L_Q[0])
L = float(N_L_Q[1])
Q = float(N_L_Q[2])

names = input().split()

total_gourds = math.ceil(L/Q)

rich_index = (total_gourds-1)%N

remaining = L%Q
if remaining==0:
    remaining = Q

print(f"{names[rich_index]} {remaining:.1f}")
