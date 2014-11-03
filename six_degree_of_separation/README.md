#### Task

Social networks have caused a social pressure to reach also people, who uses text based user interfaces. This program offers a possibility to model a network, which is similar to many social networks. Each person to be added to the social network has an unique id, which is a positive integer. There may be persons with same name, like in real life. It is possible to add relations between persons and ask if two persons has a specific relationship. It also offers interesting Six Degrees of Separation -functionality. The Six Degrees of Separation is described in (wikipedia)[http://en.wikipedia.org/wiki/Six_degrees_of_separation]


#### Commands

A <i> <n>           : Adds a person with ID <i> and name <n> to the data structure

R <t> <i1> <i2> <d> : Adds a relation of type <t> between persons <i1> and <i2>. The description of the relation is <d> and it may contain spaces.

I <t> <i1> <i2>     : Inquiries if there is relation <t> between persons <i1> and <i2>. Prints <name1>SEPARATOR<t>SEPARATOR<name2>

F<i>                : Prints all friends of <i> in order rstly added first and so on. The program prints: <name for id>HAS_FRIENDS and after that all friends in following format: <name>SEPARATOR<type>SEPARATOR <description>. If there is no friends, the program prints constant NO_FRIENDS instead of list of friends.

S <i1> <i2>         : Performs the Six Degrees of Separation and checks if <i1> and <i2> are at most six steps from each other. Function prints persons <i> and <i2>, each on own line.

E                   : Empties the data structure.

Q                   : Quits the program

======================================

#### Input and Output Sample.

$ ./prog < test_public.in

A 0 Panu

A 1 Sampo

A 2 Heli

A 3 Sauli

A 4 Lasse

A 5 Tanja

A 6 Iiris

R R 0 6 Married

R R 6 2 Relationship

R R 2 3 Relationship

R K 2 4 Daughter-Father

R F 4 5 Friend

R F 0 4 Neighbo

A 7 Juulia

R K 5 7 Biological mother

R K 0 1 Father-Son

R K 6 1 Mother-Son

S 0 2

Panu

Heli

S 0 5

Panu

Tanja

A 8 Romeo

S 0 8

No relation found.

I R 0 1

No relation found.

R R 7 8 Relationship

S 0 8

Panu

Romeo

I R 0 6

Panu R Iiris

F 0

Panu has friends:

Iiris R Married

Lasse F Neighbor

Sampo K Father-Son

Q
