import streamlit as st
import predict

"""
# Sentiment Analysis by Python
"""

"""
## Input
"""

text = st.text_input("text", "This is so good !")

pred = predict.do(text)

"""
## Prediction
"""

print(pred)
if pred < 0.5:
    "Negative"
else:
    "Positive"
