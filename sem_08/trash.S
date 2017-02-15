.text           /* секция кода программы */
.global main    /* экспортируем точку входа - функцию main */
main:
call    finish  /* вызываем подпрограмму finish: exit(0) */
