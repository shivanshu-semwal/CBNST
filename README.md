# CBNST - Computer Based Numerical and Statistical Techniques

## Index

- **lab1**
  - change a matrix to upper and lower matrix
  - make a polynomial expression parser to get the degree and coefficient
- **lab2**
  - demonstrate how to use mathematical functions with help of `math.h` lib
- **lab3**
  - generic function for bijection method (for single variable)
- **minimal programs**
  - [bisection](./src/bisection.c)
  - [regula falsi](./src/regula_falsi.c)
  - [newton raphson](./src/newton_rahpson.c)
  - [gauss elimination](./src/gauss_elimination.c)
  - [gauss jordan](./src/gauss_jordan.c)


## Linking libraries

* to link `math.h` lib use `-lm` flag, e.g. `gcc -o out -i in.c -lm`


## Notes:

* Convert text to png (using `imagemagik`)- `convert -size 1000x3000 xc:"#2e3440" -font "monofur" -pointsize 23 -fill "#d8dee9" -annotate +20+20 @filename.txt -trim -bordercolor "#2e3440" -border 20 +repage output.png`

