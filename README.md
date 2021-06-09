# CBNST - Computer Based Numerical and Statistical Techniques

## Index

- **minimal programs**
  - [Bisection Method](./src/bisection.c)
  - [Regula-Falsi Method](./src/regula_falsi.c)
  - [Newton Raphson Method](./src/newton_rahpson.c)
  - [Gauss elimination](./src/gauss_elimination.c)
  - [Gauss jordan](./src/gauss_jordan.c)
  - [Gauss jacobi](./src/gauss_jacobi.c)
  - [Gauss seidel](./src/gauss_seidel.c)
  - [Newton Forward Interpolation](./src/newtons_forward_ip.c)
  - [Newtons Backward Interpolation](./src/newtons_backword_ip.c)
  - [Lagrange interpolation Method](./src/lagrange_interpolation.txt)
  - [Trapezoidal Method](./src/trapezoidal.c)
  - [Simpson 1/3 Method](./src/simpsons1by3.c)
  - [Simpson 3/8 Method](./src/simpsons3by8.c)
  - [Euler's Method](./src/euler.c)
  - [Runge–Kutta methods](./src/runge_kutta.c)

## Linking libraries

* to link `math.h` lib use `-lm` flag, e.g. `gcc -o out -i in.c -lm`


## Notes:

* Convert text to png (using `imagemagik`)- `convert -size 1000x3000 xc:"#2e3440" -font "monofur" -pointsize 23 -fill "#d8dee9" -annotate +20+20 @filename.txt -trim -bordercolor "#2e3440" -border 20 +repage output.png`

