/* 1
x= #allumette
R(x) = #allumette apres qu'on ai joue'
R(X) = X-1 or X-2 or X-3


K = {}

x in K => R(x) instersect K = NULL

si x in K => x = 4i		(i in N)
=> R(x) = {4i-1,4i-2,4i-3}
or 	(4i-1)/4 = i - 1/4 not in K
	(4i-2)/4 = i - 2/4 not in K
	(4i-3)/4 = i - 3/4 not in K
=> R(x) intersect K = NULL

x not in K => R(x) intersect K not = NULL
si x not in K => x in { 4i+3, 4i+2, 4i+1}
=>	R(4i+3) = {4i+2, 4i+1, 4i}
or (4i)/4 = i in K
=> R(x) intersect K not = NULL
*/

/*2
paper
*/

/*3
Maintenir l'adversaire dans le noyau
*/