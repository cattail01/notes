import turtle as t
for i in range(3):
    t.forward(100 * 2)
    t.right(120)
    t.fillcolor("yellow")
    t.begin_fill()
    for j in range(2):
        t.forward(100)
        t.right(120)
    t.forward(100 * 2)
    t.left(120)
    for j in range(2):
        t.forward(100)
        t.left(120)
    t.forward(100)
    t.left(120)
    t.end_fill()
t.exitonclick()
