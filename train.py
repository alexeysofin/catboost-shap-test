from catboost import CatBoostClassifier, Pool


data = [
    [5.1, 1.2],
    [4.9, 1.5],
    [6.2, 1.4],
    [5.9, 1.0]
]
labels = [0, 1, 0, 1]

# Create Pool object
train_pool = Pool(data, label=labels)

# Initialize and train model
model = CatBoostClassifier(iterations=10, learning_rate=0.1, verbose=0)
model.fit(train_pool)

model.save_model("model.cbm")
