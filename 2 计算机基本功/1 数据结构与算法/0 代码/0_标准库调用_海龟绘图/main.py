import turtle as t
color=["pink","purple","red","blue","yellow","orange","coral","brown","yellow","fuchsia"]
width = 10 
t.pensize(width)
R = 0
for i in range(len(color)):
    R = i * width
    t.pencolor(color[i])
    t.circle(R)
    t.penup()
    t.goto(0, -R - width)
    t.pendown()
t.penup()
t.goto(0, 0)
t.exitonclick()
