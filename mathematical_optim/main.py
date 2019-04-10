import random
import networkx as nx
from model import Dijkstra
from utils import draw_graph, create_lists, check_answer

def create_graph():
    G = nx.DiGraph()
    G.add_weighted_edges_from([
        ('a', 'b', random.randint(10, 100)),
        ('a', 'c', random.randint(10, 100)),
        ('a', 'd', random.randint(10, 100)),
        ('b', 'd', random.randint(10, 100)),
        ('b', 'h', random.randint(10, 100)),
        ('c', 'e', random.randint(10, 100)),
        ('c', 'd', random.randint(10, 100)),
        ('d', 'e', random.randint(10, 100)),
        ('d', 'g', random.randint(10, 100)),
        ('d', 'f', random.randint(10, 100)),
        ('d', 'h', random.randint(10, 100)),
        ('e', 'g', random.randint(10, 100)),
        ('f', 'g', random.randint(10, 100)),
        ('h', 'f', random.randint(10, 100)),
        ('h', 'g', random.randint(10, 100))
        ])

    return G


def main():
    start = 'a'
    G = create_graph()
    verticies, edges, weights = create_lists(G)
    dijkstra_search = Dijkstra(verticies, edges, weights)
    paths, weighted_path = dijkstra_search.search_shortest_paths(start)
    weighted_path_ans = nx.single_source_dijkstra_path_length(G, start)
    check_answer(weighted_path, weighted_path_ans)

if __name__ == '__main__':
    random.seed(0)
    main()
