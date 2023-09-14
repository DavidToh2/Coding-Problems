def solution(entrances, exits, path):
    # This looks like a greedy algorithm question.
    # We'll first generate all the paths from the rooms to the escape
    # pods. This lets us look at the subgraph of paths that actually
    # work; we can ignore cycles (I don't have a rigorous math explanation
    # as to why.) After that, we'll just greedy the whole thing, using a
    # weights system to order each room.
    if len(entrances) == 0 or len(exits) == 0:
        return 0
    rooms = len(path)
    # To make things easier, we'll make a list of inputs and outputs
    # for each room.
    inlet = []
    outlet = []
    for i in range(0, rooms, 1):
        inlet_i = []
        outlet_i = []
        for j in range(0, rooms, 1):
            if path[i][j] != 0:
                outlet_i.append(j)
            if path[j][i] != 0:
                inlet_i.append(j)
        inlet.append(inlet_i)
        outlet.append(outlet_i)
    
    # Generating the subgraph. The kth element of the subgraph is a list
    # of rooms to which room k is connected.
    # To do this, we need to first find all the paths to the escape pods.
    # We'll store the list of paths in a list.
    paths = [[]]
    answer = 0
    for i in entrances:
        paths[0].append([i])
    for j in range(1, rooms, 1):
        paths.append([])
        for partial_path in paths[j-1]:
            last_element = partial_path[-1]
            if last_element in exits:
                paths[j].append(partial_path)
            else:
                for t in outlet[last_element]:
                    if t not in partial_path:
                        partial_added = partial_path + [t]
                        paths[j].append(partial_added)
    
    for final_path in paths[-1]:
        minimum = 2000000
        for i in range(0, len(final_path)-1, 1):
            pathFit = path[final_path[i]][final_path[i+1]] 
            if pathFit < minimum:
                minimum = pathFit
        answer += minimum
        for i in range(0, len(final_path)-1, 1):
            path[final_path[i]][final_path[i+1]] -= minimum
            
    return answer

print(solution([0, 1], [5,6], [[0, 0, 5, 8, 6, 0, 0], [0, 0, 7, 0, 4, 0, 0], [0, 0, 0, 9, 0, 9, 4], [0, 0, 0, 0, 8, 3, 10], [0, 0, 11, 0, 0, 0, 11], [0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0]]))