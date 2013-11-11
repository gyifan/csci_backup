/*
 *===================================================
 *  Name: Yifan Ge
 *  Course: CSCI 203 / Prof. Zaccone / MWF 1:00
 *  Lab Section: Tuesday 10-12AM
 *  Assignment: Lab #9
 *  Date: 11/2/2010
 *
 *===================================================
 */
 
/*
 *===================================================
 *
 *	Exercise 1
 *
 *===================================================
 */
Middle of null string: null
Expected: null

Middle of "": ""
Expected: ""

Middle of "abcdefg": "d"
Expected: "d"

Middle of "abcdefgh": "de"
Expected: "de"

Middle of "a": "a"
Expected: "a"

/*
 *===================================================
 *
 *	Exercise 2
 *
 *===================================================
 */
A: valid
Expected: valid

      AB: not valid
Expected: not valid

    null: not valid
Expected: not valid

       B: valid
Expected: valid

       C: valid
Expected: valid

       c: valid
Expected: valid

       d: valid
Expected: valid

       E: not valid
Expected: not valid

     xyz: not valid
Expected: not valid

     XYZ: not valid
Expected: not valid

        : not valid
Expected: not valid

       1: not valid
Expected: not valid

/*
 *===================================================
 *
 *	Exercise 3
 *
 *===================================================
 */
    1980: true
Expected: true

    1900: false
Expected: false

    2000: true
Expected: true

    1500: true
Expected: true

    1501: false
Expected: false