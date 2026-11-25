import sys

def solve():
    for line in sys.stdin:
        l,c,r1,r2 = map(int,line.split())
        
        if l==0 and c==0 and r1==0 and r2==0:
            break
            
        if 2*r1>l or 2*r1>c or 2*r2>l or 2*r2>c:
            print('N')
            continue

        dx = l-r2-r1
        dy = c-r2-r1
        
        dist_sq = dx*dx+dy*dy
        min_dist_sq = (r1+r2)**2
        
        if dist_sq>=min_dist_sq:
            print('S')
        else:
            print('N')

if __name__=="__main__":
    solve()