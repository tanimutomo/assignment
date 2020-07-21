import random
import time

import spacy
import torch
import torch.nn as nn
import torch.optim as optim

import network
import data


SEED = 0
BATCH_SIZE = 64
N_EPOCHS = 5

WEIGHT_PATH = "./models/tut1-model.pth"
EMBEDDING_DIM = 100
HIDDEN_DIM = 256
OUTPUT_DIM = 1

torch.manual_seed(SEED)
torch.backends.cudnn.deterministic = True

def main():
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

    train_data, test_data = data.load_dataset()
    data.set_vocab(train_data)
    train_loader, test_loader = data.create_loader(
        train_data, test_data, BATCH_SIZE, device,
    )
    data.save_fields()

    input_dim = len(data.TEXT.vocab)
    model = network.RNN(input_dim, EMBEDDING_DIM, HIDDEN_DIM, OUTPUT_DIM)
    optimizer = optim.SGD(model.parameters(), lr=1e-3)
    criterion = nn.BCEWithLogitsLoss()

    model = model.to(device)
    criterion = criterion.to(device)

    print("Training model...")
    best_valid_loss = float('inf')
    for epoch in range(N_EPOCHS):
        st = time.time()
        train_loss, train_acc = train(model, train_loader, optimizer, criterion)
        valid_loss, valid_acc = evaluate(model, test_loader, criterion)
        
        et = time.time()
        epoch_mins, epoch_secs = epoch_time(st, et)
        
        if valid_loss < best_valid_loss:
            best_valid_loss = valid_loss
            torch.save(model.state_dict(), WEIGHT_PATH)
            
        print(f'Epoch: {epoch + 1:02} | Epoch Time: {epoch_mins}m {epoch_secs}s')
        print(f'\tTrain Loss: {train_loss:.3f} | Train Acc: {train_acc * 100:.2f}%')
        print(f'\tTest Loss: {valid_loss:.3f} | Test Acc: {valid_acc * 100:.2f}%')


def binary_accuracy(preds, y):
    # round predictions to the closest integer
    rounded_preds = torch.round(torch.sigmoid(preds))
    correct = (rounded_preds == y).float()
    acc = correct.sum() / len(correct)
    
    return acc


def train(model, iterator, optimizer, criterion):
    epoch_loss = 0
    epoch_acc = 0
    
    for batch in iterator:
        optimizer.zero_grad()
        predictions = model(batch.text).squeeze(1)
        loss = criterion(predictions, batch.label)
        acc = binary_accuracy(predictions, batch.label)
        loss.backward()
        optimizer.step()
        epoch_loss += loss.item()
        epoch_acc += acc.item()
        
    return epoch_loss /len(iterator), epoch_acc / len(iterator)


def evaluate(model, iterator, criterion):
    epoch_loss = 0
    epoch_acc = 0
    model.eval()
    
    with torch.no_grad():
        for batch in iterator:
            predictions = model(batch.text).squeeze(1)
            loss = criterion(predictions, batch.label)
            acc = binary_accuracy(predictions, batch.label)
            epoch_loss += loss.item()
            epoch_acc += acc.item()
    
    return epoch_loss / len(iterator), epoch_acc / len(iterator)


def epoch_time(st, et):
    elapsed = et - st
    elapsed_mins = int(elapsed / 60)
    elapsed_secs = int(elapsed - (elapsed_mins * 60))
    return elapsed_mins, elapsed_secs


if __name__ == "__main__":
    main()