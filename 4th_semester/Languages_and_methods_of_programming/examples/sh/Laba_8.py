# Реализовать интерфейс по сортировке массива имеющий окно для ввода массива (так же предусмотреть возможность читать
# массив из файла и записывать в файл) три кнопки для выбора сортировки окно вывода
# отсортированного массива. Сортировки Шелла, шейкер и Хоара.

from tkinter import *
from tkinter import messagebox as mb
import sys

data = []

def shell_sort(): # сортировка Шелла
    data = result
    inc = len(data) // 2
    while inc:
        for i, el in enumerate(data):
            while i >= inc and data[i - inc] > el:
                data[i] = data[i - inc]
                i -= inc
            data[i] = el
        inc = 1 if inc == 2 else int(inc * 5.0 / 11)
    mass = ''
    for i in range(len(data)):
        mass = mass + str(data[i])
        mass = mass + ' '
    title2.configure(text = mass)
    btnShell['state'] = DISABLED
    btnShaker['state'] = DISABLED
    btnHoar['state'] = DISABLED
    starting()


def cocktail_sort(): # Шейкерная сортировка
    data = result
    n = len(data)
    swapped = True
    start = 0
    end = n - 1
    while (swapped == True):
        swapped = False
        for i in range(start, end):
            if (data[i] > data[i + 1]):
                data[i], data[i + 1] = data[i + 1], data[i]
                swapped = True
        if (swapped == False):
            break
        swapped = False
        end = end - 1
        for i in range(end - 1, start - 1, -1):
            if (data[i] > data[i + 1]):
                data[i], data[i + 1] = data[i + 1], data[i]
                swapped = True
        start = start + 1
        mass = ''
        for i in range(len(data)):
            mass = mass + str(data[i])
            mass = mass + ' '
    title2.configure(text=mass)
    btnShell['state'] = DISABLED
    btnShaker['state'] = DISABLED
    btnHoar['state'] = DISABLED
    starting()


def sort(): # функция для быстрой сортировки (сортировки Хоара)
    mass = ''
    data = result
    quicksort(data, 0, len(data))
    for i in range(len(data)):
        mass = mass + str(data[i])
        mass = mass + ' '
    title2.configure(text=mass)
    btnShell['state'] = DISABLED
    btnShaker['state'] = DISABLED
    btnHoar['state'] = DISABLED
    starting()

def quicksort(alist, start, end): # Сортировка Хоара
    if end - start > 1:
        p = partition(alist, start, end)
        quicksort(alist, start, p)
        quicksort(alist, p + 1, end)


def partition(alist, start, end): # деление для сортировки Хоара
    pivot = alist[start]
    i = start + 1
    j = end - 1

    while True:
        while (i <= j and alist[i] <= pivot):
            i = i + 1
        while (i <= j and alist[j] >= pivot):
            j = j - 1

        if i <= j:
            alist[i], alist[j] = alist[j], alist[i]
        else:
            alist[start], alist[j] = alist[j], alist[start]
            return j

def messageError():
    mb.showerror( "Ошибка", "Указана неверная директория файла! Проверьте путь.")

def starting():
    buttonWrite = Button(root, text="Запись в файл", command=writing)
    buttonWrite.grid(column=2, row=0)
    buttonWrite.place(x=40, y=400)

def writing():
    f1 = open("answer.txt", 'w')
    for i in range(len(result)):
        f1.write(str(result[i]))
        f1.write(" ")
    title = Label(root, text='Массив сохранён в файле answer.txt', font=("Arial Bold", 13), fg='black')
    title.place(x=300, y=400)


def filling_external(): # чтение массива из программы
    mass = txt.get()
    num = ''
    data = mass.split()
    global result
    result = [int(item) for item in data]
    data = result
    addNameOfString.destroy()
    main_window(mass)

def filling_file(): # чтение массива из файла
    name = txt.get()
    try:
        f = open(name)
        f.close()
    except FileNotFoundError:
        messageError()
        return False
    mass = ''
    with open(name) as inp:
        data = inp.read().split()
    for i in range(len(data)):
        mass = mass + data[i]
        mass = mass + ' '
    global result
    result = [int(item) for item in data]
    data = result
    print(data)
    addNameOfString.destroy()
    main_window(mass)

