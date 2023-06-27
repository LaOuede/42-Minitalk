<p align="center">
  <img src="https://github.com/LaOuede/42-project-badges/blob/main/badges/minitalke.png" />
</p>

<h1 align=center>minitalk</h1>

<p align=center>
  The purpose of <b>Minitalk</b> project is to code a small data exchange program using UNIX signals.
  A client must communicate a string passed as a parameter to a server which is referenced by its process ID. Then, the server displays the string.
  The only two signals allowed are SIGUSR1 & SIGUSR2.
</p>

<div align="center">

Go to [42 Québec](https://42quebec.com/) to discover the course ! 👈
</div>

---

<h3 align="left">What I've learned</h3>

I've acquired a lot of basic knowledge on C programming :
- Understanding of UNIX signals
- Handling and interpreting signals
- Memory management (dynamic arrays)
- User Interface Design
- Testing and debugging

---

<h3 align="left">If I had to do it all over again</h3>

- I would improve my memory managemtn by sending the lenght of the string as the first information.
  This way, I would only have to allocate memory once.

---

Compilation :
```bash
make
```

Execution :
```bash
./server
```
```bash
./client <server PID> <string to pass>
```

Behaviour :
<img width="2209" alt="Screen Shot 2023-06-26 at 8 25 49 AM" src="https://github.com/LaOuede/Minitalk/assets/114024436/0d74c7c6-2b19-45c4-918b-cfa8847c315b">


---

<div align="center">

To look at [my next 42 project](https://github.com/LaOuede/FdF) !
</div>
