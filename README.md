# Perceptron (Delta rule)

W' = W + (d - y) * Δ * X

## Program arguments

1: Δ  
2: Training set(CVS)  
3: Test set(CVS)

```bash
0.1 TreningSet.cvs TestCase.cvs
```

## Examples

TrainingSet.cvs
```bash
5.1,3.3,1.7,0.5,Iris-setosa
```
TestSet.cvs
```bash
5.2,3.5,1.5,0.2,UNDEFIEND
```



## Supplement

If "k" as start parameter is 0 or less, it will be redefined to standard case (0.1)  
If "k" as start parameter is greater than 1, it will be redefined to standard case (0.1)  
