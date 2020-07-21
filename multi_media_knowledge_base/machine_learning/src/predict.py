import sys

import spacy
import torch

import data
import network

WEIGHT_PATH = "./models/tut2-model.pth"
EMBEDDING_DIM = 100
HIDDEN_DIM = 256
OUTPUT_DIM = 1

device = torch.device("cpu")
data.set_vocab(data.load_dataset()[0])
model = network.RNN(
    len(data.TEXT.vocab),
    EMBEDDING_DIM,
    HIDDEN_DIM,
    OUTPUT_DIM,
)
model.eval()
model = model.to(device)

def _preprocess(sentence):
    tokenized = [tok.text for tok in spacy.load("en").tokenizer(sentence)]
    indexed = [data.TEXT.vocab.stoi[t] for t in tokenized]
    length = [len(indexed)]
    tensor = torch.LongTensor(indexed).to(device)
    tensor = tensor.unsqueeze(1)
    return tensor

def do(sentence):
    tensor = _preprocess(sentence)
    prediction = torch.sigmoid(model(tensor))
    return prediction.item()
