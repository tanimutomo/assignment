import copy
import networkx as nx

def draw_graph(G):
    pos = nx.spring_layout(G, k=0.8)
    edge_labels = {(i, j): w['weight'] for i, j, w in G.edges(data=True)}
    nx.draw_networkx_edge_labels(G,pos, edge_labels=edge_labels)
    nx.draw_networkx(G, pos=pos, with_labels=True, 
            font_weight='bold', node_color='c')


def create_lists(G):
    sources = []
    targets = []
    weights = []
    edges = []

    for a, b, c in nx.to_edgelist(G):
        sources.append(a)
        targets.append(b)
        weights.append(c['weight'])
        edges.append([a, b])
        
    verticies = copy.deepcopy(sources)
    verticies.extend(targets)
    verticies = list(set(verticies))
    verticies = sorted(verticies)

    return verticies, edges, weights

def check_answer(pred, gt):
    pred_aligned = {}
    for vertex, values in pred.items():
        length, _ = values
        pred_aligned[vertex] = length

    print("--- My Difined Model Prediction ---")
    print(pred_aligned)
    print('')
    print("--- NetworkX Model Prediction ---")
    print(gt)

    print('')
    if sorted(pred_aligned.items()) == sorted(gt.items()):
        print('Both answers are equal!')

    else:
        print('Both answers are NOT equal!')

