import os
import dill

import torch
from torchtext import data, datasets


MAX_VOCAB_SIZE = 25_000

TEXT = data.Field(tokenize="spacy")
LABEL = data.LabelField(dtype=torch.float)


def set_vocab(train_data):
    TEXT.build_vocab(train_data, max_size=MAX_VOCAB_SIZE)
    # TEXT.build_vocab(
    #     train_data, 
    #     max_size = MAX_VOCAB_SIZE, 
    #     vectors = "glove.6B.100d", 
    #     unk_init = torch.Tensor.normal_,
    # )
    LABEL.build_vocab(train_data)


def load_dataset():
    train_data, test_data = datasets.IMDB.splits(TEXT, LABEL)
    print(f'Number of training examples: {len(train_data)}')
    print(f'Number of testing examples: {len(test_data)}')
    return train_data, test_data


def create_loader(train_data, test_data, batch_size, device):
    return data.BucketIterator.splits(
        (train_data, test_data), 
        batch_size=batch_size,
        sort_within_batch=True,
        device=device,
    )


def load_fields():
    if os.path.exists("models/fields/text.field"):
        with open("./models/fields/text.field", "rb") as f:
            TEXT = dill.load(f)
    else:
        return False

    if os.path.exists("models/fields/label.field"):
        with open("./models/fields/label.field", "rb") as f:
            LABEL = dill.load(f)
    else:
        return False

    return True
    

def save_fields():
    with open("./models/fields/text.field", "wb") as f:
        dill.dump(TEXT, f)

    with open("./models/fields/label.field", "wb") as f:
        dill.dump(LABEL, f)
    