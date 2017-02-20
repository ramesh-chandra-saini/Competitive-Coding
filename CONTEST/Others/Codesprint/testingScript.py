
from svmutil import *
# Read data in LIBSVM format
y, x = svm_read_problem('../heart_scale')
print y,x
m = svm_train(y[:200], x[:200], '-c 4')
print m
p_label, p_acc, p_val = svm_predict(y[200:], x[200:], m)
print p_label,'\n',p_acc,'\n',p_val,'\n'
