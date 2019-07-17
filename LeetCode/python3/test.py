graph = [[1,2],[0],[0],[4],[3],[],[8],[],[6],[10,11],[9],[9],[14],[],[12],[16,17],[15],[15],[19,20],[18],[18],[22,23],[21],[21],[26],[],[24],[28,29],[27],[27]]
# graph = [[1], [0], [3], [2]]
num_of_node = len(graph)
A_set = set()
B_set = set()
temp_set = set()
D = set(str(i) for i in range(num_of_node))
print(D)


def devideSet(index):
    temp_set.clear()
    for num in graph[index]:
        temp_set.add(str(num))
    if temp_set:  # why only .update
        if not A_set:
            A_set.add(str(index))
            # B_set = B_set | temp_set
            B_set.update(temp_set)
        elif not A_set.isdisjoint(set([str(index)])):
            # B_set = B_set | temp_set
            B_set.update(temp_set)
        elif not B_set.isdisjoint(set([str(index)])):
            # A_set = A_set | temp_set
            A_set.update(temp_set)
        else:
            A_set.add(str(index))
            B_set.update(temp_set)
    else:
        return -1


while D:
    array = list(D)
    D.remove(array[0])
    devideSet(int(array[0]))
    temp_set.clear()

    while not (A_set | B_set).isdisjoint(D):
        array = list((A_set | B_set) & D)
        D.remove(array[0])
        devideSet(int(array[0]))
        if not A_set.isdisjoint(B_set):
            print('false')
            break


if A_set.isdisjoint(B_set):
    print('true')
