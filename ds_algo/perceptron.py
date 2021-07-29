import numpy as np

class Perceptron:
    def __init__(self, epochs, lr, no_of_inputs):
        self.epochs = epochs
        self.lr = lr
        self.no_of_inputs = no_of_inputs
        self.weights = np.random.randn(no_of_inputs,1) # (n+1)*1
        print(self.weights.shape)
    def predict(self, input_x):
        # print(input_x.shape)
        predict = np.dot(input_x,self.weights) #n*1 + 1*1
        predict = predict.sum()
        return 1 if predict > 0 else 0
    def train(self, training_x, training_y):
        no_of_train = len(training_x)
        for _ in range(self.epochs):
            for i in range(no_of_train):
                train_x = training_x[i]
                train_y = training_y[i]
                prediction = self.predict(train_x)
                train_x.shape = (len(train_x),1) # 3*1
                print(train_x[1:], train_y, prediction)
                self.weights = (self.lr*(train_y-prediction))*train_x #3,1
                # print(delta_W)


if __name__ == "__main__":
    training_x = np.array([[1,0,0],[1,0,1],[1,1,0],[1,1,1]]) # 4*3
    training_y = np.array([0,0,0,1])
    # training_y.shape = (len(training_y),1)
    perceptron = Perceptron(100, 0.1, 3)
    perceptron.train(training_x, training_y) 
    print(perceptron.weights)   
    for i in range(len(training_x)):
        print(perceptron.predict(training_x[i]))