def file_input(): # окно для открытия путём файла
    addInsert.destroy()
    global addNameOfString
    addNameOfString = Tk()
    addNameOfString.title("Расположение файла")
    addNameOfString.wm_attributes('-alpha', 1)
    addNameOfString.geometry('500x85')
    addNameOfString.resizable(width=False, height=False)

    title = Label(addNameOfString, text='Введите директорию расположения файла', font=("Arial Bold", 13), fg='black')
    title.place(x=100, y=5)

    global txt
    txt = Entry(addNameOfString, width=50)
    txt.grid(column=1, row=2)
    txt.place(x = 5, y = 30)

    ok = Button(addNameOfString, text="ОК", command = filling_file)
    ok.grid(column=2, row=0)
    ok.place(x=430, y=30)

def file_whithout_input(): # окно в случае ввода
    addInsert.destroy()
    global addNameOfString
    addNameOfString = Tk()
    addNameOfString.title("Ввод массива")
    addNameOfString.wm_attributes('-alpha', 1)
    addNameOfString.geometry('500x85')
    addNameOfString.resizable(width=False, height=False)

    title = Label(addNameOfString, text='Введите Ваш массив', font=("Arial Bold", 13), fg='black')
    title.place(x=100, y=5)

    global txt
    txt = Entry(addNameOfString, width=50)
    txt.grid(column=1, row=2)
    txt.place(x=5, y=30)

    ok = Button(addNameOfString, text="ОК", command=filling_external)
    ok.grid(column=2, row=0)
    ok.place(x=430, y=30)

def add_window(): # окно для выбора ввода массива
    global addInsert
    addInsert = Tk()
    addInsert['bg'] = 'white'
    addInsert.title("Ввод массива")
    addInsert.wm_attributes('-alpha', 1)
    addInsert.geometry('300x100')
    addInsert.resizable(width=False, height=False)

    title = Label(addInsert, text='Выберите способ ввода массива', font=("Arial Bold", 13), fg='black')
    title.place(x=45, y=5)

    btnFile = Button(addInsert, text="Файл", command = file_input)
    btnFile.grid(column=2, row=0)
    btnFile.place(x = 20, y = 39)

    btnNotFile = Button(addInsert, text="Без файла", command = file_whithout_input)
    btnNotFile.grid(column=2, row=0)
    btnNotFile.place(x=180, y=39)
    addInsert.mainloop()


def main_window(mass): # главное окно
    global root
    root = Tk()
    root['bg'] = 'white'
    root.title("Сортировка массива")
    root.wm_attributes('-alpha', 1)
    root.geometry('810x500')
    root.resizable(width=False, height=False)

    frame = Frame(root, bg='red')
    frame.place(relx=0, rely=0, relwidth=5, relheight=0.25)

    canvas = Canvas(frame, height=1024, width=805)
    img = PhotoImage(file='2.gif')
    image = canvas.create_image(0, 0, anchor='nw', image=img)
    canvas.grid(row=2, column=1)

    title = Label(root, text='Ваш массив', font=("Marker Felt", 20), fg='#FF6347')
    title.place(x=350, y=130)

    frame2 = Frame(root, bg='white')
    frame2.place(relx=0, rely=0.3, relwidth=1, relheight=0.5)

    global title2
    title2 = Label(frame2, text=mass, font=("Marker Felt", 20), fg='#FF6347', justify = CENTER)
    title2.pack()

    global btnShell
    btnShell = Button(root, text="Сортировка Шелла", command=shell_sort)
    btnShell.grid(column=2, row=0)
    btnShell.place(x=40, y=200)

    global btnShaker
    btnShaker = Button(root, text="Сортировка шейкер (коктейльная)", command=cocktail_sort)
    btnShaker.grid(column=2, row=0)
    btnShaker.place(x=250, y=200)

    global btnHoar
    btnHoar = Button(root, text="Сортировка Хоара (быстрая)", command=sort)
    btnHoar.grid(column=2, row=0)
    btnHoar.place(x=550, y=200)

    root.mainloop()

add_window()



