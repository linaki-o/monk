# Prestatement
using Octave programming environment
Matlab
# What is Machine Learning
- Grew out of work in Al
- New capability for computers
> application examples:

    - Database mining
    Large datasets from growth of automation/web
    E.g., Web click data, medical records, biology, engineering
    - Applications can't program by hand.
    E.g., Autonomous helicopter, handwriting recognition, most of
    Natural Language Processing (NLP), Computer Vision.
    - Self-customizing programs
    E.g., Amazon, Netflix product recommendations
    - Understanding human learning (brain, real Al).

# Machine Learning definition
- Arthur Samuel (1959). 
`Machine Learning: Field of study that gives computers the ability to learn without being explicitly programmed.`

- Tom Mitchell (1998).
`Well-posed Learning Problem: A computer program is said to learn from experience E with respect to some task T and some performance measure P, if its performance on T, as measured by P, improves with experience E.`

# Machine Learning algorithms
- Supervised learning
- Unsupervised learning
- Reinforcement learning
- recommender systems

## Supervised learning
right answers given

### Linear regression

predict continuous valued output 

> notation

<img src="img/notation.png">

> process

<img src="img/process.png">

<img src="img/hypothesis.png">

<img src="img/all.png">

> diagrams

<img src="img/d1.png">

<img src="img/d2.png">
<img src="img/d2.png">

> gradient descent algorithm

<img src="img/g1.png">
<img src="img/g2.png">

alpha means learning rate
- if a is too small,gradient descent can be slow
- If a is too large,gradient descent can overshoot the minimum.it may fail to converge, or even diverge  

**As we approach a local minimum, gradient descent will automatically take smaller steps.so,no need to decrease a over time**

Gradient descent will scale better to larger data sets than that normal equations method 

<img src="img/partial.png">

"Batch" Gradient Descent: `"Batch": Each step of gradient descent uses all the training examples.`

> linear algebra application

matrices * vector

<img src="img/la1.png">

matrices * matrices

<img src="img/la2.png">

Matrices that don't have an inverse are "singular" or "degenerate"

> Multiple features

n: number of features
x^(i)j = value of feature j in i^th training example.

<img src="img/mlr1.png">

> feature scaling

make sure features are on a similar scale then gradient descents can converge more quickly
<img src="img/fs1.png">

> mean normalization

<img src="img/mn1.png">

> choice of features

> Polynomial regression

<img src="img/pr.png">

> Vectorization

<img src="img/v1.png">

```m
    delta = zeros(length(theta), 1);
    delta = 1/m * (X*theta - y)' * X;
    theta = theta - alpha * delta';
```

### Classification algorithm
discrete valued output 

Yes or No

> normal linear regression doesn't work well

<img src="img/c1.png">

<img src="img/c2.png">

> logistic regression

<img src="img/lr1.png">

<img src="img/lr2.png">

> Decision boundary

<img src="img/lr3.png">


<img src="img/lr4.png">

> Cost function

cost function of linear regression doesn't work

<img src="img/cf1.png">

> really cost function

<img src="img/cf2.png">

> Simplified cost function and gradient descent

<img src="img/lr5.png">

> Advanced optimization

<img src="img/oa1.png">


```m
function [jVal,gradient] = costFunction(theta)
%COSTFUNCTION 此处显示有关此函数的摘要
%   此处显示详细说明
jVal = (theta(1) - 5) ^ 2 + (theta(2) - 5) ^ 2;
gradient = zeros(2,1);
gradient(1) = 2 * (theta(1) - 5);
gradient(2) = 2 * (theta(2) - 5);
end


>> options = optimset('GradObj', 'on', 'MaxIter', 100);
>> initialTheta = zeros(2,1); % initialTheta at least a two-dimensional vector
>> [optTheta, functionVal, exitFlag] = fminunc(@costFunction, initialTheta, options)

Local minimum found.

Optimization completed because the size of the gradient is less than
the value of the optimality tolerance.

<stopping criteria details>

ptTheta =

     5
     5


functionVal =

     0


exitFlag =

     1

```

> Multi-class classification: One-vs-all

<img src="img/ovsa.png">

<img src="img/ovsa2.png">

> The problem of overfitting

<img src="img/of1.png">

<img src="img/of2.png">

> Regularization Cost function

penalize and make some theta really small

<img src="img/r1.png">

**what if lambda is set to an extremely large value(perhaps for too large for our problem, say lambda = 10^10)** 

<font color="red">under fit</font>

<img src="img/r2.png">


> Regularized linear regression

**gradient descent**

<img src="img/rl1.png">

**Normal equation**

<img src="img/rl2.png">

**Non-invertibility(optional/advanced)**

regularization also takes care of this for us

<img src="img/rl3.png">

> Regularized logistic regression

<img src="img/rlr1.png">




## Unsupervised learning
doesn't have any label
## clustering algorithm
break data set into some separate clusters
> Application Scene
    - google news
    - Market segmentation

## Cocktail party problem

# Types of Machine Learning
