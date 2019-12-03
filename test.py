from sympy.abc import m, p, A, M
from sympy import Sum, exp, factorial
import matplotlib.pyplot as plt
import matplotlib.lines as lines
import numpy as np
import time

# 使matplotlib支持中文
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号


def calc_A():
    expr = Sum(exp(-1*A) * ((1/factorial(m)) * (A ** m)), (m, 0, M-1)) - p
    f = expr.subs({"M": 5, "p": 10 ** -5})
    return f


def plot_A():
    x = np.linspace(-100, 100, 5000)
    f = calc_A()
    y = np.array([])
    min_y = np.float('inf')
    min_y_A = 0

    last_x = 0
    last_y = 0
    for i in x:
        value = f.evalf(subs={A: i})
        y = np.append(y, value)
        if min_y > abs(value):
            min_y = abs(value)
            min_y_A = i
        last_x = i
        last_y = value

    print("min_y=", min_y)
    print("min_y_A=", min_y_A)  

    fig, ax = plt.subplots()
    ax.plot(x, y)

    ax.annotate('最近0值: \nx=%f\ny=%f' % (min_y_A, min_y),
                xy=(min_y_A, min_y), xycoords='data',
                xytext=(0, 25), textcoords='offset points',
                arrowprops=dict(facecolor='black', shrink=0.05),
                horizontalalignment='right', verticalalignment='bottom')

    ax.annotate('最后一个值: \nx=%f\ny=%f' % (last_x, last_y),
            xy=(last_x, last_y), xycoords='data',
            xytext=(20, 25), textcoords='offset points',
            arrowprops=dict(facecolor='black', shrink=0.05),
            horizontalalignment='right', verticalalignment='bottom')
    plt.show()


if __name__ == "__main__":
    startTime = time.clock()
    # calc_A()
    plot_A()
    endTime = time.clock()

    print('Running time: %s Seconds' % (endTime - startTime))
