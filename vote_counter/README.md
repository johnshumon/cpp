#### Task

Winners of the contest are voted by using text message (SMS). It is allowed to vote one contetstant from one phone number ten (10) times. In final phase there are 12 contestants and the nal phase is very popular. That means, that
there may be even millions of voters, at least hundreds of thousands. The amount of voters is, of course, unknown  beforehand. Company Fact have chosen me to implement this vote counter and its functionality, because you have necessary Data Structure knowledge! I have decided to use hashtable as one part of the data structure.
 

#### Commands

R <f>       : Reads votes from le <f> and adds them to the data structure

T<n>        : Shows top n -list

C<a>        : Count votes for artist <a>

E           : Empties the data structure.

Q           : Quits the program.

======================================

#### Input data file

<timestamp> <phone number> <artists ID>

2008-03-05T12:30Z 5874032 0
 
2008-04-06T13:31Z 5874033 1

2008-05-07T14:32Z 5874034 2

2008-05-09T18:32Z 5874134 2

2008-06-08T15:33Z 5874035 3


=========================

#### Output

$ ./eff < test_public.in

> R public_votes

> T 5

1. Isaac  25.00% of votes.

2. Mohinder 12.50% of votes.

3. Claire 6.25% of votes.

4. Hiro 6.25% of votes.

5. Jessica 6.25% of votes.

16 votes given totally.

> Q
