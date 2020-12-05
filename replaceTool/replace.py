
def replace(src, replace):
    src = src.replace(replace, '')
    return src 

import tkinter as tk  
from tkinter import ttk
  
win = tk.Tk() # Application Name  
win.title("Python GUI App")# Label  
win.geometry('600x600')
lbl = ttk.Label(win, text = "Enter the name:").place(x=0, y=0, height=30)## Click event  


txt = tk.Text(win)
txt.pack()
txt.place(x=0, y=35, height=200)

txtToOmit = tk.Text(win)
txtToOmit.pack()
txtToOmit.place(x=0, y=235, height=100)


txtResult = tk.Text(win)
txtResult.pack()
txtResult.place(x=0, y=365, height=200)

def click(txt):   
    src = txt.get("1.0", "end")
    x = txtToOmit.get("1.0", "end")[:-1]
    tmp = replace(src, x)
    txtResult.delete(1.0, "end")
    txtResult.insert(1.0, tmp)


submit = tk.Button(win, text="Replace it", command=lambda : click(txt))
submit.place(x=0, y=335)
win.mainloop()


# print(replace("hello world", "hello"))