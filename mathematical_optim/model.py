import copy

class Dijkstra:
    def __init__(self, verticies, edges, weights):
        self.pasts = []
        self.futures = []
        self.paths = []
        self.verticies = verticies # Vertcies'
        self.edges = edges
        self.weights = weights

        self.inf = sum(weights)
        self.shortests = {
                'a': [self.inf, None], 'b': [self.inf, None], 'c': [self.inf, None],
                'd': [self.inf, None], 'e': [self.inf, None], 'f': [self.inf, None], 
                'g': [self.inf, None], 'h': [self.inf, None]
                }

    def search_shortest_paths(self, start):
        self.set_start(start)
        for count in range(len(self.verticies) ** 2):
            if sorted(list(set(self.pasts))) != self.verticies:
                subtract_set, edge_cands = self.update_state()
                # 2 if
                if edge_cands != []:
                    self.update_shortests(edge_cands)
                    self.find_new_path(subtract_set)
                # 2 else
                else:
                    F = []
            else:
                break

        return self.paths, self.shortests

    def set_start(self, start):
        self.pasts.append(start)
        self.futures.append(start)
        self.shortests[start][0] = 0

    # 2
    def update_state(self):
        subtract_set = copy.deepcopy(self.verticies)
        for p in self.pasts:
            if p in subtract_set:
                subtract_set.remove(p)
                
        edge_cands = []
        for f in self.futures:
            for v in subtract_set:
                if [f, v] in self.edges:
                    edge_cands.append([f , v])

        return subtract_set, edge_cands
        
    # 3
    def update_shortests(self, edge_cands):
        for src, tar in edge_cands:
            position = self.edges.index([src, tar])
            if self.shortests[tar][0] > self.shortests[src][0] + self.weights[position]:
                self.shortests[tar][0] = self.shortests[src][0] + self.weights[position]
                self.shortests[tar][1] = src
                        
    # 4
    def find_new_path(self, subtract_set):
        w_min = self.inf
        for v in subtract_set:
            w = self.shortests[v][0]
            if w != 0 and w < w_min:
                w_min = w
                new = v
            
        self.pasts.append(new)
        self.futures.append(new)
        self.paths.append((self.shortests[new][1], new))

