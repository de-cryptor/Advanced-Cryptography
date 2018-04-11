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
N = 6 #Total Vertices
E = 10 #Total Edges

graph = [[1,2],[2,3],[3,4],[4,5],[5,1],[1,6],[2,6],[3,6],[4,6],[5,6]]
print(graph)

hamiltonian_cycle = [[1,2],[2,3],[3,4],[4,6],[6,5],[5,1]]

vertices = [1,2,3,4,5,6]
permutations = list(itertools.permutations(vertices))
#print(permutations)

rounds = 1
for r in range (0,rounds):
    print("Round : " + str(r+1))
    k = random.randint(0,100)
    print(vertices)
    per = permutations[k]
    print(per)
    iso_graph = []
    commitments = []
    for edge in graph:
        u = per[edge[0]-1]
        v = per[edge[1]-1]
        e = []
        commitment = str(u) + str(v)
        h = hashlib.sha256()
        h.update(commitment.encode())
        hex_hash = h.hexdigest()
        commitments.append(hex_hash)
        e.append(u)
        e.append(v)
        iso_graph.append(e)
    print(commitments)
    s = random.randint(0,1)
    print("Verifier Chooses random number :" + str(s))
    if s == 0:
        cycle = []
        for edge in hamiltonian_cycle:
            u = per[edge[0]-1]
            v = per[edge[1]-1]
            e = []
            e.append(u)
            e.append(v)
            cycle.append(e)
        print(cycle)
         
    else :
        iso_graph = []
        commitments=[]
        for edge in graph:
            u = per[edge[0]-1]
            v = per[edge[1]-1]
            e = []
            commitment = str(u) + str(v)
            h = hashlib.sha256()
            h.update(commitment.encode())
            hex_hash = h.hexdigest()
            commitments.append(hex_hash)
            e.append(u)
            e.append(v)
            iso_graph.append(e)
        print(iso_graph)
        print(commitments)
