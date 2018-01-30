Sheila is a student and she drives a typical student car: it is old, slow,

rusty, and falling apart. Recently, the needle on the speedometer fell

off. She glued it back on, but she might have placed it at the wrong

angle. Thus, when the speedometer reads s, her true speed is s + c,

where c is an unknown constant (possibly negative).

Sheila made a careful record of a recent journey and wants to use

this to compute c. The journey consisted of n segments. In the i

th

segment she traveled a distance of di and the speedometer read si for

the entire segment. This whole journey took time t. Help Sheila by

computing c.

Note that while Sheila’s speedometer might have negative readings,

her true speed was greater than zero for each segment of the journey.

Input

The first line of input contains two integers n (1 ≤ n ≤ 1 000), the number of sections in Sheila’s journey,

and t (1 ≤ t ≤ 106

), the total time. This is followed by n lines, each describing one segment of Sheila’s

journey. The i

th of these lines contains two integers di (1 ≤ di ≤ 1 000) and si (|si

| ≤ 1 000), the distance

and speedometer reading for the i

th segment of the journey. Time is specified in hours, distance in miles,

and speed in miles per hour.

Output

Display the constant c in miles per hour. Your answer should have an absolute or relative error of less than

10−6

.

Solution:

Since there is a constant we don't know, we need to solve the equation which contains it. The variables are related with
d = (v + c) * t, now we need to solve for c. Since most cases contain more than one segment, we obtain a system of equations.
The many equations come from not knowing the correct time for each segment, so we need to substract the other times from  the total.

In the end, c is obtainable by solving for every segment.
