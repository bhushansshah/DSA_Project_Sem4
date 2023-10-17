set size 4, 4
set multiplot layout 1, 2

set xrange [0:20]
set yrange [0:20]


unset key
set title ("Previous Route")
plot "data/initial_route" u 1:2 w lp pt 20, "data/initial_route" using 1:2:(sprintf("(%g,%g)", $1, $2)) with labels offset 1,1 notitle, 

unset key
set title ("New Route")
plot "data/final_route" u 1:2 w lp pt 20, "data/final_route" using 1:2:(sprintf("(%g,%g)", $1, $2)) with labels offset 1,1 notitle  

