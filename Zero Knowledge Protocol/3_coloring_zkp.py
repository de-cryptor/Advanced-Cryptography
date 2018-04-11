'''
    @Author - Jatin Goel
	@Institute - IIIT Allahabad
	Hardwork definitely pays off. 
	There is no substitute of hardwork.
	There is no shortcut to success. 
'''

import itertools
import hashlib
import random


# Standard Graph 
N = 10 #Total Vertices
E = 15 #Total Edges

graph = [[1,2],[2,3],[3,4],[4,5],[5,1],[1,6],[2,7],[3,8],[4,9],[5,10],[6,8],[6,9],[7,9],[7,10],[8,10]]
print(graph)

colors = ['R','G','B']
print(colors)

vertex_colors = ['R','B','R','G','B','B','G','G','R','R']


permutations = list(itertools.permutations(colors))
print(permutations)
rounds = 2

for i in range (0,rounds):
    k = random.randint(0,5)
    print(k)
    per = permutations[k]
    commitments = []
    for edge in graph:
        u = edge[0]
        v = edge[1]
        cu = vertex_colors[u-1]
        cv = vertex_colors[v-1]
        if cu == 'R':
            cu = per[0]
        elif cu == 'G':
            cu = per[1]
        elif cu == 'B':
            cu = per[2]
        
        if cv == 'R':
            cv = per[0]
        elif cv == 'G':
            cv = per[1]
        elif cv == 'B':
            cv = per[2]

        commitment = str(u) + str(cu) + str(v) + str(cv)

        h = hashlib.sha256()
        h.update(commitment.encode())
        hex_hash = h.hexdigest()
        commitments.append(hex_hash)

        #print(commitment)
    print("Commitments Sent by Prover")
    print(commitments)
    print("verifier Ask for the Edge")
    e = random.randint(0,14)
    print(graph[e])
    u = graph[e][0]
    v = graph[e][1]
    cu = vertex_colors[u-1]
    cv = vertex_colors[v-1]
    if cu == 'R':
        cu = per[0]
    elif cu == 'G':
        cu = per[1]
    elif cu == 'B':
        cu = per[2]
    
    if cv == 'R':
        cv = per[0]
    elif cv == 'G':
        cv = per[1]
    elif cv == 'B':
        cv = per[2]
    print("Prover Open up the Colors")
    print(cu,cv)
    commitment = str(u) + str(cu) + str(v) + str(cv)
    h = hashlib.sha256()
    h.update(commitment.encode())
    hex_hash = h.hexdigest()
    print("Verifier Calculates the Commitment")
    print(hex_hash)

    

    



