#   Created by Elshad Karimov
#   Copyright © AppMillers. All rights reserved.

# Build Order

# projects a,b,c,d,e,f
# dependencies: (a,d), (f,b), (b,d), (f,a), (d,c)

def createGraph(projects, dependencies):
    projectGraph = {}
    for project in projects:
        projectGraph[project] = []
    for pairs in dependencies:
        projectGraph[pairs[0]].extend(pairs[1])
    return projectGraph


project = ['a', 'b', 'c', 'd', 'e', 'f']
dependencies = [('a', 'd'), ('f', 'b'), ('b', 'd'), ('f', 'a'), ('d', 'c')]


def findBuildOrder(projects, dependencies):
    data = createGraph(project, dependencies)
    bo = []
    for i in data.keys():
        data[i]


print(findBuildOrder(project, dependencies))
