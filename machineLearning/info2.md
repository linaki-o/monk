# Machine learning diagnostic

when u test u hypothesis on a new set of houses, you find that it makes unacceptably large errors in its predictions. What should you try next?
- Get more training examples
- try smaller sets of features
- try getting additional features
- try adding polynomial features
- try decreasing lambda 
- try increasing lambda

> Evaluating a hypothesis

<img src="img/eyh.png">

split a dataset into two part, training set and test set

<img src="img/tp.png">

> Model selection and training/validation/test sets

decide degree of polynomial, features, regularization parameter lambda

<img src="img/ms.png">

<img src="img/ms2.png">

> Diagnosing bias vs. variance

<img src="img/bvsv.png">

> Regularization and bias/variance

<img src="img/ctrp.png">
<img src="img/ctrp2.png">

<img src="img/bvsv2.png">

> Learning curves

<img src="img/hb.png">

<img src="img/hv.png">

> Deciding what to try next
<img src="img/dwttn.png">

choose neural networks' architecture
- small neural network
    - fewer params, more prone to underfitting
    - computationally cheaper
- large neural network
    - more params, more prone to overfitting
    - use regularization to address overfitting 
    - use train set, validation set and test set to decide the hidden layer number
    - computationally more expensive

> Prioritizing what to work on: Spam classification example

<img src="img/basc.png">

> Error analysis

<img src="img/ra.png">

<img src="img/ea.png">
<img src="img/tione.png">

> Error metrics for skewed classes

skewed classes: have a lot more of examples from one class than from the other class. classification error or classification accuracy as evaluation metric might not that good.

------
y = 1 in presence of rare class that we want to detect

**precision**: 

**recall**:

<img src="img/pr2.png">


-------
<img src="img/nn020.png">

improve threshold, higher precision, lower recall

<img src="img/nn021.png">

reduce threshold, higher recall, lower recall

<img src="img/nn022.png">

> How to compare precision/recall numbers

<img src="img/f1.png">

> Data for machine learning

**Large data rationale**: high variance is unlikely to overfit

many parameters and many datas

# Support Vector Machine

<img src="img/svm.png">

<img src="img/svm2.png">

doesn't output the probability, either 1 or 0

> Large Margin Intuition

<img src="img/svm3.png">

<img src="img/svmdb.png">

<img src="img/svmdb2.png">

> Kernels One

<img src="img/kernels.png">