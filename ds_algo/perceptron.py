import numpy as np

class Perceptron:
    def __init__(self, epochs, lr, no_of_inputs):
        self.epochs = epochs
        self.lr = lr
        self.no_of_inputs = no_of_inputs
        self.weights = np.random.randn(no_of_inputs+1,1) # (n+1)*1
        print(self.weights.shape)
    def predict(self, input_x):
        # print(input_x.shape)
        predictions = np.dot(input_x,self.weights[1:]) + self.weights[0] #n*1 + 1*1
        return 1 if predictions > 0 else 0
    def train(self, training_x, training_y):
        no_of_train = len(training_x)
        for _ in range(self.epochs):
            for i in range(no_of_train):
                train_x = training_x[i].reshape(1,2)
                train_y = training_y[i]
                prediction = self.predict(train_x)
                print(train_x, train_y, prediction)
                self.weights[1:] += self.lr*(train_y-prediction)*np.transpose(train_x)
                self.weights[0] = self.lr*(train_y-prediction)



if __name__ == "__main__":
    training_x = np.array([[0,0],[0,1],[1,0],[1,1]]).reshape(4,2)
    training_y = np.array([0,0,0,1])
    perceptron = Perceptron(10, 0.00001, 2)
    perceptron.train(training_x, training_y) 
    print(perceptron.weights)   