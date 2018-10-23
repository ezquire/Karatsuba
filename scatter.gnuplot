set term png
set key font ",10"
set title font ",10"
set style data points
set key left top
set output "scatter.png"
set title "Scatter Plot of the time taken for Karatsuba's algorithm vs the grade school method"
set grid
set pointsize
plot "fast.txt" title "Karatsuba's", "slow.txt" title "Grade School" with points lt 2 pt 3
quit